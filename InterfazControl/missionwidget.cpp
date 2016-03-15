#include "missionwidget.h"



extern QString createPath(QString path);

MissionWidget::MissionWidget(QWidget *parent, QString mName, JoystickWidget *joystick,  Ui::NautilusCommander *gui, SendAction *sa) :
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

    lblLightsOff=ui->label_switchOff;
    lblLightsOn=ui->label_switchOn;
    lblLightsOn->setVisible(false);
    islightsOn=false;

    righLeft=-1;
    upDown=-1;

    statusVideoOff=ui->statusVideoOff;
    statusVideoOff->setVisible(true);
    isRecording=false;

    lblScreenShot=ui->label_toastSS;
    lblScreenShot->setVisible(false);


    missionNameLabel=ui->lblMissionName;
    missionNameLabel->setText(missionName);

    batteryROVPB=ui->progressBattRov;
    panCamera=ui->panCamera;
    tiltCamera=ui->tiltCamera;

    statusErrorBox=ui->statusErrorBox;
    statusErrorBox->setVisible(false);
    lblError=ui->lblError;


    sendAction=sa;
    connect(this->sendAction,SIGNAL(offline()),this,SLOT(robotDisconnected()));
    status=checkStatus();

    if(status!=-1)
    sendAction->sendComando(START_ROBOT);  //ReEnable the robot


    /********************************  Joystick *****************************************************/
    this->joystick=joystick;
    connect(joystick,SIGNAL(updateStatus(bool)),this,SLOT(updateControlStatus(bool)));
    connect(this->joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(axisEvent(QString,int)));
    connect(this->joystick,SIGNAL(joystickButtonEvent(QString, QGameControllerButtonEvent*)),this,SLOT(buttonEvent(QString,QGameControllerButtonEvent*)));

    rtsp=new openRTSP(0,missionName,numVideos);
    connect(this,SIGNAL(saveVideo()),rtsp,SLOT(saveVideo()));


  //  dataThread=new DataThread(ui->progressBattControl, ui->progressBattRov);
    //dataThread->start();



    mplayer=ui->mplayerWG;    
    //connect(mplayer,SIGNAL(stateChanged(int)),this,SLOT(updatePlayerStatus(int)));
    mplayer->start();    
    mplayer->load("rtsp://admin:12345@10.5.5.110:554");
    mplayer->setVisible(true);


    isCameraOnline=true;

    speedDial=ui->dial;
    speedDial->setNotchesVisible(false);

    speeds[0][0]=3;speeds[0][1]=10;speeds[0][2]=14;speeds[0][3]=20;//speeds[0][4]=13;//speeds[0][5]=15;speeds[0][6]=18;speeds[0][7]=22;
    speeds[1][0]=1580;speeds[1][1]=1610;speeds[1][2]=1640;speeds[1][3]=1670;//speeds[1][4]=1670;
    speeds[2][0]=1420;speeds[2][1]=1390;speeds[2][2]=1360;speeds[2][3]=1330;//speeds[2][4]=1330; y = 3000-x
    dialIndex=0;
    lastCommand="";
    speedDial->setValue(speeds[0][0]);


}

void MissionWidget::robotDisconnected(){
    qDebug()<<"Robot Offline";
    statusErrorBox->setVisible(true);
    lblError->setText("Robot Offline");
}

int MissionWidget::checkStatus(void){

    if(!sendAction->isConnected()){
        statusErrorBox->setVisible(true);
        lblError->setText("Robot Offline");
        return ERROR_ROBOT;
    }


    QProcess procRun;
    procRun.start(createPath("checkCam.sh"));
    procRun.waitForFinished( );
    QString output( procRun.readAllStandardOutput());
    procRun.close();

    qDebug()<< "Camera check "+output;

    if(!output.compare("live\n"))
       return STATUS_OK;
    else{
        statusErrorBox->setVisible(true);
        lblError->setText("Camera Offline");
        return ERROR_CAMERA;
    }

}

