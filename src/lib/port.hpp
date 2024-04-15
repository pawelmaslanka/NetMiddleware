#pragma once

struct Port {
    enum class BreakoutMode {
        BREAKOUT_NONE   = 0,
        BREAKOUT_4x100G = 1
    };

    BreakoutMode Breakout = BreakoutMode::BREAKOUT_NONE;
};