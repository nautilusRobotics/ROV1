#ifndef SENDACTION_H
#define SENDACTION_H

//#define QT_NO_DEBUG_OUTPUT
#include <QWidget>
#include <QProcess>
#include <QDebug>
#include <QString>
#include "com.h"
#include <QTcpSocket>
#define ROBOT_IP "10.5.5.103"
#define ROBOT_PORT 50002

class SendAction : public QWidget
{
  Q_OBJECT

public:
    explicit SendAction(QWidget *parent = 0);
    ~SendAction();

private:
     QProcess procRun;
     QString robotIp;
     QString serverResp;
     volatile bool txServer;
     QTcpSocket * cliente;
     bool conection;

private slots:
     void readyRead();
     void disconnected();
     void connected();

public:
     QString sendComando(QString comando);
     bool isConnected();
     void conectClient();

signals:
     void offline();

};

#endif // SENDACTION_H
