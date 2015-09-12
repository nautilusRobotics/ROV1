#ifndef EXPORTMANAGER_H
#define EXPORTMANAGER_H

#include <QObject>
#include <QProcess>
#include <QDebug>
#include <QFileInfo>
#include <QDir>

class ExportManager : public QObject
{
    Q_OBJECT
public:
    explicit ExportManager(QObject *parent = 0,QString missionName="");
private:
    QList<QString> names;
    QList<QString> freeSpace;
    QString missionName;
    quint64 toBytes(QString str);
    void getExternalDevices();
    quint64 dir_size(const QString & str);
signals:
   void success(bool);
public:

public slots:


};

#endif // EXPORTMANAGER_H
