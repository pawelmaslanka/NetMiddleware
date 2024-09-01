#include "interface_speed_request_handle.hpp"
#include "interface_management.hpp"

#include <lib/xpath/xpath.hpp>

static constexpr auto SPEED_NODE_NAME { "speed" };

InterfaceSpeedRequestHandle::InterfaceSpeedRequestHandle(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<Node> parent)
  : Node(SPEED_NODE_NAME, parent), RequestHandle(module_name, module_registry, SPEED_NODE_NAME, parent) {}

bool InterfaceSpeedRequestHandle::handle(IRequestHandle::Request& req, IRequestHandle::Response& res) {
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

    auto iface_mngr = std::dynamic_pointer_cast<InterfaceManager>(_module_registry->interfaceModule());
    if (!iface_mngr) {
        _log->error("Cannot get port manager object from modules registry");
        res.Data.Success = false;
        return false;
    }

    // FIXME: Handle request
    auto speed_str = req.Data.Value;
    if (speed_str == "fixed") {
        res.Data.Success = true;
        return true;
    }

    Net::Interface::LinkSpeed speed;
    if (speed_str == "100G") {
        speed = Net::Interface::LinkSpeed::SPEED_100G;
    }
    else if (speed_str == "400G") {
        speed = Net::Interface::LinkSpeed::SPEED_400G;
    }
    else {
        res.Data.Success = false;
        res.Data.Data = "Unsupported speed value '" + speed_str + "'";
        return false;
    }

    auto iface_id = parent()->name();
    if (!iface_mngr->setSpeed(iface_id, speed)) {
        _log->error("Failed to speed to '{}' on the interface '{}' ", speed_str, iface_id);
        res.Data.Success = false;
        return false;
    }

    _log->info("Successfully set speed to '{}' on the interface '{}'", speed_str, iface_id);
    return true;
}
