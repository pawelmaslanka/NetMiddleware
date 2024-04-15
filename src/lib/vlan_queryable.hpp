#pragma once

#include "lib/std_types.hpp"
#include "lib/vlan.hpp"

struct IVlanQueryable {
    virtual ~IVlanQueryable() = default;
    virtual const SharedPtr<Vlan> getVlan(const UInt16 vid) const = 0;
};

struct NullVlanQueryable : public IVlanQueryable {
    virtual ~NullVlanQueryable() = default;
    virtual const SharedPtr<Vlan> getVlan(const UInt16 vid) const override { static SharedPtr<Vlan> vlan = MakeShared<Vlan>(); return vlan; }
};