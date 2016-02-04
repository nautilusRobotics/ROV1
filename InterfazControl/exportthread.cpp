#include "exportthread.h"

ExportThread::ExportThread(QObject *parent, QString file, QString ext, QString missionName) :
    QThread(parent)
{
    this->file=file;
    this->ext=ext;
    this->missionName=missionName;
}


void ExportThread::run(){

    sleep(5);
    if(!QDir(ext).exists())
        QDir().mkpath(ext);

    QProcess copyFiles;
    QString run=QString("cp -r %1 %2").arg(file).arg(ext);
    copyFiles.start(run);
    copyFiles.waitForFinished();
    copyFiles.close();


   QProcess fixFiles;
   QString fix=QString("rm %1%2/settings.ini %1%2/thumb.sh").arg(ext).arg(missionName);
   fixFiles.start(fix);
   fixFiles.waitForFinished();
   fixFiles.close();

   emit saveFinish();

}
