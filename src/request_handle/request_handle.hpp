#pragma once

#include <nlohmann/json.hpp> // Must be at top due to conflicting with Array from std_types.hpp
#include "module_registry.hpp"

#include <lib/std_types.hpp>
#include <lib/xpath/composite.hpp>

using Json = nlohmann::json;

namespace RequestMetadata {
    struct Request {
        String Op;
        String Path;
        String Value;
        Map<String, String> Params;
    };

    static constexpr auto OPERATION_FIELD_NAME { "op" };
    static constexpr auto XPATH_FIELD_NAME { "path" };
    static constexpr auto VALUE_FIELD_NAME { "value" };
    static constexpr auto PARAMETERS_FIELD_NAME { "params" };
}

namespace ResponseMetadata {
    struct Response {
        String Data;
        bool Success;
    };

    static constexpr auto MESSAGE_FIELD_NAME { "msg" };
    static constexpr auto SUCCESS_FIELD_NAME { "success" };
}

// The 'RequestHandle' is an interface to implement the Chain Of Responsibility design pattern
class IRequestHandle : public XPathNode::Composite {
public:
    struct Request {
        RequestMetadata::Request Data;
        Deque<String> XPathNodes;
        Request(const Json& data);
    };

    struct Response {
        ResponseMetadata::Response Data;
        bool Success;
        Response();
    };

    IRequestHandle(const String name, SharedPtr<Node> parent = nullptr);
    virtual ~IRequestHandle() = default;

    // TODO: Consider default handle here? Just find next node and move forward there. Keep all subnodes in protected map
    virtual bool handle(Request& req, Response& res) = 0;

protected:
    bool checkIfRootXPathNodeIsMe(Request& req);
};

class RequestHandle : public IRequestHandle {
public:
    RequestHandle(StringView module_name, SharedPtr<ModuleRegistry> module_registry, const String node_name, SharedPtr<Node> parent = nullptr);
    virtual ~RequestHandle() = default;

    virtual bool handle(IRequestHandle::Request& req, IRequestHandle::Response& res) override;

protected:
    SharedPtr<ModuleRegistry> _module_registry;
    SharedPtr<Log::Logger> _log;
    String _module_name;
};
