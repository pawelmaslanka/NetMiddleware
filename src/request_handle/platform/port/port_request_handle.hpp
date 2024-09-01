#pragma once

#include <request_handle/request_handle.hpp>

class PortRequestHandle : public RequestHandle {
public:
    PortRequestHandle(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<Node> parent = nullptr);
    virtual ~PortRequestHandle() = default;

    virtual bool handle(IRequestHandle::Request& req, IRequestHandle::Response& res) override;
};
