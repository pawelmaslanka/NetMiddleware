#pragma once

#include <request_handle/request_handle.hpp>

class LacpRequestHandle : public RequestHandle {
public:
    LacpRequestHandle(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<Node> parent = nullptr);
    virtual ~LacpRequestHandle() = default;

    virtual bool handle(IRequestHandle::Request& req, IRequestHandle::Response& res) override;
};
