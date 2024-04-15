#pragma once

#include "lib/port.hpp"
#include "lib/std_types.hpp"

struct IPortQueryable {
    virtual ~IPortQueryable() = default;
    virtual const SharedPtr<Port> getPort(const String& port_id) const = 0;
};

struct NullPortQueryable : public IPortQueryable {
    virtual ~NullPortQueryable() = default;
    virtual const SharedPtr<Port> getPort(const String& port_id) const override { static SharedPtr<Port> port = MakeShared<Port>(); return port; }
};
