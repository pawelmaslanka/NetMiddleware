#pragma once

#include <request_handle/request_handle.hpp>

class InterfaceSpeedRequestHandle : public RequestHandle {
public:
    InterfaceSpeedRequestHandle(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<Node> parent = nullptr);
    virtual ~InterfaceSpeedRequestHandle() = default;

    virtual bool handle(IRequestHandle::Request& req, IRequestHandle::Response& res) override;
};
