#ifndef SENDACTION_H
#define SENDACTION_H

#include <QWidget>
#include <QProcess>
#include <QDebug>
#include <QString>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QLabel>
#include <QFile>
#include <QDesktopWidget>
#include <QApplication>
#include <QScreen>
#include <QWindow>
#include <qmpwidget.h>
#include "com.h"
#include "joystickwidget.h"
#include "player.h"



class SendAction : public QWidget
{
  Q_OBJECT

public:
    explicit SendAction(QWidget *parent = 0);
    ~SendAction();

public:
    void axisEvent(QString axis,int value);
    void buttonEvent(QString button,QGameControllerButtonEvent* event);

private:
     QString sendComando(QString comando);
     QString mapSpeed(int value);
     QProcess procRun;
     QString robotIp;
     QTextEdit txt;
     QLabel label_depth;

 signals:
     void changeDepth(double value);
     void takeScreenshot(void);
     void saveVideo(void);


};

#endif // SENDACTION_H
