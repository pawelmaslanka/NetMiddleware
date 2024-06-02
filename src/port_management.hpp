#pragma once

// #include "lib/observer.hpp"
#include "module_registry.hpp"

#include "lib/port_queryable.hpp"
#include "lib/std_types.hpp"

#include <grpcpp/grpcpp.h>
#include "port.grpc.pb.h"

class PortManager : public IPortQueryable, public Observer::IPublisher, public std::enable_shared_from_this<PortManager> {
public:
    PortManager(SharedPtr<ModuleRegistry> module_registry, SharedPtr<grpc::Channel> rpc_net_channel);
    virtual ~PortManager() = default;
    // NOTE: Port cannot be removable
    virtual const SharedPtr<Port> getPort(const String& port_id) const override;
    // virtual const SharedPtr<IEvent> context() override { return _context_event; }
    bool createPort(const String& port_id);
    bool deletePort(const String& port_id);
    bool setPortBreakout(const String& port_id, const Port::BreakoutMode mode);

private:
    SharedPtr<ModuleRegistry> _module_registry;
    Map<String, SharedPtr<Port>> _port_by_id;
    UniquePtr<DataPlane::PortManagement::Stub> _port_service;
};
