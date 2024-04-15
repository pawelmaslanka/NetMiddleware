#pragma once

struct Interface {
    enum class AdminState {
        DISABLED = 0,
        ENABLED  = 1
    };

    // Operational link status
    enum class LinkStatus {
        DOWN = 0,
        UP   = 1
    };

    enum class LinkSpeed {
        SPEED_FIXED = 0, // Fixed by breakout mode
        SPEED_100G  = 100000,
        SPEED_400G  = 400000
    };

    AdminState State = AdminState::DISABLED;
    LinkStatus Status = LinkStatus::DOWN;
    LinkSpeed Speed = LinkSpeed::SPEED_FIXED;
};