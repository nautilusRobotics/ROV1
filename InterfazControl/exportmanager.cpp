#include "exportmanager.h"

extern QString createPath(QString path);

ExportManager::ExportManager(QWidget *parent,QString mission) :
    QWidget(parent)
{
  missionName=mission;  
  isUSB=false;
  isSaving=false;
  x =parentWidget()->x();
  y = parentWidget()->y();
  h= parentWidget()->height();
  w=parentWidget()->width();
}


bool ExportManager::getExternalDevices(){
    names.clear();
    bytesFreeSpace.clear();

    bool usbConnected=false;
    QProcess usbList;

    QString run= "df";
    usbList.start(run);
    usbList.waitForFinished();
    QString output( usbList.readAllStandardOutput());
    usbList.close();


    qDebug("-----------EXTERNAL DEVICES-------------");
    qDebug()<<output;





    QList<QString> tempListNames=output.split("\n");
    tempListNames.removeAt(tempListNames.length()-1);


    qDebug("-----------SPLITED-------------");
    qDebug()<<QString("LENGTH %1").arg(tempListNames.length());


    QList<QString> tempFreeSpace;

    for(int i=0;i<tempListNames.length();i++){
        QString tempName=tempListNames.at(i);
        QList<QString> tempNames=tempName.split("/media/");        


       #ifdef Q_PROCESSOR_X86_64
        if(tempNames.size()==2){
          names.append(tempNames.at(tempNames.length()-1));
          QList<QString> tempfreeSpace=tempNames.at(0).split(" ", QString::SkipEmptyParts);          
          bytesFreeSpace.append((tempfreeSpace.at(tempfreeSpace.length()-2)).toUInt());
          usbConnected=true;
        }
       #endif

        #ifdef Q_PROCESSOR_ARM
        if(tempNames.size()==2){
          names.append(tempNames.at(tempNames.length()-1));

          if(names.at(0).compare("6B4C-FFFD")){
          QList<QString> tempfreeSpace=tempNames.at(0).split(" ", QString::SkipEmptyParts);
          bytesFreeSpace.append((tempfreeSpace.at(tempfreeSpace.length()-2)).toUInt());
          usbConnected=true;
          }
          else
           names.removeFirst();
        }
       #endif


        qDebug()<<tempName;

      }



    for(int i=0;i<bytesFreeSpace.length();i++)
        qDebug()<< bytesFreeSpace.at(i);



   return usbConnected;
}

quint64 ExportManager::toBytes(QString str){
    quint64 bytes=0;
    QString unit=str.at(str.length()-1);
    double num=str.mid(0,str.length()-1).toDouble();


    if(!unit.compare("G"))
        bytes= num*qPow(10,9);
    else if(!unit.compare("M"))
        bytes= num*qPow(10,6);
    else if(!unit.compare("K"))
        bytes= num*qPow(10,3);
    else
        bytes=num;


    qDebug()<<bytes;

    return bytes;
}

quint64 ExportManager::dir_size(const QString & str)
{
    quint64 sizex = 0;
    QFileInfo str_info(str);
    if (str_info.isDir())
    {
        QDir dir(str);
        QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs |  QDir::Hidden | QDir::NoSymLinks | QDir::NoDotAndDotDot);
        for (int i = 0; i < list.size(); ++i)
        {
            QFileInfo fileInfo = list.at(i);
            if(fileInfo.isDir())
            {
                    sizex += dir_size(fileInfo.absoluteFilePath());
            }
            else
                sizex += fileInfo.size();

        }
    }
    return sizex;
}

bool ExportManager::saveUsb(int indexUSB ){

    QString file=QString("%1/%2").arg(createPath("Missions")).arg(missionName);
    QString ext=QString("/media/%1/NautilusRobotics/").arg(names.at(indexUSB));

    ExportThread *exportT=new ExportThread(this,file,ext,missionName);
    connect(exportT,SIGNAL(saveFinish()),this,SLOT(acceptDialogs()));
    exportT->start();

    return true;

}

