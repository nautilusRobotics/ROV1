#include "missionexplorer.h"

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

    picLbl=ui->lblPic;
    showDefaultPic();

    mplayer=ui->mplayerEx;
    listFiles=ui->listWidgetEx;
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

}
void MissionExplorer::createPreviewList(){

    qDebug()<<missionPath;

    QDirIterator it(missionPath,QDir::NoDotAndDotDot | QDir::AllEntries);

    while (it.hasNext()) {
        QFileInfo Info(it.next());
        QString fileName = QString(Info.fileName());
        qDebug() <<fileName;

        QString fileType=fileName.mid(fileName.length()-4,fileName.length());

         if(!fileType.compare(".mp4")){
             QString thumbPath=QString("%1%2").arg(missionPath).arg(fileName);
             files.append(thumbPath);
             isVideoFile.append(true);

             if(createThumbs){
                  QProcess buildThumbs;
                  QString exec=QString("sh %1thumb.sh %2").arg(missionPath).arg(thumbPath);
                  qDebug() <<exec;
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
     createThumbs = !settings.value("isThumbnailed", "").toBool();
}

void MissionExplorer::saveSettings(){
 QSettings settings(m_sSettingsFile, QSettings::NativeFormat);
 settings.setValue("isThumbnailed", true);
}

void MissionExplorer::displaySource(){
   int index=listFiles->currentRow();
   QString fileToShow=files.at(index);
   qDebug()<<"Displaying Source"+fileToShow;

   if(isVideoFile.at(index)){

      /********************************  Player  *****************************************************/
      picLbl->setVisible(false);
      mplayer->setVisible(true);      
      mplayer->start();
      mplayer->load(fileToShow);

   }
   else{
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
        mplayer->setVisible(false);
        showDefaultPic();
        mplayer->stop();

        emit returnToHome();
     }
    else if(button==button_A && !event->pressed()){
      displaySource();
    }
    else if(button==button_B && !event->pressed())
        this->focusNextChild();
}


void MissionExplorer::showDefaultPic(){
    QPixmap pixmap;
    pixmap.load(DEFAULT_PIC);
    picLbl->setPixmap(pixmap);
    picLbl->setVisible(true);
}
