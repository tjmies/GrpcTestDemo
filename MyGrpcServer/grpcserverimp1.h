#ifndef GRPCSERVERIMP1_H
#define GRPCSERVERIMP1_H
#include <string>
#include <list>

#include <grpcpp/grpcpp.h>

#include "example.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::ServerWriter;
using grpc::ServerReader;

using MyGrpcS::SearchARequest;
using MyGrpcS::SearchAResponse;
using MyGrpcS::SearchBRequest;
using MyGrpcS::SearchBResponse;
using MyGrpcS::StreamRequest;
using MyGrpcS::StreamResponse;
using grpc::WriteOptions;

using namespace MyGrpcS;

using namespace  std;
extern string m_sSetA;
extern string m_sSetB;
extern string m_sGetA;
extern string m_sGetB;

template <class W,class T>
struct GrpcStream{
    int isclosed = 0;
    W* request;
    T* response;
    grpc::ServerWriter<T> * writer;
    grpc::ServerReader<W> *reader;
};

typedef list<GrpcStream<StreamRequest,StreamResponse>*> listStream;
extern listStream *listStreams;


class GrpcServerImp1 final:public SearchService::Service
{
public:
     ::grpc::Status getDataA(::grpc::ServerContext* context, const ::MyGrpcS::SearchARequest* request, ::MyGrpcS::SearchAResponse* response)override;
     ::grpc::Status setDataA(::grpc::ServerContext* context, const ::MyGrpcS::SearchAResponse* request, ::MyGrpcS::SearchARequest* response)override;
     ::grpc::Status getDataB(::grpc::ServerContext* context, const ::MyGrpcS::SearchBRequest* request, ::MyGrpcS::SearchBResponse* response)override;
     ::grpc::Status setDataB(::grpc::ServerContext* context, const ::MyGrpcS::SearchBResponse* request, ::MyGrpcS::SearchBRequest* response)override;
     ::grpc::Status streamData(::grpc::ServerContext* context, const ::MyGrpcS::StreamRequest* request, ::grpc::ServerWriter< ::MyGrpcS::StreamResponse>* writer)override;
     ::grpc::Status ctreamData(::grpc::ServerContext* context, ::grpc::ServerReader< ::MyGrpcS::StreamRequest>* reader, ::MyGrpcS::StreamResponse* response)override;
     ::grpc::Status scstreamData(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::MyGrpcS::StreamResponse, ::MyGrpcS::StreamRequest>* stream)override;

};

#endif // GRPCSERVERIMP1_H
