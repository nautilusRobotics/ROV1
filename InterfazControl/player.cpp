#include "player.h"

Player::Player(const QStringList &args, const QString &url, QWidget *parent, QLabel *nstatus): QMPwidget(parent), m_url(url){

    connect(this, SIGNAL(stateChanged(int)), this, SLOT(stateChanged(int)));

    qDebug("player Init");

    status=nstatus;

    status->setText("Camara1: Desconectada");
    status->setStyleSheet("QLabel {  color : red; }");
    enableCount=true;

    QMPwidget::start(args);


}


    void Player::stateChanged(int state){
          qDebug("StateChange");


        if (state == QMPwidget::NotStartedState) {
            QApplication::exit();
             qDebug("NotStarted");
        }
        else if (state == QMPwidget::PlayingState && mediaInfo().ok) {
            qDebug("Playing");
            status->setText("Camara1: Conectada");
            status->setStyleSheet("QLabel {  color : green; }");

            if (parentWidget()) {
               //parentWidget()->resize(mediaInfo().size.width(), mediaInfo().size.height()); 
               parentWidget()->resize(1280, 720);
            } else {
                resize(mediaInfo().size.width(), mediaInfo().size.height());
            }
        }
        else if(state==QMPwidget::IdleState){
             qDebug("IdleState");

            if(enableCount){
               status->setText("Camara1: Desconectada");
               status->setStyleSheet("QLabel {  color : red; }");
            }

        }      
        else if(state==QMPwidget::LoadingState){
              qDebug("LoadingState");
        }



    }


    void Player:: showEvent(QShowEvent *event){
        qDebug("Show Event");

        if (!event->spontaneous() && state() == QMPwidget::IdleState) {
            QMPwidget::load(m_url);

        }
    }




