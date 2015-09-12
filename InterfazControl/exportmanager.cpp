#include "exportmanager.h"
#define DEBUG_EXPORT

ExportManager::ExportManager(QObject *parent, QString missionName) :
    QObject(parent)
{
    this->missionName=missionName;
    getExternalDevices();
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


    qDebug("-----------SPLITED-------------");
    qDebug()<<QString("LENGTH %1").arg(tempListNames.length());

    QList<QString> tempFreeSpace;

    for(int i=0;i<tempListNames.length();i++){
        QString tempName=tempListNames.at(i);
        QList<QString> tempNames=tempName.split("/media/");

        if(tempNames.size()==2){
          names.append(tempNames.at(tempNames.length()-1));
          QList<QString> tempfreeSpace=tempNames.at(0).split(" ", QString::SkipEmptyParts);
          freeSpace.append(tempfreeSpace.at(tempfreeSpace.length()-2));
        }
        qDebug()<<tempName;
    }



    quint64 value=dir_size("./Missions/Mission1");
    qDebug()<<QString("FILE SIZE: %1").arg(value);
}

int ExportManager::toBytes(QString str){
    int megas=0;
    QString unit=str.at(str.length());

   // if(unit.compare("G"))
        //megas=str.

    return megas;
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
