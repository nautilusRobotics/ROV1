#include "intro.h"


//#define DEBUG_INTRO


intro::intro(QWidget *parent) :
    QWidget(parent)
{


    QIcon icon("./icons/nautilus128x128.svg");
    setWindowIcon(icon);
    setWindowTitle("Nautilus Commander");
    const QRect rec = QApplication::desktop()->screenGeometry();
    setGeometry(rec);

    /*setGeometry(0,0,1000,1000);
    setGeometry(
    QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        ));*/


    QPixmap bkgnd("./icons/intro.jpeg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);


    layout=new QGridLayout(this);
    this->setLayout(layout);

    logo=new QLabel("<img src=\"./icons/nautilus128x128.svg\">");



    welcomeTxt=new QLabel("WELCOME TO NAUTILUS COMMANDER");
    welcomeTxt->setStyleSheet("QLabel{font-size:40px;font-weight:bold;}");




    btnNew= new QPushButton("Start New Mission");
    btnNew->setIcon(QIcon( "./icons/new32.png"));
    btnNew->setIconSize(QSize(32,32));
    btnNew->setStyleSheet("QPushButton{font-size:20px;font-weight:bold;color:white;background:#295BFF}QPushButton:hover:!pressed {background:#4873FF}");
    btnNew->setFocusPolicy(Qt::NoFocus);

    connect(btnNew,SIGNAL(released()),this,SLOT(handleNewBtn()));

    newMission=new QLineEdit();
    namelbl=new QLabel("Enter the name of your mission:");
    namelbl->setStyleSheet("QLabel{font-size:20px;font-weight:bold;}");


    projectList= new QListWidget();
    exm=new ExportManager(this);
    createProjectList();
    projectList->setSelectionMode (QAbstractItemView::NoSelection);
    projectList->setFixedHeight(150);


    layout->addWidget(logo,0,0,1,4,Qt::AlignCenter);
    layout->addWidget(welcomeTxt,1,0,1,4,Qt::AlignCenter);
    layout->addWidget(namelbl,2,1,1,2,Qt::AlignBottom);
    layout->addWidget(newMission,3,1,1,2);//,Qt::AlignTop);
    layout->addWidget(btnNew,4,1,1,2);//,Qt::AlignTop);
    layout->addWidget(projectList,5,1,2,2,Qt::AlignTop);


    if(!QDir("./Missions").exists()){
        QDir().mkdir("./Missions");
    }




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

    QDirIterator it("./Missions",QDir::NoDotAndDotDot | QDir::AllDirs);

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
        myListItem->setWItem(item);


        projectList->addItem(item);
        projectList->setItemWidget(item, myListItem );
    }
}

void intro::runMission(QString missionName){
#ifdef DEBUG_INTRO
      qDebug() <<"continue "+missionName;
#endif

   this->mission=new MissionWidget(0,missionName);
   this->close();
   mission->show();
}

void intro::exploreMission(QString missionName){

#ifdef DEBUG_INTRO
      qDebug() <<"explore "+missionName;
#endif
  MissionExplorer *missionExplorer=new MissionExplorer(0,missionName);
  this->close();
  missionExplorer->show();
}

void intro::deleteMission(QString missionName,QListWidgetItem *item){

    QString msg=QString("Are you sure?\nThe Mission %1 including all files are going to be deleted").arg(missionName);
    QMessageBox::StandardButton reply;

      reply = QMessageBox::warning(this, "Alert", msg, QMessageBox::Ok|QMessageBox::Cancel);
      if (reply == QMessageBox::Ok) {

#ifdef DEBUG_INTRO
       qDebug() <<"delete "+missionName;
#endif

          QString dirName=QString("./Missions/%1").arg(missionName);

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

