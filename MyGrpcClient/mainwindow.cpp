#include "mainwindow.h"
#include <QDebug>
string m_sSetA="";
string m_sSetB="";
string m_sGetA="";
string m_sGetB="";
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    clientRes();
    m_sSetA="";
    m_sSetB="";
    m_sGetA="";
    m_sGetB="";

    UiShow();
}

MainWindow::~MainWindow()
{
}

void MainWindow::clientRes()
{
   ChannelArguments args;
   m_pClient = new ExmapleClint(grpc::CreateCustomChannel("127.0.0.1:50051", grpc::InsecureChannelCredentials(),args));
}
void MainWindow::UiShow()
{
    m_pWidget = new QWidget;
    setCentralWidget(m_pWidget);
    resize(800,300);

    m_pGetDA_But = new QPushButton("DataA",m_pWidget);
    m_pGetDB_But = new QPushButton("DataB",m_pWidget);
    m_pSetDA_But = new QPushButton("SetDA",m_pWidget);
    m_pSetDB_But = new QPushButton("SetDB",m_pWidget);
    m_pSetDA_Edit = new QTextEdit(m_pWidget);
    m_pSetDB_Edit = new QTextEdit(m_pWidget);
    m_pGetDA_Brower = new QTextBrowser(m_pWidget);
    m_pGetDB_Brower = new QTextBrowser(m_pWidget);

    m_pStream_Brower = new QTextBrowser(m_pWidget);
    m_pStreamBut = new QPushButton("stream",m_pWidget);
    m_pCStream_Brower = new QTextBrowser(m_pWidget);
    m_pCStreamBut = new QPushButton("Cstream",m_pWidget);
    m_pSCStream_Brower = new QTextBrowser(m_pWidget);
    m_pSCStreamBut = new QPushButton("SCstream",m_pWidget);

    m_pGetDA_But->setGeometry(100,0,90,40);
    m_pSetDA_But->setGeometry(0,0,90,40);
    m_pSetDB_But->setGeometry(200,0,90,40);
    m_pGetDB_But->setGeometry(300,0,90,40);

    m_pSetDA_Edit->setGeometry(0,50,90,180);
    m_pSetDB_Edit->setGeometry(200,50,90,180);
    m_pGetDA_Brower->setGeometry(100,50,90,180);
    m_pGetDB_Brower->setGeometry(300,50,90,180);

    m_pStreamBut->setGeometry(400,0,90,40);
    m_pStream_Brower->setGeometry(400,50,120,180);

    m_pCStreamBut->setGeometry(530,0,90,40);
    m_pCStream_Brower->setGeometry(530,50,120,180);
    m_pSCStreamBut->setGeometry(660,0,90,40);
    m_pSCStream_Brower->setGeometry(660,50,120,180);

    connect(m_pSetDA_But,&QPushButton::clicked,this,[&](){

        MyGrpcS::SearchARequest request;
        MyGrpcS::SearchAResponse response;
        ClientContext context;
        response.set_response(m_pSetDA_Edit->toPlainText().toStdString());
        response.set_statusr(1);

        Status status = m_pClient->stub_->setDataA(&context,response,&request);
        if(status.ok())
        {
            this->statusBar()->showMessage("set data A success");
        }
        else
        {
            cout<<status.error_code()<<":"<<status.error_message()<<endl;
            this->statusBar()->showMessage("RPC FAIL");
        }
    });
    connect(m_pGetDA_But,&QPushButton::clicked,this,[&](){
        MyGrpcS::SearchARequest request;
        MyGrpcS::SearchAResponse response;
        ClientContext context;
        request.set_request("A ");
        request.set_statusr(1);
        Status status = m_pClient->stub_->getDataA(&context,request,&response);
        if(status.ok())
        {
            string param1 = response.response();
            int param2 = response.statusr();
            m_pGetDA_Brower->setText(QString("Data A:%1 %2").arg(param1.c_str()).arg(param2));
        }
        else
        {
            cout<<status.error_code()<<":"<<status.error_message()<<endl;
            m_pGetDA_Brower->setText(QString("rpc failed"));
        }
    });
    connect(m_pSetDB_But,&QPushButton::clicked,this,[&](){
        MyGrpcS::SearchBRequest request;
        MyGrpcS::SearchBResponse response;
        ClientContext context;
        response.set_response(m_pSetDB_Edit->toPlainText().toStdString());
        response.set_statusr(1);

        Status status = m_pClient->stub_->setDataB(&context,response,&request);
        if(status.ok())
        {
            this->statusBar()->showMessage("set data B success");
        }
        else
        {
            cout<<status.error_code()<<":"<<status.error_message()<<endl;
            this->statusBar()->showMessage("RPC FAIL");
        }
    });
    connect(m_pGetDB_But,&QPushButton::clicked,this,[&](){
        MyGrpcS::SearchBRequest request;
        MyGrpcS::SearchBResponse response;
        ClientContext context;
        request.set_request("B ");
        request.set_statusr(1);
        Status status = m_pClient->stub_->getDataB(&context,request,&response);
        if(status.ok())
        {
            string param1 = response.response();
            int param2 = response.statusr();
            m_pGetDB_Brower->setText(QString("Data B:%1 %2").arg(param1.c_str()).arg(param2));
        }
        else
        {
            cout<<status.error_code()<<":"<<status.error_message()<<endl;
            m_pGetDB_Brower->setText(QString("rpc failed"));
        }
    });

    connect(m_pStreamBut,&QPushButton::clicked,this,[&](){
        ClientContext context;
        MyGrpcS::StreamRequest  request;
        request.set_mode(1);

        std::unique_ptr<grpc::ClientReader<MyGrpcS::StreamResponse>> reader = m_pClient->stub_->streamData(&context,request);
        MyGrpcS::StreamResponse response;
        int count = 0;
        while(1)
        {
            if(reader->Read(&response))
            {
                string data = response.data();
                string type= response.type();
                int num = response.num();
                QString cc = QString("data:%1 ").arg(data.c_str());
                QString tt = QString("type:%1 ").arg(type.c_str());
                QString ss = QString("num:%1 ").arg(num);
                if(m_pStream_Brower)
                {
                    m_pStream_Brower->insertPlainText(cc);
                    m_pStream_Brower->insertPlainText(tt);
                    m_pStream_Brower->insertPlainText(ss);

                    QApplication::processEvents();//while cause thread make   not plush ui

                }

                count = 0;
                cout<<"read success"<<endl;
            }
            else
                break;
        }
        cout<<"exit thread"<<endl;

    });
    connect(m_pSCStreamBut,&QPushButton::clicked,this,[&](){
        ClientContext context;
        MyGrpcS::StreamRequest  request;
        MyGrpcS::StreamResponse response;
        std::unique_ptr< ::grpc::ClientReaderWriter< ::MyGrpcS::StreamRequest, ::MyGrpcS::StreamResponse>> wRriter = m_pClient->stub_->scstreamData(&context);
        grpc::WriteOptions args;
        int count = 1;
        bool status = false;
        //send request
        while(1)
        {
            request.set_mode(count);
            if(wRriter->Write(request,args))
            {

            }
            else
            {
               break;
            }

            if(count >6)
                break;
            ++count;
        }
        wRriter->WritesDone();


        count =1;
        status = false;
        //get response
        while(wRriter->Read(&response))
        {
           string data = response.data();
           string type= response.type();
           int num = response.num();
           QString cc = QString("data:%1 ").arg(data.c_str());
           QString tt = QString("type:%1 ").arg(type.c_str());
           QString ss = QString("num:%1 ").arg(num);
           if(m_pSCStream_Brower)
           {
               m_pSCStream_Brower->insertPlainText(cc);
               m_pSCStream_Brower->insertPlainText(tt);
               m_pSCStream_Brower->insertPlainText(ss);

               QApplication::processEvents();//while cause thread make   not plush ui

           }

        }
        Status st = wRriter->Finish();
        if(!st.ok())
            cout<<"error:"<<st.error_message()<<endl;
        cout<<"exit thread"<<endl;

    });
    connect(m_pCStreamBut,&QPushButton::clicked,this,[&](){
        ClientContext context;
        MyGrpcS::StreamRequest  request;
        MyGrpcS::StreamResponse response;
        std::unique_ptr<grpc::ClientWriter<MyGrpcS::StreamRequest>> writer = m_pClient->stub_->ctreamData(&context,&response);
        grpc::WriteOptions args;
        int count = 1;
        bool status = false;
        //send request
        while(1)
        {
            request.set_mode(count);
            if(writer->Write(request,args))
            {

            }
            else
                break;
            if(count >6)
                break;
            ++count;
        }
        writer->WritesDone();//close write
        Status st = writer->Finish();
        if(!st.ok())
            cout<<"status error:"<<st.error_message()<<endl;


        //get response
        delay(200);
        if(response.data() !="")
        {
            string data = response.data();
            string type= response.type();
            int num = response.num();
            QString cc = QString("data:%1 ").arg(data.c_str());
            QString tt = QString("type:%1 ").arg(type.c_str());
            QString ss = QString("num:%1 ").arg(num);
            if(m_pCStream_Brower)
            {
                m_pCStream_Brower->insertPlainText(cc);
                m_pCStream_Brower->insertPlainText(tt);
                m_pCStream_Brower->insertPlainText(ss);

                QApplication::processEvents();//while cause thread make   not plush ui

            }
        }
        cout<<"exit thread"<<endl;

    });
}
