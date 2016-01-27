#include "openrtsp.h"


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
       QString run= QString("sh rtsp.sh %1 %2").arg(missionName).arg(numVideo);
       qDebug() << run; 
       procSave.start(run);
   }
   else{
       isSaving=false;
       qDebug() << "Closing RTSP";
       numVideo++;
       QProcess kill;
       QString run= QString("sh rtsp_kill.sh %1").arg(procSave.pid()+1);
       qDebug() << run;
       kill.start(run);
       kill.waitForFinished();
       kill.kill();
   }
 }


int openRTSP::getVideoCount(){
    return numVideo;
}
