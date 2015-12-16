#include "missionwidget.h"
#define USER_DEBUG_SA
#define OFFLINE_SA

extern QString createPath(QString path);

MissionWidget::MissionWidget(QWidget *parent, QString mName, JoystickWidget *joystick,  Ui::NautilusCommander *gui) :
    QWidget(parent)
{
     this->missionName=mName;
     this->ui=gui;

     m_sSettingsFile = QString("%1/%2/settings.ini").arg(createPath("Missions")).arg(missionName);
     loadSettings();

     //Create Mission Folder.
     QString missionFolder=QString("%1/%2").arg(createPath("Missions")).arg(missionName);
     if(!QDir(missionFolder).exists()){
         QDir().mkdir(missionFolder);
     }


    /********************************  Joystick *****************************************************/

    this->joystick=joystick;

    connect(this->joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(axisEvent(QString,int)));
    connect(this->joystick,SIGNAL(joystickButtonEvent(QString, QGameControllerButtonEvent*)),this,SLOT(buttonEvent(QString,QGameControllerButtonEvent*)));

    rtsp=new openRTSP(0,missionName,numVideos);
    connect(this,SIGNAL(saveVideo()),rtsp,SLOT(saveVideo()));
    connect(rtsp,SIGNAL(isRecording(bool)),this,SLOT(updateRecording(bool)));

    robotIp="10.5.5.103 ";

    mplayer=ui->mplayerWG;
    statusErrorBox=ui->statusErrorBox;
    lblLightsOff=ui->label_switchOff;
    lblLightsOn=ui->label_switchOn;
    lblLightsOn->setVisible(false);
    islightsOn=false;
    righLeft=-1;
    upDown=-1;

    missionNameLabel=ui->lblMissionName;
    missionNameLabel->setText(missionName);

    batteryROVPB=ui->progressBattRov;    
    panCamera=ui->panCamera;
    tiltCamera=ui->tiltCamera;

    QStringList argumentos;
    argumentos.push_back("-fps");
    argumentos.push_back("30");
    mplayer->start(argumentos);
    mplayer->load("rtsp://admin:12345@10.5.5.110:554");

    dataThread=new DataThread(ui->progressBattControl);
    dataThread->start();
}


void MissionWidget::updatePlayerStatus(bool isConnected){

}

void MissionWidget::updateControlStatus(bool isConnected){

}

void MissionWidget::takeScreenshot(){
   qDebug()<<"ScreenShot-----------------------------------";
  /* QScreen *screen = QGuiApplication::primaryScreen();
   int x=this->x();
   int y=this->y();
   QPixmap pxm = screen->grabWindow(QApplication::desktop()->winId(),x+OFFSET_X,y+OFFSET_Y,SCREEN_SHOT_LR,SCREEN_SHOT_UD);

   QString picFolder=QString("%1/%2/pic_%3.jpeg").arg(createPath("Missions")).arg(missionName).arg(numPic);
   qDebug()<<picFolder;
   QFile file(picFolder);
   file.open(QIODevice::WriteOnly);
   pxm.save(&file, "JPG",100);
   numPic++;*/

   QProcess procRTSP;
   QString run=QString("sh rtspShot.sh %1/%2 pic_%3.png").arg(createPath("Missions")).arg(missionName).arg(numPic);
   qDebug()<<run;
   procRTSP.start(run);
   procRTSP.waitForFinished();
  //QString output( procRTSP.readAllStandardOutput());
   numPic++;
   qDebug()<<"--------------------------------------------";

}

void MissionWidget::updateRobotDepth(double value){

}

void MissionWidget::updateRecording(bool isRecording){
    if(isRecording){

    }
    else{

    }
}

void MissionWidget::handleButtonHome(){    

}

void MissionWidget::loadSettings(){
     QSettings settings(m_sSettingsFile, QSettings::NativeFormat);
     QString countVideos = settings.value("videos", "").toString();
     QString countPic = settings.value("pics", "").toString();
     qDebug()<<"Load Settigns videos:"+countVideos+" pics: "+countPic;


     if(!countVideos.compare("")){
          numPic=0;
          numVideos=0;

     }
     else{
         numPic=countPic.toInt();
         numVideos=countVideos.toInt();
     }

}

void MissionWidget::saveSettings()
{
     QSettings settings(m_sSettingsFile, QSettings::NativeFormat);
     if(rtsp->getVideoCount()!=numVideos)settings.setValue("isThumbnailed", false);
     QString countVideos=QString("%1").arg(rtsp->getVideoCount());
     QString countPic=QString("%1").arg(numPic);
     settings.setValue("videos", countVideos);
     settings.setValue("pics", countPic);
}

