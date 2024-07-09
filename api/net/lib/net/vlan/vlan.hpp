#pragma once

#include <net/common.hpp>
#include <lib/std_types.hpp>

namespace Lib::Net {

struct Vlan {
    typedef uint16_t VID;
    static constexpr VID DEFAULT_VLAN = 1;

    Set<ID> TaggedMembers;
    Set<ID> UntaggedMembers;
    Set<ID> NativeMembers;
};

} // namespace Lib::Net
