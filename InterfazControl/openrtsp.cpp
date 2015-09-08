#include "openrtsp.h"
//#define DEBUG_OPENRTSP

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

#ifdef DEBUG_OPENRTSP
       qDebug() << run;
#endif
       procSave.start(run);
       emit isRecording(true);

   }
   else{
       isSaving=false;
       qDebug() << "Closing RTSP";
       numVideo++;
       QProcess kill;
       QString run= QString("sh rtsp_kill.sh %1").arg(procSave.pid()+1);

#ifdef DEBUG_OPENRTSP
       qDebug() << run;
#endif
       kill.start(run);
       kill.waitForFinished();
       kill.kill();

       emit isRecording(false);
   }
 }
