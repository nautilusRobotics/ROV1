#include "playercontrols.h"

#include <QBoxLayout>
#include <QSlider>
#include <QStyle>
#include <QToolButton>
#include <QComboBox>

PlayerControls::PlayerControls(QWidget *parent)
    : QWidget(parent)
    , playerState(QMediaPlayer::StoppedState)
    , playerMuted(false)
    , playButton(0)
    , reloadButton(0)
    , videoSlider(0)

{
    playButton = new QToolButton(this);
    playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

    connect(playButton, SIGNAL(clicked()), this, SLOT(playClicked()));

    reloadButton = new QToolButton(this);




    reloadButton->setIcon(QIcon("./icons/reload.png"));
    reloadButton->setIconSize(QSize(16,16));
    reloadButton->setEnabled(false);

    connect(reloadButton, SIGNAL(clicked()), this, SIGNAL(reload()));


    videoSlider = new QSlider(Qt::Horizontal, this);
    videoSlider->setRange(0, 100);

    connect(videoSlider, SIGNAL(sliderMoved(int)), this, SIGNAL(changeVideo(int)));


    QBoxLayout *layout = new QHBoxLayout;
    layout->setMargin(0);
    layout->addWidget(reloadButton);
    layout->addWidget(playButton); 
    layout->addWidget(videoSlider);

    setLayout(layout);
}

QMediaPlayer::State PlayerControls::state() const
{
    return playerState;
}

void PlayerControls::setState(QMediaPlayer::State state)
{
    if (state != playerState) {
        playerState = state;

        switch (state) {
        case QMediaPlayer::StoppedState:
            reloadButton->setEnabled(false);
            playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
            break;
        case QMediaPlayer::PlayingState:
            reloadButton->setEnabled(true);
            playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
            break;
        case QMediaPlayer::PausedState:
            reloadButton->setEnabled(true);
            playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
            break;
        }
    }
}


void PlayerControls::playClicked()
{
    switch (playerState) {
    case QMediaPlayer::StoppedState:
    case QMediaPlayer::PausedState:
        emit play();
        break;
    case QMediaPlayer::PlayingState:
        emit pause();
        break;
    }
}



QAbstractSlider *PlayerControls::getVideoSlider(){
     return videoSlider;
}


