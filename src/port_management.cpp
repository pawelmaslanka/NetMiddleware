#include "port_management.hpp"

#include "lib/port_observable.hpp"
#include <spdlog/spdlog.h>

PortManager::PortManager(SharedPtr<ModuleRegistry> module_registry, SharedPtr<grpc::Channel> rpc_net_channel)
: _module_registry { module_registry }, _port_service { DataPlane::PortManagement::NewStub(rpc_net_channel) } {

}

const SharedPtr<Port> PortManager::getPort(const String& port_id) const {
    auto port_it = _port_by_id.find(port_id);
    if (port_it != _port_by_id.end()) {
        return nullptr;
    }

    return port_it->second;
}

bool PortManager::createPort(const String& port_id) {
    if (_port_by_id.find(port_id) != _port_by_id.end()) {
        spdlog::error("Port '{}' already exists", port_id);
        return false;
    }

    _port_by_id[port_id] = MakeShared<Port>();
    spdlog::info("Successfully created the port '{}'", port_id);
    notifySubscribers(MakeShared<PortObservable::CreatePortEvent>(shared_from_this(), port_id));
    return true;
}

bool PortManager::deletePort(const String& port_id) {
    if (_port_by_id.find(port_id) == _port_by_id.end()) {
        spdlog::error("Port '{}' not exists", port_id);
        return false;
    }

    _port_by_id.erase(port_id);
    spdlog::info("Successfully deleted the port '{}'", port_id);
    notifySubscribers(MakeShared<PortObservable::DeletePortEvent>(shared_from_this(), port_id));
    return true;
}

bool PortManager::setPortBreakout(const String& port_id, const Port::BreakoutMode mode) {
    auto port_it = _port_by_id.find(port_id);
    if (port_it == _port_by_id.end()) {
        spdlog::error("Port '{}' not exists", port_id);
        return false;
    }

    grpc::ClientContext context;
    DataPlane::Result result;
    DataPlane::PortBreakoutMode port_breakoutmode;
    port_breakoutmode.mutable_port()->set_id(port_id);
    port_breakoutmode.set_mode(mode);
    auto status = _port_service->SetPortBreakout(&context, port_breakoutmode, &result);
    if (!status.ok()) {
        spdlog::error("Failed to send request to set breakout mode on the port '{}': {} ({})",
            port_id, status.error_message(), status.error_code());
        return false;
    }

    port_it->second->Breakout = mode;
    spdlog::info("Successfully set breakout mode '{}' on the port '{}'", mode, port_id);
    return true;
}
