#include "port_management.hpp"

#include "lib/port_observable.hpp"

PortManager::PortManager(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<grpc::Channel> rpc_net_channel)
: _module_name { module_name }, _module_registry { module_registry }, _port_service { DataPlane::PortManagement::NewStub(rpc_net_channel) },
  _log { module_registry->logModule()->getLogger(String(module_name)) } {
    // Nothing more to do
}

const WeakPtr<Net::Port> PortManager::getPort(const Net::ID& port_id) const {
    auto port_it = _port_by_id.find(port_id);
    if (port_it != _port_by_id.end()) {
        return {};
    }

    return port_it->second;
}

bool PortManager::createPort(const Net::ID& port_id) {
    if (_port_by_id.find(port_id) != _port_by_id.end()) {
        _log->error("Port '{}' already exists", port_id);
        return false;
    }

    _port_by_id[port_id] = MakeShared<Net::Port>();
    _log->info("Successfully created the port '{}'", port_id);
    notifySubscribers(MakeShared<PortObservable::CreatePortEvent>(shared_from_this(), port_id));
    return true;
}

bool PortManager::deletePort(const Net::ID& port_id) {
    if (_port_by_id.find(port_id) == _port_by_id.end()) {
        _log->error("Port '{}' not exists", port_id);
        return false;
    }

    _port_by_id.erase(port_id);
    _log->info("Successfully deleted the port '{}'", port_id);
    notifySubscribers(MakeShared<PortObservable::DeletePortEvent>(shared_from_this(), port_id));
    return true;
}

bool PortManager::setPortBreakout(const Net::ID& port_id, const Net::Port::BreakoutMode mode) {
    auto port_it = _port_by_id.find(port_id);
    if (port_it == _port_by_id.end()) {
        _log->error("Port '{}' not exists", port_id);
        return false;
    }

    grpc::ClientContext context;
    DataPlane::Result result;
    DataPlane::PortBreakoutMode port_breakoutmode;
    port_breakoutmode.mutable_port()->set_id(port_id);
    port_breakoutmode.set_mode(mode);
    auto status = _port_service->SetPortBreakout(&context, port_breakoutmode, &result);
    if (!status.ok()) {
        _log->error("Failed to send request to set breakout mode on the port '{}': {} ({})",
            port_id, status.error_message(), status.error_code());
        return false;
    }

    port_it->second->Breakout = mode;
    _log->info("Successfully set breakout mode '{}' on the port '{}'", mode, port_id);
    return true;
}
