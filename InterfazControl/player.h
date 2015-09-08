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


class Player : public QMPwidget
{
    Q_OBJECT

public:
    Player(const QStringList &args, const QString &url, QWidget *parent = 0);
    bool enableCount;
    void screenShot();
    void play();

private slots:
    void stateChanged(int state);


protected:
    void showEvent(QShowEvent *event);


private:
    QString m_url;    
    const QStringList &arguments;

    signals:
     void updateStatus(bool isConnected);


};


#endif // PLAYER_H

