#pragma once

#include <request_handle/request_handle.hpp>

class RstpRequestHandle : public RequestHandle {
public:
    RstpRequestHandle(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<Node> parent = nullptr);
    virtual ~RstpRequestHandle() = default;

    virtual bool handle(IRequestHandle::Request& req, IRequestHandle::Response& res) override;
};
