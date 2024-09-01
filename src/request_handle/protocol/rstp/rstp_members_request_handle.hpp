#pragma once

#include <request_handle/request_handle.hpp>

class RstpMembersRequestHandle : public RequestHandle {
public:
    RstpMembersRequestHandle(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<Node> parent = nullptr);
    virtual ~RstpMembersRequestHandle() = default;

    virtual bool handle(IRequestHandle::Request& req, IRequestHandle::Response& res) override;
};
