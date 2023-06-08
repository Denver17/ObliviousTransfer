// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: SimplestOT.proto

#include "SimplestOT.pb.h"
#include "SimplestOT.grpc.pb.h"

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
namespace SimplestOT {

static const char* OT_method_names[] = {
  "/SimplestOT.OT/SendA",
  "/SimplestOT.OT/SendCipherText",
};

std::unique_ptr< OT::Stub> OT::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< OT::Stub> stub(new OT::Stub(channel, options));
  return stub;
}

OT::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_SendA_(OT_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_SendCipherText_(OT_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status OT::Stub::SendA(::grpc::ClientContext* context, const ::SimplestOT::ARequest& request, ::SimplestOT::BReply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::SimplestOT::ARequest, ::SimplestOT::BReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SendA_, context, request, response);
}

void OT::Stub::async::SendA(::grpc::ClientContext* context, const ::SimplestOT::ARequest* request, ::SimplestOT::BReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::SimplestOT::ARequest, ::SimplestOT::BReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SendA_, context, request, response, std::move(f));
}

void OT::Stub::async::SendA(::grpc::ClientContext* context, const ::SimplestOT::ARequest* request, ::SimplestOT::BReply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SendA_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::SimplestOT::BReply>* OT::Stub::PrepareAsyncSendARaw(::grpc::ClientContext* context, const ::SimplestOT::ARequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::SimplestOT::BReply, ::SimplestOT::ARequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SendA_, context, request);
}

::grpc::ClientAsyncResponseReader< ::SimplestOT::BReply>* OT::Stub::AsyncSendARaw(::grpc::ClientContext* context, const ::SimplestOT::ARequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSendARaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status OT::Stub::SendCipherText(::grpc::ClientContext* context, const ::SimplestOT::CTRequest& request, ::SimplestOT::CTReply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::SimplestOT::CTRequest, ::SimplestOT::CTReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SendCipherText_, context, request, response);
}

void OT::Stub::async::SendCipherText(::grpc::ClientContext* context, const ::SimplestOT::CTRequest* request, ::SimplestOT::CTReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::SimplestOT::CTRequest, ::SimplestOT::CTReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SendCipherText_, context, request, response, std::move(f));
}

void OT::Stub::async::SendCipherText(::grpc::ClientContext* context, const ::SimplestOT::CTRequest* request, ::SimplestOT::CTReply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SendCipherText_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::SimplestOT::CTReply>* OT::Stub::PrepareAsyncSendCipherTextRaw(::grpc::ClientContext* context, const ::SimplestOT::CTRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::SimplestOT::CTReply, ::SimplestOT::CTRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SendCipherText_, context, request);
}

::grpc::ClientAsyncResponseReader< ::SimplestOT::CTReply>* OT::Stub::AsyncSendCipherTextRaw(::grpc::ClientContext* context, const ::SimplestOT::CTRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSendCipherTextRaw(context, request, cq);
  result->StartCall();
  return result;
}

OT::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OT_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OT::Service, ::SimplestOT::ARequest, ::SimplestOT::BReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OT::Service* service,
             ::grpc::ServerContext* ctx,
             const ::SimplestOT::ARequest* req,
             ::SimplestOT::BReply* resp) {
               return service->SendA(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OT_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OT::Service, ::SimplestOT::CTRequest, ::SimplestOT::CTReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OT::Service* service,
             ::grpc::ServerContext* ctx,
             const ::SimplestOT::CTRequest* req,
             ::SimplestOT::CTReply* resp) {
               return service->SendCipherText(ctx, req, resp);
             }, this)));
}

OT::Service::~Service() {
}

::grpc::Status OT::Service::SendA(::grpc::ServerContext* context, const ::SimplestOT::ARequest* request, ::SimplestOT::BReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status OT::Service::SendCipherText(::grpc::ServerContext* context, const ::SimplestOT::CTRequest* request, ::SimplestOT::CTReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace SimplestOT
