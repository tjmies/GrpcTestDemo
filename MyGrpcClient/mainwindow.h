#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QApplication>
#include <QPushButton>
#include <QTextBrowser>
#include <QTextEdit>
#include <QMainWindow>
#include <QStatusBar>
#include <grpcpp/grpcpp.h>
#include <QElapsedTimer>
#include "example.grpc.pb.h"


using grpc::ClientAsyncResponseReader;
using grpc::ClientContext;
using grpc::CompletionQueue;
using grpc::Status;
using MyGrpcS::SearchService;
using grpc::Channel;
using grpc::ChannelArguments;
using grpc::ClientReader;




#include <string>
using namespace  std;
using namespace MyGrpcS;




class ExmapleClint{
public:
    explicit ExmapleClint(std::shared_ptr<grpc::Channel> channel):
        stub_(SearchService::NewStub(channel)){}

    std::unique_ptr<SearchService::Stub> stub_;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void clientRes();

    void UiShow();
    void delay(int num)
    {
        QElapsedTimer t;
        t.start();
        while(t.elapsed()<num); //delay 200ms
    }

private:
    QPushButton *m_pGetDA_But=nullptr;
    QPushButton *m_pSetDA_But=nullptr;
    QPushButton *m_pGetDB_But=nullptr;
    QPushButton *m_pSetDB_But=nullptr;

    QWidget *m_pWidget = nullptr;
    QTextEdit *m_pSetDA_Edit=nullptr;
    QTextEdit *m_pSetDB_Edit=nullptr;
    QTextBrowser *m_pGetDA_Brower=nullptr;
    QTextBrowser *m_pGetDB_Brower=nullptr;

    ExmapleClint *m_pClient=nullptr;

    string m_sSetA;
    string m_sSetB;
    string m_sGetA;
    string m_sGetB;

    QPushButton *m_pStreamBut = nullptr;
    QTextBrowser *m_pStream_Brower = nullptr;

    QPushButton *m_pCStreamBut = nullptr;
    QTextBrowser *m_pCStream_Brower = nullptr;
    QPushButton *m_pSCStreamBut = nullptr;
    QTextBrowser *m_pSCStream_Brower = nullptr;


};


#endif // MAINWINDOW_H
