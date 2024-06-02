#include "port_observable.hpp"

using namespace PortObservable;

IPortObservable::IPortObservable(SharedPtr<IPortQueryable> portQueryable, StringView port_id)
: _portQueryable { portQueryable }, _port_id { port_id } {

}

const String& IPortObservable::portId() {
    return _port_id;
}

CreatePortEvent::CreatePortEvent(SharedPtr<IPortQueryable> portQueryable, StringView port_id)
: IPortObservable { portQueryable, port_id } {
    // Nothing more to do
}

DeletePortEvent::DeletePortEvent(SharedPtr<IPortQueryable> portQueryable, StringView port_id)
: IPortObservable { portQueryable, port_id } {
    // Nothing more to do
}
