#include "missionexplorer.h"

MissionExplorer::MissionExplorer(QWidget *parent, QString missionName) :
    QWidget(parent)
{
    QIcon icon("./icons/nautilus128x128.svg");
    setWindowIcon(icon);
    setWindowTitle("Nautilus Mission Explorer");
    this->missionPath=QString("./Missions/%1/").arg(missionName);

    /********************************  Player  *****************************************************/
    QStringList argumentos;
    argumentos.push_back("-vf");
    argumentos.push_back("screenshot");
    argumentos.push_back("-fps");
    argumentos.push_back("20");
    argumentos.push_back("-osdlevel");
    argumentos.push_back("0");

    widget.setFixedSize(1280,720);
    player=new Player(argumentos, "./Missions/Mission1/test.mp4", &widget);
    player->setFixedSize(1280,720);
    /***********************************************************************************************/
    controls = new PlayerControls(this);

    controls->setState(QMediaPlayer::PlayingState);
    connect(controls, SIGNAL(play()), player, SLOT(play()));
    connect(controls, SIGNAL(pause()), player, SLOT(pause()));
    connect(controls, SIGNAL(reload()), player, SLOT(reload()));
    connect(player, SIGNAL(newState(QMediaPlayer::State)),controls, SLOT(setState(QMediaPlayer::State)));
    player->setVideoSlider(controls->getVideoSlider());


    /***********************************************************************************************/
    listFiles=new QListWidget();
    createPreviewList();
    listFiles->setFixedWidth(200);



    layout=new QGridLayout();
    layout->addWidget(player,0,0);
    layout->addWidget(controls,1,0);
    layout->addWidget(listFiles,0,1,2,1);
    this->setLayout(layout);


    adjustSize();
    setGeometry(QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
     ));

}


void MissionExplorer::createPreviewList(){

    qDebug()<<missionPath;
    QDirIterator it(missionPath,QDir::NoDotAndDotDot | QDir::AllEntries);

    while (it.hasNext()) {
        QFileInfo Info(it.next());
        QString fileName = QString(Info.fileName());
        qDebug() <<fileName;
        qDebug() <<fileName.mid(fileName.length()-4,fileName.length());


     if(!fileName.mid(fileName.length()-3,fileName.length()).compare("mp4") || !fileName.mid(fileName.length()-4,fileName.length()).compare("jpeg")){
            QListWidgetItem *item = new QListWidgetItem();
            item->setSizeHint(QSize(item->sizeHint().width(), 60));

            QString thumbPath=QString("%1%2").arg(missionPath).arg(fileName);
            thumbElement=new ThumbViewer(0,thumbPath);

            listFiles->addItem(item);
            listFiles->setItemWidget(item, thumbElement);
     }

    }
}
