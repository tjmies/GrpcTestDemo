#include "grpcserverimp1.h"
#include <QElapsedTimer>

listStream *listStreams= new listStream;
grpc::Status GrpcServerImp1::getDataA(grpc::ServerContext *context, const SearchARequest *request, SearchAResponse *response)
{
    response->set_statusr(5);
    response->set_response(m_sSetA);

    return Status::OK;
}

grpc::Status GrpcServerImp1::setDataA(grpc::ServerContext *context, const SearchAResponse *request, SearchARequest *response)
{

   int status = response->statusr();
    m_sGetA = request->response();
    m_sGetA += "status:"+to_string(status);
     return Status::OK;
}

grpc::Status GrpcServerImp1::getDataB(grpc::ServerContext *context, const SearchBRequest *request, SearchBResponse *response)
{
    response->set_statusr(10);
    response->set_response(m_sSetB);

    return Status::OK;
}

grpc::Status GrpcServerImp1::setDataB(grpc::ServerContext *context, const SearchBResponse *request, SearchBRequest *response)
{
    int status = response->statusr();
     m_sGetB = request->response();
     m_sGetB += "status:"+to_string(status);

     return Status::OK;
}

grpc::Status GrpcServerImp1::streamData(grpc::ServerContext *context, const StreamRequest *request, ::grpc::ServerWriter<StreamResponse> *writer)
{
    cout<<"enter streamdata"<<endl;
    GrpcStream<StreamRequest,StreamResponse> *stream = new GrpcStream<StreamRequest,StreamResponse>;
    stream->isclosed = 0;
    stream->request = (StreamRequest*)request;
    stream->writer = writer;
    //listStreams->push_back(stream); //save once time request

    for(int i=1;i<6;i++)
    {
        MyGrpcS::StreamResponse *response = new MyGrpcS::StreamResponse;
        response->set_num(i);
        response->set_data("ssssssssssss"+to_string(i));
        response->set_type("server-rpc");
        ::grpc::WriteOptions options;
        stream->writer->Write(*response,options);
        delete response;
        response = nullptr;
    }

    delete  stream;
    stream = nullptr;
    return Status::OK;
}

grpc::Status GrpcServerImp1::ctreamData(grpc::ServerContext *context, ::grpc::ServerReader<StreamRequest> *reader, StreamResponse *response)
{
    //client rpc
    cout<<"client rpc"<<endl;
    GrpcStream<StreamRequest,StreamResponse> *stream = new GrpcStream<StreamRequest,StreamResponse>;
    stream->isclosed = 0;
    stream->response = response;
    stream->reader = reader;

    StreamRequest request;

    while(reader->Read(&request))
    {
        cout<<"mode:"<<request.mode()<<endl;
    }
    cout<<"end read"<<endl;
    //response
    response->set_num(1);
    response->set_data("server recv cilent request...");
    response->set_type("client-rpc");

    return Status::OK;


}

grpc::Status GrpcServerImp1::scstreamData(grpc::ServerContext *context, ::grpc::ServerReaderWriter<StreamResponse, StreamRequest> *stream)
{
    cout<<"server and client rpc"<<endl;

   StreamRequest request;
   StreamResponse response;
   int i=0;
   bool status = false;


   while(1)
   {
        //handle request
        if(stream->Read(&request))
        {
            cout<<"mode:"<<request.mode()<<endl;
        }
        else
        {
            status = true;
        }
        //handle response
        response.set_num(i);
        response.set_data("scscscscscsc"+to_string(i));
        response.set_type("server and clieny-rpc");
        ::grpc::WriteOptions options;
        stream->Write(response,options);
        i++;
        if(status)
            break;
   }
    return Status::OK;
}
