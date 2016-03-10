#include "missionexplorer.h"

extern QString createPath(QString path);

MissionExplorer::MissionExplorer(QWidget *parent, QString missionName, JoystickWidget *joystick, Ui::NautilusCommander *gui) :
    QWidget(parent)
{
    ui=gui;
    this->joystick=joystick;
    connect(joystick,SIGNAL(updateStatus(bool)),this,SLOT(updateControlStatus(bool)));
    connect(this->joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(axisEvent(QString,int)));
    connect(this->joystick,SIGNAL(joystickButtonEvent(QString, QGameControllerButtonEvent*)),this,SLOT(buttonEvent(QString,QGameControllerButtonEvent*)));

    QString missionsPath=createPath("Missions");
    missionPath=QString("%1/%2/").arg(missionsPath).arg(missionName);
    m_sSettingsFile = QString("%1/%2/settings.ini").arg(missionsPath).arg(missionName);

    loadSettings();

    picLbl=ui->lblPic;
    showDefaultPic();

    mplayer=ui->mplayerEx;
    listFiles=ui->listWidgetEx;
    listFiles->clear();

    lblMissionName=ui->lblMissionNameEx;
    lblMissionName->setText(missionName);
    fileRow=0;


    QString thumbsPath=QString("%1thumb.sh").arg(missionPath);
    QFileInfo checkFile(thumbsPath);
    if (!checkFile.exists()){         
         qDebug()<< "file "+thumbsPath+" not exist";         
         QFile::copy(createPath("thumbs.sh"), thumbsPath);
    }    
    else qDebug()<< "file "+thumbsPath+" exist";

    createPreviewList();        
    listFiles->setCurrentRow(0);
    listFiles->setStyleSheet("QListWidget::item { background-color: rgb(245, 245, 245);}QListWidget::item:selected {background-color: #F59236;}");

    groupPlayer=ui->groupPlayer;
    groupPlayer->setVisible(false);
    progressPlay=ui->playerSlider;
    progressPlay->setFocusPolicy(Qt::NoFocus);

    connect(progressPlay,SIGNAL(valueChanged(int)),this,SLOT(sliderChange(int)));
    lblPlayPause=ui->lblPlayStopIcon;
    mplayer->setSeekSlider(progressPlay);    
    isPlaying=false;
    videoFile=" ";
    isVideoActive=false;

}

void MissionExplorer::createPreviewList(){

    qDebug()<<missionPath;

    QDirIterator it(missionPath,QDir::NoDotAndDotDot | QDir::AllEntries);

    while (it.hasNext()) {
        QFileInfo Info(it.next());
        QString fileRaw = QString(Info.fileName()); //Name plus Extension
        QString fileName=fileRaw.mid(0,fileRaw.length()-4); //justName
        QString fileType=fileRaw.mid(fileRaw.length()-4,fileRaw.length());
        int fileIdx=fileRaw.mid(3,fileRaw.length()-4).toInt();

        qDebug()<<"File Raw  "+fileRaw;
        qDebug()<<"Mid test "+fileRaw.mid(3,fileRaw.length()-4);
        qDebug()<<"Mid test2 "+fileRaw.mid(2,fileRaw.length());
        qDebug()<<"File Idx  "+QString().number(fileIdx);
        qDebug()<<"videoThumnailed "+QString().number(videoThumbnailed);
        qDebug()<<"picsGen "+QString().number(picsGen);

         if(!fileType.compare(".mp4")){
             QString thumbPath=QString("%1%2").arg(missionPath).arg(fileRaw);
             files.append(thumbPath);
             isVideoFile.append(true);

             if(fileIdx>videoThumbnailed){
                  QProcess buildThumbs;
                  QString output=QString("%1.thumb").arg(fileName); // video thumb pic
                  QString exec=QString("sh %1thumb.sh %2 %3").arg(missionPath).arg(thumbPath).arg(output);
                  qDebug() <<exec;
                  buildThumbs.start(exec);
                  buildThumbs.waitForFinished();
                  videoThumbnailed++;
             }
         }
         else if(!fileType.compare(".pvd") ){  //PIC VIDEO FILE
            QString thumbPath=QString("%1%2.pvd").arg(missionPath).arg(fileName);

             if(fileIdx>picsGen){
                  QProcess buildPicsFromShotVideo;
                  QString output=QString("%1.png").arg(fileName);
                  QString exec=QString("sh %1thumb.sh %2 %3").arg(missionPath).arg(thumbPath).arg(output);
                  qDebug() <<exec;
                  buildPicsFromShotVideo.start(exec);
                  buildPicsFromShotVideo.waitForFinished();
                  picsGen++;
             }

             files.prepend(thumbPath);
             isVideoFile.prepend(false);
         }

     }


    for (int i = 0; i < files.size(); ++i) {
        qDebug()<<"List "+files.at(i);        
        addPreviewItem(files.at(i),isVideoFile.at(i));
    }


}

