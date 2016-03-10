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

    QString s1=QString("pic_1.pvd");
    QString s2=QString("pic_10.pvd");
    QString s3=QString("pic_100.pvd");

    s1.remove(QRegExp("[pic_.vd]"));
    s2.remove(QRegExp("[pic_.vd]"));
    s3.remove(QRegExp("[pic_.vd]"));


    qDebug()<<s1;
    qDebug()<<s2;
    qDebug()<<s3;

    //------------------------------Init------------------------------------------
    QApplication app(argc, argv);
    app.setOverrideCursor( QCursor( Qt::BlankCursor ) );
    MainApp welcomeScreen;    
    welcomeScreen.show();

    return app.exec();
}

QString createPath(QString path){
  return QString("%1/%2").arg(fullPath).arg(path);
}




