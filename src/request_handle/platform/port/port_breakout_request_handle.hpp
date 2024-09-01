#pragma once

#include <request_handle/request_handle.hpp>

class PortBreakoutRequestHandle : public RequestHandle {
public:
    PortBreakoutRequestHandle(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<Node> parent = nullptr);
    virtual ~PortBreakoutRequestHandle() = default;

    virtual bool handle(IRequestHandle::Request& req, IRequestHandle::Response& res) override;
};
