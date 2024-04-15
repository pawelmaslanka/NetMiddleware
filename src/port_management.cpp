#include "port_management.hpp"

PortManager::PortManager(SharedPtr<ModuleRegistry> module_registry)
: _module_registry { module_registry } {

}

const SharedPtr<Port> PortManager::getPort(const String& port_id) const {
    auto port_it = _ports.find(port_id);
    if (port_it != _ports.end()) {
        return nullptr;
    }

    return port_it->second;
}
