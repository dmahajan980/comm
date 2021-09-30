// @generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: tunnelbroker.proto
#ifndef GRPC_tunnelbroker_2eproto__INCLUDED
#define GRPC_tunnelbroker_2eproto__INCLUDED

#include "tunnelbroker.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace tunnelbroker {

class TunnelBrokerService final {
 public:
  static constexpr char const* service_full_name() {
    return "tunnelbroker.TunnelBrokerService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status CheckIfPrimaryDeviceOnline(::grpc::ClientContext* context, const ::tunnelbroker::CheckRequest& request, ::tunnelbroker::CheckResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::tunnelbroker::CheckResponse>> AsyncCheckIfPrimaryDeviceOnline(::grpc::ClientContext* context, const ::tunnelbroker::CheckRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::tunnelbroker::CheckResponse>>(AsyncCheckIfPrimaryDeviceOnlineRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::tunnelbroker::CheckResponse>> PrepareAsyncCheckIfPrimaryDeviceOnline(::grpc::ClientContext* context, const ::tunnelbroker::CheckRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::tunnelbroker::CheckResponse>>(PrepareAsyncCheckIfPrimaryDeviceOnlineRaw(context, request, cq));
    }
    virtual ::grpc::Status BecomeNewPrimaryDevice(::grpc::ClientContext* context, const ::tunnelbroker::NewPrimaryRequest& request, ::tunnelbroker::NewPrimaryResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::tunnelbroker::NewPrimaryResponse>> AsyncBecomeNewPrimaryDevice(::grpc::ClientContext* context, const ::tunnelbroker::NewPrimaryRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::tunnelbroker::NewPrimaryResponse>>(AsyncBecomeNewPrimaryDeviceRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::tunnelbroker::NewPrimaryResponse>> PrepareAsyncBecomeNewPrimaryDevice(::grpc::ClientContext* context, const ::tunnelbroker::NewPrimaryRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::tunnelbroker::NewPrimaryResponse>>(PrepareAsyncBecomeNewPrimaryDeviceRaw(context, request, cq));
    }
    virtual ::grpc::Status SendPong(::grpc::ClientContext* context, const ::tunnelbroker::PongRequest& request, ::tunnelbroker::PongResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::tunnelbroker::PongResponse>> AsyncSendPong(::grpc::ClientContext* context, const ::tunnelbroker::PongRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::tunnelbroker::PongResponse>>(AsyncSendPongRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::tunnelbroker::PongResponse>> PrepareAsyncSendPong(::grpc::ClientContext* context, const ::tunnelbroker::PongRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::tunnelbroker::PongResponse>>(PrepareAsyncSendPongRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void CheckIfPrimaryDeviceOnline(::grpc::ClientContext* context, const ::tunnelbroker::CheckRequest* request, ::tunnelbroker::CheckResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void CheckIfPrimaryDeviceOnline(::grpc::ClientContext* context, const ::tunnelbroker::CheckRequest* request, ::tunnelbroker::CheckResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      virtual void BecomeNewPrimaryDevice(::grpc::ClientContext* context, const ::tunnelbroker::NewPrimaryRequest* request, ::tunnelbroker::NewPrimaryResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void BecomeNewPrimaryDevice(::grpc::ClientContext* context, const ::tunnelbroker::NewPrimaryRequest* request, ::tunnelbroker::NewPrimaryResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      virtual void SendPong(::grpc::ClientContext* context, const ::tunnelbroker::PongRequest* request, ::tunnelbroker::PongResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void SendPong(::grpc::ClientContext* context, const ::tunnelbroker::PongRequest* request, ::tunnelbroker::PongResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::tunnelbroker::CheckResponse>* AsyncCheckIfPrimaryDeviceOnlineRaw(::grpc::ClientContext* context, const ::tunnelbroker::CheckRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::tunnelbroker::CheckResponse>* PrepareAsyncCheckIfPrimaryDeviceOnlineRaw(::grpc::ClientContext* context, const ::tunnelbroker::CheckRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::tunnelbroker::NewPrimaryResponse>* AsyncBecomeNewPrimaryDeviceRaw(::grpc::ClientContext* context, const ::tunnelbroker::NewPrimaryRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::tunnelbroker::NewPrimaryResponse>* PrepareAsyncBecomeNewPrimaryDeviceRaw(::grpc::ClientContext* context, const ::tunnelbroker::NewPrimaryRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::tunnelbroker::PongResponse>* AsyncSendPongRaw(::grpc::ClientContext* context, const ::tunnelbroker::PongRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::tunnelbroker::PongResponse>* PrepareAsyncSendPongRaw(::grpc::ClientContext* context, const ::tunnelbroker::PongRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status CheckIfPrimaryDeviceOnline(::grpc::ClientContext* context, const ::tunnelbroker::CheckRequest& request, ::tunnelbroker::CheckResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::tunnelbroker::CheckResponse>> AsyncCheckIfPrimaryDeviceOnline(::grpc::ClientContext* context, const ::tunnelbroker::CheckRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::tunnelbroker::CheckResponse>>(AsyncCheckIfPrimaryDeviceOnlineRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::tunnelbroker::CheckResponse>> PrepareAsyncCheckIfPrimaryDeviceOnline(::grpc::ClientContext* context, const ::tunnelbroker::CheckRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::tunnelbroker::CheckResponse>>(PrepareAsyncCheckIfPrimaryDeviceOnlineRaw(context, request, cq));
    }
    ::grpc::Status BecomeNewPrimaryDevice(::grpc::ClientContext* context, const ::tunnelbroker::NewPrimaryRequest& request, ::tunnelbroker::NewPrimaryResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::tunnelbroker::NewPrimaryResponse>> AsyncBecomeNewPrimaryDevice(::grpc::ClientContext* context, const ::tunnelbroker::NewPrimaryRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::tunnelbroker::NewPrimaryResponse>>(AsyncBecomeNewPrimaryDeviceRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::tunnelbroker::NewPrimaryResponse>> PrepareAsyncBecomeNewPrimaryDevice(::grpc::ClientContext* context, const ::tunnelbroker::NewPrimaryRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::tunnelbroker::NewPrimaryResponse>>(PrepareAsyncBecomeNewPrimaryDeviceRaw(context, request, cq));
    }
    ::grpc::Status SendPong(::grpc::ClientContext* context, const ::tunnelbroker::PongRequest& request, ::tunnelbroker::PongResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::tunnelbroker::PongResponse>> AsyncSendPong(::grpc::ClientContext* context, const ::tunnelbroker::PongRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::tunnelbroker::PongResponse>>(AsyncSendPongRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::tunnelbroker::PongResponse>> PrepareAsyncSendPong(::grpc::ClientContext* context, const ::tunnelbroker::PongRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::tunnelbroker::PongResponse>>(PrepareAsyncSendPongRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void CheckIfPrimaryDeviceOnline(::grpc::ClientContext* context, const ::tunnelbroker::CheckRequest* request, ::tunnelbroker::CheckResponse* response, std::function<void(::grpc::Status)>) override;
      void CheckIfPrimaryDeviceOnline(::grpc::ClientContext* context, const ::tunnelbroker::CheckRequest* request, ::tunnelbroker::CheckResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
      void BecomeNewPrimaryDevice(::grpc::ClientContext* context, const ::tunnelbroker::NewPrimaryRequest* request, ::tunnelbroker::NewPrimaryResponse* response, std::function<void(::grpc::Status)>) override;
      void BecomeNewPrimaryDevice(::grpc::ClientContext* context, const ::tunnelbroker::NewPrimaryRequest* request, ::tunnelbroker::NewPrimaryResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
      void SendPong(::grpc::ClientContext* context, const ::tunnelbroker::PongRequest* request, ::tunnelbroker::PongResponse* response, std::function<void(::grpc::Status)>) override;
      void SendPong(::grpc::ClientContext* context, const ::tunnelbroker::PongRequest* request, ::tunnelbroker::PongResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::tunnelbroker::CheckResponse>* AsyncCheckIfPrimaryDeviceOnlineRaw(::grpc::ClientContext* context, const ::tunnelbroker::CheckRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::tunnelbroker::CheckResponse>* PrepareAsyncCheckIfPrimaryDeviceOnlineRaw(::grpc::ClientContext* context, const ::tunnelbroker::CheckRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::tunnelbroker::NewPrimaryResponse>* AsyncBecomeNewPrimaryDeviceRaw(::grpc::ClientContext* context, const ::tunnelbroker::NewPrimaryRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::tunnelbroker::NewPrimaryResponse>* PrepareAsyncBecomeNewPrimaryDeviceRaw(::grpc::ClientContext* context, const ::tunnelbroker::NewPrimaryRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::tunnelbroker::PongResponse>* AsyncSendPongRaw(::grpc::ClientContext* context, const ::tunnelbroker::PongRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::tunnelbroker::PongResponse>* PrepareAsyncSendPongRaw(::grpc::ClientContext* context, const ::tunnelbroker::PongRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_CheckIfPrimaryDeviceOnline_;
    const ::grpc::internal::RpcMethod rpcmethod_BecomeNewPrimaryDevice_;
    const ::grpc::internal::RpcMethod rpcmethod_SendPong_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status CheckIfPrimaryDeviceOnline(::grpc::ServerContext* context, const ::tunnelbroker::CheckRequest* request, ::tunnelbroker::CheckResponse* response);
    virtual ::grpc::Status BecomeNewPrimaryDevice(::grpc::ServerContext* context, const ::tunnelbroker::NewPrimaryRequest* request, ::tunnelbroker::NewPrimaryResponse* response);
    virtual ::grpc::Status SendPong(::grpc::ServerContext* context, const ::tunnelbroker::PongRequest* request, ::tunnelbroker::PongResponse* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_CheckIfPrimaryDeviceOnline : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_CheckIfPrimaryDeviceOnline() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_CheckIfPrimaryDeviceOnline() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CheckIfPrimaryDeviceOnline(::grpc::ServerContext* /*context*/, const ::tunnelbroker::CheckRequest* /*request*/, ::tunnelbroker::CheckResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestCheckIfPrimaryDeviceOnline(::grpc::ServerContext* context, ::tunnelbroker::CheckRequest* request, ::grpc::ServerAsyncResponseWriter< ::tunnelbroker::CheckResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_BecomeNewPrimaryDevice : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_BecomeNewPrimaryDevice() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_BecomeNewPrimaryDevice() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status BecomeNewPrimaryDevice(::grpc::ServerContext* /*context*/, const ::tunnelbroker::NewPrimaryRequest* /*request*/, ::tunnelbroker::NewPrimaryResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestBecomeNewPrimaryDevice(::grpc::ServerContext* context, ::tunnelbroker::NewPrimaryRequest* request, ::grpc::ServerAsyncResponseWriter< ::tunnelbroker::NewPrimaryResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_SendPong : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_SendPong() {
      ::grpc::Service::MarkMethodAsync(2);
    }
    ~WithAsyncMethod_SendPong() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendPong(::grpc::ServerContext* /*context*/, const ::tunnelbroker::PongRequest* /*request*/, ::tunnelbroker::PongResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSendPong(::grpc::ServerContext* context, ::tunnelbroker::PongRequest* request, ::grpc::ServerAsyncResponseWriter< ::tunnelbroker::PongResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_CheckIfPrimaryDeviceOnline<WithAsyncMethod_BecomeNewPrimaryDevice<WithAsyncMethod_SendPong<Service > > > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_CheckIfPrimaryDeviceOnline : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_CheckIfPrimaryDeviceOnline() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::tunnelbroker::CheckRequest, ::tunnelbroker::CheckResponse>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::tunnelbroker::CheckRequest* request, ::tunnelbroker::CheckResponse* response) { return this->CheckIfPrimaryDeviceOnline(context, request, response); }));}
    void SetMessageAllocatorFor_CheckIfPrimaryDeviceOnline(
        ::grpc::MessageAllocator< ::tunnelbroker::CheckRequest, ::tunnelbroker::CheckResponse>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::tunnelbroker::CheckRequest, ::tunnelbroker::CheckResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_CheckIfPrimaryDeviceOnline() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CheckIfPrimaryDeviceOnline(::grpc::ServerContext* /*context*/, const ::tunnelbroker::CheckRequest* /*request*/, ::tunnelbroker::CheckResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* CheckIfPrimaryDeviceOnline(
      ::grpc::CallbackServerContext* /*context*/, const ::tunnelbroker::CheckRequest* /*request*/, ::tunnelbroker::CheckResponse* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_BecomeNewPrimaryDevice : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_BecomeNewPrimaryDevice() {
      ::grpc::Service::MarkMethodCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::tunnelbroker::NewPrimaryRequest, ::tunnelbroker::NewPrimaryResponse>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::tunnelbroker::NewPrimaryRequest* request, ::tunnelbroker::NewPrimaryResponse* response) { return this->BecomeNewPrimaryDevice(context, request, response); }));}
    void SetMessageAllocatorFor_BecomeNewPrimaryDevice(
        ::grpc::MessageAllocator< ::tunnelbroker::NewPrimaryRequest, ::tunnelbroker::NewPrimaryResponse>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(1);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::tunnelbroker::NewPrimaryRequest, ::tunnelbroker::NewPrimaryResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_BecomeNewPrimaryDevice() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status BecomeNewPrimaryDevice(::grpc::ServerContext* /*context*/, const ::tunnelbroker::NewPrimaryRequest* /*request*/, ::tunnelbroker::NewPrimaryResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* BecomeNewPrimaryDevice(
      ::grpc::CallbackServerContext* /*context*/, const ::tunnelbroker::NewPrimaryRequest* /*request*/, ::tunnelbroker::NewPrimaryResponse* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_SendPong : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_SendPong() {
      ::grpc::Service::MarkMethodCallback(2,
          new ::grpc::internal::CallbackUnaryHandler< ::tunnelbroker::PongRequest, ::tunnelbroker::PongResponse>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::tunnelbroker::PongRequest* request, ::tunnelbroker::PongResponse* response) { return this->SendPong(context, request, response); }));}
    void SetMessageAllocatorFor_SendPong(
        ::grpc::MessageAllocator< ::tunnelbroker::PongRequest, ::tunnelbroker::PongResponse>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(2);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::tunnelbroker::PongRequest, ::tunnelbroker::PongResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_SendPong() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendPong(::grpc::ServerContext* /*context*/, const ::tunnelbroker::PongRequest* /*request*/, ::tunnelbroker::PongResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* SendPong(
      ::grpc::CallbackServerContext* /*context*/, const ::tunnelbroker::PongRequest* /*request*/, ::tunnelbroker::PongResponse* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_CheckIfPrimaryDeviceOnline<WithCallbackMethod_BecomeNewPrimaryDevice<WithCallbackMethod_SendPong<Service > > > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_CheckIfPrimaryDeviceOnline : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_CheckIfPrimaryDeviceOnline() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_CheckIfPrimaryDeviceOnline() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CheckIfPrimaryDeviceOnline(::grpc::ServerContext* /*context*/, const ::tunnelbroker::CheckRequest* /*request*/, ::tunnelbroker::CheckResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_BecomeNewPrimaryDevice : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_BecomeNewPrimaryDevice() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_BecomeNewPrimaryDevice() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status BecomeNewPrimaryDevice(::grpc::ServerContext* /*context*/, const ::tunnelbroker::NewPrimaryRequest* /*request*/, ::tunnelbroker::NewPrimaryResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_SendPong : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_SendPong() {
      ::grpc::Service::MarkMethodGeneric(2);
    }
    ~WithGenericMethod_SendPong() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendPong(::grpc::ServerContext* /*context*/, const ::tunnelbroker::PongRequest* /*request*/, ::tunnelbroker::PongResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_CheckIfPrimaryDeviceOnline : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_CheckIfPrimaryDeviceOnline() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_CheckIfPrimaryDeviceOnline() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CheckIfPrimaryDeviceOnline(::grpc::ServerContext* /*context*/, const ::tunnelbroker::CheckRequest* /*request*/, ::tunnelbroker::CheckResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestCheckIfPrimaryDeviceOnline(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_BecomeNewPrimaryDevice : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_BecomeNewPrimaryDevice() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_BecomeNewPrimaryDevice() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status BecomeNewPrimaryDevice(::grpc::ServerContext* /*context*/, const ::tunnelbroker::NewPrimaryRequest* /*request*/, ::tunnelbroker::NewPrimaryResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestBecomeNewPrimaryDevice(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_SendPong : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_SendPong() {
      ::grpc::Service::MarkMethodRaw(2);
    }
    ~WithRawMethod_SendPong() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendPong(::grpc::ServerContext* /*context*/, const ::tunnelbroker::PongRequest* /*request*/, ::tunnelbroker::PongResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSendPong(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_CheckIfPrimaryDeviceOnline : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_CheckIfPrimaryDeviceOnline() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->CheckIfPrimaryDeviceOnline(context, request, response); }));
    }
    ~WithRawCallbackMethod_CheckIfPrimaryDeviceOnline() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CheckIfPrimaryDeviceOnline(::grpc::ServerContext* /*context*/, const ::tunnelbroker::CheckRequest* /*request*/, ::tunnelbroker::CheckResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* CheckIfPrimaryDeviceOnline(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_BecomeNewPrimaryDevice : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_BecomeNewPrimaryDevice() {
      ::grpc::Service::MarkMethodRawCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->BecomeNewPrimaryDevice(context, request, response); }));
    }
    ~WithRawCallbackMethod_BecomeNewPrimaryDevice() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status BecomeNewPrimaryDevice(::grpc::ServerContext* /*context*/, const ::tunnelbroker::NewPrimaryRequest* /*request*/, ::tunnelbroker::NewPrimaryResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* BecomeNewPrimaryDevice(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_SendPong : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_SendPong() {
      ::grpc::Service::MarkMethodRawCallback(2,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->SendPong(context, request, response); }));
    }
    ~WithRawCallbackMethod_SendPong() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendPong(::grpc::ServerContext* /*context*/, const ::tunnelbroker::PongRequest* /*request*/, ::tunnelbroker::PongResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* SendPong(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_CheckIfPrimaryDeviceOnline : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_CheckIfPrimaryDeviceOnline() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::tunnelbroker::CheckRequest, ::tunnelbroker::CheckResponse>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::tunnelbroker::CheckRequest, ::tunnelbroker::CheckResponse>* streamer) {
                       return this->StreamedCheckIfPrimaryDeviceOnline(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_CheckIfPrimaryDeviceOnline() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status CheckIfPrimaryDeviceOnline(::grpc::ServerContext* /*context*/, const ::tunnelbroker::CheckRequest* /*request*/, ::tunnelbroker::CheckResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedCheckIfPrimaryDeviceOnline(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::tunnelbroker::CheckRequest,::tunnelbroker::CheckResponse>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_BecomeNewPrimaryDevice : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_BecomeNewPrimaryDevice() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler<
          ::tunnelbroker::NewPrimaryRequest, ::tunnelbroker::NewPrimaryResponse>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::tunnelbroker::NewPrimaryRequest, ::tunnelbroker::NewPrimaryResponse>* streamer) {
                       return this->StreamedBecomeNewPrimaryDevice(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_BecomeNewPrimaryDevice() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status BecomeNewPrimaryDevice(::grpc::ServerContext* /*context*/, const ::tunnelbroker::NewPrimaryRequest* /*request*/, ::tunnelbroker::NewPrimaryResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedBecomeNewPrimaryDevice(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::tunnelbroker::NewPrimaryRequest,::tunnelbroker::NewPrimaryResponse>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_SendPong : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_SendPong() {
      ::grpc::Service::MarkMethodStreamed(2,
        new ::grpc::internal::StreamedUnaryHandler<
          ::tunnelbroker::PongRequest, ::tunnelbroker::PongResponse>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::tunnelbroker::PongRequest, ::tunnelbroker::PongResponse>* streamer) {
                       return this->StreamedSendPong(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_SendPong() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status SendPong(::grpc::ServerContext* /*context*/, const ::tunnelbroker::PongRequest* /*request*/, ::tunnelbroker::PongResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedSendPong(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::tunnelbroker::PongRequest,::tunnelbroker::PongResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_CheckIfPrimaryDeviceOnline<WithStreamedUnaryMethod_BecomeNewPrimaryDevice<WithStreamedUnaryMethod_SendPong<Service > > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_CheckIfPrimaryDeviceOnline<WithStreamedUnaryMethod_BecomeNewPrimaryDevice<WithStreamedUnaryMethod_SendPong<Service > > > StreamedService;
};

}  // namespace tunnelbroker


#endif  // GRPC_tunnelbroker_2eproto__INCLUDED