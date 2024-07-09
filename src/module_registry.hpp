#pragma once

#include <lib/log.hpp>

#include <net/module_registry.hpp>
#include <lib/std_types.hpp>

namespace Net = Lib::Net;

class ModuleRegistry : public Net::ModuleRegistry {
public:
    ModuleRegistry()
      : _logger_registry { MakeShared<Log::NullLoggerRegistryManagement>() } {
        // Nothing more to do
    }

    inline const SharedPtr<Log::ILoggerRegistryManagement> loggerRegistry() const { return _logger_registry; }
    inline void setLoggerRegistry(SharedPtr<Log::ILoggerRegistryManagement> logger_registry) { _logger_registry = logger_registry; }

private:
    SharedPtr<Log::ILoggerRegistryManagement> _logger_registry;
};
