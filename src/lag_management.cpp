#include "lag_management.hpp"

#include "lib/lag_observable.hpp"
#include <spdlog/spdlog.h>

LagManager::LagManager(SharedPtr<ModuleRegistry> module_registry, SharedPtr<grpc::Channel> rpc_net_channel)
: _module_registry { module_registry }, _lag_service { Net::LagManagement::NewStub(rpc_net_channel) } {
}

bool LagManager::createLag(const String& lag_id) {
    if (_lag_by_id.find(lag_id) != _lag_by_id.end()) {
        spdlog::error("LAG '{}' already exists", lag_id);
        return false;
    }

    grpc::ClientContext context;
    Net::Result result;
    Net::Lag lag;
    lag.set_id(lag_id);
    auto status = _lag_service->CreateLag(&context, lag, &result);
    if (!status.ok()) {
        spdlog::error("Failed to send request to create the LAG instance '{}': {} ({})",
            lag_id, status.error_message(), status.error_code());
        return false;
    }

    _lag_by_id[lag_id] = MakeShared<Lag>();
    return true;
}

bool LagManager::deleteLag(const String& lag_id) {
    if (_lag_by_id.find(lag_id) == _lag_by_id.end()) {
        spdlog::error("LAG '{}' not exists", lag_id);
        return false;
    }

    grpc::ClientContext context;
    Net::Result result;
    Net::Lag lag;
    lag.set_id(lag_id);
    auto status = _lag_service->DeleteLag(&context, lag, &result);
    if (!status.ok()) {
        spdlog::error("Failed to send request to delete the LAG instance '{}': {} ({})",
            lag_id, status.error_message(), status.error_code());
        return false;
    }

    _lag_by_id.erase(lag_id);
    return true;
}

bool LagManager::addMember(const String& lag_id, const String& member_id) {
    auto lag_it = _lag_by_id.find(lag_id);
    if (lag_it == _lag_by_id.end()) {
        spdlog::error("LAG '{}' not exists", lag_id);
        return false;
    }

    grpc::ClientContext context;
    Net::Result result;
    Net::LagMember lag_member;
    lag_member.mutable_lag()->set_id(lag_id);
    auto member = lag_member.add_members();
    member->set_id(member_id);
    member->set_type(Net::IfaceType::IFACE_ETH);
    auto status = _lag_service->AddLagMember(&context, lag_member, &result);
    if (!status.ok()) {
        spdlog::error("Failed to send request to add member to the LAG instance '{}': {} ({})",
            lag_id, status.error_message(), status.error_code());
        return false;
    }

    lag_it->second->Members.emplace(member_id);
    notifySubscribers(MakeShared<LagObservable::AddMemberEvent>(shared_from_this(), lag_id, member_id));
    return true;
}

bool LagManager::removeMember(const String& lag_id, const String& member_id) {
    auto lag_it = _lag_by_id.find(lag_id);
    if (lag_it == _lag_by_id.end()) {
        spdlog::error("LAG '{}' not exists", lag_id);
        return false;
    }

    grpc::ClientContext context;
    Net::Result result;
    Net::LagMember lag_member;
    lag_member.mutable_lag()->set_id(lag_id);
    auto member = lag_member.add_members();
    member->set_id(member_id);
    member->set_type(Net::IfaceType::IFACE_ETH);
    auto status = _lag_service->RemoveLagMember(&context, lag_member, &result);
    if (!status.ok()) {
        spdlog::error("Failed to send request to remove member from the LAG instance '{}': {} ({})",
            lag_id, status.error_message(), status.error_code());
        return false;
    }

    lag_it->second->Members.erase(member_id);
    notifySubscribers(MakeShared<LagObservable::RemoveMemberEvent>(shared_from_this(), lag_id, member_id));
    return true;
}

bool LagManager::enableLacpProtocol(const String& lag_id, const bool enableLacp) {
    auto lag_it = _lag_by_id.find(lag_id);
    if (lag_it == _lag_by_id.end()) {
        spdlog::error("LAG '{}' not exists", lag_id);
        return false;
    }

    auto oldLagType = lag_it->second->Type;
    lag_it->second->Type = enableLacp ? Lag::LagType::DYNAMIC : Lag::LagType::STATIC;
    if (oldLagType != lag_it->second->Type) {
        if (lag_it->second->Type == Lag::LagType::DYNAMIC) {
            // FIXME: Remove all members from static LAG and re-add them dynamically by LACP
        }
        // FIXME: Call RPC
    }

    return true;
}

const SharedPtr<Lag> LagManager::getLag(const String& lag_id) const {
    auto lag_it = _lag_by_id.find(lag_id);
    if (lag_it == _lag_by_id.end()) {
        return nullptr;
    }

    return lag_it->second;
}
