#include "lag_management.hpp"

#include "lib/lag_observable.hpp"
#include <spdlog/spdlog.h>

LagManager::LagManager(StringView module_name, SharedPtr<ModuleRegistry> module_registry,
                       SharedPtr<grpc::Channel> rpc_net_channel)
    : _module_name{module_name}, _module_registry{module_registry},
      _lag_service{DPLag::LagManagement::NewStub(rpc_net_channel)},
      _log{module_registry->loggerRegistry()->getLogger(String(module_name))} {
    // Nothing more to do
}

bool LagManager::createLag(const Net::ID &lag_id, const String &mac_address) {
    if (_lag_by_id.find(lag_id) != _lag_by_id.end()) {
        _log->error("LAG '{}' already exists", lag_id);
        return false;
    }

    grpc::ClientContext context;
    DataPlane::Result result;
    DPLag::Lag lag;
    lag.set_id(lag_id);
    lag.set_mac_address(mac_address);
    auto status = _lag_service->CreateLag(&context, lag, &result);
    if (!status.ok()) {
        _log->error("Failed to send request to create the LAG instance '{}': {} ({})",
                    lag_id, status.error_message(), status.error_code());
        return false;
    }

    _lag_by_id[lag_id] = MakeSharedPtr<Net::Lag>();
    notifySubscribers(MakeSharedPtr<LagObservable::CreateLagEvent>(shared_from_this(), lag_id));
    return true;
}

bool LagManager::deleteLag(const Net::ID &lag_id) {
    if (_lag_by_id.find(lag_id) == _lag_by_id.end()) {
        _log->error("LAG '{}' not exists", lag_id);
        return false;
    }

    grpc::ClientContext context;
    DataPlane::Result result;
    DPLag::Lag lag;
    lag.set_id(lag_id);
    auto status = _lag_service->DeleteLag(&context, lag, &result);
    if (!status.ok()) {
        _log->error("Failed to send request to delete the LAG instance '{}': {} ({})",
                    lag_id, status.error_message(), status.error_code());
        return false;
    }

    _lag_by_id.erase(lag_id);
    notifySubscribers(MakeSharedPtr<LagObservable::DeleteLagEvent>(shared_from_this(), lag_id));
    return true;
}

bool LagManager::addMember(const Net::ID &lag_id, const Net::ID &member_id) {
    auto lag_it = _lag_by_id.find(lag_id);
    if (lag_it == _lag_by_id.end()) {
        _log->error("LAG '{}' not exists", lag_id);
        return false;
    }

    grpc::ClientContext context;
    DataPlane::Result result;
    DPLag::LagMember lag_member;
    lag_member.set_lag_id(lag_id);
    auto member = lag_member.add_members();
    member->set_id(member_id);
    auto status = _lag_service->AddLagMember(&context, lag_member, &result);
    if (!status.ok()) {
        _log->error("Failed to send request to add member to the LAG instance '{}': {} ({})",
                    lag_id, status.error_message(), status.error_code());
        return false;
    }

    lag_it->second->Members.emplace(member_id);
    notifySubscribers(MakeSharedPtr<LagObservable::AddMemberEvent>(shared_from_this(), lag_id, member_id));
    return true;
}

bool LagManager::removeMember(const Net::ID &lag_id, const Net::ID &member_id) {
    auto lag_it = _lag_by_id.find(lag_id);
    if (lag_it == _lag_by_id.end()) {
        _log->error("LAG '{}' not exists", lag_id);
        return false;
    }

    grpc::ClientContext context;
    DataPlane::Result result;
    DPLag::LagMember lag_member;
    lag_member.set_lag_id(lag_id);
    auto member = lag_member.add_members();
    member->set_id(member_id);
    auto status = _lag_service->RemoveLagMember(&context, lag_member, &result);
    if (!status.ok()) {
        _log->error("Failed to send request to remove member from the LAG instance '{}': {} ({})",
                    lag_id, status.error_message(), status.error_code());
        return false;
    }

    lag_it->second->Members.erase(member_id);
    notifySubscribers(MakeSharedPtr<LagObservable::RemoveMemberEvent>(shared_from_this(), lag_id, member_id));
    return true;
}

bool LagManager::enableLacpProtocol(const Net::ID &lag_id, const bool enableLacp) {
    auto lag_it = _lag_by_id.find(lag_id);
    if (lag_it == _lag_by_id.end()) {
        _log->error("LAG '{}' not exists", lag_id);
        return false;
    }

    auto oldLagType = lag_it->second->Type;
    lag_it->second->Type = enableLacp ? Net::Lag::ControlProtocol::LACP : Net::Lag::ControlProtocol::NONE;
    if (oldLagType != lag_it->second->Type) {
        if (lag_it->second->Type == Net::Lag::ControlProtocol::LACP) {
            // FIXME: Remove all members from static LAG and re-add them dynamically by LACP
        }
        // FIXME: Call RPC
    }

    return true;
}

const WeakPtr<Net::Lag> LagManager::getLag(const Net::ID &lag_id) const {
    auto lag_it = _lag_by_id.find(lag_id);
    if (lag_it == _lag_by_id.end()) {
        return {};
    }

    return lag_it->second;
}
