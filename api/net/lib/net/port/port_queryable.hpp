#pragma once

#include "port.hpp"

#include <lib/std_types.hpp>

namespace Lib::Net {

struct IPortQueryable {
    virtual ~IPortQueryable() = default;
    virtual const WeakPtr<Port> getPort(const ID& port_id) const = 0;
};

struct NullPortQueryable : public IPortQueryable {
    virtual ~NullPortQueryable() = default;
    virtual const WeakPtr<Port> getPort(const ID& port_id) const override {
        static SharedPtr<Port> port = MakeShared<Port>();
        return port;
    }
};

} // namespace Lib::Net
