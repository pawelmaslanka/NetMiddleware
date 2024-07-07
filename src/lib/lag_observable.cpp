#include "lag_observable.hpp"

using namespace LagObservable;

ILagObservable::ILagObservable(SharedPtr<Net::ILagQueryable> lagQueryable, StringView lag_id)
: _lagQueryable { lagQueryable }, _lag_id { lag_id } {

}

const String& ILagObservable::lagId() {
    return _lag_id;
}

CreateLagEvent::CreateLagEvent(SharedPtr<Net::ILagQueryable> lagQueryable, StringView lag_id)
: ILagObservable { lagQueryable, lag_id } {
    // Nothing more to do
}

DeleteLagEvent::DeleteLagEvent(SharedPtr<Net::ILagQueryable> lagQueryable, StringView lag_id)
: ILagObservable { lagQueryable, lag_id } {
    // Nothing more to do
}

AddMemberEvent::AddMemberEvent(SharedPtr<Net::ILagQueryable> lagQueryable, StringView lag_id, StringView member_id)
: ILagObservable { lagQueryable, lag_id }, _member_id { member_id } {
    // Nothing more to do
}

const String& AddMemberEvent::memberId() {
    return _member_id;
}

RemoveMemberEvent::RemoveMemberEvent(SharedPtr<Net::ILagQueryable> lagQueryable, StringView lag_id, StringView member_id)
: ILagObservable { lagQueryable, lag_id }, _member_id { member_id } {
    // Nothing more to do
}

const String& RemoveMemberEvent::memberId() {
    return _member_id;
}
