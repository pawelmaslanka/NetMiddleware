#include "ethernet_request_handle.hpp"
#include "interface_speed_request_handle.hpp"
#include "interface_management.hpp"

#include <lib/xpath/xpath.hpp>

static constexpr auto ETHERNET_NODE_NAME { "ethernet" };
static String MAC_ADDRESS_PARAM_NAME { "mac-address" };

EthernetRequestHandle::EthernetRequestHandle(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<Node> parent)
  : Node(ETHERNET_NODE_NAME, parent), RequestHandle(module_name, module_registry, ETHERNET_NODE_NAME, parent) {}

bool EthernetRequestHandle::handle(IRequestHandle::Request& req, IRequestHandle::Response& res) {
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

    auto iface_id = req.Data.Value;
    Regex iface_id_regex("^(eth[0-9]-(6[5-6])|eth[0-9]-(6[0-6]|5[0-9]|4[0-9]|3[0-9]|2[0-9]|1[0-9]|[1-9])(_[1-4])?)$");
    if (!std::regex_match(iface_id, iface_id_regex)) {
        res.Data.Success = false;
        res.Data.Data = "Not found interface id as value for xpath '" + req.Data.Path + "', got '" + iface_id + "'";
        return false;
    }

    auto iface_mngr = std::dynamic_pointer_cast<InterfaceManager>(_module_registry->interfaceModule());
    if (!iface_mngr) {
        _log->error("Cannot get interface manager object from modules registry");
        res.Data.Success = false;
        return false;
    }

    auto mac_address_it = req.Data.Params.find(MAC_ADDRESS_PARAM_NAME);
    if (mac_address_it == req.Data.Params.end()) {
        res.Data.Success = false;
        res.Data.Data = "Missing mandatory request parameter '" + MAC_ADDRESS_PARAM_NAME + "'";
        return false;
    }

    auto mac_address = mac_address_it->second;
    if (mac_address == "auto") {
        // FIXME: Get real "host" MAC address binded to the interface
        mac_address = "11:22:33:44:55:66";
    }

    if (!iface_mngr->createInterface(iface_id, mac_address)) {
        _log->error("Failed to create interface '{}'", iface_id);
        res.Data.Success = false;
        return false;
    }

    auto iface_req_hdl = MakeSharedPtr<RequestHandle>(_module_name, _module_registry, iface_id, XPathNode::Node::shared_from_this());
    XPathNode::Composite::add(iface_req_hdl);
    auto iface_speed_req_hdl = MakeSharedPtr<InterfaceSpeedRequestHandle>(_module_name, _module_registry, iface_req_hdl);
    iface_req_hdl->add(iface_speed_req_hdl);
    _log->info("Successfully created new node '{}' for xpath '{}'", iface_req_hdl->name(), req.Data.Path);
    return true;
}
