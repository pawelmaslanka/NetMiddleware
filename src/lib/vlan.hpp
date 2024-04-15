#pragma once

#include "lib/std_types.hpp"

struct Vlan {
    static constexpr UInt16 DEFAULT_VLAN = 1;
    Set<String> TaggedMembers;
    Set<String> UntaggedMembers;
    Set<String> NativeMembers;
};