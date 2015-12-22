#ifndef DATATHREAD_H
#define DATATHREAD_H

#include <QThread>
#include <QTimer>
#include <QProgressBar>
#include <QProcess>
#include <QDebug>
#include <QObject>

#include "com.h"
#include "sendaction.h"

#define QSTYLE_PROGRESS_BATT_CONTROL "QProgressBar {border: 2px solid grey;border-radius: 5px; text-align: center; background-image:  url(:/null); } QProgressBar::chunk {background-color:  rgb(146, 255, 116);width: 20px;}"

class DataThread : public QThread
{
     Q_OBJECT

public:
    DataThread(QProgressBar *bc, QProgressBar *br);

private:
    QTimer *timer;
    QProgressBar *batteryControl, *batteryRobot;
    QProcess procRun;
    int valueTest;    
    SendAction *sendAction;
    QString sendComando(QString comando);

public slots:
    void update();

protected:
    void run();

};

#endif // DATATHREAD_H
