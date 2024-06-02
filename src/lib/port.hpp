#pragma once

#include <port.pb.h>

struct Port {
    // enum class BreakoutMode {
    //     BREAKOUT_NONE   = 0,
    //     BREAKOUT_4x100G = 1
    // };
    using BreakoutMode = DataPlane::BreakoutMode;

    BreakoutMode Breakout = BreakoutMode::BREAKOUT_NONE;
};
