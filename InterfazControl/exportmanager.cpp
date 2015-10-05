#include "exportmanager.h"
#define DEBUG_EXPORT

extern QString createPath(QString path);

ExportManager::ExportManager(QWidget *parent,QString mission) :
    QWidget(parent)
{
  missionName=mission;
  layout=new QGridLayout();
  msgBox=new QDialog();
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

#ifdef DEBUG_EXPORT
      qDebug("-----------EXTERNAL DEVICES-------------");
      qDebug()<<output;
#endif




    QList<QString> tempListNames=output.split("\n");
    tempListNames.removeAt(tempListNames.length()-1);

  #ifdef DEBUG_EXPORT
    qDebug("-----------SPLITED-------------");
    qDebug()<<QString("LENGTH %1").arg(tempListNames.length());
  #endif

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

#ifdef DEBUG_EXPORT
        qDebug()<<tempName;
#endif
      }


#ifdef DEBUG_EXPORT
    for(int i=0;i<bytesFreeSpace.length();i++)
        qDebug()<< bytesFreeSpace.at(i);

#endif

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

#ifdef DEBUG_EXPORT
    qDebug()<<bytes;
#endif
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

    if(!QDir(ext).exists())
        QDir().mkpath(ext);

    QProcess copyFiles;
    QString run=QString("cp -r %1 %2").arg(file).arg(ext);
    copyFiles.start(run);
    copyFiles.waitForFinished();


   QProcess fixFiles;
   QString fix=QString("rm %1%2/settings.ini %1%2/thumb.sh").arg(ext).arg(missionName);
   fixFiles.start(fix);
   fixFiles.waitForFinished();


    msgBox->accept();

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


    int x =parentWidget()->x();
    int y = parentWidget()->y();
    int h= parentWidget()->height();
    int w=parentWidget()->width();

    delete(msgBox);
    msgBox=new QDialog();
    msgBox->setGeometry(x+(w/3),y+(h/2),500,100);
    //msgBox.setFixedSize(msgBox.width(), msgBox.height());
    msgBox->setWindowFlags( Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint );

    //delete(layout);
    layout=new QGridLayout();

    /*
    int rowCount=layout->rowCount();
    qDebug()<<"ROW COUNT"+rowCount;
    for(int i=0; i<rowCount ;i++){
       layout->takeAt(i);
       delete(layout->itemAt(i));
    }*/


    if(getExternalDevices()){
         msgBox->setWindowTitle("Export to:");
        for(int i=0; i<names.length();i++){
            myWidgetUsb *btn=new myWidgetUsb(this,i,checkUsb(i),names.at(i));
            btn->setFixedSize(500,60);
            connect(btn,SIGNAL(usbSelected(int)),this,SLOT(saveUsb(int)));
            layout->addWidget(btn);
        }
    }
    else
    msgBox->setWindowTitle("No USB devices");

   /****************Close Button********************************************/
    QPushButton *closeBtn=new QPushButton(" Close");
    closeBtn->setIcon(QIcon(createPath("icons/close.png")));
    closeBtn->setIconSize(QSize(32,32));
    closeBtn->setFocusPolicy(Qt::NoFocus);
    closeBtn->setStyleSheet("QPushButton{font-size:15px;font-weight:bold;color:black;background:#EE4545}");
    closeBtn->setFixedSize(482,45);
    connect(closeBtn,SIGNAL(released()),this,SLOT(cancelDialog()));
    qDebug()<<"ROW COUNT POSt"+layout->rowCount();
    layout->addWidget(closeBtn,layout->rowCount(),0,1,1,Qt::AlignCenter);
   /************************************************************/


    msgBox->setLayout(layout);
    msgBox->adjustSize();
    msgBox->exec();


}

void ExportManager::cancelDialog(){
    msgBox->accept();

}



