#include "sendaction.h"

#define USER_DEBUG_SA
#define OFFLINE_SA

extern QString createPath(QString path);

SendAction::SendAction(QWidget *parent) : QWidget(parent){
  robotIp="10.5.5.103 ";
}

QString SendAction::sendComando(QString comando){

#ifdef Q_PROCESSOR_X86
     QString run= createPath("cliente.o ")+robotIp+comando;
#endif

#ifdef Q_PROCESSOR_ARM
    QString run= createPath("clienteOlimex.o ")+robotIp+comando;
#endif

    qDebug() << run;

#ifndef OFFLINE_SA
        procRun.start(run);
        procRun.waitForFinished(500);
        QString output( procRun.readAllStandardOutput());
    #ifdef USER_DEBUG_SA
          qDebug()<<"server Resp "+output;
    #endif
        output=output.mid(0,5);

        procRun.close();
        return output;
#else
    return "offline";
#endif


}

SendAction::~SendAction (){

}
