#ifndef DATATHREAD_H
#define DATATHREAD_H

#include <QThread>
#include <QTimer>
#include <QProgressBar>
#include <QProcess>
#include <QDebug>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include "com.h"
#include "sendaction.h"

#define QSTYLE_PROGRESS_BATT_CONTROL "QProgressBar {border: 2px solid grey;border-radius: 5px; text-align: center; background-image:  url(:/null); } QProgressBar::chunk {background-color:  rgb(146, 255, 116);width: 20px;}"

class DataThread : public QThread
{
     Q_OBJECT

public:
    DataThread(QProgressBar *bc, QProgressBar *br);
    void closeServer();

private:
    QProgressBar *batteryControl, *batteryRobot;        
    QTcpServer *server;
    QTcpSocket *socket;
    int valueTest, robotBattery;
    bool newMessage;

public slots:
    void update();
    void newConnection();
    void startRead();
    void disconnected();
    void stop();



protected:
    void run();

};

#endif // DATATHREAD_H
