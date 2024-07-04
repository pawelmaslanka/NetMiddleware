#pragma once

#include "module_registry.hpp"

#include "lib/interface_queryable.hpp"
#include "lib/std_types.hpp"

#include <grpcpp/grpcpp.h>
#include "interface.grpc.pb.h"

class InterfaceManager : public IInterfaceQueryable, public Observer::IPublisher, public std::enable_shared_from_this<InterfaceManager> {
public:
    InterfaceManager(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<grpc::Channel> rpc_net_channel);
    virtual ~InterfaceManager() = default;
    bool createInterface(const String& iface_id);
    bool deleteInterface(const String& iface_id);
    bool setAdminState(const String& iface_id, Interface::AdminState state);
    bool setSpeed(const String& iface_id, Interface::LinkSpeed speed);
    virtual const SharedPtr<Interface> getInterface(const String& interface_id) const override;

private:
    String _module_name;
    SharedPtr<ModuleRegistry> _module_registry;
    Map<String, SharedPtr<Interface>> _iface_by_id;
    UniquePtr<DataPlane::Interface::InterfaceManagement::Stub> _iface_service;
    SharedPtr<Log::Logger> _log;
};
