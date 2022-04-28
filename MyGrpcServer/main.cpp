#include <string>
#include <memory>
#include <thread>
#include <QApplication>
//#define TEST
#define EXAMPLE

#ifdef EXAMPLE
    #include "mainwindow.h"
    #include "grpcserverimp1.h"


void runServer(){
    std::string server_addr("0.0.0.0:50051");
    GrpcServerImp1 service;

    ServerBuilder builder;
    builder.AddListeningPort(server_addr,grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout<<"server listening on"<<server_addr<<std::endl;
    server->Wait();
}
#endif


#ifdef TEST
#include <grpcpp/grpcpp.h>

#include "test.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::ServerWriter;
using grpc::ServerReader;

using namespace std;

class GrpcServerImp1 final:public SearchSerive::Service
{
public:

    ::grpc::Status Search(::grpc::ServerContext* context, const ::SearchRequest* request, ::SearchResponse* response)override{
        std::string prefix("server ");
        response->set_response(prefix+request->request());
        response->set_event(22);
        response->set_meg("i am handsome");
        cout<<"recv event:"<<request->event()<<" request:"<<request->request()<<endl;

        return Status::OK;
    }


};

void runServer(){
    std::string server_addr("0.0.0.0:50051");
    GrpcServerImp1 service;

    ServerBuilder builder;
    builder.AddListeningPort(server_addr,grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout<<"server listening on"<<server_addr<<std::endl;
    server->Wait();
}
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#ifdef EXAMPLE


    MainWindow w;
    w.show();
    thread th1(runServer);
   // th1.join();
#endif

#ifdef TEST
    runServer();
#endif
    return a.exec();
}
