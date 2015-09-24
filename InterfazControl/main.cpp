#include <main.h>



int main(int argc, char *argv[])
{
    //------------------------------Init------------------------------------------
    QApplication app(argc, argv);


    intro welcomeScreen;
    welcomeScreen.show();


    return app.exec();
}

QString createPath(QString path){
  QString fullPath;
  #ifdef Q_PROCESSOR_X86
      fullPath=QDir::currentPath();
      qDebug("INTELPROCESSOR");
  #endif

  #ifdef Q_PROCESSOR_ARM
      fullPath="/home/olimex/Documents/ROV1/InterfazControl"
      qDebug("OLIMEX PROCESSOR");
  #endif
  return QString("%1/%2").arg(fullPath).arg(path);
}




