#include "missionexplorer.h"

#define DEBUG_EXPLORER

MissionExplorer::MissionExplorer(QWidget *parent, QString missionName) :
    QWidget(parent)
{
    QIcon icon("./icons/nautilus128x128.svg");
    setWindowIcon(icon);
    setWindowTitle("Nautilus Mission Explorer");
    missionPath=QString("./Missions/%1/").arg(missionName);
    m_sSettingsFile = QString("./Missions/%1/settings.ini").arg(missionName);

    loadSettings();

    argumentos.push_back("-vf");
    argumentos.push_back("screenshot");
    argumentos.push_back("-fps");
    argumentos.push_back("20");
    argumentos.push_back("-osdlevel");
    argumentos.push_back("0");

    /****************************Player Buttons*********************************************/
    playButton = new QPushButton(this);
    playButton->setIcon(QIcon("./icons/playRed.png"));
    playButton->setIconSize(QSize(32,32));
    connect(playButton,SIGNAL(released()),this,SLOT(playCLiked()));

    reloadButton = new QPushButton(this);
    reloadButton->setIcon(QIcon("./icons/reload.png"));
    reloadButton->setIconSize(QSize(32,32));


    videoSlider = new QSlider(Qt::Horizontal, this);
    videoSlider->setRange(0, 100);

    playButton->setEnabled(false);
    reloadButton->setEnabled(false);
    videoSlider->setEnabled(false);


    /******************************Source Viewer********************************/

    player=NULL;
    picLbl=NULL;

    QPixmap defaultPixmap("./icons/explorerDefault.png");
    defaultLbl=new QLabel("");
    defaultLbl->setPixmap(defaultPixmap);


    listFiles=new QListWidget();    
    listFiles->setFixedWidth(200);
    connect(listFiles,SIGNAL(itemPressed(QListWidgetItem*)),this,SLOT(displaySource()));

    /***********************************************************************************************/

    btn_export = new QPushButton("Export");
    btn_export->setIcon(QIcon("./icons/export.png"));
    btn_export->setIconSize(QSize(32,32));
    exm=new ExportManager(this,missionName);
    connect(btn_export,SIGNAL(released()),exm,SLOT(launchDialog()));

    /***********************************************************************************************/
    layout=new QGridLayout();
    layout->addWidget(defaultLbl,0,0,1,3);

    layout->addWidget(playButton,1,0);
    layout->addWidget(reloadButton,1,1);
    layout->addWidget(videoSlider,1,2);
    layout->addWidget(listFiles,0,4,1,1);
    layout->addWidget(btn_export,1,4,1,1);
    this->setLayout(layout);


    adjustSize();
    setGeometry(QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
     ));

    QString thumbsPath=QString("%1thumb.sh").arg(missionPath);
    QFileInfo checkFile(thumbsPath);
    if (!checkFile.exists()){
         #ifdef DEBUG_EXPLORER
         qDebug()<< "file "+thumbsPath+" not exist";
         #endif
         QFile::copy("./thumbs.sh", thumbsPath);
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
              buildThumbs.start(exec);
              buildThumbs.waitForFinished();
             }
         }
         else if(!fileType.compare("jpeg") ){
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
    if(!type)p.load("./icons/pic.png");else p.load("./icons/movie.png");


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

void MissionExplorer::closeEvent(QCloseEvent *event) {
    saveSettings();
    event->accept();
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
   if(player!=NULL){

       player->setVisible(false);


   }


   if(isVideoFile.at(index)){

       /********************************  Player  *****************************************************/
       Player *toKill=player;

       player=new Player(argumentos, fileToShow, this);

       delete(toKill);

       player->setFixedSize(1280,720);


       connect(this, SIGNAL(play()), player, SLOT(play()));
       connect(this, SIGNAL(pause()), player, SLOT(pause()));
       connect(reloadButton, SIGNAL(released()), player, SLOT(reload()));
       connect(player,SIGNAL(newState(QMediaPlayer::State)),this,SLOT(setState(QMediaPlayer::State)));
       player->setSeekSlider(videoSlider);

       layout->addWidget(player,0,0,1,3);
       this->setState(QMediaPlayer::PlayingState);

   }
   else{
      playButton->setEnabled(false);
      reloadButton->setEnabled(false);
      videoSlider->setEnabled(false);

      QString picToShow=QString("<img src=\"%1\">").arg(fileToShow);
      picLbl=new QLabel(picToShow);
      picLbl->setFixedSize(1280,720);
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
            playButton->setIcon(QIcon("./icons/playRed.png"));
            reloadButton->setEnabled(false);
            break;
        case QMediaPlayer::PlayingState:
            playButton->setIcon(QIcon("./icons/pause.png"));
            reloadButton->setEnabled(true);
            emit play();
            break;
        case QMediaPlayer::PausedState:
            playButton->setIcon(QIcon("./icons/playRed.png"));
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





