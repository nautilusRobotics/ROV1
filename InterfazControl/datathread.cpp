#include "datathread.h"


extern QString createPath(QString path);

DataThread::DataThread(QProgressBar *bc, QProgressBar *br)
{
   qDebug("Data Thread");
   batteryControl=bc;  
   batteryRobot=br;
   valueTest=0;
   robotBattery=0;

   server=new QTcpServer(this);
   connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));

   if(server->listen(QHostAddress::Any,8888))
       qDebug("Server Listening ....");
   else
       qDebug("Server Listening EROR");

   //update();
}


void DataThread::run(){
    while(!this->isFinished()){
        if(newMessage){
           update();
           newMessage=false;
        }
    }
       qDebug("finish Thread");
}

void DataThread::stop()
{
    qDebug("Stop Thread");
    server->close();
    quit(); // terminate thread
}

void DataThread::update(){
#ifdef Q_PROCESSOR_ARM
        QString run=createPath("battSense.sh");
        QProcess procRun;
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
         valueTest=(valueTest<100)?valueTest+1:0;
#endif

         batteryRobot->setValue(robotBattery);
}

void DataThread::closeServer(){
    server->close();
}


void DataThread::newConnection(){
   qDebug("new Connection");
   socket=server->nextPendingConnection();
   socket->setReadBufferSize(8);
   connect(socket, SIGNAL(readyRead()),this, SLOT(startRead()));
   connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
}

void DataThread::disconnected(){
   qDebug("Disconected");
}

void DataThread::startRead(){
    newMessage=true;    
    int sn=socket->bytesAvailable();
    qDebug("socket bytes %d",sn);   
    QString clientMessage=QString(socket->read(socket->bytesAvailable()));   
    robotBattery=clientMessage.toInt();
    qDebug()<<"cliente"+clientMessage;
    qDebug("Robot battery %d",robotBattery);
}



