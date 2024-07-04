#include "interface_observable.hpp"

using namespace InterfaceObservable;

IInterfaceObservable::IInterfaceObservable(SharedPtr<IInterfaceQueryable> iface_queryable, StringView iface_id)
: _iface_queryable { iface_queryable }, _iface_id { iface_id } {

}

const String& IInterfaceObservable::ifaceId() {
    return _iface_id;
}

CreateInterfaceEvent::CreateInterfaceEvent(SharedPtr<IInterfaceQueryable> iface_queryable, StringView iface_id)
: IInterfaceObservable { iface_queryable, iface_id } {
    // Nothing more to do
}

DeleteInterfaceEvent::DeleteInterfaceEvent(SharedPtr<IInterfaceQueryable> iface_queryable, StringView iface_id)
: IInterfaceObservable { iface_queryable, iface_id } {
    // Nothing more to do
}
