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
    layout->addWidget(logo,0,0,1,4);
    layout->setAlignment(logo, Qt::AlignCenter);

    welcomeTxt=new QLabel("WELCOME TO NAUTILUS COMMANDER");
    welcomeTxt->setStyleSheet("QLabel{font-size:40px;font-weight:bold;}");

    layout->addWidget(welcomeTxt,1,0,1,4);
    layout->setAlignment(welcomeTxt, Qt::AlignCenter);

    btnNew= new QPushButton("Start New Mission");
    btnNew->setIcon(QIcon( "./icons/new32.png"));
    btnNew->setIconSize(QSize(32,32));
    btnNew->setStyleSheet("QPushButton{font-size:20px;font-weight:bold;background:#58FA58}QPushButton:hover:!pressed {background:#A9F5A9}");
    btnNew->setFocusPolicy(Qt::NoFocus);

    connect(btnNew,SIGNAL(released()),this,SLOT(handleNewBtn()));

    newMission=new QLineEdit();
    namelbl=new QLabel("Enter the name of your mission:");
    namelbl->setStyleSheet("QLabel{font-size:20px;font-weight:bold;}");


   /* openlbl=new QLabel("Or open a recent Mission:");
    openlbl->setStyleSheet("QLabel{font-size:20px;font-weight:bold;}");*/



    btnOpen= new QPushButton("Open Mission");
    btnOpen->setIcon(QIcon( "./icons/folder32.png"));
    btnOpen->setIconSize(QSize(32,32));
    btnOpen->setStyleSheet("QPushButton{font-size:20px;font-weight:bold;background:#A4A4A4} QPushButton:hover:!pressed {background:#D8D8D8}" );
    btnOpen->setFocusPolicy(Qt::NoFocus);
    connect(btnOpen,SIGNAL(released()),this,SLOT(handleOpenBtn()));



    layout->addWidget(namelbl,2,1,1,2);
    layout->addWidget(newMission,3,1,1,2);
    layout->addWidget(btnNew,4,1,1,2);
    layout->addWidget(btnOpen,5,1,2,2,Qt::AlignTop);


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
          this->hide();
          this->mission=new MissionWidget(0,str);
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

void intro::handleOpenBtn(){
    qDebug("click open");
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
