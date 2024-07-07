#pragma once

#include "lib/observer.hpp"
#include "module_registry.hpp"

#include <grpcpp/grpcpp.h>
#include <net/port/port_queryable.hpp>
#include <std_types.hpp>
#include <port.grpc.pb.h>

class PortManager : public Net::IPortQueryable, public Observer::IPublisher, public std::enable_shared_from_this<PortManager> {
public:
    PortManager(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<grpc::Channel> rpc_net_channel);
    virtual ~PortManager() = default;
    // NOTE: Port cannot be removable
    virtual const WeakPtr<Net::Port> getPort(const Net::ID& port_id) const override;
    // virtual const SharedPtr<IEvent> context() override { return _context_event; }
    bool createPort(const Net::ID& port_id);
    bool deletePort(const Net::ID& port_id);
    bool setPortBreakout(const Net::ID& port_id, const Net::Port::BreakoutMode mode);

private:
    String _module_name;
    SharedPtr<ModuleRegistry> _module_registry;
    Map<Net::ID, SharedPtr<Net::Port>> _port_by_id;
    UniquePtr<DataPlane::PortManagement::Stub> _port_service;
    SharedPtr<Log::Logger> _log;
};
