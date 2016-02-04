#ifndef MISSIONEXPLORER_H
#define MISSIONEXPLORER_H

#define QT_NO_DEBUG_OUTPUT
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
#include <QHBoxLayout>
#include "thumbviewer.h"
#include "exportmanager.h"
#include "joystickwidget.h"
#include "ui_Intro.h"
#define DEFAULT_PIC ":/new/prefix1/explorerDefault2.png"
#define WHITE_PIC ":/new/prefix1/white1600x1000.png"

class MissionExplorer : public QWidget
{
    Q_OBJECT
public:
    explicit MissionExplorer(QWidget *parent = 0, QString missionName="Untitled",JoystickWidget *joystick= 0, Ui::NautilusCommander *gui=0);

signals:
    void returnToHome();

public slots:
    void displaySource();    
    void axisEvent(QString axis,int value);
    void buttonEvent(QString button,QGameControllerButtonEvent* event);
    void sliderChange(int value);


private:
    JoystickWidget *joystick;
    QGridLayout *layout; 
    QMPwidget *mplayer;
    QListWidget *listFiles;
    QString missionPath,m_sSettingsFile;
    ThumbViewer *thumbElement;
    QList<QString> files;
    QList<bool> isVideoFile;
    QLabel *picLbl, *defaultLbl, *lblMissionName, *lblPlayPause;
    QPushButton *btn_export,*button_home;
    int fileRow;
    ExportManager *exm;    
    Ui::NautilusCommander *ui;
    QGroupBox *groupPlayer;
    QSlider *progressPlay;
    QString videoFile;

    bool createThumbs;
    bool isPlaying, isVideoActive;
    void createPreviewList();
    void addPreviewItem(QString preThumb, bool type);
    void loadSettings();
    void saveSettings();
    void showDefaultPic();


};

#endif // MISSIONEXPLORER_H
