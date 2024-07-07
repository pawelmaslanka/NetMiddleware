/*
 * Copyright (C) 2024 Pawel Maslanka (pawmas@hotmail.com)
 * This program is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation, version 3.
 */
#pragma once

#include "lib/log.hpp"
#include <std_types.hpp>

namespace Log {
// Logger instance.
// It delivers sink of client's log and should not be used directly by client.
class ILogger {
public:
    virtual ~ILogger() = default;
    virtual void log(const Log::Level level, const String& msg);
};

class ManagerBuilder;

// Logger service proxy.
// It manages of the actual logger instance and the module's log severity level.
class Manager final : public IService {
public:
    virtual ~Manager() = default;
    virtual void log(StringView module_name, const Level level, StringView msg) override;
    void setLogger(SharedPtr<ILogger> logger);
    bool setSeverityLevel(StringView module_name, Level level);

private:
    friend ManagerBuilder;
    Manager();
    Mutex _mtx;
    SharedPtr<ILogger> _logger;
    Map<String, Level> _log_level_by_module_name;
};

class ManagerBuilder final {
public:
    SharedPtr<ManagerBuilder>& instance();
    static SharedPtr<Manager>& get();

private:
    ManagerBuilder() = default;
    static Mutex _mtx;
};

} // namespace Log
