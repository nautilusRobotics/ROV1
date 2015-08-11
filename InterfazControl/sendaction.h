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
#include "com.h"
#include "joystickwidget.h"



class SendAction : public QWidget
{
  Q_OBJECT

public:
    explicit SendAction(QWidget *parent = 0);
    ~SendAction();

public:
    void axisEvent(QString axis,int value);
    void buttonEvent(QString button);

private:
     QString sendComando(QString comando);
     QProcess procRun;
     QString robotIp;
     QTextEdit txt;
     QLabel label_depth;
};

#endif // SENDACTION_H
