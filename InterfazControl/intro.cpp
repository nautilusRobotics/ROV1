#include "intro.h"
extern QString fullPath;

//#define DEBUG_INTRO

extern QString createPath(QString path);

intro::intro(QWidget *parent) :
    QWidget(parent)
{

    QIcon icon(createPath("icons/nautilus128x128.svg"));
    setWindowIcon(icon);
    setWindowTitle("Nautilus Commander");
    const QRect rec = QApplication::desktop()->screenGeometry();
    setGeometry(rec);


    QPixmap bkgnd(createPath("icons/intro.jpeg"));
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);


    layout=new QGridLayout(this);
    this->setLayout(layout);

    logo=new QLabel(QString("<img src=\"%1\">").arg(createPath("icons/nautilus128x128.svg")));



    welcomeTxt=new QLabel("WELCOME TO NAUTILUS COMMANDER");
    welcomeTxt->setStyleSheet("QLabel{font-size:40px;font-weight:bold;}");




    btnNew= new QPushButton("Start New Mission");
    btnNew->setIcon(QIcon(createPath("icons/new32.png")));
    btnNew->setIconSize(QSize(32,32));
    btnNew->setStyleSheet("QPushButton{font-size:20px;font-weight:bold;color:white;background:#295BFF}QPushButton:hover:!pressed {background:#4873FF}");
    btnNew->setFocusPolicy(Qt::NoFocus);

    connect(btnNew,SIGNAL(released()),this,SLOT(handleNewBtn()));

    newMission=new QLineEdit();
    namelbl=new QLabel("Enter the name of your mission:");
    namelbl->setStyleSheet("QLabel{font-size:20px;font-weight:bold;}");

    missionsPath=createPath("Missions");
    if(!QDir(missionsPath).exists()){
        QDir().mkdir(missionsPath);
    }


    projectList= new QListWidget();
    exm=new ExportManager(this);
    createProjectList();
    projectList->setSelectionMode (QAbstractItemView::NoSelection);
    projectList->setFixedHeight(150);


    button_off = new QPushButton();
    button_off->setIcon(QIcon(createPath("icons/off.png")));
    button_off->setIconSize(QSize(32,32));
    connect(button_off,SIGNAL(released()),this,SLOT(handleButtonOff()));


    layout->addWidget(logo,0,0,1,4,Qt::AlignCenter);
    layout->addWidget(button_off,0,0,1,4,Qt::AlignLeft);
    layout->addWidget(welcomeTxt,1,0,1,4,Qt::AlignCenter);
    layout->addWidget(namelbl,2,1,1,2,Qt::AlignBottom);
    layout->addWidget(newMission,3,1,1,2);//,Qt::AlignTop);
    layout->addWidget(btnNew,4,1,1,2);//,Qt::AlignTop);
    layout->addWidget(projectList,5,1,3,2,Qt::AlignTop);


    isOpen=false;

    //this->setWindowState( Qt::WindowFullScreen );

}

void intro::handleNewBtn(){

  if(newMission->text().compare("")){

#ifdef DEBUG_INTRO
      qDebug()<<"click new: "+newMission->text();
#endif


      QRegExp rx ("[^a-zA-Z0-9]");
      QString fixedName =newMission->text().replace(rx,"");

#ifdef DEBUG_INTRO
      qDebug()<<"click fixed: "+fixedName;
#endif


      if(fixedName.compare("")){
          runMission(fixedName);
      }
      else{
           showMessage("Invalid mission name");
           newMission->setText("");
      }

  }
  else{

#ifdef DEBUG_INTRO
        qDebug("campo de texto vacio");
#endif


       showMessage("Write the name of the new mission");
       newMission->setFocus();
  }
}

void  intro::showMessage(QString message){
    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.setIcon(QMessageBox::Warning);
    int x =this->x();
    int y =this->y();
    int h=this->height();
    int w=this->width();
    msgBox.setGeometry(x+(w/4),y+(h/2),100,100);
    msgBox.exec();
}

void intro::createProjectList(){

    QDirIterator it(missionsPath,QDir::NoDotAndDotDot | QDir::AllDirs);

    while (it.hasNext()) {
        QFileInfo Info(it.next());
        QString missionName = QString(Info.fileName());

#ifdef DEBUG_INTRO
        qDebug() <<missionName;
#endif


        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(QSize(item->sizeHint().width(), 60));

        myItem *myListItem = new myItem(0,missionName);
        connect(myListItem,SIGNAL(continueSignal(QString)),this,SLOT(runMission(QString)));
        connect(myListItem,SIGNAL(deleteSignal(QString,QListWidgetItem*)),this,SLOT(deleteMission(QString,QListWidgetItem*)));
        connect(myListItem,SIGNAL(exploreSignal(QString)),this,SLOT(exploreMission(QString)));
        exm->setMissionName(missionName);
        connect(myListItem,SIGNAL(exportSignal()),exm,SLOT(launchDialog()));



        projectList->addItem(item);
        projectList->setItemWidget(item, myListItem );
    }
}

void intro::runMission(QString missionName){
#ifdef DEBUG_INTRO
      qDebug() <<"continue "+missionName;
#endif

   //this->mission=new MissionWidget(0,missionName,this);
   //this->close();
   //mission->show();

}

void intro::exploreMission(QString missionName){

#ifdef DEBUG_INTRO
      qDebug() <<"explore "+missionName;
#endif
  //MissionExplorer *missionExplorer=new MissionExplorer(0,missionName);
  this->close();
  //missionExplorer->show();
}

void intro::deleteMission(QString missionName,QListWidgetItem *item){

    QString msg=QString("Are you sure?\nThe Mission %1 including all files are going to be deleted").arg(missionName);
    QMessageBox::StandardButton reply;

      reply = QMessageBox::warning(this, "Alert", msg, QMessageBox::Ok|QMessageBox::Cancel);
      if (reply == QMessageBox::Ok) {

#ifdef DEBUG_INTRO
       qDebug() <<"delete "+missionName;
#endif

          QString dirName=QString("%1/%2").arg(missionsPath).arg(missionName);

          QDir dir(dirName);

          if(dir.removeRecursively()){
            #ifdef DEBUG_INTRO
                   qDebug()<<"delete OK";
            #endif
              projectList->takeItem(projectList->row(item));

          }
          else{
            #ifdef DEBUG_INTRO
                      qDebug()<<"no delete";
            #endif
          }
      }

}

void intro::reOpen(){

    qDebug("RE OPEN");
    delete(projectList);
    projectList= new QListWidget();
    projectList->setSelectionMode (QAbstractItemView::NoSelection);
    projectList->setFixedHeight(150);
    createProjectList();
    layout->addWidget(projectList,5,1,2,2,Qt::AlignTop);

}

void intro::showEvent(QShowEvent *ev){
    qDebug("Show Event");

    if(isOpen)
       reOpen();

    isOpen=true;
}

void intro::handleButtonOff(){
    QString msg=QString("Are you sure? \n The robot is save? \n the system is going to turning off");
    QMessageBox::StandardButton reply;

    reply = QMessageBox::warning(this, "Alert", msg, QMessageBox::Ok|QMessageBox::Cancel);
    if (reply == QMessageBox::Ok)this->close();

}

