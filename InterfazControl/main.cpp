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
    app.setOverrideCursor( QCursor( Qt::BlankCursor ) );

    QPixmap pixmap(createPath("icons/explorerDefault.png"));
    QSplashScreen splash(pixmap);
    splash.show();
    app.processEvents();
    splash.showMessage("Loading gui..");
    MainApp welcomeScreen;
    splash.showMessage("Loaded gui");
    welcomeScreen.show();

    splash.finish(&welcomeScreen);



    return app.exec();
}

QString createPath(QString path){
  return QString("%1/%2").arg(fullPath).arg(path);
}




