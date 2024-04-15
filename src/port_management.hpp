#pragma once

// #include "lib/observer.hpp"
#include "module_registry.hpp"

#include "lib/port_queryable.hpp"
#include "lib/std_types.hpp"

class PortManager : public IPortQueryable /* , public IPublisher */ {
public:
    PortManager(SharedPtr<ModuleRegistry> module_registry);
    virtual ~PortManager() = default;
    // NOTE: Port cannot be removable
    virtual const SharedPtr<Port> getPort(const String& port_id) const override;
    // virtual const SharedPtr<IEvent> context() override { return _context_event; }

private:
    // class ContextEvent : public IEvent {
    // public:
    //     virtual ~ContextEvent() = default;
    //     ContextEvent() : _port { MakeShared<Port>() } { }
    //     const SharedPtr<Port> port() { return _port; }

    // private:
    //     const SharedPtr<Port> _port;

    //     friend class PortManager;
    //     void setPort(SharedPtr<Port> port) { _port = port; }
    // };

    // SharedPtr<ContextEvent> _context_event;

    SharedPtr<ModuleRegistry> _module_registry;
    Map<String, SharedPtr<Port>> _ports; // Port by id
};
