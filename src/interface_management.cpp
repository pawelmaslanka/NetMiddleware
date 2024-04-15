#include "interface_management.hpp"

InterfaceManager::InterfaceManager(SharedPtr<ModuleRegistry> module_registry)
: _module_registry { module_registry } {

}

const SharedPtr<Interface> InterfaceManager::getInterface(const String& interface_id) const {
    auto interface_it = _interfaces.find(interface_id);
    if (interface_it != _interfaces.end()) {
        return nullptr;
    }

    return interface_it->second;
}
