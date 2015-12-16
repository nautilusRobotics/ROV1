#include "datathread.h"

extern QString createPath(QString path);

DataThread::DataThread(QProgressBar *bc)
{
   timer=new QTimer();
   batteryControl=bc;
   valueTest=0;
}


void DataThread::run()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);

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
        qDebug()<<"ControlBattery Level: "+output;
        batteryControl->setValue(output.toInt());
        //output=output.mid(output.size()-5,output.size());
        procRun.close();
#endif
#ifndef Q_PROCESSOR_ARM
         batteryControl->setValue(valueTest);
         valueTest++;
#endif

}
