#include "missionwidget.h"
#include "intro.h"

extern QString createPath(QString path);

MissionWidget::MissionWidget(QWidget *parent, QString missionName) :
    QWidget(parent)
{
     this->missionName=missionName;

     m_sSettingsFile = QString("%1/%2/settings.ini").arg(createPath("Missions")).arg(missionName);
     loadSettings();
     /*Qt::WindowFlags flags(Qt::Window | Qt::CustomizeWindowHint | Qt::TitleBarArea);

     this->setWindowFlags(flags);*/

     //this->setWindowState( Qt::WindowFullScreen );

     //Create Mission Folder.
     QString missionFolder=QString("%1/%2").arg(createPath("Missions")).arg(missionName);
     if(!QDir(missionFolder).exists()){
         QDir().mkdir(missionFolder);
     }


     QIcon icon(createPath("icons/nautilus.svg"));
     setWindowIcon(icon);
     setWindowTitle(missionName);


     /*QPixmap bkgnd("./icons/mission.jpeg");
     bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
     QPalette palette;
     palette.setBrush(QPalette::Background, bkgnd);
     this->setPalette(palette);*/



     layout=new QGridLayout(this);
     this->setLayout(layout);

     button_test = new QPushButton();
     button_test->setIcon(QIcon("*/icons/control.png"));
     button_test->setIconSize(QSize(32,32));
     button_test->setGeometry(0,0,30,30);


    /******************************** ToolBar Buttons  *********************************************/
    button_control = new QPushButton();
    button_control->setIcon(QIcon(createPath("icons/control.png")));
    button_control->setIconSize(QSize(32,32));

    button_home = new QPushButton();
    button_home->setIcon(QIcon(createPath("icons/home.png")));
    button_home->setIconSize(QSize(32,32));
    connect(button_home,SIGNAL(released()),this,SLOT(handleButtonHome()));

   /* button_1 = new QPushButton();
    button_1->setIcon(QIcon("./icons/nautilus.svg"));
    button_1->setIconSize(QSize(32,32));*/



    button_camara = new QPushButton();
    button_camara->setIcon(QIcon(createPath("icons/camara.png")));
    button_camara->setIconSize(QSize(32,32));

    button_off = new QPushButton();
    button_off->setIcon(QIcon(createPath("icons/off.png")));
    button_off->setIconSize(QSize(32,32));
    connect(button_off,SIGNAL(released()),this,SLOT(handleButtonOff()));

    toolbar=new QToolBar("Tools");
    toolbar->setGeometry(10,10,300,30);
    toolbar->addWidget(button_home);
    toolbar->addWidget(button_control);
    toolbar->addWidget(button_camara);
    toolbar->addWidget(button_off);

    layout->addWidget(toolbar,0,0);

    /***********************************************************************************************/


    /********************************  Player  *****************************************************/
    QStringList argumentos;
    //argumentos.push_back("-vf");
    //argumentos.push_back("screenshot");
    argumentos.push_back("-fps");
    argumentos.push_back("20");

    //widget.setGeometry(400,Qt::AlignCenter,1280,720);
   // widget.setFixedSize(1280,720);

    statusPlayer=new QLabel();
    //player=new Player(argumentos, "rtsp://admin:12345@10.5.5.110:554//Streaming/Channels/1", &widget);
    player=new Player(argumentos, "rtsp://admin:12345@10.5.5.110:554//Streaming/Channels/1", this);
    player->setFixedSize(1280,720);
    connect(player,SIGNAL(updateStatus(bool)),this,SLOT(updatePlayerStatus(bool)));
    layout->addWidget(player, 1, 0,1,3);
    /***********************************************************************************************/



    /********************************  Joystick *****************************************************/
    statusJoystick=new QLabel();

    joystick=new JoystickWidget();
    connect(button_control, SIGNAL (released()), joystick, SLOT (setController()));
    connect(joystick,SIGNAL(updateStatus(bool)),this,SLOT(updateControlStatus(bool)));
    joystick->init();

    sendAction=joystick->getSendAction();

    robotDepth=new QLabel();
    connect(sendAction,SIGNAL(takeScreenshot()),this,SLOT(takeScreenshot()));
    connect(sendAction,SIGNAL(changeDepth(double)),this,SLOT(updateRobotDepth(double)));

    rtsp=new openRTSP(0,missionName,numVideos);
    connect(sendAction,SIGNAL(saveVideo()),rtsp,SLOT(saveVideo()));
    connect(rtsp,SIGNAL(isRecording(bool)),this,SLOT(updateRecording(bool)));

    layout->addWidget(robotDepth,2,0);
   /***********************************************************************************************/

    battery=new QProgressBar();
    battery->setValue(100);
    battery->setStyleSheet("QProgressBar {border: 2px solid black;border-radius: 10px; text-align: center;padding: 1px;}  QProgressBar::chunk { width: 10px;  background: qlineargradient(x1: 0, y1: 0, x2: 5, y2: 0, stop: 0 green, stop: 1 white);}");
    battery->setFixedSize(200,25);
    layout->addWidget(battery,2,1);

    depth=new QProgressBar();
    depth->setValue(50);
    depth->setStyleSheet("QProgressBar {border: 2px solid black;border-radius: 10px; text-align: center;padding: 1px;}  QProgressBar::chunk { width: 10px;  background: qlineargradient(x1: 0, y1: 0, x2: 5, y2: 0, stop: 0 green, stop: 1 white);}");

    depth->setFixedSize(200,25);
    layout->addWidget(depth,2,2);


    statusRobot=new QLabel();
    statusRobot->setText("Robot: Conectado");
    layout->addWidget(statusRobot,3,0);

    statusRecording=new QLabel();
    statusRecording->setText("Recording Off");
    layout->addWidget(statusRecording,3,1);
    layout->addWidget(statusPlayer,3,2);
    layout->addWidget(statusJoystick,4,0);

    adjustSize();
    setGeometry(QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
     ));





}


