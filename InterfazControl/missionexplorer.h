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
#include "thumbviewer.h"
#include "exportmanager.h"
#include "joystickwidget.h"
#include "ui_Intro.h"

class MissionExplorer : public QWidget
{
    Q_OBJECT
public:
    explicit MissionExplorer(QWidget *parent = 0, QString missionName="Untitled",JoystickWidget *joystick= 0, Ui::NautilusCommander *gui=0);

signals:
    void play();
    void pause();
    void returnToHome();
public slots:
    void displaySource();    
    void axisEvent(QString axis,int value);
    void buttonEvent(QString button,QGameControllerButtonEvent* event);


private:
    JoystickWidget *joystick;
    QGridLayout *layout; 
    QMPwidget *mplayer;
    QListWidget *listFiles;
    QString missionPath,m_sSettingsFile;
    ThumbViewer *thumbElement;
    QList<QString> files;
    QList<bool> isVideoFile;
    QLabel *picLbl, *defaultLbl;
    QStringList argumentos;    
    QAbstractButton *playButton,*reloadButton;
    QAbstractSlider *videoSlider;
    QPushButton *btn_export,*button_home;    
    int fileRow;
    ExportManager *exm;    
    Ui::NautilusCommander *ui;

    bool createThumbs;
    void createPreviewList();
    void addPreviewItem(QString preThumb, bool type);
    void loadSettings();
    void saveSettings();


};

#endif // MISSIONEXPLORER_H