void MissionWidget::closeEvent(QCloseEvent *event) {
    saveSettings();
    event->accept();
}

void MissionWidget::axisEvent(QString axis,int value){
#ifdef USER_DEBUG_SA
     qDebug("axis  %d",value);
#endif

    if(axis== axis_right_vertical){
//        if(value>=999)
//            sendComando(DOWN_ROBOT);
//        else if(value<=-999)
//            sendComando(UP_ROBOT);
    }
    else if(axis==axis_left_vertical){
            QString mappedSpeed=mapSpeed(-value);
            QString strToSend=QString("%1%2").arg(FORWARD_ROBOT).arg(mappedSpeed);
            sendComando(strToSend);
            if(value==0 || value==maxControl || value ==minESCms) //Se repite el comando para asegurar que se realice
                sendComando(strToSend);

    }
    else if((axis==axis_cross_vertical)&& value==-1000){
       sendComando(TILT_UP);
       sendComando(NULL_CMD);

    }
    else if((axis==axis_cross_vertical) && value==0){
       sendComando(TILT_STOP);
       sendComando(NULL_CMD);
    }
    else if((axis==axis_cross_vertical)&& value==1000){  
        sendComando(TILT_DOWN);
        sendComando(NULL_CMD);
    }
    else if((axis==axis_cross_horizontal)&& value==-1000){     
        sendComando(PAN_UP);
        sendComando(NULL_CMD);
    }
    else if((axis==axis_cross_horizontal) && value==0){
       sendComando(PAN_STOP);
       sendComando(NULL_CMD);
    }
    else if((axis==axis_cross_horizontal)&& value==1000){ 
        sendComando(PAN_DOWN);
        sendComando(NULL_CMD);
    }

}

void MissionWidget::buttonEvent(QString button, QGameControllerButtonEvent *event){
#ifdef USER_DEBUG_SA
     qDebug("handle button");
#endif

     if(button==button_A && !event->pressed()){         
         tiltCamera->setValue(centerCamera);
         panCamera->setValue(centerCamera);
         sendComando(CENTER_CAMARA);
         sendComando(NULL_CMD);

     }
     else if(button==button_back && !event->pressed()){

          sendComando(CLOSE_ROBOT);
          disconnect(this->joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(axisEvent(QString,int)));
          disconnect(this->joystick,SIGNAL(joystickButtonEvent(QString, QGameControllerButtonEvent*)),this,SLOT(buttonEvent(QString,QGameControllerButtonEvent*)));
          saveSettings();
          emit returnToHome();

             #ifdef USER_DEBUG_SA
                  qDebug("==================================================================released Back==================================================================");
             #endif


     }
     else if(button==button_B && !event->pressed()){
      //emit takeScreenshot();
            takeScreenshot();

            #ifdef USER_DEBUG_SA
                 qDebug("released B");
            #endif

     }
     else if(button==button_Y && !event->pressed()){
         //emit saveVideo();

             #ifdef USER_DEBUG_SA
                  qDebug("released Y");
             #endif

     }
     else if(button==button_X && !event->pressed()){
         islightsOn=!islightsOn;
         if(islightsOn){
            lblLightsOff->setVisible(false);
            lblLightsOn->setVisible(true);
            sendComando(ON_LIGHT);
         }
         else{
             lblLightsOff->setVisible(true);
             lblLightsOn->setVisible(false);
             sendComando(OFF_LIGHT);
         }

         sendComando(NULL_CMD);
          #ifdef USER_DEBUG_SA
                 qDebug("released X");
          #endif
     }




}

QString MissionWidget::sendComando(QString comando){

#ifdef Q_PROCESSOR_X86
     QString run= createPath("cliente.o ")+robotIp+comando;
#endif

#ifdef Q_PROCESSOR_ARM
    QString run= createPath("clienteOlimex.o ")+robotIp+comando;
#endif

    qDebug() << run;

#ifndef OFFLINE_SA
        procRun.start(run);
        procRun.waitForFinished();
        QString output( procRun.readAllStandardOutput());
    #ifdef USER_DEBUG_SA
          qDebug()<<output;
    #endif
        output=output.mid(output.size()-5,output.size());
        procRun.close();
        return output;
#else
    return "offline";
#endif


}

QString MissionWidget::mapSpeed(int value){
   double m=(double) (maxESCms-minESCms)/(maxControl-minControl);
#ifdef USER_DEBUG_SA
     qDebug()<<"m "<<m;
#endif
   double b=minESCms-(m*minControl);
   int speed=m*value+b;

   return QString("%1").arg(speed);
}
