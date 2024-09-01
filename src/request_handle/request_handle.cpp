#include "request_handle.hpp"
#include "module_names.hpp"

#include <xpath/xpath.hpp>

using Json = nlohmann::json;

void from_json(const Json& json_req, RequestMetadata::Request& req) {
    json_req.at(RequestMetadata::OPERATION_FIELD_NAME).get_to(req.Op);
    json_req.at(RequestMetadata::XPATH_FIELD_NAME).get_to(req.Path);
    json_req.at(RequestMetadata::VALUE_FIELD_NAME).get_to(req.Value);
    for (auto& param : json_req.at(RequestMetadata::PARAMETERS_FIELD_NAME)) {
        req.Params[param] = json_req[RequestMetadata::PARAMETERS_FIELD_NAME][param];
    }
}

static RequestMetadata::Request convertRequestJsonToObjectF(const Json& json_req) {
    RequestMetadata::Request req;
    json_req.at(RequestMetadata::OPERATION_FIELD_NAME).get_to(req.Op);
    json_req.at(RequestMetadata::XPATH_FIELD_NAME).get_to(req.Path);
    json_req.at(RequestMetadata::VALUE_FIELD_NAME).get_to(req.Value);
    if (json_req.find(RequestMetadata::PARAMETERS_FIELD_NAME) != json_req.end()) {
        for (auto it = json_req.at(RequestMetadata::PARAMETERS_FIELD_NAME).begin(); it != json_req.at(RequestMetadata::PARAMETERS_FIELD_NAME).end(); it++) {
            req.Params[it.key()] = it.value();
        }
    }

    return req;
}

void to_json(Json& json_res, const ResponseMetadata::Response& res) {
    json_res = Json {
        { ResponseMetadata::SUCCESS_FIELD_NAME, res.Success },
        { ResponseMetadata::MESSAGE_FIELD_NAME, res.Data }
    };
}

IRequestHandle::IRequestHandle(const String name, SharedPtr<Node> parent)
  : XPathNode::Composite(name, parent) {

}

IRequestHandle::Request::Request(const Json& data)
  : Data(convertRequestJsonToObjectF(data) /* data[0].get<RequestMetadata::Request>() */), XPathNodes {} {
    if (data.find(RequestMetadata::XPATH_FIELD_NAME) != data.end()) {
        auto xpath = data.at(RequestMetadata::XPATH_FIELD_NAME);
        XPathNodes = XPath::parse(xpath);
        XPathNodes.push_front(XPath::ROOT_NODE_START);
    }
}

IRequestHandle::Response::Response()
  : Data {}, Success { false } {

}

bool IRequestHandle::checkIfRootXPathNodeIsMe(Request& req) {
    if (req.XPathNodes.size() == 0) {
        return false;
    }

    if (req.XPathNodes.front() != name()) {
        return false;
    }

    req.XPathNodes.pop_front();
    return true;
}

RequestHandle::RequestHandle(StringView module_name, SharedPtr<ModuleRegistry> module_registry, const String node_name, SharedPtr<Node> parent)
  : Node(node_name, parent), IRequestHandle(node_name, parent), _module_registry { module_registry },
    _log { module_registry->loggerRegistry()->getLogger(String(module_name)) },
    _module_name { module_name } {}

bool RequestHandle::handle(Request& req, Response& res) {
    if (!checkIfRootXPathNodeIsMe(req)) {
        res.Data.Success = false;
        res.Data.Data = "Invalid xpath '" + req.Data.Path + "' during processing current node '" + name() + "'";
        return false;
    }

    if (req.XPathNodes.size() == 0) {
        // Finished processing request
        res.Data.Success = true;
        return true;
    }

    auto node = findNode(req.XPathNodes.front());
    if (!node) {
        res.Data.Success = false;
        res.Data.Data = "Not found node '" + req.XPathNodes.front() + "' at xpath '" + req.Data.Path + "'";
        return false;
    }

    return std::dynamic_pointer_cast<IRequestHandle>(node)->handle(req, res);
}
