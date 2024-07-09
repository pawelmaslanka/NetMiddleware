#pragma once


#include "lib/observer.hpp"

#include <net/port/port_queryable.hpp>
#include <lib/std_types.hpp>

namespace PortObservable {

namespace Net = Lib::Net;

class IPortObservable : public Observer::Event {
public:
    IPortObservable(SharedPtr<Net::IPortQueryable> portQueryable, StringView port_id);
    virtual ~IPortObservable() = default;
    const String& portId();

private:
    SharedPtr<Net::IPortQueryable> _portQueryable;
    String _port_id;
};

class CreatePortEvent final : public IPortObservable {
public:
    virtual ~CreatePortEvent() = default;
    CreatePortEvent(SharedPtr<Net::IPortQueryable> portQueryable, StringView port_id);
};

class DeletePortEvent final : public IPortObservable {
public:
    virtual ~DeletePortEvent() = default;
    DeletePortEvent(SharedPtr<Net::IPortQueryable> portQueryable, StringView port_id);
};

} // namespace PortObservable
