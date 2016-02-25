#ifndef MISSIONWIDGET_H
#define MISSIONWIDGET_H

#define QT_NO_DEBUG_OUTPUT
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

#define STATUS_OK     0
#define ERROR_ROBOT  -1
#define ERROR_CAMERA -2

#define centerCamera 11



class MissionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MissionWidget(QWidget *parent = 0, QString mName="Untitled",  JoystickWidget *joystick= 0, Ui::NautilusCommander *gui=0, SendAction *sa=0);
signals:
    void returnToHome();
    void saveVideo(void);
    void controlOut(void);



public slots:
    void updatePlayerStatus(int state);
    void updateControlStatus(bool isConnected);                 
    void axisEvent(QString axis,int value);
    void buttonEvent(QString button,QGameControllerButtonEvent* event);
    void searchCamera(void);
    void robotDisconnected(void);
    void closeScreenShot(void);


private:
    JoystickWidget *joystick;
    QProgressBar *batteryROV,*batteryControl;
    QLabel *statusJoystick,*robotDepth,*statusRecording,*missionNameLabel, *lblError, *lblScreenShot;
    QString missionName;
    openRTSP *rtsp;    
    QString m_sSettingsFile;         
    QProcess procRun;        
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
    QProcess rumble;
    int numPic,numVideos,dialIndex,status;
    int speeds[3][4];
    bool islightsOn, isRecording, isCameraOnline;
    int righLeft, upDown;    
    void loadSettings(void);
    void saveSettings(void);
    void takeScreenshot(void);
    void resendCommand(void);
    int checkStatus(void);
    QString mapSpeed(int value);

};

#endif // MISSIONWIDGET_H
