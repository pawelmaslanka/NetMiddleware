#pragma once

#include <request_handle/request_handle.hpp>

class AggregateEthernetMembersRequestHandle : public RequestHandle {
public:
    AggregateEthernetMembersRequestHandle(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<Node> parent = nullptr);
    virtual ~AggregateEthernetMembersRequestHandle() = default;

    virtual bool handle(IRequestHandle::Request& req, IRequestHandle::Response& res) override;
};
