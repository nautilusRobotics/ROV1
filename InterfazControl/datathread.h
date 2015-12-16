#ifndef DATATHREAD_H
#define DATATHREAD_H

#include <QThread>
#include <QTimer>
#include <QProgressBar>
#include <QProcess>
#include <QDebug>
#include <QObject>

class DataThread : public QThread
{
     Q_OBJECT

public:
    DataThread(QProgressBar *bc);

private:
    QTimer *timer;
    QProgressBar *batteryControl;
    QProcess procRun;
    int valueTest;

public slots:
    void update();

protected:
    void run();

};

#endif // DATATHREAD_H
