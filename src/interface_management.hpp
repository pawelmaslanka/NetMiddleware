#pragma once

#include "lib/observer.hpp"
#include "module_registry.hpp"

#include <grpcpp/grpcpp.h>
#include <interface.grpc.pb.h>
#include <net/interface/interface_queryable.hpp>
#include <lib/std_types.hpp>

namespace Net = Lib::Net; 

class InterfaceManager : public Net::IInterfaceQueryable, public Observer::IPublisher, public std::enable_shared_from_this<InterfaceManager> {
public:
    InterfaceManager(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<grpc::Channel> rpc_net_channel);
    virtual ~InterfaceManager() = default;
    bool createInterface(const Net::ID& iface_id, const String& mac_address);
    bool deleteInterface(const Net::ID& iface_id);
    bool setAdminState(const Net::ID& iface_id, Net::Interface::AdminState state);
    bool setSpeed(const Net::ID& iface_id, Net::Interface::LinkSpeed speed);
    virtual const WeakPtr<Net::Interface> getInterface(const Net::ID& interface_id) const override;

private:
    String _module_name;
    SharedPtr<ModuleRegistry> _module_registry;
    Map<Net::ID, SharedPtr<Net::Interface>> _iface_by_id;
    UniquePtr<DataPlane::Interface::InterfaceManagement::Stub> _iface_service;
    SharedPtr<Log::Logger> _log;
};
