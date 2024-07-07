#pragma once

#include <std_types.hpp>
#include <spdlog/spdlog.h>
#include <spdlog/common.h>

namespace Log {

using Logger = spdlog::logger;

class LoggersRegistry {
public:
    LoggersRegistry(spdlog::sinks_init_list sinks_list);
    virtual ~LoggersRegistry() = default;
    void registerModule(const String& module_name);
    SharedPtr<Logger> getLogger(const String& module_name);

private:
    Map<String, SharedPtr<Logger>> _logger_by_module_name;
    spdlog::sinks_init_list _sinks_list;
};

} // namespace Log
