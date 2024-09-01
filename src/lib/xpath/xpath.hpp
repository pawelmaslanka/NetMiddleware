#pragma once

#include <lib/std_types.hpp>

namespace XPath {
    static auto constexpr ROOT_NODE_START = "/";
    // Separates tokens inside a xpath string
    static auto constexpr SEPARATOR = "/";

    // Parse xpath string into separated xpath tokens
    Deque<String> parse(const String& xpath);

    // Combine xpath tokens into xpath string
    String combine(const Deque<String>& xpath_tokens);
}
