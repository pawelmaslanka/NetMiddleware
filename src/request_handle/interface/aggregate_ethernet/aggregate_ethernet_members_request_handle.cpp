#include "aggregate_ethernet_members_request_handle.hpp"
#include "interface_management.hpp"
#include "lag_management.hpp"

#include <lib/xpath/xpath.hpp>

static constexpr auto MEMBERS_NODE_NAME { "members" };

AggregateEthernetMembersRequestHandle::AggregateEthernetMembersRequestHandle(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<Node> parent)
  : Node(MEMBERS_NODE_NAME, parent), RequestHandle(module_name, module_registry, MEMBERS_NODE_NAME, parent) {}

bool AggregateEthernetMembersRequestHandle::handle(IRequestHandle::Request& req, IRequestHandle::Response& res) {
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
    Regex iface_id_regex("^(eth[0-9]-(6[5-6])|eth[0-9]-(6[0-6]|5[0-9]|4[0-9]|3[0-9]|2[0-9]|1[0-9]|[1-9])(_[1-4])?)$");
    if (!std::regex_match(iface_id, iface_id_regex)) {
        res.Data.Success = false;
        res.Data.Data = "Not found inerface id as value for xpath '" + req.Data.Path + "', got '" + iface_id + "'";
        return false;
    }

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

    auto lag_mngr = std::dynamic_pointer_cast<LagManager>(_module_registry->lagModule());
    if (!lag_mngr) {
        _log->error("Cannot get lag manager object from modules registry");
        res.Data.Success = false;
        return false;
    }

    auto lag_id = parent()->name();
    if (!lag_mngr->addMember(lag_id, iface_id)) {
        _log->error("Failed to add member '{}' to the lag '{}'", iface_id, lag_id);
        res.Data.Success = false;
        return false;
    }

    return true;
}
