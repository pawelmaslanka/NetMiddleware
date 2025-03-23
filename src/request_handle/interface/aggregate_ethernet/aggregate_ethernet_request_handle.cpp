#include "aggregate_ethernet_request_handle.hpp"
#include "aggregate_ethernet_members_request_handle.hpp"
#include "lag_management.hpp"

#include <lib/xpath/xpath.hpp>

static constexpr auto AGGREGATE_ETHERNET_NODE_NAME { "aggregate-ethernet" };
static String MAC_ADDRESS_PARAM_NAME { "mac-address" };

AggregateEthernetRequestHandle::AggregateEthernetRequestHandle(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<Node> parent)
  : Node(AGGREGATE_ETHERNET_NODE_NAME, parent), RequestHandle(module_name, module_registry, AGGREGATE_ETHERNET_NODE_NAME, parent) {}

bool AggregateEthernetRequestHandle::handle(IRequestHandle::Request& req, IRequestHandle::Response& res) {
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

    auto lag_id = req.Data.Value;
    Regex lag_id_regex("^(lag-(6[5-6])|lag-(6[0-6]|5[0-9]|4[0-9]|3[0-9]|2[0-9]|1[0-9]|[1-9]))$");
    if (!std::regex_match(lag_id, lag_id_regex)) {
        res.Data.Success = false;
        res.Data.Data = "Not found lag id as value for xpath '" + req.Data.Path + "', got '" + lag_id + "'";
        return false;
    }

    auto lag_mngr = std::dynamic_pointer_cast<LagManager>(_module_registry->lagModule());
    if (!lag_mngr) {
        _log->error("Cannot get lag manager object from modules registry");
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
        // FIXME: Get real "host" MAC address binded to the LAG
        mac_address = "66:55:44:33:22:11";
    }

    if (!lag_mngr->createLag(lag_id, mac_address)) {
        _log->error("Failed to create lag '{}'", lag_id);
        res.Data.Success = false;
        return false;
    }

    auto lag_req_hdl = MakeSharedPtr<RequestHandle>(_module_name, _module_registry, lag_id, XPathNode::Node::shared_from_this());
    XPathNode::Composite::add(lag_req_hdl);
    auto lag_members_req_hdl = MakeSharedPtr<AggregateEthernetMembersRequestHandle>(_module_name, _module_registry, lag_req_hdl);
    lag_req_hdl->add(lag_members_req_hdl);
    _log->info("Successfully created new node '{}' for xpath '{}'", lag_req_hdl->name(), req.Data.Path);
    return true;
}
