#include "exportmanager.h"
//#define DEBUG_EXPORT

extern QString createPath(QString path);

ExportManager::ExportManager(QWidget *parent,QString mission) :
    QWidget(parent)
{
  missionName=mission;
}


void ExportManager::getExternalDevices(){
    QProcess usbList;

    QString run= "df -h";
    usbList.start(run);
    usbList.waitForFinished();
    QString output( usbList.readAllStandardOutput());

#ifdef DEBUG_EXPORT
      qDebug("-----------EXTERNAL DEVICES-------------");
      qDebug()<<output;
#endif

    usbList.close();


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

        if(tempNames.size()==2){
          names.append(tempNames.at(tempNames.length()-1));
          QList<QString> tempfreeSpace=tempNames.at(0).split(" ", QString::SkipEmptyParts);
          freeSpace.append(tempfreeSpace.at(tempfreeSpace.length()-2));          
        }
#ifdef DEBUG_EXPORT
        qDebug()<<tempName;
#endif
    }

    for(int i=0;i<freeSpace.length();i++)
       bytesFreeSpace.append(toBytes(freeSpace.at(i)));


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


    msgBox.accept();

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
    getExternalDevices();

    int x =parentWidget()->x();
    int y = parentWidget()->y();
    int h= parentWidget()->height();
    int w=parentWidget()->width();
    msgBox.setGeometry(x+(w/3),y+(h/2),500,100);
    msgBox.setWindowTitle("Export to:");
    msgBox.setFixedSize(msgBox.width(), msgBox.height());

    QGridLayout *layout=new QGridLayout();



     for(int i=0; i<names.length();i++){
         myWidgetUsb *btn=new myWidgetUsb(this,i,checkUsb(i),names.at(i));
         connect(btn,SIGNAL(usbSelected(int)),this,SLOT(saveUsb(int)));
         layout->addWidget(btn);
    }


    msgBox.setLayout(layout);
    msgBox.exec();


}





