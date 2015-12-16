#include "datathread.h"

extern QString createPath(QString path);

DataThread::DataThread(QProgressBar *bc)
{
   timer=new QTimer();
   batteryControl=bc;
   batteryControl->setStyleSheet(QSTYLE_PROGRESS_BATT_CONTROL);
   valueTest=10;
   update();
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
        output=output.mid(0,output.size()-3);
        qDebug()<<"ControlBattery Level: "+output;
        batteryControl->setValue(output.toInt());        
        procRun.close();
#endif
#ifndef Q_PROCESSOR_ARM
         batteryControl->setValue(valueTest);
         valueTest++;
#endif

}
