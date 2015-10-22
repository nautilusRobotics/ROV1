#include "sendaction.h"

#define USER_DEBUG_SA
extern QString createPath(QString path);

SendAction::SendAction(QWidget *parent) : QWidget(parent){
  robotIp="10.5.5.103 ";
}

void SendAction::axisEvent(QString axis,int value){
#ifdef USER_DEBUG_SA
     qDebug("axis  %d",value);
#endif

    if(axis== axis_right_vertical){
//        if(value>=999)
//            sendComando(DOWN_ROBOT);
//        else if(value<=-999)
//            sendComando(UP_ROBOT);
    }
    else if(axis==axis_left_vertical){
        if(value<=0){
            QString mappedSpeed=mapSpeed(-value);
            QString strToSend=QString("%1%2").arg(FORWARD_ROBOT).arg(mappedSpeed);
            sendComando(strToSend);
        }
    }
    else if(axis==axis_cross_vertical && value<0){
            sendComando(UP_CAMARA);
    }
    else if(axis==axis_cross_vertical && value>0){
            sendComando(DOWN_CAMARA);
    }
    else if(axis==axis_cross_vertical && value==0){
            sendComando(NULL_CMD);
    }

}

QString SendAction::mapSpeed(int value){
   double m=(double) (maxESCms-minESCms)/(maxControl-minControl);
#ifdef USER_DEBUG_SA
     qDebug()<<"m "<<m;
#endif
   double b=minESCms-(m*minControl);
   int speed=m*value+b;

   return QString("%1").arg(speed);
}

void SendAction::buttonEvent(QString button, QGameControllerButtonEvent *event){
#ifdef USER_DEBUG_SA
     qDebug("handle button");
#endif

     if(button==button_A && !event->pressed()){
         double scaleFactor=1;
         /*double depth=sendComando(GET_DEPTH).toDouble()*scaleFactor;
         emit changeDepth(depth);*/
         emit changeDepth(1.2);

     }
     else if(button==button_back && !event->pressed()){

          sendComando(CLOSE_ROBOT);

             #ifdef USER_DEBUG_SA
                  qDebug("==================================================================released Back==================================================================");
             #endif


     }
     else if(button==button_B && !event->pressed()){
        emit takeScreenshot();

            #ifdef USER_DEBUG_SA
                 qDebug("released B");
            #endif

     }
     else if(button==button_Y && !event->pressed()){
         emit saveVideo();

             #ifdef USER_DEBUG_SA
                  qDebug("released Y");
             #endif

     }
     else if(button==button_X && !event->pressed()){
         sendComando(TOGGLE_LIGHT);
         sendComando(NULL_CMD);
          #ifdef USER_DEBUG_SA
                 qDebug("released X");
          #endif
     }




}

QString SendAction::sendComando(QString comando){
    QString run= createPath("cliente.o ")+robotIp+comando;
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
