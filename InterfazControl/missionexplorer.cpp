#include "missionexplorer.h"

//#define DEBUG_EXPLORER

extern QString createPath(QString path);

MissionExplorer::MissionExplorer(QWidget *parent, QString missionName, JoystickWidget *joystick, Ui::NautilusCommander *gui) :
    QWidget(parent)
{
    ui=gui;
    this->joystick=joystick;
    connect(this->joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(axisEvent(QString,int)));
    connect(this->joystick,SIGNAL(joystickButtonEvent(QString, QGameControllerButtonEvent*)),this,SLOT(buttonEvent(QString,QGameControllerButtonEvent*)));

    QString missionsPath=createPath("Missions");
    missionPath=QString("%1/%2/").arg(missionsPath).arg(missionName);
    m_sSettingsFile = QString("%1/%2/settings.ini").arg(missionsPath).arg(missionName);

    loadSettings();

    argumentos.push_back("-fps");
    argumentos.push_back("30");
    argumentos.push_back("-osdlevel");
    argumentos.push_back("0");

    defaultLbl=ui->lblDefault;
    picLbl=ui->lblPic;
    mplayer=ui->mplayerEx;
    listFiles=ui->listWidgetEx;

    fileRow=0;


    QString thumbsPath=QString("%1thumb.sh").arg(missionPath);
    QFileInfo checkFile(thumbsPath);
    if (!checkFile.exists()){
         #ifdef DEBUG_EXPLORER
         qDebug()<< "file "+thumbsPath+" not exist";
         #endif
         QFile::copy(createPath("thumbs.sh"), thumbsPath);
    }
    #ifdef DEBUG_EXPLORER
    else qDebug()<< "file "+thumbsPath+" exist";
    #endif


    createPreviewList();

}

void MissionExplorer::createPreviewList(){


    #ifdef DEBUG_EXPLORER
    qDebug()<<missionPath;
    #endif
    QDirIterator it(missionPath,QDir::NoDotAndDotDot | QDir::AllEntries);

    while (it.hasNext()) {
        QFileInfo Info(it.next());
        QString fileName = QString(Info.fileName());


        #ifdef DEBUG_EXPLORER
        qDebug() <<fileName;
        #endif


        QString fileType=fileName.mid(fileName.length()-4,fileName.length());

         if(!fileType.compare(".mp4")){
             QString thumbPath=QString("%1%2").arg(missionPath).arg(fileName);
             files.append(thumbPath);
             isVideoFile.append(true);

             if(createThumbs){
              QProcess buildThumbs;
              QString exec=QString("sh %1thumb.sh %2").arg(missionPath).arg(thumbPath);
                #ifdef DEBUG_EXPLORER
                qDebug() <<exec;
                #endif
              buildThumbs.start(exec);
              buildThumbs.waitForFinished();
             }
         }
         else if(!fileType.compare(".png") ){
             QString thumbPath=QString("%1%2").arg(missionPath).arg(fileName);
             files.prepend(thumbPath);
             isVideoFile.prepend(false);
         }

     }


    for (int i = 0; i < files.size(); ++i) {

        #ifdef DEBUG_EXPLORER
        qDebug()<<"List "+files.at(i);
        #endif
       addPreviewItem(files.at(i),isVideoFile.at(i));
    }


}

void MissionExplorer::addPreviewItem(QString preThumb,bool type){
    QListWidgetItem *item=new QListWidgetItem();
    item->setSizeHint(QSize(item->sizeHint().width(), 200));
    listFiles->addItem(item);
    QString thumbPath;


    thumbPath=(!type)?preThumb:QString("%1.thumb").arg(preThumb);


    QImage img(thumbPath);
    QImage *thumb =new QImage( img.scaled(180, 180, Qt::IgnoreAspectRatio, Qt::FastTransformation));
    QLabel *thumbElement = new QLabel("");

    QPixmap p;
    if(!type)p.load(createPath("icons/pic.png"));else p.load(createPath("icons/movie.png"));


    QPixmap pixmap = QPixmap::fromImage(*thumb);
    QPainter painter(&pixmap);
    painter.drawPixmap(58,58, p);
    thumbElement->setPixmap(pixmap);
    listFiles->setItemWidget(item, thumbElement);
}

