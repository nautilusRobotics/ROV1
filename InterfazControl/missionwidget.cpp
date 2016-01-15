#include "missionwidget.h"
#define USER_DEBUG_MW


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


    robotIp="10.5.5.103 ";


    statusErrorBox=ui->statusErrorBox;
    statusErrorBox->setVisible(false);

    lblLightsOff=ui->label_switchOff;
    lblLightsOn=ui->label_switchOn;
    lblLightsOn->setVisible(false);
    islightsOn=false;

    statusErrorBox->setVisible(false);
    lblError=ui->lblError;

    righLeft=-1;
    upDown=-1;

    statusVideoOff=ui->statusVideoOff;
    statusVideoOff->setVisible(true);
    isRecording=false;


    missionNameLabel=ui->lblMissionName;
    missionNameLabel->setText(missionName);

    batteryROVPB=ui->progressBattRov;    
    panCamera=ui->panCamera;
    tiltCamera=ui->tiltCamera;

    dataThread=new DataThread(ui->progressBattControl, ui->progressBattRov);
    dataThread->start();

    sendAction=new SendAction();


    //searchCamera();
    mplayer=ui->mplayerWG;
    mplayer->start();
    mplayer->load("rtsp://admin:12345@10.5.5.110:554");
    isCameraOnline=true;

    speedDial=ui->dial;
    speedDial->setNotchesVisible(false);

    speeds[0][0]=1;speeds[0][1]=4;speeds[0][2]=8;speeds[0][3]=10;speeds[0][4]=13;//speeds[0][5]=15;speeds[0][6]=18;speeds[0][7]=22;
    speeds[1][0]=1550;speeds[1][1]=1580;speeds[1][2]=1610;speeds[1][3]=1640;speeds[1][4]=1670;
    speeds[2][0]=1490;speeds[2][1]=1420;speeds[2][2]=1390;speeds[2][3]=1360;speeds[2][4]=1330;
    dialIndex=0;
    lastCommand="";
    speedDial->setValue(speeds[0][0]);
}

void MissionWidget::updatePlayerStatus(bool isConnected){

}

void MissionWidget::updateControlStatus(bool isConnected){

}

void MissionWidget::takeScreenshot(){
   if(isCameraOnline){
        qDebug()<<"ScreenShot-----------------------------------";
        QProcess procRTSP;
        QString run=QString("sh rtspShot.sh %1/%2 pic_%3.png").arg(createPath("Missions")).arg(missionName).arg(numPic);
        qDebug()<<run;
        procRTSP.start(run);
        procRTSP.waitForFinished();
        numPic++;
   }
   else
        qDebug()<<"ScreenShot ERROR";
}

