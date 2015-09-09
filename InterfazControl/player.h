#ifndef PLAYER_H
#define PLAYER_H
#include "qmpwidget.h"

#include <QApplication>
#include <QGridLayout>
#include <QShowEvent>
#include <QSlider>
#include <QFileDialog>
#include <QLabel>
#include <QPushButton>
#include <QMediaPlayer>


class Player : public QMPwidget
{
    Q_OBJECT

public:
    Player(const QStringList &args, const QString &url, QWidget *parent = 0);
    bool enableCount;
    void screenShot();
    void setVideoSlider(QAbstractSlider *slider);

private:
    QString m_url;
    const QStringList &arguments;

private slots:
    void stateChanged(int state);
    void play();
    void pause();
    void reload();

signals:
    void newState(QMediaPlayer::State);
    void updateStatus(bool isConnected);

protected:
    void showEvent(QShowEvent *event);



};


#endif // PLAYER_H

