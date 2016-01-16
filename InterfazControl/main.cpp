#include <main.h>


int main(int argc, char *argv[])
{
#ifdef Q_PROCESSOR_X86
    fullPath=QDir::currentPath();
    qDebug("INTELPROCESSOR");
#endif

#ifdef Q_PROCESSOR_ARM
    fullPath="/home/olimex/Documents/ROV1/InterfazControl";
    qDebug("OLIMEX PROCESSOR");
#endif

    //------------------------------Init------------------------------------------
    QApplication app(argc, argv);


    MainApp welcomeScreen;
    welcomeScreen.show();



    return app.exec();
}

QString createPath(QString path){
  return QString("%1/%2").arg(fullPath).arg(path);
}




