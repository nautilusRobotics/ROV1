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
  QString fullPath=QDir::currentPath();
  return QString("%1/%2").arg(fullPath).arg(path);
}




