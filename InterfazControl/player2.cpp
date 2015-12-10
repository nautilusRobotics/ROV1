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
          playerStatus=QMPwidget::NotStartedState;
        }
        else if (state == QMPwidget::PlayingState && mediaInfo().ok) {

        #ifdef DEBUG_PLAYER
             qDebug("Playing");
        #endif
            emit updateStatus(true);

             playerStatus=QMPwidget::PlayingState;

        }
        else if(state==QMPwidget::IdleState){
            #ifdef DEBUG_PLAYER
                 qDebug("IdleState");
            #endif

            if(enableCount){               
                emit updateStatus(false);
            }

            if(playerStatus==QMPwidget::PlayingState)
                emit newState(QMediaPlayer::StoppedState);

            playerStatus=QMPwidget::IdleState;
        }      
        else if(state==QMPwidget::LoadingState){
            #ifdef DEBUG_PLAYER
                 qDebug("LoadingState");
            #endif
                 playerStatus=QMPwidget::LoadingState;
        }
        else if(state==QMPwidget::PausedState){
#ifdef DEBUG_PLAYER
            qDebug("PausedState");
#endif
          playerStatus=QMPwidget::PausedState;

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


    void Player::reload(){
        QMPwidget::QMPwidget::seek(0,QMPwidget::PercentageSeek);
    }