bool ExportManager::checkUsb(int indexUSB){
    if(dir_size(missionName)<bytesFreeSpace.at(indexUSB))
         return true;

    return false;
}

void ExportManager::setMissionName(QString missionName){
    this->missionName=missionName;
}

void ExportManager::launchDialog(){
    msgBox=new QDialog();
    msgBox->setGeometry(x+(w/3),y+(h/3),500,100);
    msgBox->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
   // msgBox->setWindowFlags(Qt::FramelessWindowHint);

    QGridLayout *layout=new QGridLayout();
    QLabel *titleLbl=new QLabel("Export to: ");
    titleLbl->setFocusPolicy(Qt::NoFocus);
    titleLbl->setStyleSheet("background-image: url(null);color: rgb(153, 153, 153);font: bold 11pt;");
    titleLbl->setFixedSize(482,45);
    layout->addWidget(titleLbl,0,0,1,1,Qt::AlignCenter);


    if(getExternalDevices()){     
        for(int i=0; i<names.length();i++){
            myWidgetUsb *btn=new myWidgetUsb(this,i,checkUsb(i),names.at(i));
            btn->setFixedSize(500,60);         
            layout->addWidget(btn);
        }
        isUSB=true;
    }
    else{
      titleLbl->setText("No USB devices");
      isUSB=false;
    }



   /****************Close Button********************************************/
    QLabel *hintlbl=new QLabel("");
    hintlbl->setFocusPolicy(Qt::NoFocus);
    hintlbl->setStyleSheet("background-image: url(:/new/prefix1/hintExport.png);");
    hintlbl->setFixedSize(482,45);
    layout->addWidget(hintlbl,layout->rowCount(),0,1,1,Qt::AlignCenter);
   /************************************************************************/
    msgBox->setLayout(layout);
    msgBox->adjustSize();
    msgBox->show();
}

void ExportManager::joystickButtonUSB(QString button,QGameControllerButtonEvent* event){
    qDebug()<<"Button Pressed";
    if(button==button_A && !event->pressed() && isUSB && !isSaving){
      rumble.start(createPath("rumbleGamepad.o"));
      isSaving=true;

      loadingBox=new QDialog();
      loadingBox->setGeometry(x+(w/3),y+(h/3),522,183);
      loadingBox->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);

      QGridLayout *loadingBoxlayout=new QGridLayout();
      QLabel *loadingTitleLbl=new QLabel("Saving ... ");
      loadingTitleLbl->setFocusPolicy(Qt::NoFocus);
      loadingTitleLbl->setStyleSheet("background-image: url(null);color: rgb(153, 153, 153);font: bold 13pt;");
      loadingTitleLbl->setFixedSize(482,45);
      loadingBoxlayout->addWidget(loadingTitleLbl,0,0,1,1,Qt::AlignCenter);

      QMovie *movie=new QMovie(":/new/prefix1/loadingBar.gif");
      QLabel *loadingLbl=new QLabel();
      loadingLbl->setFixedSize(280,45);
      loadingLbl->setMovie(movie);
      movie->start();

      loadingBoxlayout->addWidget(loadingLbl,1,0,1,1,Qt::AlignCenter);
      loadingBox->setLayout(loadingBoxlayout);
      loadingBox->show();

      saveUsb(0);
    }
    else if(button==button_A && !event->pressed() && !isUSB){
        rumble.start(createPath("rumbleGamepad.o"));
        emit success(false);
        msgBox->accept();
    }
    else if(button==button_B && !event->pressed() && !isSaving){
       rumble.start(createPath("rumbleGamepad.o"));
       emit success(false);       
       msgBox->accept();       
    }
}

/*
void ExportManager::joystickAxisUSB(QString axis, int value){

}
*/


void ExportManager::acceptDialogs(){
    qDebug()<<"Saved..";
    loadingBox->accept();
    msgBox->accept();
    sleep(0.6);
    emit success(true);
}