void MissionWidget::updatePlayerStatus(int state){
    if(state==QMPwidget::IdleState){
        qDebug()<< "Player IdleState";
        lblError->setText("Camera Offline");
        statusErrorBox->setVisible(true);
    }
    else if(state==QMPwidget::PlayingState){
        qDebug()<< "Player Playing State";
        statusErrorBox->setVisible(false);
    }
}

void MissionWidget::updateControlStatus(bool  isConnected ){
    if(!isConnected){
        sendAction->sendComando(STOP_ROBOT);
        disconnect(this->joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(axisEvent(QString,int)));
        disconnect(this->joystick,SIGNAL(joystickButtonEvent(QString, QGameControllerButtonEvent*)),this,SLOT(buttonEvent(QString,QGameControllerButtonEvent*)));
        saveSettings();
        dataThread->closeServer();
        dataThread->terminate();
        emit controlOut();
    }
}




void MissionWidget::takeScreenshot(){
   if(isCameraOnline){
        lblScreenShot->setVisible(true);
        QTimer::singleShot(1500,Qt::PreciseTimer ,this, SLOT(closeScreenShot()));
        qDebug()<<"ScreenShot-----------------------------------";
        QProcess procRTSP;
        numPic++;
        QString run=QString("sh %1 %2/%3/pic_%4.pvd").arg(createPath("rtspShot.sh")).arg(createPath("Missions")).arg(missionName).arg(numPic);
        qDebug()<<run;
        procRTSP.start(run);
        procRTSP.waitForFinished();
   }
   else
        qDebug()<<"ScreenShot ERROR";
}

void MissionWidget::closeScreenShot(){
    lblScreenShot->setVisible(false);
}

void MissionWidget::loadSettings(){
     QSettings settings(m_sSettingsFile, QSettings::NativeFormat);
     QString countVideos = settings.value("videos", "").toString();
     QString countPic = settings.value("pics", "").toString();
     qDebug()<<"Load Settigns videos:"+countVideos+" pics: "+countPic;

     numPic=countPic.compare("")?countPic.toInt():0;
     numVideos=countVideos.compare("")?countVideos.toInt():0;
}

void MissionWidget::saveSettings()
{
     QSettings settings(m_sSettingsFile, QSettings::NativeFormat);
     settings.setValue("videos", QString::number(rtsp->getVideoCount()));
     settings.setValue("pics",  QString::number(numPic));
}

void MissionWidget::axisEvent(QString axis,int value){
     qDebug("axis  %d",value);

    if(axis== axis_left_horizontal){  
        QString command="";

        switch (value) {
        case -1000:
            command= QString("%1%2").arg(RIGHT_ROBOT).arg(speeds[2][dialIndex]);
            break;
        case 1000:
            command=QString("%1%2").arg(LEFT_ROBOT).arg(speeds[1][dialIndex]);
            break;
        case  0:
            command=QString("%1%2").arg(LEFT_ROBOT).arg(1500);
            break;
        }
        if(command.compare("")){
            sendAction->sendComando(command);
            lastCommand=command;
        }


    }
    else if(axis==axis_left_vertical){     
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
                lastCommand=command;
            }

    }
    else if(axis==axis_right_vertical){
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
            lastCommand=command;
        }
    }
    else if((axis==axis_cross_vertical)&& value==-1000)
       sendAction->sendComando(TILT_UP);
    else if((axis==axis_cross_vertical) && value==0)
       sendAction->sendComando(TILT_STOP);       
    else if((axis==axis_cross_vertical)&& value==1000)
        sendAction->sendComando(TILT_DOWN);
    else if((axis==axis_cross_horizontal)&& value==-1000)
        sendAction->sendComando(PAN_UP);
    else if((axis==axis_cross_horizontal) && value==0)
       sendAction->sendComando(PAN_STOP);           
    else if((axis==axis_cross_horizontal)&& value==1000)
       sendAction->sendComando(PAN_DOWN);



}

