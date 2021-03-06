// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: example.proto

#include "example.pb.h"
#include "example.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace MyGrpcS {

static const char* SearchService_method_names[] = {
  "/MyGrpcS.SearchService/getDataA",
  "/MyGrpcS.SearchService/setDataA",
  "/MyGrpcS.SearchService/getDataB",
  "/MyGrpcS.SearchService/setDataB",
  "/MyGrpcS.SearchService/streamData",
  "/MyGrpcS.SearchService/ctreamData",
  "/MyGrpcS.SearchService/scstreamData",
};

std::unique_ptr< SearchService::Stub> SearchService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< SearchService::Stub> stub(new SearchService::Stub(channel));
  return stub;
}

SearchService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_getDataA_(SearchService_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_setDataA_(SearchService_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_getDataB_(SearchService_method_names[2], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_setDataB_(SearchService_method_names[3], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_streamData_(SearchService_method_names[4], ::grpc::internal::RpcMethod::SERVER_STREAMING, channel)
  , rpcmethod_ctreamData_(SearchService_method_names[5], ::grpc::internal::RpcMethod::CLIENT_STREAMING, channel)
  , rpcmethod_scstreamData_(SearchService_method_names[6], ::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  {}

::grpc::Status SearchService::Stub::getDataA(::grpc::ClientContext* context, const ::MyGrpcS::SearchARequest& request, ::MyGrpcS::SearchAResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_getDataA_, context, request, response);
}

void SearchService::Stub::experimental_async::getDataA(::grpc::ClientContext* context, const ::MyGrpcS::SearchARequest* request, ::MyGrpcS::SearchAResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_getDataA_, context, request, response, std::move(f));
}

void SearchService::Stub::experimental_async::getDataA(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::MyGrpcS::SearchAResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_getDataA_, context, request, response, std::move(f));
}

void SearchService::Stub::experimental_async::getDataA(::grpc::ClientContext* context, const ::MyGrpcS::SearchARequest* request, ::MyGrpcS::SearchAResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_getDataA_, context, request, response, reactor);
}

void SearchService::Stub::experimental_async::getDataA(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::MyGrpcS::SearchAResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_getDataA_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::MyGrpcS::SearchAResponse>* SearchService::Stub::AsyncgetDataARaw(::grpc::ClientContext* context, const ::MyGrpcS::SearchARequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::MyGrpcS::SearchAResponse>::Create(channel_.get(), cq, rpcmethod_getDataA_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::MyGrpcS::SearchAResponse>* SearchService::Stub::PrepareAsyncgetDataARaw(::grpc::ClientContext* context, const ::MyGrpcS::SearchARequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::MyGrpcS::SearchAResponse>::Create(channel_.get(), cq, rpcmethod_getDataA_, context, request, false);
}

::grpc::Status SearchService::Stub::setDataA(::grpc::ClientContext* context, const ::MyGrpcS::SearchAResponse& request, ::MyGrpcS::SearchARequest* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_setDataA_, context, request, response);
}

void SearchService::Stub::experimental_async::setDataA(::grpc::ClientContext* context, const ::MyGrpcS::SearchAResponse* request, ::MyGrpcS::SearchARequest* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_setDataA_, context, request, response, std::move(f));
}

void SearchService::Stub::experimental_async::setDataA(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::MyGrpcS::SearchARequest* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_setDataA_, context, request, response, std::move(f));
}

void SearchService::Stub::experimental_async::setDataA(::grpc::ClientContext* context, const ::MyGrpcS::SearchAResponse* request, ::MyGrpcS::SearchARequest* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_setDataA_, context, request, response, reactor);
}

