/*
 * Copyright (C) 2024 Pawel Maslanka (pawmas@hotmail.com)
 * This program is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation, version 3.
 */
#pragma once

#include "lib/std_types.hpp"

namespace Log {
// Log severity level
enum Level {
    TRACE   = 0,
    DEBUG   = 1,
    INFO    = 2,
    WARN    = 3,
    ERROR   = 4,
    FATAL   = 5
};

// Log service.
// Client should use it directly to put the message to the log.
class IService {
public:
    virtual ~IService() = default;
    virtual bool log(StringView module_name, const Log::Level level, StringView msg) = 0;
};

} // namespace Log