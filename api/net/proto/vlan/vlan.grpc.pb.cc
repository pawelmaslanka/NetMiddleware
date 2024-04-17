// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: vlan.proto

#include "vlan.pb.h"
#include "vlan.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace Net {

static const char* VlanManagement_method_names[] = {
  "/Net.VlanManagement/CreateVlan",
  "/Net.VlanManagement/DeleteVlan",
  "/Net.VlanManagement/AddVlanMember",
  "/Net.VlanManagement/RemoveVlanMember",
};

std::unique_ptr< VlanManagement::Stub> VlanManagement::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< VlanManagement::Stub> stub(new VlanManagement::Stub(channel, options));
  return stub;
}

VlanManagement::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_CreateVlan_(VlanManagement_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_DeleteVlan_(VlanManagement_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_AddVlanMember_(VlanManagement_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_RemoveVlanMember_(VlanManagement_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status VlanManagement::Stub::CreateVlan(::grpc::ClientContext* context, const ::Net::VlanInstance& request, ::Net::Result* response) {
  return ::grpc::internal::BlockingUnaryCall< ::Net::VlanInstance, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_CreateVlan_, context, request, response);
}

void VlanManagement::Stub::async::CreateVlan(::grpc::ClientContext* context, const ::Net::VlanInstance* request, ::Net::Result* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::Net::VlanInstance, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_CreateVlan_, context, request, response, std::move(f));
}

void VlanManagement::Stub::async::CreateVlan(::grpc::ClientContext* context, const ::Net::VlanInstance* request, ::Net::Result* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_CreateVlan_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::Net::Result>* VlanManagement::Stub::PrepareAsyncCreateVlanRaw(::grpc::ClientContext* context, const ::Net::VlanInstance& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::Net::Result, ::Net::VlanInstance, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_CreateVlan_, context, request);
}

::grpc::ClientAsyncResponseReader< ::Net::Result>* VlanManagement::Stub::AsyncCreateVlanRaw(::grpc::ClientContext* context, const ::Net::VlanInstance& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncCreateVlanRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status VlanManagement::Stub::DeleteVlan(::grpc::ClientContext* context, const ::Net::VlanInstance& request, ::Net::Result* response) {
  return ::grpc::internal::BlockingUnaryCall< ::Net::VlanInstance, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_DeleteVlan_, context, request, response);
}

void VlanManagement::Stub::async::DeleteVlan(::grpc::ClientContext* context, const ::Net::VlanInstance* request, ::Net::Result* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::Net::VlanInstance, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_DeleteVlan_, context, request, response, std::move(f));
}

void VlanManagement::Stub::async::DeleteVlan(::grpc::ClientContext* context, const ::Net::VlanInstance* request, ::Net::Result* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_DeleteVlan_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::Net::Result>* VlanManagement::Stub::PrepareAsyncDeleteVlanRaw(::grpc::ClientContext* context, const ::Net::VlanInstance& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::Net::Result, ::Net::VlanInstance, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_DeleteVlan_, context, request);
}

::grpc::ClientAsyncResponseReader< ::Net::Result>* VlanManagement::Stub::AsyncDeleteVlanRaw(::grpc::ClientContext* context, const ::Net::VlanInstance& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncDeleteVlanRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status VlanManagement::Stub::AddVlanMember(::grpc::ClientContext* context, const ::Net::VlanMember& request, ::Net::Result* response) {
  return ::grpc::internal::BlockingUnaryCall< ::Net::VlanMember, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_AddVlanMember_, context, request, response);
}

void VlanManagement::Stub::async::AddVlanMember(::grpc::ClientContext* context, const ::Net::VlanMember* request, ::Net::Result* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::Net::VlanMember, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AddVlanMember_, context, request, response, std::move(f));
}

void VlanManagement::Stub::async::AddVlanMember(::grpc::ClientContext* context, const ::Net::VlanMember* request, ::Net::Result* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AddVlanMember_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::Net::Result>* VlanManagement::Stub::PrepareAsyncAddVlanMemberRaw(::grpc::ClientContext* context, const ::Net::VlanMember& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::Net::Result, ::Net::VlanMember, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_AddVlanMember_, context, request);
}

::grpc::ClientAsyncResponseReader< ::Net::Result>* VlanManagement::Stub::AsyncAddVlanMemberRaw(::grpc::ClientContext* context, const ::Net::VlanMember& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncAddVlanMemberRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status VlanManagement::Stub::RemoveVlanMember(::grpc::ClientContext* context, const ::Net::VlanMember& request, ::Net::Result* response) {
  return ::grpc::internal::BlockingUnaryCall< ::Net::VlanMember, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_RemoveVlanMember_, context, request, response);
}

void VlanManagement::Stub::async::RemoveVlanMember(::grpc::ClientContext* context, const ::Net::VlanMember* request, ::Net::Result* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::Net::VlanMember, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_RemoveVlanMember_, context, request, response, std::move(f));
}

void VlanManagement::Stub::async::RemoveVlanMember(::grpc::ClientContext* context, const ::Net::VlanMember* request, ::Net::Result* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_RemoveVlanMember_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::Net::Result>* VlanManagement::Stub::PrepareAsyncRemoveVlanMemberRaw(::grpc::ClientContext* context, const ::Net::VlanMember& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::Net::Result, ::Net::VlanMember, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_RemoveVlanMember_, context, request);
}

::grpc::ClientAsyncResponseReader< ::Net::Result>* VlanManagement::Stub::AsyncRemoveVlanMemberRaw(::grpc::ClientContext* context, const ::Net::VlanMember& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncRemoveVlanMemberRaw(context, request, cq);
  result->StartCall();
  return result;
}

VlanManagement::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      VlanManagement_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< VlanManagement::Service, ::Net::VlanInstance, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](VlanManagement::Service* service,
             ::grpc::ServerContext* ctx,
             const ::Net::VlanInstance* req,
             ::Net::Result* resp) {
               return service->CreateVlan(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      VlanManagement_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< VlanManagement::Service, ::Net::VlanInstance, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](VlanManagement::Service* service,
             ::grpc::ServerContext* ctx,
             const ::Net::VlanInstance* req,
             ::Net::Result* resp) {
               return service->DeleteVlan(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      VlanManagement_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< VlanManagement::Service, ::Net::VlanMember, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](VlanManagement::Service* service,
             ::grpc::ServerContext* ctx,
             const ::Net::VlanMember* req,
             ::Net::Result* resp) {
               return service->AddVlanMember(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      VlanManagement_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< VlanManagement::Service, ::Net::VlanMember, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](VlanManagement::Service* service,
             ::grpc::ServerContext* ctx,
             const ::Net::VlanMember* req,
             ::Net::Result* resp) {
               return service->RemoveVlanMember(ctx, req, resp);
             }, this)));
}

VlanManagement::Service::~Service() {
}

::grpc::Status VlanManagement::Service::CreateVlan(::grpc::ServerContext* context, const ::Net::VlanInstance* request, ::Net::Result* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status VlanManagement::Service::DeleteVlan(::grpc::ServerContext* context, const ::Net::VlanInstance* request, ::Net::Result* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status VlanManagement::Service::AddVlanMember(::grpc::ServerContext* context, const ::Net::VlanMember* request, ::Net::Result* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status VlanManagement::Service::RemoveVlanMember(::grpc::ServerContext* context, const ::Net::VlanMember* request, ::Net::Result* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace Net
