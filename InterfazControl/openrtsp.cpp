#include "openrtsp.h"

extern QString createPath(QString path);

openRTSP::openRTSP(QObject *parent,QString missionName,int numVideo):
    QObject(parent)
{
  isSaving=false;

  this->missionName=missionName;
  this->numVideo=numVideo;
}


void openRTSP::saveVideo(){
   if(!isSaving){
       isSaving=true;
       QString run= QString("sh %1 %2 %3").arg(createPath("rtsp.sh")).arg(missionName).arg(numVideo);
       qDebug() << run; 
       procSave.start(run);
   }
   else{
       isSaving=false;
       qDebug() << "Closing RTSP";
       numVideo++;
       QProcess kill;
       QString run= QString("sh %1 %2").arg(createPath("rtsp_kill.sh")).arg(procSave.pid()+1);
       qDebug() << run;
       kill.start(run);
       kill.waitForFinished();
       kill.kill();
   }
 }


int openRTSP::getVideoCount(){
    return numVideo;
}