void SearchService::Stub::experimental_async::setDataA(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::MyGrpcS::SearchARequest* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_setDataA_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::MyGrpcS::SearchARequest>* SearchService::Stub::AsyncsetDataARaw(::grpc::ClientContext* context, const ::MyGrpcS::SearchAResponse& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::MyGrpcS::SearchARequest>::Create(channel_.get(), cq, rpcmethod_setDataA_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::MyGrpcS::SearchARequest>* SearchService::Stub::PrepareAsyncsetDataARaw(::grpc::ClientContext* context, const ::MyGrpcS::SearchAResponse& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::MyGrpcS::SearchARequest>::Create(channel_.get(), cq, rpcmethod_setDataA_, context, request, false);
}

::grpc::Status SearchService::Stub::getDataB(::grpc::ClientContext* context, const ::MyGrpcS::SearchBRequest& request, ::MyGrpcS::SearchBResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_getDataB_, context, request, response);
}

void SearchService::Stub::experimental_async::getDataB(::grpc::ClientContext* context, const ::MyGrpcS::SearchBRequest* request, ::MyGrpcS::SearchBResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_getDataB_, context, request, response, std::move(f));
}

void SearchService::Stub::experimental_async::getDataB(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::MyGrpcS::SearchBResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_getDataB_, context, request, response, std::move(f));
}

void SearchService::Stub::experimental_async::getDataB(::grpc::ClientContext* context, const ::MyGrpcS::SearchBRequest* request, ::MyGrpcS::SearchBResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_getDataB_, context, request, response, reactor);
}

void SearchService::Stub::experimental_async::getDataB(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::MyGrpcS::SearchBResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_getDataB_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::MyGrpcS::SearchBResponse>* SearchService::Stub::AsyncgetDataBRaw(::grpc::ClientContext* context, const ::MyGrpcS::SearchBRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::MyGrpcS::SearchBResponse>::Create(channel_.get(), cq, rpcmethod_getDataB_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::MyGrpcS::SearchBResponse>* SearchService::Stub::PrepareAsyncgetDataBRaw(::grpc::ClientContext* context, const ::MyGrpcS::SearchBRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::MyGrpcS::SearchBResponse>::Create(channel_.get(), cq, rpcmethod_getDataB_, context, request, false);
}

::grpc::Status SearchService::Stub::setDataB(::grpc::ClientContext* context, const ::MyGrpcS::SearchBResponse& request, ::MyGrpcS::SearchBRequest* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_setDataB_, context, request, response);
}

void SearchService::Stub::experimental_async::setDataB(::grpc::ClientContext* context, const ::MyGrpcS::SearchBResponse* request, ::MyGrpcS::SearchBRequest* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_setDataB_, context, request, response, std::move(f));
}

void SearchService::Stub::experimental_async::setDataB(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::MyGrpcS::SearchBRequest* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_setDataB_, context, request, response, std::move(f));
}

void SearchService::Stub::experimental_async::setDataB(::grpc::ClientContext* context, const ::MyGrpcS::SearchBResponse* request, ::MyGrpcS::SearchBRequest* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_setDataB_, context, request, response, reactor);
}

