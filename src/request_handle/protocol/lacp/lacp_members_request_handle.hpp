#pragma once

#include <request_handle/request_handle.hpp>

class LacpMembersRequestHandle : public RequestHandle {
public:
    LacpMembersRequestHandle(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<Node> parent = nullptr);
    virtual ~LacpMembersRequestHandle() = default;

    virtual bool handle(IRequestHandle::Request& req, IRequestHandle::Response& res) override;
};
