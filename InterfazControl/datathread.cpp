#include "datathread.h"


extern QString createPath(QString path);

DataThread::DataThread(QProgressBar *bc, QProgressBar *br, QLabel *depth)
{
   qDebug("Data Thread");
   batteryControl=bc;  
   batteryRobot=br;
   labelDepth=depth;
   valueTest=0;
   robotBattery=0;
   robotDepth="0";

   server=new QTcpServer(this);
   connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));
   connect(this,SIGNAL(controlStatus(int)),batteryControl,SLOT(setValue(int)));
   connect(this,SIGNAL(rovStatus(int)),batteryRobot,SLOT(setValue(int)));
   connect(this,SIGNAL(rovDepthStatus(QString)),labelDepth,SLOT(setText(QString)));

   if(server->listen(QHostAddress::Any,8888))
       qDebug("Server Listening ....");
   else
       qDebug("Server Listening EROR");

   //update();
}


void DataThread::run(){
       qDebug("Running Server");
    while(!this->isFinished()){
        if(newMessage){
           qDebug("New Message");
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

        emit controlStatus(output.toInt());
        procRun.close();        

#endif
#ifndef Q_PROCESSOR_ARM
         qDebug()<<"Update Q_PROCCESSOR_ARM "+ QString().number(valueTest);
         batteryControl->setValue(valueTest);
         valueTest=(valueTest<100)?valueTest+1:0;
#endif

         emit  rovStatus(robotBattery);
         emit rovDepthStatus(robotDepth);
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
    QString battString=clientMessage.mid(4,3);
    QString depthString=clientMessage.mid(0,4);
    robotBattery=battString.toInt();
    robotDepth=QString().number(depthString.toInt());
    qDebug("Robot battery %d",robotBattery);
    qDebug()<<"Robot depth "+robotDepth;
}



