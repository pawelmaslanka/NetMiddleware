#pragma once

#include <lib/common.hpp>
#include <lib/std_types.hpp>

namespace Lib::Net {

struct Lag {
    static constexpr auto LAG_IFNAME_PREFIX = "lag";
    enum class LagType {
        STATIC  = 0,
        DYNAMIC = 1
    };

    Set<ID> Members;
    LagType Type = LagType::STATIC;
};

} // namespace Lib::Net
