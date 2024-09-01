#pragma once

#include <request_handle/request_handle.hpp>

class VlanMembersPerTypeRequestHandle : public RequestHandle {
public:
    enum class VlanType {
        NATIVE = 0,
        TAGGED = 1,
        UNTAGGED = 2
    };

    VlanMembersPerTypeRequestHandle(StringView module_name, SharedPtr<ModuleRegistry> module_registry, const VlanType type, SharedPtr<Node> parent = nullptr);
    virtual ~VlanMembersPerTypeRequestHandle() = default;

    virtual bool handle(IRequestHandle::Request& req, IRequestHandle::Response& res) override;

private:
    String convertVlanTypeToString(const VlanType type);
};
