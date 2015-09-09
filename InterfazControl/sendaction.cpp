#include "sendaction.h"

#define USER_DEBUG_SA


SendAction::SendAction(QWidget *parent) : QWidget(parent){
  robotIp="10.5.5.103 ";
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

void SendAction::buttonEvent(QString button, QGameControllerButtonEvent *event){
#ifdef USER_DEBUG_SA
     qDebug("handle button");
#endif
     if(button==button_A){         
         double scaleFactor=1;
         /*double depth=sendComando(GET_DEPTH).toDouble()*scaleFactor;
         emit changeDepth(depth);*/
         emit changeDepth(1.2);

     }
     else if(button==button_back){
         sendComando(CLOSE_ROBOT);
     }
     else if(button==button_B){

        if(!event->pressed()){   //Just when button is released


        emit takeScreenshot();

            #ifdef USER_DEBUG_SA
                 qDebug("released B");
            #endif
         }
     }
     else if(button==button_Y){
         if(!event->pressed()){   //Just when button is released


         emit saveVideo();

             #ifdef USER_DEBUG_SA
                  qDebug("released Y");
             #endif
          }
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



SendAction::~SendAction (){

}
