#include <memory>
#include <QApplication>

//#define TEST
#define EXAMPLE

#ifdef EXAMPLE
    #include "mainwindow.h"
#endif


#ifdef TEST
#include "test.grpc.pb.h"
#include <string>
#include <grpcpp/grpcpp.h>

using namespace  std;
using grpc::ClientAsyncResponseReader;
using grpc::ClientContext;
using grpc::CompletionQueue;
using grpc::Status;
using grpc::Channel;
using grpc::ChannelArguments;


class exmapleClint{
public:
    exmapleClint(std::shared_ptr<grpc::Channel> channel):
        stub_(SearchSerive::NewStub(channel)){}


    void Search(string &user)
    {
        //send data to server
        SearchRequest request;
        request.set_request(user);
        request.set_event(10);
        SearchResponse response;
        ClientContext context;

        Status status = stub_->Search(&context,request,&response);
        if(status.ok())
        {
            std::cout<<"client recv response:"<<response.response()<<endl;
            std::cout<<"client recv event:"<<response.event()<<endl;
            std::cout<<"client msg:"<<response.meg()<<endl;

        }
        else
        {
            cout<<status.error_code()<<":"<<status.error_message()<<endl;
            std::cout<< "RPC FAIL";
        }
    }

private:
    std::unique_ptr<SearchSerive::Stub> stub_;
};
void clientRes()
{
    ChannelArguments args;
    //args.SetLoadBalancingPolicyName("roubd");
    exmapleClint client(grpc::CreateCustomChannel("127.0.0.1:50051", grpc::InsecureChannelCredentials(),args));
    string user("world");
    client.Search(user);


}
#endif
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#ifdef EXAMPLE
    MainWindow w;
    w.show();
#endif
#ifdef TEST
    clientRes();
 #endif
    return a.exec();
}
/*
 *
 * Copyright 2015 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/*
#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#ifdef BAZEL_BUILD
#include "examples/protos/helloworld.grpc.pb.h"
#else
#include "helloworld.grpc.pb.h"
#endif

using grpc::Channel;
using grpc::ChannelArguments;
using grpc::ClientContext;
using grpc::Status;
using helloworld::Greeter;
using helloworld::HelloReply;
using helloworld::HelloRequest;

class GreeterClient {
 public:
  GreeterClient(std::shared_ptr<Channel> channel)
      : stub_(Greeter::NewStub(channel)) {}

  // Assembles the client's payload, sends it and presents the response back
  // from the server.
  std::string SayHello(const std::string& user) {
    // Data we are sending to the server.
    HelloRequest request;
    request.set_name(user);

    // Container for the data we expect from the server.
    HelloReply reply;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    // The actual RPC.
    Status status = stub_->SayHello(&context, request, &reply);

    // Act upon its status.
    if (status.ok()) {
      return reply.message();
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed";
    }
  }

 private:
  std::unique_ptr<Greeter::Stub> stub_;
};

int main(int argc, char** argv) {
  // Instantiate the client. It requires a channel, out of which the actual RPCs
  // are created. This channel models a connection to an endpoint (in this case,
  // localhost at port 50051). We indicate that the channel isn't authenticated
  // (use of InsecureChannelCredentials()).
  ChannelArguments args;
  // Set the load balancing policy for the channel.
  args.SetLoadBalancingPolicyName("round_robin");
  GreeterClient greeter(grpc::CreateCustomChannel(
      "localhost:50051", grpc::InsecureChannelCredentials(), args));
  std::string user("world");
  std::string reply = greeter.SayHello(user);
  std::cout << "Greeter received: " << reply << std::endl;

  return 0;
}
*/
