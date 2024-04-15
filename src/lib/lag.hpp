#pragma once

#include "lib/std_types.hpp"

struct Lag {
    static constexpr auto LAG_IFNAME_PREFIX = "lag";
    enum class LagType {
        STATIC  = 0,
        DYNAMIC = 1
    };

    Set<String> Members;
    LagType Type = LagType::STATIC;
};
