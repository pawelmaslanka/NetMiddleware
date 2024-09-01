#include "port_breakout_request_handle.hpp"
#include "port_management.hpp"

#include <lib/xpath/xpath.hpp>

static constexpr auto BREAKOUT_MODE_NODE_NAME { "breakout-mode" };

PortBreakoutRequestHandle::PortBreakoutRequestHandle(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<Node> parent)
  : Node(BREAKOUT_MODE_NODE_NAME, parent), RequestHandle(module_name, module_registry, BREAKOUT_MODE_NODE_NAME, parent) {}

bool PortBreakoutRequestHandle::handle(IRequestHandle::Request& req, IRequestHandle::Response& res) {
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

    auto port_mngr = std::dynamic_pointer_cast<PortManager>(_module_registry->portModule());
    if (!port_mngr) {
        _log->error("Cannot get port manager object from modules registry");
        res.Data.Success = false;
        return false;
    }

    // FIXME: Handle request
    auto mode_str = req.Data.Value;
    Net::Port::BreakoutMode mode;
    if (mode_str == "none") {
        mode = Net::Port::BreakoutMode::BREAKOUT_NONE;
    }
    else if (mode_str == "4x100G") {
        mode = Net::Port::BreakoutMode::BREAKOUT_4X100G;
    }
    else {
        res.Data.Success = false;
        res.Data.Data = "Unsupported breakout mode value '" + mode_str + "'";
        return false;
    }

    auto port_id = parent()->name();
    if (!port_mngr->setPortBreakout(port_id, mode)) {
        _log->error("Failed to set breakout mode to '{}' on the port '{}' ", mode_str, port_id);
        res.Data.Success = false;
        return false;
    }

    _log->info("Successfully set breakout mode '{}' on the port '{}'", mode_str, port_id);
    return true;
}
