#pragma once

#include "lib/observer.hpp"
#include <lib/std_types.hpp>

#include <net/interface/interface_queryable.hpp>

namespace InterfaceObservable {

namespace Net = Lib::Net;

class IInterfaceObservable : public Observer::Event {
public:
    IInterfaceObservable(SharedPtr<Net::IInterfaceQueryable> iface_queryable, StringView iface_id);
    virtual ~IInterfaceObservable() = default;
    const String& ifaceId();

private:
    SharedPtr<Net::IInterfaceQueryable> _iface_queryable;
    String _iface_id;
};

class CreateInterfaceEvent final : public IInterfaceObservable {
public:
    virtual ~CreateInterfaceEvent() = default;
    CreateInterfaceEvent(SharedPtr<Net::IInterfaceQueryable> iface_queryable, StringView iface_id);
};

class DeleteInterfaceEvent final : public IInterfaceObservable {
public:
    virtual ~DeleteInterfaceEvent() = default;
    DeleteInterfaceEvent(SharedPtr<Net::IInterfaceQueryable> iface_queryable, StringView iface_id);
};

} // namespace InterfaceObservable
