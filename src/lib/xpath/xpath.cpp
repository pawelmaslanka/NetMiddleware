#include "xpath.hpp"

Deque<String> XPath::parse(const String& xpath) {
    Deque<String> xpath_tokens;
    // Returns first token
    char* token = std::strtok(const_cast<char*>(xpath.c_str()), XPath::SEPARATOR);
    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != nullptr) {
        xpath_tokens.push_back(token);
        token = std::strtok(nullptr, XPath::SEPARATOR);
    }

    return xpath_tokens;
}

String XPath::combine(const Deque<String>& xpath_tokens) {
    if (xpath_tokens.size() == 0) {
        return SEPARATOR;
    }

    String xpath;
    for (const auto& token : xpath_tokens) {
        xpath += SEPARATOR;
        xpath += token;
    }

    return xpath;
}
