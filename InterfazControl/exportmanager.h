#ifndef EXPORTMANAGER_H
#define EXPORTMANAGER_H

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
#include "mywidgetusb.h"

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
    bool getExternalDevices();
    quint64 dir_size(const QString & str);
    QDialog msgBox;
    bool checkUsb(int indexUSB);    
    bool copyDir(const QString &srcFilePath, const QString &tgtFilePath);

signals:
   void success(bool);
public:
  void setMissionName(QString missionName);
public slots:
   void launchDialog();
   bool saveUsb(int indexUSB );
   void cancelDialog();



};

#endif // EXPORTMANAGER_H

