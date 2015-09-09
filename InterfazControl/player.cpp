#include "player.h"
//#define DEBUG_PLAYER

Player::Player(const QStringList &args, const QString &url, QWidget *parent): QMPwidget(parent), m_url(url),arguments(args){

    connect(this, SIGNAL(stateChanged(int)), this, SLOT(stateChanged(int)));

    #ifdef DEBUG_PLAYER
        qDebug("player Init");
    #endif


    enableCount=true;

    QMPwidget::start(args);

}


    void Player::stateChanged(int state){

        #ifdef DEBUG_PLAYER
              QString dbg=QString("StateChange %1").arg(state);
              qDebug()<<dbg;
        #endif


        if (state == QMPwidget::NotStartedState) {
            QApplication::exit();

        #ifdef DEBUG_PLAYER
             qDebug("NotStarted");
        #endif

        }
        else if (state == QMPwidget::PlayingState && mediaInfo().ok) {

        #ifdef DEBUG_PLAYER
             qDebug("Playing");
        #endif
            emit updateStatus(true);
            emit newState(QMediaPlayer::PlayingState);

        }
        else if(state==QMPwidget::IdleState){
            #ifdef DEBUG_PLAYER
                 qDebug("IdleState");
            #endif

            if(enableCount){               
                emit updateStatus(false);
            }


        }      
        else if(state==QMPwidget::LoadingState){
            #ifdef DEBUG_PLAYER
                 qDebug("LoadingState");
            #endif
        }
        else if(state==QMPwidget::PausedState){
#ifdef DEBUG_PLAYER
            qDebug("PausedState");
#endif

            emit newState(QMediaPlayer::PausedState);
        }




    }


    void Player:: showEvent(QShowEvent *event){
        #ifdef DEBUG_PLAYER
             qDebug("showEvent");
        #endif

        if (!event->spontaneous() && state() == QMPwidget::IdleState) {
            QMPwidget::load(m_url);

        }
    }


    void Player::play(){
        QMPwidget::play();
    }
    void Player:: pause(){
        QMPwidget::pause();
    }
    void Player::reload(){
        QMPwidget::QMPwidget::seek(0,QMPwidget::PercentageSeek);
    }


    void Player::setVideoSlider(QAbstractSlider *slider){
       QMPwidget::setSeekSlider(slider);
    }

