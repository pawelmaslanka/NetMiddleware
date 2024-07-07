#include "port_observable.hpp"

using namespace PortObservable;

IPortObservable::IPortObservable(SharedPtr<Net::IPortQueryable> portQueryable, StringView port_id)
: _portQueryable { portQueryable }, _port_id { port_id } {

}

const String& IPortObservable::portId() {
    return _port_id;
}

CreatePortEvent::CreatePortEvent(SharedPtr<Net::IPortQueryable> portQueryable, StringView port_id)
: IPortObservable { portQueryable, port_id } {
    // Nothing more to do
}

DeletePortEvent::DeletePortEvent(SharedPtr<Net::IPortQueryable> portQueryable, StringView port_id)
: IPortObservable { portQueryable, port_id } {
    // Nothing more to do
}
