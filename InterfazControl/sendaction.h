#ifndef SENDACTION_H
#define SENDACTION_H

#include <QWidget>
#include <QProcess>
#include <QDebug>
#include <QString>
#include "com.h"

class SendAction : public QWidget
{
  Q_OBJECT

public:
    explicit SendAction(QWidget *parent = 0);
    ~SendAction();

private:
     QProcess procRun;
     QString robotIp;

public:
     QString sendComando(QString comando);

};

#endif // SENDACTION_H
