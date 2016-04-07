#include "exportthread.h"

extern QString createPath(QString path);

ExportThread::ExportThread(QObject *parent, QString src, QString ext, QString missionName) :
    QThread(parent)
{
    this->src=src;
    this->dest=ext;
    this->missionName=missionName;
}


void ExportThread::run(){
    sleep(1);
    QProcess copyFiles;
    QString run=QString("copy.sh %1/*.png %2").arg(src).arg(dest);
    qDebug()<<"export command png "+run;
    copyFiles.start(createPath(run));
    copyFiles.waitForFinished();
    copyFiles.close();

    run=QString("copy.sh %1/*.mp4 %2").arg(src).arg(dest);
    qDebug()<<"export command mp4  "+run;
    copyFiles.start(createPath(run));
    copyFiles.waitForFinished();
    copyFiles.close();

    emit saveFinish();

}
