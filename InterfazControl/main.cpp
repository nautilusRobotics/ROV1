#include <main.h>


int main(int argc, char *argv[])
{
#ifdef Q_PROCESSOR_X86
    fullPath=QDir::currentPath();
    qDebug("INTELPROCESSOR");
#endif

#ifdef Q_PROCESSOR_ARM
    fullPath="/mnt/disk1/NautilusOne";
    qDebug("OLIMEX PROCESSOR");
#endif

    //------------------------------Init------------------------------------------
    QApplication app(argc, argv);


    MainApp welcomeScreen;
 qDebug("start showing gui...");
    welcomeScreen.show();
 qDebug("gui showed...");



    return app.exec();
}

QString createPath(QString path){
  return QString("%1/%2").arg(fullPath).arg(path);
}




