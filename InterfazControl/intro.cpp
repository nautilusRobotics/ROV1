#include "intro.h"

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

      qDebug()<<"click new: "+newMission->text();


      QRegExp rx ("[^a-zA-Z0-9]");
      QString str =newMission->text().replace(rx,"");

      qDebug()<<"click fixed: "+str;

      if(str.compare("")){
          this->mission=new MissionWidget(0,str);
          this->close();
          mission->show();
      }
      else{
           showMessage("Invalid mission name");
           newMission->setText("");
      }

  }
  else{
       qDebug("vacio");
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
        qDebug() <<missionName;

        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(QSize(item->sizeHint().width(), 60));

        myItem *myListItem = new myItem(0,missionName);
        connect(myListItem,SIGNAL(continueSignal(QString)),this,SLOT(continueMission(QString)));
        connect(myListItem,SIGNAL(deleteSignal(QString,QListWidgetItem*)),this,SLOT(deleteMission(QString,QListWidgetItem*)));
        connect(myListItem,SIGNAL(exploreSignal(QString)),this,SLOT(exploreMission(QString)));
        myListItem->setWItem(item);


        projectList->addItem(item);
        projectList->setItemWidget(item, myListItem );
    }
}

void intro::continueMission(QString missionName){
   qDebug() <<"continue "+missionName;


   QString path=QString("./Missions/%1/prefs.mission").arg(missionName);
   qDebug()<<path;
   QFile file(path);

   if(!file.open(QIODevice::ReadOnly))
       QMessageBox::information(0, "error","Error Loading Mission");

   else{
       QTextStream in(&file);
       QString videos = in.readLine();
       QString pics = in.readLine();
       file.close();
       int videoCount=videos.mid(2,videos.length()).toInt();
       int picCount=pics.mid(2,pics.length()).toInt();
       qDebug()<< "video count: "+videoCount;
       qDebug()<< "pic count: "+picCount;
       this->mission=new MissionWidget(0,missionName,videoCount,picCount);
       this->close();
       mission->show();
   }


}

void intro::exploreMission(QString missionName){
  qDebug() <<"explore "+missionName;
  MissionExplorer *missionExplorer=new MissionExplorer(0,missionName);
  this->close();
  missionExplorer->show();
}

void intro::deleteMission(QString missionName,QListWidgetItem *item){

    QString msg=QString("Are you sure?\nThe Mission %1 including all files are going to be deleted").arg(missionName);
    QMessageBox::StandardButton reply;

      reply = QMessageBox::warning(this, "Alert", msg, QMessageBox::Ok|QMessageBox::Cancel);
      if (reply == QMessageBox::Ok) {
          qDebug() <<"delete "+missionName;
          QString dirName=QString("./Missions/%1").arg(missionName);

          QDir dir(dirName);

          if(dir.removeRecursively()){
              qDebug()<<"delete OK";
              projectList->takeItem(projectList->row(item));

          }
          else{
              qDebug()<<"no delete";
          }
      }

}

