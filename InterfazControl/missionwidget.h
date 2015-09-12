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
//#include <QWidget>


#include "player.h"
#include "qmpwidget.h"
#include "qgamecontroller.h"
#include "joystickwidget.h"
#include "qgamecontroller.h"
#include "openrtsp.h"


/*---------ScreenShot definitions-----------*/
#define OFFSET_X 10
#define OFFSET_Y 90
#define SCREEN_SHOT_LR 1260 //Let-Right
#define SCREEN_SHOT_UD 550 //up-down
/*-----------------------------------------*/





class MissionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MissionWidget(QWidget *parent = 0, QString missionName="Untitled"); 
signals:

public slots:
    void updatePlayerStatus(bool isConnected);
    void updateControlStatus(bool isConnected);
    void takeScreenshot(void);
    void updateRobotDepth(double value);
    void updateRecording(bool isRecording);
    void handleButtonOff();
    void handleButtonHome();

private:
   // QMPwidget widget;
    Player *player;
    QPushButton *button_control,*button_1,*button_camara, *button_test, *button_off,*button_home;
    QToolBar *toolbar;
    JoystickWidget *joystick;
    SendAction* sendAction;
    QGridLayout *layout;
    QProgressBar *battery,*depth;
    QLabel *statusRobot,  *statusPlayer, *statusJoystick,*robotDepth,*statusRecording;
    QString missionName;
    openRTSP *rtsp;    
    QString m_sSettingsFile;

    int numPic,numVideos;
    void loadSettings();
    void saveSettings();

protected:
     void closeEvent(QCloseEvent *event);


};

#endif // MISSIONWIDGET_H
