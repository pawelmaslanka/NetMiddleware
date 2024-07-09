#pragma once

#include "interface.hpp"

#include <lib/std_types.hpp>

namespace Lib::Net {

struct IInterfaceQueryable {
    virtual ~IInterfaceQueryable() = default;
    virtual const WeakPtr<Interface> getInterface(const ID& iface_id) const = 0;
};

struct NullInterfaceQueryable : public IInterfaceQueryable {
    virtual ~NullInterfaceQueryable() = default;
    virtual const WeakPtr<Interface> getInterface(const ID& iface_id) const override {
        static SharedPtr<Interface> interface = MakeShared<Interface>();
        return interface;
    }
};

} // namespace Lib::Net
