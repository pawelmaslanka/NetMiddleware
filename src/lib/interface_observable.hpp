#pragma once

#include "lib/interface_queryable.hpp"
#include "lib/observer.hpp"
#include "lib/std_types.hpp"

namespace InterfaceObservable {

class IInterfaceObservable : public Observer::Event {
public:
    IInterfaceObservable(SharedPtr<IInterfaceQueryable> iface_queryable, StringView iface_id);
    virtual ~IInterfaceObservable() = default;
    const String& ifaceId();

private:
    SharedPtr<IInterfaceQueryable> _iface_queryable;
    String _iface_id;
};

class CreateInterfaceEvent final : public IInterfaceObservable {
public:
    virtual ~CreateInterfaceEvent() = default;
    CreateInterfaceEvent(SharedPtr<IInterfaceQueryable> iface_queryable, StringView iface_id);
};

class DeleteInterfaceEvent final : public IInterfaceObservable {
public:
    virtual ~DeleteInterfaceEvent() = default;
    DeleteInterfaceEvent(SharedPtr<IInterfaceQueryable> iface_queryable, StringView iface_id);
};

} // namespace InterfaceObservable
