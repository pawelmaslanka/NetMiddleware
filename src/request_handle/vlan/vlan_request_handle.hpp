#pragma once

#include <request_handle/request_handle.hpp>

class VlanRequestHandle : public RequestHandle {
public:
    VlanRequestHandle(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<Node> parent = nullptr);
    virtual ~VlanRequestHandle() = default;

    virtual bool handle(IRequestHandle::Request& req, IRequestHandle::Response& res) override;
};
