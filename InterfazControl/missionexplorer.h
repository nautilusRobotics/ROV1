#ifndef MISSIONEXPLORER_H
#define MISSIONEXPLORER_H

#include <QWidget>
#include <QGridLayout>
#include <QStyle>
#include <QDesktopWidget>
#include <QObject>
#include <QListWidget>
#include <QDirIterator>
#include <QSettings>
#include <QProcess>
#include <QPainter>
#include "player.h" 
#include "thumbviewer.h"

class MissionExplorer : public QWidget
{
    Q_OBJECT
public:
    explicit MissionExplorer(QWidget *parent = 0, QString missionPath="Untitled");

signals:
    void play();
    void pause();
public slots:
    void displaySource();
    void playCLiked();
    void setState(QMediaPlayer::State);
private:
    QGridLayout *layout; 
    Player *player;    
    QListWidget *listFiles;
    QString missionPath,m_sSettingsFile;
    ThumbViewer *thumbElement;
    QList<QString> files;
    QList<bool> isVideoFile;
    QLabel *picLbl, *defaultLbl;
    QStringList argumentos;
    bool createThumbs;
    QAbstractButton *playButton;
    QAbstractButton *reloadButton;
    QAbstractSlider *videoSlider;    
    QMediaPlayer::State playerState;
    void createPreviewList();
    void addPreviewItem(QString preThumb, bool type);
    void loadSettings();
    void saveSettings();

protected:
     void closeEvent(QCloseEvent *event);

};

#endif // MISSIONEXPLORER_H
