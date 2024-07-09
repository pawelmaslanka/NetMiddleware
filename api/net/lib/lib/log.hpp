#pragma once

#include <lib/std_types.hpp>
#include <spdlog/spdlog.h>
#include <spdlog/common.h>

namespace Log {

using Logger = spdlog::logger;

class ILoggerRegistryManagement {
public:
    virtual ~ILoggerRegistryManagement() = default;
    virtual void registerModule(const String& module_name) = 0;
    virtual SharedPtr<Logger> getLogger(const String& module_name) = 0;
};

class NullLoggerRegistryManagement : public ILoggerRegistryManagement {
public:
    virtual ~NullLoggerRegistryManagement() = default;
    virtual void registerModule([[maybe_unused ]] const String&) override {};
    virtual SharedPtr<Logger> getLogger([[maybe_unused ]] const String&) override {
        static SharedPtr<Logger> logger = MakeShared<Logger>("");
        return logger;
     };
};

class LoggerRegistry : public ILoggerRegistryManagement {
public:
    virtual ~LoggerRegistry() = default;
    LoggerRegistry(spdlog::sinks_init_list sinks_list) : _sinks_list (std::move(sinks_list)) {}
    virtual void registerModule(const String& module_name) override { _logger_by_module_name[module_name] = MakeShared<Logger>(module_name, _sinks_list); }
    virtual SharedPtr<Logger> getLogger(const String& module_name) override {
        auto logger_it = _logger_by_module_name.find(module_name);
        if (logger_it == _logger_by_module_name.end()) {
            // If currently the logger has not been registered yet then create new one and turn off logging possibility
            _logger_by_module_name[module_name] = MakeShared<Logger>(module_name);
            logger_it = _logger_by_module_name.find(module_name);
            logger_it->second->set_level(spdlog::level::off);
        }

        return logger_it->second;
    }

private:
    Map<String, SharedPtr<Logger>> _logger_by_module_name;
    spdlog::sinks_init_list _sinks_list;
};

} // namespace Log