void MissionWidget::updatePlayerStatus(bool isConnected){
    if(isConnected){
        statusPlayer->setText("Camara: Conectada");
        statusPlayer->setStyleSheet("QLabel {  color : green; }");
    }
    else{
        statusPlayer->setText("Camara: Desonectada");
        statusPlayer->setStyleSheet("QLabel {  color : red; }");
    }
}

void MissionWidget::updateControlStatus(bool isConnected){
    if(isConnected){
        statusJoystick->setText("Control: Conectado");
        statusJoystick->setStyleSheet("QLabel {  color : green; }");
        button_control->setEnabled(false);
    }
    else{
        statusJoystick->setText("Control: Desconectado");
        statusJoystick->setStyleSheet("QLabel {  color : red; }");
        button_control->setEnabled(true);
    }
}

void MissionWidget::takeScreenshot(){
   QScreen *screen = QGuiApplication::primaryScreen();
   int x=this->x();
   int y=this->y();
   QPixmap pxm = screen->grabWindow(QApplication::desktop()->winId(),x+OFFSET_X,y+OFFSET_Y,SCREEN_SHOT_LR,SCREEN_SHOT_UD);

   QString picFolder=QString("%1/%2/pic_%3.jpeg").arg(createPath("Missions")).arg(missionName).arg(numPic);
   qDebug()<<picFolder;
   QFile file(picFolder);
   file.open(QIODevice::WriteOnly);
   pxm.save(&file, "JPG",100);
   numPic++;

}

void MissionWidget::updateRobotDepth(double value){
   QString valueAsString = QString::number(value);
   robotDepth->setText("DEPTH: "+valueAsString);
}

void MissionWidget::updateRecording(bool isRecording){
    if(isRecording){
        statusRecording->setText("Recording ON");
        statusRecording->setStyleSheet("QLabel {  color : green; }");
    }
    else{
        statusRecording->setText("Recording Off");
        statusRecording->setStyleSheet("QLabel {  color : red; }");
    }
}

void MissionWidget::handleButtonHome(){    

    this->close();

    /*intro welcomeScreen;
    welcomeScreen.show();*/

}

void MissionWidget::handleButtonOff(){
    QString msg=QString("Are you sure? \n The robot is save? \n the system is going to turning off");
    QMessageBox::StandardButton reply;

    reply = QMessageBox::warning(this, "Alert", msg, QMessageBox::Ok|QMessageBox::Cancel);
    if (reply == QMessageBox::Ok)this->close();

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
