#include "interface_management.hpp"

#include "lib/interface_observable.hpp"

using namespace InterfaceObservable;

InterfaceManager::InterfaceManager(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<grpc::Channel> rpc_net_channel)
  : _module_name { module_name }, _module_registry { module_registry }, _iface_service { DataPlane::Interface::InterfaceManagement::NewStub(rpc_net_channel) },
    _log { module_registry->loggerRegistry()->getLogger(String(module_name)) } {
    // Nothing more to do
}

bool InterfaceManager::createInterface(const Net::ID& iface_id, const String& mac_address) {
    if (_iface_by_id.find(iface_id) != _iface_by_id.end()) {
        _log->error("Interface '{}' already exists", iface_id);
        return false;
    }

    grpc::ClientContext context;
    DataPlane::Result result;
    DataPlane::Interface::Iface iface;
    iface.set_id(iface_id);
    iface.set_mac_address(mac_address);
    auto status = _iface_service->CreateInterface(&context, iface, &result);
    if (!status.ok()) {
        _log->error("Failed to send request to create the interface instance '{}': {} ({})",
            iface_id, status.error_message(), status.error_code());
        return false;
    }

    _iface_by_id[iface_id] = MakeSharedPtr<Net::Interface>();
    _log->info("Successfully created the interface '{}'", iface_id);
    notifySubscribers(MakeSharedPtr<InterfaceObservable::CreateInterfaceEvent>(shared_from_this(), iface_id));
    return true;
}

bool InterfaceManager::deleteInterface(const Net::ID& iface_id) {
    auto iface_it = _iface_by_id.find(iface_id);
    if (iface_it == _iface_by_id.end()) {
        _log->error("Interface '{}' already exists", iface_id);
        return false;
    }

    grpc::ClientContext context;
    DataPlane::Result result;
    DataPlane::Interface::Iface iface;
    iface.set_id(iface_id);
    auto status = _iface_service->DeleteInterface(&context, iface, &result);
    if (!status.ok()) {
        _log->error("Failed to send request to create the interface instance '{}': {} ({})",
            iface_id, status.error_message(), status.error_code());
        return false;
    }

    _iface_by_id.erase(iface_it);
    _log->info("Successfully removed the interface '{}'", iface_id);
    notifySubscribers(MakeSharedPtr<InterfaceObservable::DeleteInterfaceEvent>(shared_from_this(), iface_id));
    return true;
}

bool InterfaceManager::setAdminState(const Net::ID& iface_id, Net::Interface::AdminState state) {
    auto iface_it = _iface_by_id.find(iface_id);
    if (iface_it == _iface_by_id.end()) {
        _log->error("Interface '{}' does not exists", iface_id);
        return false;
    }

    grpc::ClientContext context;
    DataPlane::Result result;
    DataPlane::Interface::IfaceState iface_state;
    iface_state.mutable_iface()->set_id(iface_id);
    iface_state.set_state(state);
    auto status = _iface_service->SetAdminState(&context, iface_state, &result);
    if (!status.ok()) {
        _log->error("Failed to send request to set admin state {} on the interface '{}': {} ({})",
            state, iface_id, status.error_message(), status.error_code());
        return false;
    }

    _log->info("Successfully to set an admin state {} on the interface '{}'", state, iface_id);
    return true;
}

bool InterfaceManager::setSpeed(const Net::ID& iface_id, Net::Interface::LinkSpeed speed) {
    auto iface_it = _iface_by_id.find(iface_id);
    if (iface_it == _iface_by_id.end()) {
        _log->error("Interface '{}' does not exists", iface_id);
        return false;
    }

    grpc::ClientContext context;
    DataPlane::Result result;
    DataPlane::Interface::IfaceSpeed iface_speed;
    iface_speed.mutable_iface()->set_id(iface_id);
    iface_speed.set_speed(speed);
    auto status = _iface_service->SetSpeed(&context, iface_speed, &result);
    if (!status.ok()) {
        _log->error("Failed to send request to set speed {} on the interface '{}': {} ({})",
            speed, iface_id, status.error_message(), status.error_code());
        return false;
    }

    _log->info("Successfully set a speed {} on the interface '{}'", speed, iface_id);
    return true;
}

const WeakPtr<Net::Interface> InterfaceManager::getInterface(const Net::ID& interface_id) const {
    auto interface_it = _iface_by_id.find(interface_id);
    if (interface_it == _iface_by_id.end()) {
        return {};
    }

    return interface_it->second;
}
