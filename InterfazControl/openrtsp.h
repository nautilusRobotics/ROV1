#ifndef OPENRTSP_H
#define OPENRTSP_H


#define QT_NO_DEBUG_OUTPUT
#include <QObject>
#include <QProcess>
#include <QDebug>

class openRTSP : public QObject
{
    Q_OBJECT
public:
    explicit openRTSP(QObject *parent = 0,QString missionName="untitled",int numVideo=0);

public slots:
    void saveVideo();
    int getVideoCount();
private:
    QProcess procSave;
    bool isSaving;
    QString missionName;
    int numVideo;
};

#endif // OPENRTSP_H