void MissionExplorer::addPreviewItem(QString preThumb,bool type){
    QListWidgetItem *item=new QListWidgetItem();
    item->setSizeHint(QSize(item->sizeHint().width(), 180));
    listFiles->addItem(item);
    QString thumbPath;


    thumbPath=(!type)?preThumb:QString("%1.thumb").arg(preThumb);


    QImage img(thumbPath);
    QImage *thumb =new QImage( img.scaled(180, 180, Qt::IgnoreAspectRatio, Qt::FastTransformation));
    QLabel *thumbElement = new QLabel("");
    thumbElement->setAlignment(Qt::AlignCenter);

    QPixmap p;
    if(!type)p.load(createPath("icons/pic.png"));else p.load(createPath("icons/movie.png"));


    QPixmap pixmap = QPixmap::fromImage(*thumb);
    QPainter painter(&pixmap);
    painter.drawPixmap(58,58, p);
    thumbElement->setPixmap(pixmap);
    QWidget *w=new QWidget;
    QHBoxLayout* layout=new QHBoxLayout;
    layout->addWidget(thumbElement);
    w->setLayout(layout);
    listFiles->setItemWidget(item, w);
}

void MissionExplorer::loadSettings(){
     QSettings settings(m_sSettingsFile, QSettings::NativeFormat);
     videoThumbnailed = settings.value("videoThumbnailed", "").toString().compare("")?settings.value("videoThumbnailed", "").toInt():0;
     picsGen= settings.value("picsGen", "").toString().compare("")?settings.value("picsGen", "").toInt():0;
     numPics=settings.value("pics", "").toString().compare("")?settings.value("pics", "").toInt():0;
     numVids=settings.value("videos", "").toString().compare("")?settings.value("videos", "").toInt():0;
}

void MissionExplorer::saveSettings(){
  QSettings settings(m_sSettingsFile, QSettings::NativeFormat);
  settings.setValue("picsGen", QString::number(picsGen));
  settings.setValue("videoThumbnailed", QString::number(videoThumbnailed));
}

void MissionExplorer::displaySource(){
   int index=listFiles->currentRow();
   QString fileToShow=files.at(index);
   videoFile=fileToShow;
   qDebug()<<"Displaying Source"+fileToShow;

   if(isVideoFile.at(index)){
      /********************************  Player  *****************************************************/
      groupPlayer->setVisible(true);
      lblPlayPause->setStyleSheet("background-image: url(:/new/prefix1/pause50.png);");
      picLbl->setVisible(false);
      mplayer->setVisible(true);          
      isPlaying=true;
      isVideoActive=true;
      mplayer->start();
      mplayer->load(fileToShow);
   }
   else{
      isVideoActive=false;
      groupPlayer->setVisible(false);
      mplayer->setVisible(false);
      mplayer->stop();
      picLbl->setVisible(true);
      QPixmap pixmap;
      pixmap.load(fileToShow);
      pixmap = pixmap.scaled(1600, 1000, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
      picLbl->setPixmap(pixmap);
   }


}


void MissionExplorer::axisEvent(QString axis,int value){
   if(axis==axis_cross_vertical && value==1000){
       rumble.start(createPath("rumbleGamepad.o"));
       fileRow=(fileRow+1>listFiles->count()-1)?0:fileRow+1;
   }
   else if(axis==axis_cross_vertical && value==-1000){
       rumble.start(createPath("rumbleGamepad.o"));
       fileRow=(fileRow-1<0)?0:fileRow-1;
   }

   listFiles->setCurrentRow(fileRow);

}

void MissionExplorer::buttonEvent(QString button, QGameControllerButtonEvent *event){
    if(button==button_back && !event->pressed()){
        rumble.start(createPath("rumbleGamepad.o"));
        disconnect(this->joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(axisEvent(QString,int)));
        disconnect(this->joystick,SIGNAL(joystickButtonEvent(QString, QGameControllerButtonEvent*)),this,SLOT(buttonEvent(QString,QGameControllerButtonEvent*)));
        saveSettings();
        mplayer->setVisible(false);
        showDefaultPic();
        mplayer->stop();

        emit returnToHome();
     }
    else if(button==button_A && !event->pressed()){
        rumble.start(createPath("rumbleGamepad.o"));
      displaySource();
    }
    else if(button==button_B && !event->pressed() && isVideoActive){
        rumble.start(createPath("rumbleGamepad.o"));

        if(isPlaying){
            mplayer->pause();
            lblPlayPause->setStyleSheet("background-image: url(:/new/prefix1/play50.png);");
        }
        else if(progressPlay->value()!=0){
            mplayer->play();
            lblPlayPause->setStyleSheet("background-image: url(:/new/prefix1/pause50.png);");
        }
        else{
            mplayer->start();
            mplayer->load(videoFile);
            lblPlayPause->setStyleSheet("background-image: url(:/new/prefix1/pause50.png);");
        }

        isPlaying=!isPlaying;

    }

}


void MissionExplorer::showDefaultPic(){
    QPixmap pixmap;
    pixmap.load(DEFAULT_PIC);
    picLbl->setPixmap(pixmap);
    picLbl->setVisible(true);
}

void MissionExplorer::sliderChange(int value){
  if(value==progressPlay->maximum()){
      progressPlay->setValue(0);
      isPlaying=false;
     lblPlayPause->setStyleSheet("background-image: url(:/new/prefix1/play50.png);");
  }
}

void MissionExplorer::updateControlStatus(bool isConnected){
   if(!isConnected){
       disconnect(this->joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(axisEvent(QString,int)));
       disconnect(this->joystick,SIGNAL(joystickButtonEvent(QString, QGameControllerButtonEvent*)),this,SLOT(buttonEvent(QString,QGameControllerButtonEvent*)));
       saveSettings();
       mplayer->setVisible(false);
       showDefaultPic();
       mplayer->stop();

       emit controlOut();
   }
}
