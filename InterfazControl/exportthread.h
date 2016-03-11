#ifndef EXPORTTHREAD_H
#define EXPORTTHREAD_H



#include <QThread>
#include <QDir>
#include <QProcess>
#include <QDebug>
#define QT_NO_DEBUG_OUTPUT

class ExportThread : public QThread
{
    Q_OBJECT
public:
    explicit ExportThread(QObject *parent = 0, QString src="", QString dest="", QString missionName="");
    void run();
    bool Stop;

private:
    QString src,dest,missionName;

signals:
    void saveFinish(void);
public slots:

};

#endif // EXPORTTHREAD_H
