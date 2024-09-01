#include "vlan_members_request_handle.hpp"

#include "interface_management.hpp"
#include "lag_management.hpp"
#include "vlan_management.hpp"

#include <lib/xpath/xpath.hpp>

static constexpr auto VLAN_NATIVE_STR { "native" };
static constexpr auto VLAN_TAGGED_STR { "tagged" };
static constexpr auto VLAN_UNTAGGED_STR { "untagged" };

VlanMembersPerTypeRequestHandle::VlanMembersPerTypeRequestHandle(StringView module_name, SharedPtr<ModuleRegistry> module_registry, const VlanMembersPerTypeRequestHandle::VlanType type, SharedPtr<Node> parent)
  : Node(convertVlanTypeToString(type), parent), RequestHandle(module_name, module_registry, convertVlanTypeToString(type), parent) {}

bool VlanMembersPerTypeRequestHandle::handle(IRequestHandle::Request& req, IRequestHandle::Response& res) {
    if (!checkIfRootXPathNodeIsMe(req)) {
        res.Data.Success = false;
        res.Data.Data = "Invalid xpath '" + req.Data.Path + "' during processing current node '" + name() + "'";
        return false;
    }

    if (req.XPathNodes.size() != 0) {
        res.Data.Success = false;
        res.Data.Data = "The node '" + name() + "' is a leaf and there should not be more nodes in xpath '" + req.Data.Path + "'";
        return false;
    }

    auto iface_id = req.Data.Value;
    Regex iface_id_regex("^((eth[0-9]-(6[5-6])|eth[0-9]-(6[0-6]|5[0-9]|4[0-9]|3[0-9]|2[0-9]|1[0-9]|[1-9])(_[1-4])?)|(lag-(6[5-6])|lag-(6[0-6]|5[0-9]|4[0-9]|3[0-9]|2[0-9]|1[0-9]|[1-9])))$");
    if (!std::regex_match(iface_id, iface_id_regex)) {
        res.Data.Success = false;
        res.Data.Data = "Not found inerface id as value for xpath '" + req.Data.Path + "', got '" + iface_id + "'";
        return false;
    }

    if (std::regex_match(iface_id, Regex { "^(lag-(6[5-6])|lag-(6[0-6]|5[0-9]|4[0-9]|3[0-9]|2[0-9]|1[0-9]|[1-9]))$" })) {
        auto lag_module = _module_registry->lagModule();
        if (!lag_module) {
            _log->error("Cannot get lag module from modules registry");
            res.Data.Success = false;
            return false;
        }

        if (!lag_module->getLag(iface_id).lock()) {
            _log->error("LAG interface '{}' does not exist", iface_id);
            res.Data.Data = "LAG interface '" + iface_id + "' does not exist";
            res.Data.Success = false;
            return false;
        }
    }
    else {
        auto iface_module = _module_registry->interfaceModule();
        if (!iface_module) {
            _log->error("Cannot get interface module from modules registry");
            res.Data.Success = false;
            return false;
        }

        if (!iface_module->getInterface(iface_id).lock()) {
            _log->error("Interface '{}' does not exist", iface_id);
            res.Data.Data = "Interface '" + iface_id + "' does not exist";
            res.Data.Success = false;
            return false;
        }
    }

    auto vlan_mngr = std::dynamic_pointer_cast<VlanManager>(_module_registry->vlanModule());
    if (!vlan_mngr) {
        _log->error("Cannot get vlan manager object from modules registry");
        res.Data.Success = false;
        return false;
    }


    StringStream vlan_id_str;
    vlan_id_str << parent()->parent()->name(); // [native|tagged|untagged] -> [members] -> [VLAN ID]
    Net::Vlan::VID vid;
    vlan_id_str >> vid;
    if ((name() == VLAN_NATIVE_STR)
        && !vlan_mngr->setNativeVlan(vid, iface_id)) {
        _log->error("Failed to add member '{}' to the native vlan '{}'", iface_id, vid);
        res.Data.Success = false;
        return false;
    }
    else if ((name() == VLAN_TAGGED_STR)
        && !vlan_mngr->addTaggedMember(vid, iface_id)) {
        _log->error("Failed to add member '{}' to the tagged vlan '{}'", iface_id, vid);
        res.Data.Success = false;
        return false;
    } else if (!vlan_mngr->addUntaggedMember(vid, iface_id)) {
        _log->error("Failed to add member '{}' to the untagged vlan '{}'", iface_id, vid);
        res.Data.Success = false;
        return false;
    }

    return true;
}

String VlanMembersPerTypeRequestHandle::convertVlanTypeToString(const VlanMembersPerTypeRequestHandle::VlanType type) {
    switch (type) {
    case VlanMembersPerTypeRequestHandle::VlanType::NATIVE: {
        return VLAN_NATIVE_STR;
    }
    case VlanMembersPerTypeRequestHandle::VlanType::TAGGED: {
        return VLAN_TAGGED_STR;
    }
    case VlanMembersPerTypeRequestHandle::VlanType::UNTAGGED: {
        return VLAN_UNTAGGED_STR;
    }
    }
}