void SearchService::Stub::experimental_async::setDataB(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::MyGrpcS::SearchBRequest* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_setDataB_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::MyGrpcS::SearchBRequest>* SearchService::Stub::AsyncsetDataBRaw(::grpc::ClientContext* context, const ::MyGrpcS::SearchBResponse& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::MyGrpcS::SearchBRequest>::Create(channel_.get(), cq, rpcmethod_setDataB_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::MyGrpcS::SearchBRequest>* SearchService::Stub::PrepareAsyncsetDataBRaw(::grpc::ClientContext* context, const ::MyGrpcS::SearchBResponse& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::MyGrpcS::SearchBRequest>::Create(channel_.get(), cq, rpcmethod_setDataB_, context, request, false);
}

::grpc::ClientReader< ::MyGrpcS::StreamResponse>* SearchService::Stub::streamDataRaw(::grpc::ClientContext* context, const ::MyGrpcS::StreamRequest& request) {
  return ::grpc_impl::internal::ClientReaderFactory< ::MyGrpcS::StreamResponse>::Create(channel_.get(), rpcmethod_streamData_, context, request);
}

void SearchService::Stub::experimental_async::streamData(::grpc::ClientContext* context, ::MyGrpcS::StreamRequest* request, ::grpc::experimental::ClientReadReactor< ::MyGrpcS::StreamResponse>* reactor) {
  ::grpc_impl::internal::ClientCallbackReaderFactory< ::MyGrpcS::StreamResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_streamData_, context, request, reactor);
}

::grpc::ClientAsyncReader< ::MyGrpcS::StreamResponse>* SearchService::Stub::AsyncstreamDataRaw(::grpc::ClientContext* context, const ::MyGrpcS::StreamRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc_impl::internal::ClientAsyncReaderFactory< ::MyGrpcS::StreamResponse>::Create(channel_.get(), cq, rpcmethod_streamData_, context, request, true, tag);
}

::grpc::ClientAsyncReader< ::MyGrpcS::StreamResponse>* SearchService::Stub::PrepareAsyncstreamDataRaw(::grpc::ClientContext* context, const ::MyGrpcS::StreamRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncReaderFactory< ::MyGrpcS::StreamResponse>::Create(channel_.get(), cq, rpcmethod_streamData_, context, request, false, nullptr);
}

::grpc::ClientWriter< ::MyGrpcS::StreamRequest>* SearchService::Stub::ctreamDataRaw(::grpc::ClientContext* context, ::MyGrpcS::StreamResponse* response) {
  return ::grpc_impl::internal::ClientWriterFactory< ::MyGrpcS::StreamRequest>::Create(channel_.get(), rpcmethod_ctreamData_, context, response);
}

void SearchService::Stub::experimental_async::ctreamData(::grpc::ClientContext* context, ::MyGrpcS::StreamResponse* response, ::grpc::experimental::ClientWriteReactor< ::MyGrpcS::StreamRequest>* reactor) {
  ::grpc_impl::internal::ClientCallbackWriterFactory< ::MyGrpcS::StreamRequest>::Create(stub_->channel_.get(), stub_->rpcmethod_ctreamData_, context, response, reactor);
}

::grpc::ClientAsyncWriter< ::MyGrpcS::StreamRequest>* SearchService::Stub::AsyncctreamDataRaw(::grpc::ClientContext* context, ::MyGrpcS::StreamResponse* response, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc_impl::internal::ClientAsyncWriterFactory< ::MyGrpcS::StreamRequest>::Create(channel_.get(), cq, rpcmethod_ctreamData_, context, response, true, tag);
}

::grpc::ClientAsyncWriter< ::MyGrpcS::StreamRequest>* SearchService::Stub::PrepareAsyncctreamDataRaw(::grpc::ClientContext* context, ::MyGrpcS::StreamResponse* response, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncWriterFactory< ::MyGrpcS::StreamRequest>::Create(channel_.get(), cq, rpcmethod_ctreamData_, context, response, false, nullptr);
}

::grpc::ClientReaderWriter< ::MyGrpcS::StreamRequest, ::MyGrpcS::StreamResponse>* SearchService::Stub::scstreamDataRaw(::grpc::ClientContext* context) {
  return ::grpc_impl::internal::ClientReaderWriterFactory< ::MyGrpcS::StreamRequest, ::MyGrpcS::StreamResponse>::Create(channel_.get(), rpcmethod_scstreamData_, context);
}

void SearchService::Stub::experimental_async::scstreamData(::grpc::ClientContext* context, ::grpc::experimental::ClientBidiReactor< ::MyGrpcS::StreamRequest,::MyGrpcS::StreamResponse>* reactor) {
  ::grpc_impl::internal::ClientCallbackReaderWriterFactory< ::MyGrpcS::StreamRequest,::MyGrpcS::StreamResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_scstreamData_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::MyGrpcS::StreamRequest, ::MyGrpcS::StreamResponse>* SearchService::Stub::AsyncscstreamDataRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc_impl::internal::ClientAsyncReaderWriterFactory< ::MyGrpcS::StreamRequest, ::MyGrpcS::StreamResponse>::Create(channel_.get(), cq, rpcmethod_scstreamData_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::MyGrpcS::StreamRequest, ::MyGrpcS::StreamResponse>* SearchService::Stub::PrepareAsyncscstreamDataRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncReaderWriterFactory< ::MyGrpcS::StreamRequest, ::MyGrpcS::StreamResponse>::Create(channel_.get(), cq, rpcmethod_scstreamData_, context, false, nullptr);
}

SearchService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      SearchService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< SearchService::Service, ::MyGrpcS::SearchARequest, ::MyGrpcS::SearchAResponse>(
          [](SearchService::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::MyGrpcS::SearchARequest* req,
             ::MyGrpcS::SearchAResponse* resp) {
               return service->getDataA(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      SearchService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< SearchService::Service, ::MyGrpcS::SearchAResponse, ::MyGrpcS::SearchARequest>(
          [](SearchService::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::MyGrpcS::SearchAResponse* req,
             ::MyGrpcS::SearchARequest* resp) {
               return service->setDataA(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      SearchService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< SearchService::Service, ::MyGrpcS::SearchBRequest, ::MyGrpcS::SearchBResponse>(
          [](SearchService::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::MyGrpcS::SearchBRequest* req,
             ::MyGrpcS::SearchBResponse* resp) {
               return service->getDataB(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      SearchService_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< SearchService::Service, ::MyGrpcS::SearchBResponse, ::MyGrpcS::SearchBRequest>(
          [](SearchService::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::MyGrpcS::SearchBResponse* req,
             ::MyGrpcS::SearchBRequest* resp) {
               return service->setDataB(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      SearchService_method_names[4],
      ::grpc::internal::RpcMethod::SERVER_STREAMING,
      new ::grpc::internal::ServerStreamingHandler< SearchService::Service, ::MyGrpcS::StreamRequest, ::MyGrpcS::StreamResponse>(
          [](SearchService::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::MyGrpcS::StreamRequest* req,
             ::grpc_impl::ServerWriter<::MyGrpcS::StreamResponse>* writer) {
               return service->streamData(ctx, req, writer);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      SearchService_method_names[5],
      ::grpc::internal::RpcMethod::CLIENT_STREAMING,
      new ::grpc::internal::ClientStreamingHandler< SearchService::Service, ::MyGrpcS::StreamRequest, ::MyGrpcS::StreamResponse>(
          [](SearchService::Service* service,
             ::grpc_impl::ServerContext* ctx,
             ::grpc_impl::ServerReader<::MyGrpcS::StreamRequest>* reader,
             ::MyGrpcS::StreamResponse* resp) {
               return service->ctreamData(ctx, reader, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      SearchService_method_names[6],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< SearchService::Service, ::MyGrpcS::StreamRequest, ::MyGrpcS::StreamResponse>(
          [](SearchService::Service* service,
             ::grpc_impl::ServerContext* ctx,
             ::grpc_impl::ServerReaderWriter<::MyGrpcS::StreamResponse,
             ::MyGrpcS::StreamRequest>* stream) {
               return service->scstreamData(ctx, stream);
             }, this)));
}

SearchService::Service::~Service() {
}

::grpc::Status SearchService::Service::getDataA(::grpc::ServerContext* context, const ::MyGrpcS::SearchARequest* request, ::MyGrpcS::SearchAResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status SearchService::Service::setDataA(::grpc::ServerContext* context, const ::MyGrpcS::SearchAResponse* request, ::MyGrpcS::SearchARequest* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status SearchService::Service::getDataB(::grpc::ServerContext* context, const ::MyGrpcS::SearchBRequest* request, ::MyGrpcS::SearchBResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status SearchService::Service::setDataB(::grpc::ServerContext* context, const ::MyGrpcS::SearchBResponse* request, ::MyGrpcS::SearchBRequest* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status SearchService::Service::streamData(::grpc::ServerContext* context, const ::MyGrpcS::StreamRequest* request, ::grpc::ServerWriter< ::MyGrpcS::StreamResponse>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status SearchService::Service::ctreamData(::grpc::ServerContext* context, ::grpc::ServerReader< ::MyGrpcS::StreamRequest>* reader, ::MyGrpcS::StreamResponse* response) {
  (void) context;
  (void) reader;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status SearchService::Service::scstreamData(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::MyGrpcS::StreamResponse, ::MyGrpcS::StreamRequest>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace MyGrpcS