void MissionWidget::updateRobotDepth(double value){

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

void MissionWidget::axisEvent(QString axis,int value){
#ifdef USER_DEBUG_MW
     qDebug("axis  %d",value);
#endif

    if(axis== axis_left_horizontal){
       /* QString mappedSpeed=mapSpeed(-value);
        QString command=value<0?RIGHT_ROBOT:LEFT_ROBOT;
        QString strToSend=QString("%1%2").arg(command).arg(mappedSpeed);
        sendAction->sendComando(strToSend);
        if(value==0 || value==maxControl || value ==minControl) //Se repite el comando para asegurar que se realice
            sendAction->sendComando(strToSend);*/
        QString command="";

        switch (value) {
        case 1000:
            command= QString("%1%2").arg(RIGHT_ROBOT).arg(speeds[2][dialIndex]);
            break;
        case -1000:
            command=QString("%1%2").arg(LEFT_ROBOT).arg(speeds[1][dialIndex]);
            break;
        case  0:
            command=QString("%1%2").arg(LEFT_ROBOT).arg(1500);
            break;
        }
        if(command.compare("")){
            sendAction->sendComando(command);
            /*sendAction->sendComando(command);
            sendAction->sendComando(command);*/
            lastCommand=command;
        }


    }
    else if(axis==axis_left_vertical){
           /* QString mappedSpeed=mapSpeed(-value);
            QString strToSend=QString("%1%2").arg(GO_ROBOT).arg(mappedSpeed);
            sendAction->sendComando(strToSend);
            if(value==0 || value==maxControl || value ==minControl) //Se repite el comando para asegurar que se realice
                sendAction->sendComando(strToSend);*/
            QString command="";
            switch (value) {
            case 1000:
                command=QString("%1%2").arg(GO_ROBOT).arg(speeds[2][dialIndex]);
                break;
            case -1000:
                command=QString("%1%2").arg(GO_ROBOT).arg(speeds[1][dialIndex]);
                break;
            case  0:
                command=QString("%1%2").arg(GO_ROBOT).arg(1500);
                break;
            }

            if(command.compare("")){
                sendAction->sendComando(command);
                /*sendAction->sendComando(command);
                sendAction->sendComando(command);*/
                lastCommand=command;
            }

    }
    else if(axis==axis_right_vertical){
           /* QString mappedSpeed=mapSpeed(-value);
            QString strToSend=QString("%1%2").arg(UPDOWN_ROBOT).arg(mappedSpeed);
            sendAction->sendComando(strToSend);
            if(value==0 || value==maxControl || value ==minControl) //Se repite el comando para asegurar que se realice
                sendAction->sendComando(strToSend);*/
        QString command="";
        switch (value) {
        case 1000:
            command=QString("%1%2").arg(UPDOWN_ROBOT).arg(speeds[2][dialIndex]);

            break;
        case -1000:
            command=QString("%1%2").arg(UPDOWN_ROBOT).arg(speeds[1][dialIndex]);
            break;
        case  0:
            command=QString("%1%2").arg(UPDOWN_ROBOT).arg(1500);
            break;
        }

        if(command.compare("")){
            sendAction->sendComando(command);
            /*sendAction->sendComando(command);
            sendAction->sendComando(command);*/
            lastCommand=command;
        }
    }
    else if((axis==axis_cross_vertical)&& value==-1000){
       sendAction->sendComando(TILT_UP);
       //sendAction->sendComando(NULL_CMD);

    }
    else if((axis==axis_cross_vertical) && value==0){
       sendAction->sendComando(TILT_STOP);
       //sendAction->sendComando(NULL_CMD);
    }
    else if((axis==axis_cross_vertical)&& value==1000){  
        sendAction->sendComando(TILT_DOWN);
       // sendAction->sendComando(NULL_CMD);
    }
    else if((axis==axis_cross_horizontal)&& value==-1000){     
        sendAction->sendComando(PAN_UP);
       // sendAction->sendComando(NULL_CMD);
    }
    else if((axis==axis_cross_horizontal) && value==0){
       sendAction->sendComando(PAN_STOP);
       //sendAction->sendComando(NULL_CMD);
    }
    else if((axis==axis_cross_horizontal)&& value==1000){ 
        sendAction->sendComando(PAN_DOWN);
        //sendAction->sendComando(NULL_CMD);
    }

}

void MissionWidget::buttonEvent(QString button, QGameControllerButtonEvent *event){
#ifdef USER_DEBUG_MW
     qDebug("handle button");
#endif
     if(button==button_back && !event->pressed()){

          sendAction->sendComando(STOP_ROBOT);
         // sendAction->sendComando(NULL_CMD);
          disconnect(this->joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(axisEvent(QString,int)));
          disconnect(this->joystick,SIGNAL(joystickButtonEvent(QString, QGameControllerButtonEvent*)),this,SLOT(buttonEvent(QString,QGameControllerButtonEvent*)));
          saveSettings();

          emit returnToHome();

         #ifdef USER_DEBUG_MW
              qDebug("==================================================================released Back==================================================================");
         #endif
     }
     else if(button==button_X && !event->pressed()){
         tiltCamera->setValue(centerCamera);
         panCamera->setValue(centerCamera);
         sendAction->sendComando(CENTER_CAMARA);
         //sendAction->sendComando(NULL_CMD);

     }
     else if(button==button_A && !event->pressed()){
            takeScreenshot();
            #ifdef USER_DEBUG_MW
                 qDebug("released B");
            #endif
     }
     else if(button==button_B && !event->pressed()){
         if(isCameraOnline){
                 emit saveVideo();
                 isRecording=!isRecording;
                 if(isRecording)
                     statusVideoOff->setVisible(false);
                 else
                     statusVideoOff->setVisible(true);
         }

         #ifdef USER_DEBUG_MW
                 qDebug("released Y");
         #endif
     }
     else if(button==button_RB && !event->pressed()){
         int maxDial=speeds[0][4];
         dialIndex=(speedDial->value()<maxDial)?dialIndex+1:dialIndex;
         speedDial->setValue(speeds[0][dialIndex]);
         resendCommand();
#ifdef USER_DEBUG_MW
        qDebug() <<"released RB dial:"+speedDial->value();
#endif


     }
     else if(button==button_LB && !event->pressed()){
         int minDial=speeds[0][0];
         dialIndex=(speedDial->value()>minDial)?dialIndex-1:dialIndex;
         speedDial->setValue(speeds[0][dialIndex]);
         resendCommand();
         #ifdef USER_DEBUG_MW
                 qDebug() <<"released LB dial:"+speedDial->value();
         #endif



     }
    /* else if(button==button_X && !event->pressed()){
         islightsOn=!islightsOn;
         if(islightsOn){
            lblLightsOff->setVisible(false);
            lblLightsOn->setVisible(true);
            sendAction->sendComando(ON_LIGHT);
         }
         else{
             lblLightsOff->setVisible(true);
             lblLightsOn->setVisible(false);
             sendAction->sendComando(OFF_LIGHT);
         }

         //sendAction->sendComando(NULL_CMD);
          #ifdef USER_DEBUG_MW
                 qDebug("released X");
          #endif
     }*/




}


void MissionWidget::resendCommand(){
    QString commandValue=lastCommand.mid(lastCommand.length()-4,lastCommand.length()-1);
    QString command=lastCommand.mid(0,lastCommand.length()-4);
    QString newCommand="";

    if(commandValue.compare("1500") && commandValue.compare("")){
      if(!command.compare(LEFT_ROBOT)){
         newCommand=QString("%1%2").arg(LEFT_ROBOT).arg(speeds[1][dialIndex]);
      }
      else if(!command.compare(RIGHT_ROBOT)){
         newCommand=QString("%1%2").arg(RIGHT_ROBOT).arg(speeds[2][dialIndex]);
      }
      else if(!command.compare(GO_ROBOT) && commandValue.toInt()>1500){
         newCommand=QString("%1%2").arg(GO_ROBOT).arg(speeds[1][dialIndex]);
      }
      else if(!command.compare(GO_ROBOT) && commandValue.toInt()<1500){
         newCommand=QString("%1%2").arg(GO_ROBOT).arg(speeds[2][dialIndex]);
      }
      else if(!command.compare(UPDOWN_ROBOT) && commandValue.toInt()>1500){
         newCommand=QString("%1%2").arg(UPDOWN_ROBOT).arg(speeds[1][dialIndex]);
      }
      else if(!command.compare(UPDOWN_ROBOT) && commandValue.toInt()<1500){
         newCommand=QString("%1%2").arg(UPDOWN_ROBOT).arg(speeds[2][dialIndex]);
      }

      sendAction->sendComando(newCommand);
      /*sendAction->sendComando(command);
      sendAction->sendComando(command);*/
      lastCommand=newCommand;
    }

#ifdef USER_DEBUG_MW
      qDebug() <<"trimmed command:"+command+" "+commandValue;
#endif


}

QString MissionWidget::mapSpeed(int value){
   double m=(double) (maxESCms-minESCms)/(maxControl-minControl);
#ifdef USER_DEBUG_MW
     qDebug()<<"m "<<m;
#endif
   double b=minESCms-(m*minControl);
   int speed=m*value+b;

   return QString("%1").arg(speed);
}

void MissionWidget::searchCamera(){
    QString checkCamera="sh checkCam.sh";
    QProcess procRun;
    procRun.start(checkCamera);
    procRun.waitForFinished();
    QString output(procRun.readAllStandardOutput());
    procRun.close();

    isCameraOnline= !output.compare("live\n");

    if(isCameraOnline){
        qDebug()<<"CAMERA LIVE";
        mplayer=ui->mplayerWG;
        mplayer->start();
        mplayer->load("rtsp://admin:12345@10.5.5.110:554");
        statusErrorBox->setVisible(false);
    }
    else{
        qDebug()<<"CAMERA DIE";
        lblError->setText("Camera Error");
        statusErrorBox->setVisible(true);
        QTimer::singleShot(1000,Qt::PreciseTimer ,this, SLOT(searchCamera()));
    }
}
