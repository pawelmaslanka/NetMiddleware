#pragma once

#include "lib/lag.hpp"
#include "lib/observer.hpp"
#include "lib/std_types.hpp"

struct ILagQueryable {
    virtual ~ILagQueryable() = default;
    virtual const SharedPtr<Lag> getLag(const String& lag_id) const = 0;
};

struct NullLagQueryable : public ILagQueryable {
    virtual ~NullLagQueryable() = default;
    virtual const SharedPtr<Lag> getLag(const String& lag_id) const override { static SharedPtr<Lag> lag = MakeShared<Lag>(); return lag; }
};
