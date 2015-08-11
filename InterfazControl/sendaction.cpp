#include "sendaction.h"


#define USER_DEBUG_SA

SendAction::SendAction(QWidget *parent) :
    QWidget(parent)
{    
  robotIp="10.5.5.103 ";

  QVBoxLayout *layout = new QVBoxLayout(this);

  label_depth.setText("DEPTH: ");
  layout->addWidget(&label_depth,1,0);

}

void SendAction::axisEvent(QString axis,int value){
#ifdef USER_DEBUG_SA
     qDebug("axis  %d",value);
#endif

    if(axis== axis_right_vertical){
        if(value>=999)
            sendComando(DOWN_ROBOT);
        else if(value<=-999)
            sendComando(UP_ROBOT);
    }

}


void SendAction::buttonEvent(QString button){
#ifdef USER_DEBUG_SA
     qDebug("handle button");
#endif
     if(button==button_A){
         label_depth.setText("DEPTH: "+ sendComando(GET_DEPTH));
     }
     else if(button==button_back){
         sendComando(CLOSE_ROBOT);
     }

}

QString SendAction::sendComando(QString comando){
    QString run= "./cliente.o "+robotIp+comando;
    qDebug() << run;
    procRun.start(run);
    procRun.waitForFinished();
    QString output( procRun.readAllStandardOutput());
#ifdef USER_DEBUG_SA
      qDebug()<<output;
#endif
    output=output.mid(output.size()-5,output.size());
    procRun.close();
    return output;
}


SendAction::~SendAction ()
{

}
