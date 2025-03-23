#pragma once

#include "vlan.hpp"

#include <lib/std_types.hpp>

namespace Lib::Net {

struct IVlanQueryable {
    virtual ~IVlanQueryable() = default;
    virtual const WeakPtr<Vlan> getVlan(const Vlan::VID vid) const = 0;
};

struct NullVlanQueryable : public IVlanQueryable {
    virtual ~NullVlanQueryable() = default;
    virtual const WeakPtr<Vlan> getVlan(const Vlan::VID vid) const override {
        static SharedPtr<Vlan> vlan = MakeSharedPtr<Vlan>();
        return vlan;
    }
};

}
