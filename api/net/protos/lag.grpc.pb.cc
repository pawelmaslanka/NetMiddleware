// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: lag.proto

#include "lag.pb.h"
#include "lag.grpc.pb.h"

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

static const char* Lag_method_names[] = {
  "/Net.Lag/Create",
  "/Net.Lag/Delete",
  "/Net.Lag/AddMember",
  "/Net.Lag/RemoveMember",
};

std::unique_ptr< Lag::Stub> Lag::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Lag::Stub> stub(new Lag::Stub(channel, options));
  return stub;
}

Lag::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_Create_(Lag_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Delete_(Lag_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_AddMember_(Lag_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_RemoveMember_(Lag_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status Lag::Stub::Create(::grpc::ClientContext* context, const ::Net::LagIface& request, ::Net::Result* response) {
  return ::grpc::internal::BlockingUnaryCall< ::Net::LagIface, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Create_, context, request, response);
}

void Lag::Stub::async::Create(::grpc::ClientContext* context, const ::Net::LagIface* request, ::Net::Result* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::Net::LagIface, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Create_, context, request, response, std::move(f));
}

void Lag::Stub::async::Create(::grpc::ClientContext* context, const ::Net::LagIface* request, ::Net::Result* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Create_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::Net::Result>* Lag::Stub::PrepareAsyncCreateRaw(::grpc::ClientContext* context, const ::Net::LagIface& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::Net::Result, ::Net::LagIface, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Create_, context, request);
}

::grpc::ClientAsyncResponseReader< ::Net::Result>* Lag::Stub::AsyncCreateRaw(::grpc::ClientContext* context, const ::Net::LagIface& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncCreateRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status Lag::Stub::Delete(::grpc::ClientContext* context, const ::Net::LagIface& request, ::Net::Result* response) {
  return ::grpc::internal::BlockingUnaryCall< ::Net::LagIface, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Delete_, context, request, response);
}

void Lag::Stub::async::Delete(::grpc::ClientContext* context, const ::Net::LagIface* request, ::Net::Result* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::Net::LagIface, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Delete_, context, request, response, std::move(f));
}

void Lag::Stub::async::Delete(::grpc::ClientContext* context, const ::Net::LagIface* request, ::Net::Result* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Delete_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::Net::Result>* Lag::Stub::PrepareAsyncDeleteRaw(::grpc::ClientContext* context, const ::Net::LagIface& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::Net::Result, ::Net::LagIface, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Delete_, context, request);
}

::grpc::ClientAsyncResponseReader< ::Net::Result>* Lag::Stub::AsyncDeleteRaw(::grpc::ClientContext* context, const ::Net::LagIface& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncDeleteRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status Lag::Stub::AddMember(::grpc::ClientContext* context, const ::Net::LagMember& request, ::Net::Result* response) {
  return ::grpc::internal::BlockingUnaryCall< ::Net::LagMember, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_AddMember_, context, request, response);
}

void Lag::Stub::async::AddMember(::grpc::ClientContext* context, const ::Net::LagMember* request, ::Net::Result* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::Net::LagMember, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AddMember_, context, request, response, std::move(f));
}

void Lag::Stub::async::AddMember(::grpc::ClientContext* context, const ::Net::LagMember* request, ::Net::Result* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AddMember_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::Net::Result>* Lag::Stub::PrepareAsyncAddMemberRaw(::grpc::ClientContext* context, const ::Net::LagMember& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::Net::Result, ::Net::LagMember, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_AddMember_, context, request);
}

::grpc::ClientAsyncResponseReader< ::Net::Result>* Lag::Stub::AsyncAddMemberRaw(::grpc::ClientContext* context, const ::Net::LagMember& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncAddMemberRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status Lag::Stub::RemoveMember(::grpc::ClientContext* context, const ::Net::LagMember& request, ::Net::Result* response) {
  return ::grpc::internal::BlockingUnaryCall< ::Net::LagMember, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_RemoveMember_, context, request, response);
}

void Lag::Stub::async::RemoveMember(::grpc::ClientContext* context, const ::Net::LagMember* request, ::Net::Result* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::Net::LagMember, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_RemoveMember_, context, request, response, std::move(f));
}

void Lag::Stub::async::RemoveMember(::grpc::ClientContext* context, const ::Net::LagMember* request, ::Net::Result* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_RemoveMember_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::Net::Result>* Lag::Stub::PrepareAsyncRemoveMemberRaw(::grpc::ClientContext* context, const ::Net::LagMember& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::Net::Result, ::Net::LagMember, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_RemoveMember_, context, request);
}

::grpc::ClientAsyncResponseReader< ::Net::Result>* Lag::Stub::AsyncRemoveMemberRaw(::grpc::ClientContext* context, const ::Net::LagMember& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncRemoveMemberRaw(context, request, cq);
  result->StartCall();
  return result;
}

Lag::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Lag_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Lag::Service, ::Net::LagIface, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Lag::Service* service,
             ::grpc::ServerContext* ctx,
             const ::Net::LagIface* req,
             ::Net::Result* resp) {
               return service->Create(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Lag_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Lag::Service, ::Net::LagIface, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Lag::Service* service,
             ::grpc::ServerContext* ctx,
             const ::Net::LagIface* req,
             ::Net::Result* resp) {
               return service->Delete(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Lag_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Lag::Service, ::Net::LagMember, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Lag::Service* service,
             ::grpc::ServerContext* ctx,
             const ::Net::LagMember* req,
             ::Net::Result* resp) {
               return service->AddMember(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Lag_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Lag::Service, ::Net::LagMember, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Lag::Service* service,
             ::grpc::ServerContext* ctx,
             const ::Net::LagMember* req,
             ::Net::Result* resp) {
               return service->RemoveMember(ctx, req, resp);
             }, this)));
}

Lag::Service::~Service() {
}

::grpc::Status Lag::Service::Create(::grpc::ServerContext* context, const ::Net::LagIface* request, ::Net::Result* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Lag::Service::Delete(::grpc::ServerContext* context, const ::Net::LagIface* request, ::Net::Result* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Lag::Service::AddMember(::grpc::ServerContext* context, const ::Net::LagMember* request, ::Net::Result* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Lag::Service::RemoveMember(::grpc::ServerContext* context, const ::Net::LagMember* request, ::Net::Result* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace Net

