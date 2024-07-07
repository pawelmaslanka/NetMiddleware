#pragma once

#include <interface.pb.h>
#include <net/common.hpp>

namespace Lib::Net {

struct Interface {
    using AdminState = DataPlane::Interface::AdminState;
    using LinkSpeed = DataPlane::Interface::LinkSpeed;
    // Operational link status
    enum class LinkStatus {
        DOWN = 0,
        UP   = 1
    };

    AdminState State = AdminState::DISABLED;
    LinkSpeed Speed = LinkSpeed::SPEED_MAX;
    LinkStatus Status = LinkStatus::DOWN;
};

} // namespace Lib::Net
