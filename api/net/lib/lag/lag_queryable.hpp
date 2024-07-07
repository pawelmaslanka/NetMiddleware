#pragma once

#include "lag.hpp"
#include <lib/std_types.hpp>

namespace Lib::Net {

struct ILagQueryable {
    virtual ~ILagQueryable() = default;
    virtual const WeakPtr<Lag> getLag(const ID& lag_id) const = 0;
};

struct NullLagQueryable : public ILagQueryable {
    virtual ~NullLagQueryable() = default;
    virtual const WeakPtr<Lag> getLag(const ID& lag_id) const override {
        static SharedPtr<Lag> lag = MakeShared<Lag>();
        return lag;
    }
};

} // namespace Lib::Net
