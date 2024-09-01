#pragma once

#include <request_handle/request_handle.hpp>

class AggregateEthernetRequestHandle : public RequestHandle {
public:
    AggregateEthernetRequestHandle(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<Node> parent = nullptr);
    virtual ~AggregateEthernetRequestHandle() = default;

    virtual bool handle(IRequestHandle::Request& req, IRequestHandle::Response& res) override;
};
