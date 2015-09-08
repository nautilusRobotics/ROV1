#ifndef OPENRTSP_H
#define OPENRTSP_H

#include <QObject>
#include <QProcess>
#include <QDebug>

class openRTSP : public QObject
{
    Q_OBJECT
public:
    explicit openRTSP(QObject *parent = 0,QString missionName="untitled",int numVideo=0);

signals:
    void isRecording(bool);

public slots:
    void saveVideo();
private:
    QProcess procSave;
    bool isSaving;
    QString missionName;
    int numVideo;
};

#endif // OPENRTSP_H
