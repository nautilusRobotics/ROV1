#include "sendaction.h"
//#define OFFLINE

SendAction::SendAction(QWidget *parent) : QWidget(parent){    
    cliente = new QTcpSocket(this);
    connect(cliente, SIGNAL(connected()),this, SLOT(connected()));
    connect(cliente, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(cliente, SIGNAL(readyRead()), SLOT(readyRead()));

    serverResp=QString("");
    txServer=false;
    conection=false;
}

QString SendAction::sendComando(QString comando){
    comando=comando.append("\n");
    qDebug()<<"comando: "+comando;
    QByteArray data=comando.toLocal8Bit();
    cliente->write(data);
    //cliente->waitForBytesWritten();
    if(comando.at(0)==QChar(REQUEST_KEY_CHAR)){         
         txServer=false;
         cliente->waitForReadyRead();
         qDebug()<<"final server resp"+serverResp;
         return serverResp;
    }    
    return "";
}

void SendAction::conectClient(){ 
    qDebug()<<"Connecting Client";    
    cliente->connectToHost(ROBOT_IP, 50002);
    cliente->waitForConnected();
}

void SendAction::readyRead(){
  QByteArray data = cliente->readAll();
  serverResp=QString(data);
  txServer=true;  
}

void SendAction::connected(){    
    qDebug() << "Connected...";    
    conection=true;
}

bool SendAction::isConnected(){
#ifdef OFFLINE
    return true;
#endif
    return conection;
}

void SendAction::disconnected(){    
    qDebug() << "disconnected...";    
    conection=false;
    emit offline();
}

SendAction::~SendAction (){
    cliente->close();
}
