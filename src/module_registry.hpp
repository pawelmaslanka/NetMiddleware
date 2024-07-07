#pragma once

#include "lib/log.hpp"

#include <net/module_registry.hpp>
#include <std_types.hpp>

namespace Net = Lib::Net;

class ModuleRegistry : public Net::ModuleRegistry {
public:
    ModuleRegistry()
      : _log_module { MakeShared<Log::LoggersRegistry>(spdlog::sinks_init_list()) } {
        // Nothing more to do
    }

    inline const SharedPtr<Log::LoggersRegistry> logModule() const { return _log_module; }
    inline void setLogModule(SharedPtr<Log::LoggersRegistry> log_module) { _log_module = log_module; }

private:
    SharedPtr<Log::LoggersRegistry> _log_module;
};
