#include "mainwindow.h"
#include <QDebug>
#include <QString>
#include  <pthread.h>
#include <QElapsedTimer>

string m_sSetA="";
string m_sSetB="";
string m_sGetA="";
string m_sGetB="";

QMutex m_mutex;
pthread_t tt;
string  streamd ="";
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    UiShow();
    //m_pTimer = new QTimer();
   // connect(m_pTimer,&QTimer::timeout,this,&MainWindow::streamCheckRun);
   // m_pTimer->start(200);

   //pthread_create(&tt,nullptr,streamCheckRun,nullptr);
}

MainWindow::~MainWindow()
{


}


void MainWindow::UiShow()
{
    m_pWidget = new QWidget;
    setCentralWidget(m_pWidget);
    resize(400,300);

    m_pGetDA_But = new QPushButton("DataA",m_pWidget);
    m_pGetDB_But = new QPushButton("DataB",m_pWidget);
    m_pSetDA_But = new QPushButton("SetDA",m_pWidget);
    m_pSetDB_But = new QPushButton("SetDB",m_pWidget);
    m_pSetDA_Edit = new QTextEdit(m_pWidget);
    m_pSetDB_Edit = new QTextEdit(m_pWidget);
    m_pGetDA_Brower = new QTextBrowser(m_pWidget);
    m_pGetDB_Brower = new QTextBrowser(m_pWidget);
    //m_pStream_Edit = new QTextEdit(m_pWidget);


    m_pGetDA_But->setGeometry(100,0,90,40);
    m_pSetDA_But->setGeometry(0,0,90,40);
    m_pSetDB_But->setGeometry(200,0,90,40);
    m_pGetDB_But->setGeometry(300,0,90,40);

    m_pSetDA_Edit->setGeometry(0,50,90,180);
    m_pSetDB_Edit->setGeometry(200,50,90,180);
    m_pGetDA_Brower->setGeometry(100,50,90,180);
    m_pGetDB_Brower->setGeometry(300,50,90,180);
   // m_pStream_Edit->setGeometry(0,240,350,40);

    connect(m_pSetDA_But,&QPushButton::clicked,this,[&](){
        m_sSetA = m_pSetDA_Edit->toPlainText().toStdString();


    });
    connect(m_pGetDA_But,&QPushButton::clicked,this,[&](){
        m_pGetDA_Brower->setText(QString(m_sGetA.c_str()));
    });
    connect(m_pSetDB_But,&QPushButton::clicked,this,[&](){
        m_sSetB = m_pSetDB_Edit->toPlainText().toStdString();
    });
    connect(m_pGetDB_But,&QPushButton::clicked,this,[&](){
        m_pGetDB_Brower->setText(QString(m_sGetB.c_str()));
    });
    connect(m_pSetDA_Edit,&QTextEdit::textChanged,[&](){
        m_sSetA = m_pSetDA_Edit->toPlainText().toStdString();
    });
    connect(m_pSetDB_Edit,&QTextEdit::textChanged,[&](){
        m_sSetB = m_pSetDB_Edit->toPlainText().toStdString();
    });

//    connect(m_pStream_Edit,&QTextEdit::textChanged,this,[&](){
//        streamd = m_pStream_Edit->toPlainText().toStdString();
//    });

}

void *streamCheckRun(void *args)
{
    auto delay=[](int num){
        QElapsedTimer t;
        t.start();
        while(t.elapsed()<num); //delay 200ms
    };

    while(1)
    {
        //qDebug()<<"change text";
        m_mutex.lock();

        listStream::iterator iter= listStreams->begin();
        for(;iter!= listStreams->end();)
        {

            MyGrpcS::StreamResponse *response = new MyGrpcS::StreamResponse;
            response->set_num(1);
            response->set_data(streamd);
            response->set_type("stream");

            GrpcStream<MyGrpcS::StreamRequest,MyGrpcS::StreamResponse> *stream = *iter;
            ::grpc::WriteOptions options;
            if(!stream->writer->Write(*response,options))
            {
                listStreams->erase(iter++);
                stream->isclosed = 1;
            }
            else
                iter++;

        }
        m_mutex.unlock();
        delay(200);
    }


}





