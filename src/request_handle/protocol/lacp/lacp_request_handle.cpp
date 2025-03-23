#include "lacp_request_handle.hpp"
#include "lacp_members_request_handle.hpp"
#include "lag_management.hpp"

#include <lib/xpath/xpath.hpp>

static constexpr auto LACP_NODE_NAME { "lacp" };

LacpRequestHandle::LacpRequestHandle(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<Node> parent)
  : Node(LACP_NODE_NAME, parent), RequestHandle(module_name, module_registry, LACP_NODE_NAME, parent) {}

bool LacpRequestHandle::handle(IRequestHandle::Request& req, IRequestHandle::Response& res) {
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

    auto lag_module = _module_registry->lagModule();
    if (!lag_module) {
        _log->error("Cannot get lag module from modules registry");
        res.Data.Success = false;
        return false;
    }

    if (!lag_module->getLag(lag_id).lock()) {
        _log->error("LAG interface '{}' does not exist", lag_id);
        res.Data.Data = "LAG interface '" + lag_id + "' does not exist";
        res.Data.Success = false;
        return false;
    }

    auto lag_req_hdl = MakeSharedPtr<RequestHandle>(_module_name, _module_registry, lag_id, XPathNode::Node::shared_from_this());
    XPathNode::Composite::add(lag_req_hdl);
    auto lag_members_req_hdl = MakeSharedPtr<LacpMembersRequestHandle>(_module_name, _module_registry, lag_req_hdl);
    lag_req_hdl->add(lag_members_req_hdl);
    _log->info("Successfully created new node '{}' for xpath '{}'", lag_req_hdl->name(), req.Data.Path);
    return true;
}
