#include "exportthread.h"

ExportThread::ExportThread(QObject *parent, QString file, QString ext, QString missionName) :
    QThread(parent)
{
    this->file=file;
    this->ext=ext;
    this->missionName=missionName;
}


void ExportThread::run(){

    sleep(2);
    qDebug()<<"Export Animation Finished";
    if(!QDir(ext).exists())
        QDir().mkpath(ext);

    QProcess copyFiles;
    QString run=QString("cp -r %1 %2").arg(file).arg(ext);
     qDebug()<<"export command  "+run;
    copyFiles.start(run);
    copyFiles.waitForFinished();
    copyFiles.close();


   QProcess fixFiles;
   QString fix=QString("rm %1%2/settings.ini %1%2/thumb.sh").arg(ext).arg(missionName);
   qDebug()<<"export fix command  "+fix;
   fixFiles.start(fix);
   fixFiles.waitForFinished();
   fixFiles.close();

   emit saveFinish();

}