void MissionWidget::buttonEvent(QString button, QGameControllerButtonEvent *event){
     if(button==button_back && !event->pressed()){

          rumble.start(createPath("rumbleGamepad.o"));                     
          sendAction->sendComando(STOP_ROBOT);
          if(isRecording)emit saveVideo();

          disconnect(this->joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(axisEvent(QString,int)));
          disconnect(this->joystick,SIGNAL(joystickButtonEvent(QString, QGameControllerButtonEvent*)),this,SLOT(buttonEvent(QString,QGameControllerButtonEvent*)));
          saveSettings();
          dataThread->closeServer();
          dataThread->terminate();
          mplayer->setVisible(false);

          emit returnToHome();

     }
     else if(button==button_X && !event->pressed()){
         rumble.start(createPath("rumbleGamepad.o"));
         tiltCamera->setValue(centerCamera);
         panCamera->setValue(centerCamera);
         sendAction->sendComando(CENTER_CAMARA);
     }
     else if(button==button_A && !event->pressed()){
            rumble.start(createPath("rumbleGamepad.o"));
            takeScreenshot();
            qDebug("released B");
     }
     else if(button==button_B && !event->pressed()){
         rumble.start(createPath("rumbleGamepad.o"));
         if(isCameraOnline){


                 emit saveVideo();
                 qDebug("emit saveVideo");

                 isRecording=!isRecording;
                 if(isRecording)
                     statusVideoOff->setVisible(false);
                 else
                     statusVideoOff->setVisible(true);
         }

         qDebug("released B");

     }
     else if(button==button_RB && !event->pressed()){
         rumble.start(createPath("rumbleGamepad.o"));
         int maxDial=speeds[0][3];
         dialIndex=(speedDial->value()<maxDial)?dialIndex+1:dialIndex;
         speedDial->setValue(speeds[0][dialIndex]);
         resendCommand();
         qDebug() <<"released RB dial:"+speedDial->value();
     }
     else if(button==button_LB && !event->pressed()){
         rumble.start(createPath("rumbleGamepad.o"));
         int minDial=speeds[0][0];
         dialIndex=(speedDial->value()>minDial)?dialIndex-1:dialIndex;
         speedDial->setValue(speeds[0][dialIndex]);
         resendCommand();
         qDebug() <<"released LB dial:"+speedDial->value();

     }
     else if(button==button_Y && !event->pressed()){
         rumble.start(createPath("rumbleGamepad.o"));
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
     }

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
      lastCommand=newCommand;
    }


    qDebug() <<"trimmed command:"+command+" "+commandValue;
}

QString MissionWidget::mapSpeed(int value){
   double m=(double) (maxESCms-minESCms)/(maxControl-minControl);
   qDebug()<<"m "<<m;
   double b=minESCms-(m*minControl);
   int speed=m*value+b;

   return QString("%1").arg(speed);
}

void MissionWidget::searchCamera(){
    QString checkCamera=QString("sh %1").arg(createPath("checkCam.sh"));
    QProcess procRun;
    procRun.start(checkCamera);
    procRun.waitForFinished();
    QString output(procRun.readAllStandardOutput());
    procRun.close();

    isCameraOnline= !output.compare("live\n");

    if(isCameraOnline){
        qDebug()<<"CAMERA LIVE";
        mplayer=ui->mplayerWG;               
        mplayer->load("rtsp://admin:12345@10.5.5.110:554");
        mplayer->start();
        connect(mplayer,SIGNAL(stateChanged(int)),this,SLOT(updatePlayerStatus(int)));
        statusErrorBox->setVisible(false);
    }
    else{
        qDebug()<<"CAMERA DIE";
        lblError->setText("Camera Error");
        statusErrorBox->setVisible(true);
        QTimer::singleShot(1000,Qt::PreciseTimer ,this, SLOT(searchCamera()));
    }
}
