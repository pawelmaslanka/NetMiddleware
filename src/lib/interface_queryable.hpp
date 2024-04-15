#pragma once

#include "lib/interface.hpp"
#include "lib/std_types.hpp"

struct IInterfaceQueryable {
    virtual ~IInterfaceQueryable() = default;
    virtual const SharedPtr<Interface> getInterface(const String& interface_id) const = 0;
};

struct NullInterfaceQueryable : public IInterfaceQueryable {
    virtual ~NullInterfaceQueryable() = default;
    virtual const SharedPtr<Interface> getInterface(const String& interface_id) const override { static SharedPtr<Interface> interface = MakeShared<Interface>(); return interface; }
};
