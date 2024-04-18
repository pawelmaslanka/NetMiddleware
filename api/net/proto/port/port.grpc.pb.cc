// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: port.proto

#include "port.pb.h"
#include "port.grpc.pb.h"

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

static const char* PortManagement_method_names[] = {
  "/Net.PortManagement/CreatePort",
  "/Net.PortManagement/DeletePort",
  "/Net.PortManagement/SetPortBreakout",
};

std::unique_ptr< PortManagement::Stub> PortManagement::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< PortManagement::Stub> stub(new PortManagement::Stub(channel, options));
  return stub;
}

PortManagement::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_CreatePort_(PortManagement_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_DeletePort_(PortManagement_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_SetPortBreakout_(PortManagement_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status PortManagement::Stub::CreatePort(::grpc::ClientContext* context, const ::Net::Port& request, ::Net::Result* response) {
  return ::grpc::internal::BlockingUnaryCall< ::Net::Port, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_CreatePort_, context, request, response);
}

void PortManagement::Stub::async::CreatePort(::grpc::ClientContext* context, const ::Net::Port* request, ::Net::Result* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::Net::Port, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_CreatePort_, context, request, response, std::move(f));
}

void PortManagement::Stub::async::CreatePort(::grpc::ClientContext* context, const ::Net::Port* request, ::Net::Result* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_CreatePort_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::Net::Result>* PortManagement::Stub::PrepareAsyncCreatePortRaw(::grpc::ClientContext* context, const ::Net::Port& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::Net::Result, ::Net::Port, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_CreatePort_, context, request);
}

::grpc::ClientAsyncResponseReader< ::Net::Result>* PortManagement::Stub::AsyncCreatePortRaw(::grpc::ClientContext* context, const ::Net::Port& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncCreatePortRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status PortManagement::Stub::DeletePort(::grpc::ClientContext* context, const ::Net::Port& request, ::Net::Result* response) {
  return ::grpc::internal::BlockingUnaryCall< ::Net::Port, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_DeletePort_, context, request, response);
}

void PortManagement::Stub::async::DeletePort(::grpc::ClientContext* context, const ::Net::Port* request, ::Net::Result* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::Net::Port, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_DeletePort_, context, request, response, std::move(f));
}

void PortManagement::Stub::async::DeletePort(::grpc::ClientContext* context, const ::Net::Port* request, ::Net::Result* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_DeletePort_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::Net::Result>* PortManagement::Stub::PrepareAsyncDeletePortRaw(::grpc::ClientContext* context, const ::Net::Port& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::Net::Result, ::Net::Port, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_DeletePort_, context, request);
}

::grpc::ClientAsyncResponseReader< ::Net::Result>* PortManagement::Stub::AsyncDeletePortRaw(::grpc::ClientContext* context, const ::Net::Port& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncDeletePortRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status PortManagement::Stub::SetPortBreakout(::grpc::ClientContext* context, const ::Net::PortBreakoutMode& request, ::Net::Result* response) {
  return ::grpc::internal::BlockingUnaryCall< ::Net::PortBreakoutMode, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SetPortBreakout_, context, request, response);
}

void PortManagement::Stub::async::SetPortBreakout(::grpc::ClientContext* context, const ::Net::PortBreakoutMode* request, ::Net::Result* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::Net::PortBreakoutMode, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SetPortBreakout_, context, request, response, std::move(f));
}

void PortManagement::Stub::async::SetPortBreakout(::grpc::ClientContext* context, const ::Net::PortBreakoutMode* request, ::Net::Result* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SetPortBreakout_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::Net::Result>* PortManagement::Stub::PrepareAsyncSetPortBreakoutRaw(::grpc::ClientContext* context, const ::Net::PortBreakoutMode& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::Net::Result, ::Net::PortBreakoutMode, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SetPortBreakout_, context, request);
}

::grpc::ClientAsyncResponseReader< ::Net::Result>* PortManagement::Stub::AsyncSetPortBreakoutRaw(::grpc::ClientContext* context, const ::Net::PortBreakoutMode& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSetPortBreakoutRaw(context, request, cq);
  result->StartCall();
  return result;
}

PortManagement::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      PortManagement_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< PortManagement::Service, ::Net::Port, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](PortManagement::Service* service,
             ::grpc::ServerContext* ctx,
             const ::Net::Port* req,
             ::Net::Result* resp) {
               return service->CreatePort(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      PortManagement_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< PortManagement::Service, ::Net::Port, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](PortManagement::Service* service,
             ::grpc::ServerContext* ctx,
             const ::Net::Port* req,
             ::Net::Result* resp) {
               return service->DeletePort(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      PortManagement_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< PortManagement::Service, ::Net::PortBreakoutMode, ::Net::Result, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](PortManagement::Service* service,
             ::grpc::ServerContext* ctx,
             const ::Net::PortBreakoutMode* req,
             ::Net::Result* resp) {
               return service->SetPortBreakout(ctx, req, resp);
             }, this)));
}

PortManagement::Service::~Service() {
}

::grpc::Status PortManagement::Service::CreatePort(::grpc::ServerContext* context, const ::Net::Port* request, ::Net::Result* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status PortManagement::Service::DeletePort(::grpc::ServerContext* context, const ::Net::Port* request, ::Net::Result* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status PortManagement::Service::SetPortBreakout(::grpc::ServerContext* context, const ::Net::PortBreakoutMode* request, ::Net::Result* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace Net

