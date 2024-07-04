#include "log.hpp"

using namespace Log;

LoggersRegistry::LoggersRegistry(spdlog::sinks_init_list sinks_list)
  : _sinks_list (std::move(sinks_list)) {
    // Nothing more to do
}

void LoggersRegistry::registerModule(const String &module_name) {
    _logger_by_module_name[module_name] = MakeShared<Logger>(module_name, _sinks_list);
}

SharedPtr<spdlog::logger> LoggersRegistry::getLogger(const String &module_name) {
    auto logger_it = _logger_by_module_name.find(module_name);
    if (logger_it == _logger_by_module_name.end()) {
        // If currently the logger has not been registered yet then create new one and turn off logging possibility
        _logger_by_module_name[module_name] = MakeShared<Logger>(module_name);
        logger_it = _logger_by_module_name.find(module_name);
        logger_it->second->set_level(spdlog::level::off);
    }

    return logger_it->second;
}
