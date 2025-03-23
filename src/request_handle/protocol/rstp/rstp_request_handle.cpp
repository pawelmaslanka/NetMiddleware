#include "rstp_request_handle.hpp"
#include "rstp_members_request_handle.hpp"

#include <lib/xpath/xpath.hpp>

static constexpr auto RSTP_NODE_NAME { "rstp" };

RstpRequestHandle::RstpRequestHandle(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<Node> parent)
  : Node(RSTP_NODE_NAME, parent), RequestHandle(module_name, module_registry, RSTP_NODE_NAME, parent) {}

bool RstpRequestHandle::handle(IRequestHandle::Request& req, IRequestHandle::Response& res) {
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

    auto br_id = req.Data.Value;
    Regex br_id_regex("^(br-(6[5-6])|br-(6[0-6]|5[0-9]|4[0-9]|3[0-9]|2[0-9]|1[0-9]|[1-9]))$");
    if (!std::regex_match(br_id, br_id_regex)) {
        res.Data.Success = false;
        res.Data.Data = "Not found bridge id as value for xpath '" + req.Data.Path + "', got '" + br_id + "'";
        return false;
    }

    // TODO: Needs additional implementation to handle bridge instance creating

    auto rstp_bridge_req_hdl = MakeSharedPtr<RequestHandle>(_module_name, _module_registry, br_id, XPathNode::Node::shared_from_this());
    XPathNode::Composite::add(rstp_bridge_req_hdl);
    auto rstp_members_bridge_req_hdl = MakeSharedPtr<RstpMembersRequestHandle>(_module_name, _module_registry, rstp_bridge_req_hdl);
    rstp_bridge_req_hdl->add(rstp_members_bridge_req_hdl);
    _log->info("Successfully created new node '{}' for xpath '{}'", rstp_bridge_req_hdl->name(), req.Data.Path);
    return true;
}
