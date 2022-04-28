#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <string>
#include <QPushButton>
#include <QTextBrowser>
#include <QTextEdit>
#include <QTimer>
#include <QMutex>

#include "grpcserverimp1.h"
using namespace std;

extern string  streamd;
void *streamCheckRun(void *args);

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

   // void RunServer();

    void UiShow();

protected slots:
//    void streamCheckRun(void *args);

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

    QTextEdit *m_pStream_Edit=nullptr;

    QTimer *m_pTimer = nullptr;

   // static QMutex m_mutex;
};

#endif // MAINWINDOW_H
