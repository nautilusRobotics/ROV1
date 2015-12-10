#ifndef MISSIONWIDGET_H
#define MISSIONWIDGET_H

#include <QGridLayout>
#include <QShowEvent>
#include <QFileDialog>
#include <QTextEdit>
#include <QToolBar>
#include <QPushButton>
#include <QGraphicsOpacityEffect>
#include <QProgressBar>
#include <QObject>
#include <QWidget>
#include <QStatusBar>
#include <QMessageBox>
#include <QStyle>
#include <QSettings>
#include "qgamecontroller.h"
#include "joystickwidget.h"
#include "qgamecontroller.h"
#include "openrtsp.h"
#include "ui_Intro.h"
#include "com.h"



/*---------ScreenShot definitions-----------*/
#define OFFSET_X 10
#define OFFSET_Y 90
#define SCREEN_SHOT_LR 1900 //Let-Right
#define SCREEN_SHOT_UD 850 //up-down
/*-----------------------------------------*/

#define centerCamera 11



class MissionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MissionWidget(QWidget *parent = 0, QString mName="Untitled",  JoystickWidget *joystick= 0, Ui::NautilusCommander *gui=0);
signals:
    void returnToHome();
    void saveVideo(void);


public slots:
    void updatePlayerStatus(bool isConnected);
    void updateControlStatus(bool isConnected);    
    void updateRobotDepth(double value);
    void updateRecording(bool isRecording);   
    void handleButtonHome();    
    void axisEvent(QString axis,int value);
    void buttonEvent(QString button,QGameControllerButtonEvent* event);


private:
    JoystickWidget *joystick;
    QProgressBar *batteryROV,*batteryControl;
    QLabel *statusJoystick,*robotDepth,*statusRecording,*missionNameLabel;
    QString missionName;
    openRTSP *rtsp;    
    QString m_sSettingsFile;         
    QProcess procRun;
    QString robotIp;    
    QLabel *lblLightsOn, *lblLightsOff;
    QProgressBar *batteryROVPB, *batteryControlPB;
    QSlider  *panCamera, *tiltCamera;
    QGroupBox *statusErrorBox;
    Ui::NautilusCommander *ui;
    QMPwidget *mplayer;
    int numPic,numVideos;
    bool islightsOn;
    int righLeft, upDown;
    void loadSettings();
    void saveSettings();
    void takeScreenshot(void);
    QString mapSpeed(int value);
    QString sendComando(QString comando);

protected:
     void closeEvent(QCloseEvent *event);


};

#endif // MISSIONWIDGET_H
