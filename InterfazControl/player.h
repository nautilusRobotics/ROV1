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
    Player(const QStringList &args, const QString &url, QWidget *parent = 0, QLabel *nstatus=NULL);
    bool enableCount;

private slots:
    void stateChanged(int state);


protected:
    void showEvent(QShowEvent *event);

   // void keyPressEvent(QKeyEvent *event);


private:
    QString m_url;
    QLabel *status;


};


#endif // PLAYER_H

