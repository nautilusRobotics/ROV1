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
#include "exportmanager.h"

class MissionExplorer : public QWidget
{
    Q_OBJECT
public:
    explicit MissionExplorer(QWidget *parent = 0, QString missionPath="Untitled",QWidget *home=NULL);

signals:
    void play();
    void pause();
public slots:
    void displaySource();
    void playCLiked();
    void setState(QMediaPlayer::State);
    void handleButtonHome();
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
    QAbstractButton *playButton,*reloadButton;
    QAbstractSlider *videoSlider;
    QPushButton *btn_export,*button_home;
    QMediaPlayer::State playerState;
    void createPreviewList();
    void addPreviewItem(QString preThumb, bool type);
    void loadSettings();
    void saveSettings();
    ExportManager *exm;
    QWidget *home;

protected:
     void closeEvent(QCloseEvent *event);

};

#endif // MISSIONEXPLORER_H
