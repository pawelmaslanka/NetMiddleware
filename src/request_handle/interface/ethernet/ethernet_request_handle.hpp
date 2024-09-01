#pragma once

#include <request_handle/request_handle.hpp>

class EthernetRequestHandle : public RequestHandle {
public:
    EthernetRequestHandle(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<Node> parent = nullptr);
    virtual ~EthernetRequestHandle() = default;

    virtual bool handle(IRequestHandle::Request& req, IRequestHandle::Response& res) override;
};
