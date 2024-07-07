#pragma once

#include <lib/common.hpp>
#include <port.pb.h>

#include <limits>

namespace Lib::Net {

struct Port {
    using BreakoutMode = DataPlane::BreakoutMode;
    typedef uint32_t IdxT;
    typedef uint8_t UnitT;
    typedef uint8_t PortT;
    typedef uint8_t SubportT;
    static constexpr auto INVALID_IDX = std::numeric_limits<IdxT>::max();
    static constexpr SubportT MAX_SUBPORTS = 4;

    BreakoutMode Breakout = BreakoutMode::BREAKOUT_NONE;

    IdxT idx(const ID& port_id) {
        UnitT unit = 0;
        PortT port = 0;
        SubportT subport = 0;
        const auto rv = parsePortId(port_id, unit, port, subport);
        const auto base_idx = ((port - 1) * MAX_SUBPORTS) + (port - 1);
        if (rv == 2) {
            return base_idx;
        }
        else if (rv == 3) {
            return base_idx + subport;
        }

        return INVALID_IDX;
    }

    static int parsePortId(const ID& id, UnitT& unit, PortT& port, Port::SubportT& subport) {
        const auto rv = ::sscanf(id.c_str(), "eth%hhu-%hhu_%hhu", &unit, &port, &subport);
        if ((rv == 2) || (rv == 3)) {
            return rv;
        }

        return -1;
    }
};

} // namespace Lib::Net
