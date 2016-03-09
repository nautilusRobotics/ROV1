#ifndef EXPORTTHREAD_H
#define EXPORTTHREAD_H


//#define QT_NO_DEBUG_OUTPUT
#include <QThread>
#include <QDir>
#include <QProcess>
#include <QDebug>


class ExportThread : public QThread
{
    Q_OBJECT
public:
    explicit ExportThread(QObject *parent = 0, QString file="", QString ext="", QString missionName="");
    void run();
    bool Stop;

private:
    QString file,ext,missionName;

signals:
    void saveFinish(void);
public slots:

};

#endif // EXPORTTHREAD_H
