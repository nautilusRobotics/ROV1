#ifndef EXPORTMANAGER_H
#define EXPORTMANAGER_H


#define QT_NO_DEBUG_OUTPUT
#include <QObject>
#include <QProcess>
#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QtMath>
#include <QListWidget>
#include <QDialog>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QMovie>
#include "mywidgetusb.h"
#include "joystickwidget.h"
#include "qgamecontroller.h"
#include "exportthread.h"
#include <unistd.h>


class ExportManager : public QWidget
{
    Q_OBJECT
public:
    explicit ExportManager(QWidget *parent = 0, QString mission="");
private:
    QList<QString> names;    
    QList<quint64> bytesFreeSpace;
    QString missionName;
    quint64 toBytes(QString str);
    quint64 dir_size(const QString & str);
    QDialog *msgBox, *loadingBox;
    int x,y,h,w;
    bool isUSB, isSaving;
    bool getExternalDevices();  
    bool checkUsb(int indexUSB);    
    bool copyDir(const QString &srcFilePath, const QString &tgtFilePath);
    QProcess rumble;

signals:
   void success(bool success);

public:
  void setMissionName(QString missionName);


public slots:
  void acceptDialogs();
   void launchDialog();
   bool saveUsb(int indexUSB );   
   void joystickButtonUSB(QString button,QGameControllerButtonEvent* event);
   //void joystickAxisUSB(QString axis, int value);


};

#endif // EXPORTMANAGER_H

