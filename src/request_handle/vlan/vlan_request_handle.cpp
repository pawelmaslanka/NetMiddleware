#include "vlan_request_handle.hpp"
#include "vlan_members_request_handle.hpp"

#include "vlan_management.hpp"

#include <lib/xpath/xpath.hpp>

static constexpr auto VLAN_NODE_NAME { "vlan" };

VlanRequestHandle::VlanRequestHandle(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<Node> parent)
  : Node(VLAN_NODE_NAME, parent), RequestHandle(module_name, module_registry, VLAN_NODE_NAME, parent) {}

bool VlanRequestHandle::handle(IRequestHandle::Request& req, IRequestHandle::Response& res) {
    if (!checkIfRootXPathNodeIsMe(req)) {
        res.Data.Success = false;
        res.Data.Data = "Invalid xpath '" + req.Data.Path + "' during processing current node '" + name() + "'";
        return false;
    }

    if (req.XPathNodes.size() != 0) {
        _log->info("Continue handling request for xpath '{}' in another node '{}'", req.Data.Path, req.XPathNodes.front());
        auto node = findNode(req.XPathNodes.front());
        if (!node) {
            res.Data.Success = false;
            res.Data.Data = "Not found node '" + req.XPathNodes.front() + "' at xpath '" + req.Data.Path + "'";
            return false;
        }

        return std::dynamic_pointer_cast<IRequestHandle>(node)->handle(req, res);
    }

    StringStream vlan_id_str;
    vlan_id_str << req.Data.Value;
    Regex vlan_id_regex("^((40[0-9][0-5])|([1-3][0-9][0-9][0-9])|([0-9][0-9])|[1-9])$");
    if (!std::regex_match(vlan_id_str.str(), vlan_id_regex)) {
        res.Data.Success = false;
        res.Data.Data = "Not found vlan id as value for xpath '" + req.Data.Path + "', got '" + vlan_id_str.str() + "'";
        return false;
    }

    auto vlan_mngr = std::dynamic_pointer_cast<VlanManager>(_module_registry->vlanModule());
    if (!vlan_mngr) {
        _log->error("Cannot get vlan manager object from modules registry");
        res.Data.Success = false;
        return false;
    }

    Net::Vlan::VID vid = 0;
    vlan_id_str >> vid;

    if (!vlan_mngr->createVlan(vid)) {
        _log->error("Failed to create vlan id '{}'", vid);
        res.Data.Success = false;
        return false;
    }

    auto vlan_req_hdl = MakeSharedPtr<RequestHandle>(_module_name, _module_registry, vlan_id_str.str(), XPathNode::Node::shared_from_this());
    XPathNode::Composite::add(vlan_req_hdl);
    auto vlan_members_req_hdl = MakeSharedPtr<RequestHandle>(_module_name, _module_registry, "members", XPathNode::Node::shared_from_this());
    vlan_req_hdl->add(vlan_members_req_hdl);
    for (auto vlan_type : { VlanMembersPerTypeRequestHandle::VlanType::NATIVE,
                            VlanMembersPerTypeRequestHandle::VlanType::TAGGED,
                            VlanMembersPerTypeRequestHandle::VlanType::UNTAGGED }) {
        auto vlan_members_type_req_hdl = MakeSharedPtr<VlanMembersPerTypeRequestHandle>(_module_name, _module_registry, vlan_type, vlan_members_req_hdl);
        vlan_members_req_hdl->add(vlan_members_type_req_hdl);
    }

    _log->info("Successfully created new node '{}' for xpath '{}'", vlan_req_hdl->name(), req.Data.Path);
    return true;
}