void MissionExplorer::loadSettings(){
     QSettings settings(m_sSettingsFile, QSettings::NativeFormat);
     createThumbs = !settings.value("isThumbnailed", "").toBool();
}

void MissionExplorer::saveSettings(){
 QSettings settings(m_sSettingsFile, QSettings::NativeFormat);
 settings.setValue("isThumbnailed", true);
}

void MissionExplorer::displaySource(){
   int index=listFiles->currentRow();
   QString fileToShow=files.at(index);

#ifdef DEBUG_EXPLORER
   qDebug("Displaying Source");
#endif

   defaultLbl->setVisible(false);
   if(picLbl!=NULL){
       picLbl->setVisible(false);
       picLbl->clear();
   }
   /*if(player!=NULL){

       player->setVisible(false);


   }*/


   if(isVideoFile.at(index)){

       /********************************  Player  *****************************************************/
     /*  QMPwidget *toKill=player;

       player=new QMPwidget(argumentos, fileToShow, this);

       delete(toKill);

       player->setFixedSize(1650,1000);


       connect(this, SIGNAL(play()), player, SLOT(play()));
       connect(this, SIGNAL(pause()), player, SLOT(pause()));
       connect(reloadButton, SIGNAL(released()), player, SLOT(reload()));
       connect(player,SIGNAL(newState(QMediaPlayer::State)),this,SLOT(setState(QMediaPlayer::State)));
       player->setSeekSlider(videoSlider);

       layout->addWidget(player,0,0,1,3);
       this->setState(QMediaPlayer::PlayingState);*/

   }
   else{
      playButton->setEnabled(false);
      reloadButton->setEnabled(false);
      videoSlider->setEnabled(false);

      /*
      QString picToShow=QString("<img src=\"%1\">").arg(fileToShow);
      picLbl=new QLabel(picToShow);
      picLbl->setFixedSize(1650,900);*/


      QImage img(fileToShow);
      QImage *image =new QImage( img.scaled(1650, 900, Qt::IgnoreAspectRatio, Qt::FastTransformation));
      picLbl= new QLabel("");
      QPixmap pixmap = QPixmap::fromImage(*image);
      picLbl->setPixmap(pixmap);

      layout->addWidget(picLbl,0,0,1,3,Qt::AlignCenter);
   }


}

void MissionExplorer::setState(QMediaPlayer::State state)
{
    playButton->setEnabled(true);
    if (state != playerState) {
        playerState = state;

        switch (state) {
        case QMediaPlayer::StoppedState:
            playButton->setIcon(QIcon(createPath("icons/playRed.png")));
            reloadButton->setEnabled(false);
            break;
        case QMediaPlayer::PlayingState:
            playButton->setIcon(QIcon(createPath("icons/pause.png")));
            reloadButton->setEnabled(true);
            emit play();
            break;
        case QMediaPlayer::PausedState:
            playButton->setIcon(QIcon(createPath("icons/playRed.png")));
            reloadButton->setEnabled(true);
            emit pause();
            break;
        }
    }
}

void MissionExplorer::playCLiked(){
   switch (playerState) {
   case QMediaPlayer::StoppedState:
        displaySource();
       break;
   case QMediaPlayer::PausedState:
       setState(QMediaPlayer::PlayingState);
       break;
   case QMediaPlayer::PlayingState:
       setState(QMediaPlayer::PausedState);
       break;
   }
}


void MissionExplorer::axisEvent(QString axis,int value){
   if(axis==axis_cross_vertical && value==1000)
       fileRow=(fileRow+1>listFiles->count()-1)?0:fileRow+1;
   else if(axis==axis_cross_vertical && value==-1000)
       fileRow=(fileRow-1<0)?0:fileRow-1;

   listFiles->setCurrentRow(fileRow);
}

void MissionExplorer::buttonEvent(QString button, QGameControllerButtonEvent *event){
    if(button==button_back && !event->pressed()){
        disconnect(this->joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(axisEvent(QString,int)));
        disconnect(this->joystick,SIGNAL(joystickButtonEvent(QString, QGameControllerButtonEvent*)),this,SLOT(buttonEvent(QString,QGameControllerButtonEvent*)));
        saveSettings();
        emit returnToHome();
     }
    else if(button==button_A && !event->pressed()){
      displaySource();
    }
}


