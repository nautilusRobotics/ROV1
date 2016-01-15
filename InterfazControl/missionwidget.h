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
#include <QScreen>
#include <QDial>
#include <QDesktopWidget>
#include "qgamecontroller.h"
#include "joystickwidget.h"
#include "qgamecontroller.h"
#include "openrtsp.h"
#include "ui_Intro.h"
#include "com.h"
#include "datathread.h"
#include "sendaction.h"




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
    void handleButtonHome();    
    void axisEvent(QString axis,int value);
    void buttonEvent(QString button,QGameControllerButtonEvent* event);
    void searchCamera(void);


private:
    JoystickWidget *joystick;
    QProgressBar *batteryROV,*batteryControl;
    QLabel *statusJoystick,*robotDepth,*statusRecording,*missionNameLabel, *lblError;
    QString missionName;
    openRTSP *rtsp;    
    QString m_sSettingsFile;         
    QProcess procRun;
    QString robotIp;    
    QLabel *lblLightsOn, *lblLightsOff;
    QProgressBar *batteryROVPB, *batteryControlPB;
    QSlider  *panCamera, *tiltCamera;
    QGroupBox *statusErrorBox, *statusVideoOff;
    Ui::NautilusCommander *ui;
    QMPwidget *mplayer;
    DataThread *dataThread;
    SendAction *sendAction;
    QDial *speedDial;
    QString lastCommand;
    int numPic,numVideos,dialIndex;
    int speeds[3][4];
    bool islightsOn, isRecording, isCameraOnline;
    int righLeft, upDown;    
    void loadSettings(void);
    void saveSettings(void);
    void takeScreenshot(void);
    void resendCommand(void);
    QString mapSpeed(int value);


};

#endif // MISSIONWIDGET_H
