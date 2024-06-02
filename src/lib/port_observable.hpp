#pragma once

#include "lib/port_queryable.hpp"
#include "lib/observer.hpp"
#include "lib/std_types.hpp"

namespace PortObservable {

class IPortObservable : public Observer::Event {
public:
    IPortObservable(SharedPtr<IPortQueryable> portQueryable, StringView port_id);
    virtual ~IPortObservable() = default;
    const String& portId();

private:
    SharedPtr<IPortQueryable> _portQueryable;
    String _port_id;
};

class CreatePortEvent final : public IPortObservable {
public:
    virtual ~CreatePortEvent() = default;
    CreatePortEvent(SharedPtr<IPortQueryable> portQueryable, StringView port_id);
};

class DeletePortEvent final : public IPortObservable {
public:
    virtual ~DeletePortEvent() = default;
    DeletePortEvent(SharedPtr<IPortQueryable> portQueryable, StringView port_id);
};

} // namespace PortObservable
