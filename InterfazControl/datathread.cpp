#include "datathread.h"


extern QString createPath(QString path);

DataThread::DataThread(QProgressBar *bc, QProgressBar *br)
{
   timer=new QTimer();
   batteryControl=bc;  
   batteryRobot=br;
   valueTest=10;
   update();
   sendAction=new SendAction();
}


void DataThread::run()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(5000);

    while(1){

    }

}

void DataThread::update(){
        //qDebug()<<"update Data Thread";
#ifdef Q_PROCESSOR_ARM
        QString run=createPath("battSense.py");
        procRun.start(run);
        procRun.waitForFinished();
        QString output(procRun.readAllStandardOutput());

        if(output.compare("100\n"))
            output=output.mid(0,output.size()-3);
        else
         output=output.mid(0,output.size()-1);

        //qDebug()<<"ControlBattery Level: "+output;

        batteryControl->setValue(output.toInt());        
        procRun.close();        

#endif
#ifndef Q_PROCESSOR_ARM
         batteryControl->setValue(valueTest);
         valueTest++;
#endif

#ifndef OFFLINE_SA
         /*GetRobot Battery*/
        // QString batteryStatus=sendAction->sendComando(GET_BATTERY);
        // batteryRobot->setValue(batteryStatus.toInt());
#endif

}



