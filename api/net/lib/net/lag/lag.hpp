#pragma once

#include <net/common.hpp>
#include <lib/std_types.hpp>

namespace Lib::Net {

struct Lag {
    static constexpr auto LAG_IFNAME_PREFIX = "lag";
    enum class ControlProtocol {
        NONE  = 0,
        LACP = 1
    };

    Set<ID> Members;
    ControlProtocol Type = ControlProtocol::NONE;
};

} // namespace Lib::Net
