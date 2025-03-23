/*
 * Copyright (C) 2024 Pawel Maslanka (pawmas@hotmail.com)
 * This program is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation, version 3.
 */
#include "log_management.hpp"

using namespace Log;

class NullLogger final : public ILogger {
public:
    static SharedPtr<NullLogger>& instance() {
        static SharedPtr<NullLogger> logger;
        static Mutex mtx;
        if (!logger) {
            LockGuard lock_mtx { mtx };
            if (!logger) {
                logger = MakeSharedPtr<NullLogger>();
            }
        }

        return logger;
    }

    virtual ~NullLogger() = default;
    virtual void log(const Log::Level, const String&) override { }

private:
    NullLogger() = default;
};

Manager::Manager()
  : _logger { NullLogger::instance() } {
}

void Manager::log(StringView module_name, const Level level, StringView msg) {
    String module(module_name);
    LockGuard mtx_lock { _mtx };
    const auto log_level_it = _log_level_by_module_name.find(module);
    if (log_level_it == _log_level_by_module_name.end()) {
        return;
    }

    _logger->log(level, String(msg));
}

void Manager::setLogger(SharedPtr<ILogger> logger) {
    if (!logger) {
        logger = std::dynamic_pointer_cast<ILogger>(NullLogger::instance());
    }

    LockGuard mtx_lock { _mtx };
    _logger = logger;
}

Mutex ManagerBuilder::_mtx;

SharedPtr<ManagerBuilder>& ManagerBuilder::instance() {
    static SharedPtr<ManagerBuilder> builder;
    if (!builder) {
        LockGuard mtx_lock { _mtx };
        if (!builder) {
            builder = MakeSharedPtr<ManagerBuilder>();
        }
    }

    return builder;
}

SharedPtr<Manager>& ManagerBuilder::get() {
    static SharedPtr<Manager> manager;
    LockGuard mtx_lock { _mtx };
    if (!manager) {
        manager = MakeSharedPtr<Manager>();
    }
    
    return manager;
}
