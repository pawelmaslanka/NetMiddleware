#pragma once

#include "lib/observer.hpp"

#include <net/lag/lag_queryable.hpp>
#include <lib/std_types.hpp>

namespace LagObservable {

namespace Net = Lib::Net;

class ILagObservable : public Observer::Event {
public:
    static constexpr auto CHANGED_STATE = "CHANGED_STATE";
    static constexpr auto ADDED_MEMBER = "ADDED_MEMBER";
    static constexpr auto REMOVED_MEMBER = "REMOVED_MEMBER";

    ILagObservable(SharedPtr<Net::ILagQueryable> lagQueryable, StringView lag_id);
    virtual ~ILagObservable() = default;
    const String& lagId();

private:
    SharedPtr<Net::ILagQueryable> _lagQueryable;
    String _lag_id;
};

class CreateLagEvent final : public ILagObservable {
public:
    virtual ~CreateLagEvent() = default;
    CreateLagEvent(SharedPtr<Net::ILagQueryable> lagQueryable, StringView lag_id);
};

class DeleteLagEvent final : public ILagObservable {
public:
    virtual ~DeleteLagEvent() = default;
    DeleteLagEvent(SharedPtr<Net::ILagQueryable> lagQueryable, StringView lag_id);
};

class AddMemberEvent final : public ILagObservable {
public:
    virtual ~AddMemberEvent() = default;
    AddMemberEvent(SharedPtr<Net::ILagQueryable> lagQueryable, StringView lag_id, StringView member_id);
    const String& memberId();

private:
    String _member_id; // In case of add or remove LAG's members
};

class RemoveMemberEvent final : public ILagObservable {
public:
    virtual ~RemoveMemberEvent() = default;
    RemoveMemberEvent(SharedPtr<Net::ILagQueryable> lagQueryable, StringView lag_id, StringView member_id);
    const String& memberId();

private:
    String _member_id; // In case of add or remove LAG's members
};

} // namespace LagObservable
