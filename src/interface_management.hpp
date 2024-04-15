#pragma once

#include "module_registry.hpp"

#include "lib/interface_queryable.hpp"
#include "lib/std_types.hpp"

class InterfaceManager : public IInterfaceQueryable /* , public IPublisher */ {
public:
    InterfaceManager(SharedPtr<ModuleRegistry> module_registry);
    virtual ~InterfaceManager() = default;
    virtual const SharedPtr<Interface> getInterface(const String& interface_id) const override;

private:
    SharedPtr<ModuleRegistry> _module_registry;
    Map<String, SharedPtr<Interface>> _interfaces; // Interface by id
};
