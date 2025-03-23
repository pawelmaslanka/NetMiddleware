#include "port_request_handle.hpp"
#include "port_breakout_request_handle.hpp"
#include "port_management.hpp"

#include <lib/xpath/xpath.hpp>

static constexpr auto PORT_NODE_NAME { "port" };

PortRequestHandle::PortRequestHandle(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<Node> parent)
  : Node(PORT_NODE_NAME, parent), RequestHandle(module_name, module_registry, PORT_NODE_NAME, parent) {}

bool PortRequestHandle::handle(IRequestHandle::Request& req, IRequestHandle::Response& res) {
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

    auto port_id = req.Data.Value;
    Regex port_id_regex("^(eth[0-9]-(6[5-6])|eth[0-9]-(6[0-6]|5[0-9]|4[0-9]|3[0-9]|2[0-9]|1[0-9]|[1-9]))$");
    if (!std::regex_match(port_id, port_id_regex)) {
        res.Data.Success = false;
        res.Data.Data = "Not found port id as value for xpath '" + req.Data.Path + "', got '" + port_id + "'";
        return false;
    }

    auto port_mngr = std::dynamic_pointer_cast<PortManager>(_module_registry->portModule());
    if (!port_mngr) {
        _log->error("Cannot get port manager object from modules registry");
        res.Data.Success = false;
        return false;
    }

    if (!port_mngr->createPort(port_id)) {
        _log->error("Failed to create port '{}'", port_id);
        res.Data.Success = false;
        return false;
    }

    auto port_req_hdl = MakeSharedPtr<RequestHandle>(_module_name, _module_registry, port_id, XPathNode::Node::shared_from_this());
    XPathNode::Composite::add(port_req_hdl);
    auto port_breakout_mode_req_hdl = MakeSharedPtr<PortBreakoutRequestHandle>(_module_name, _module_registry, port_req_hdl);
    port_req_hdl->add(port_breakout_mode_req_hdl);
    _log->info("Successfully created new node '{}' for xpath '{}'", port_req_hdl->name(), req.Data.Path);
    return true;
}
