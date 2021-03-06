#ifndef MAINAPP_H
#define MAINAPP_H


#define QT_NO_DEBUG_OUTPUT
#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QPixmap>
#include <QLineEdit>
#include <QToolTip>
#include <QDialog>
#include <QStyle>
#include <QListWidget>
#include <QDirIterator>
#include <QFileInfo>
#include <QShowEvent>
#include <QGraphicsScene>
#include <QBitArray>
#include <QStackedWidget>


#include "missionexplorer.h"
#include "missionwidget.h"
#include "exportmanager.h"

#include "qgamecontroller.h"
#include "joystickwidget.h"

#include "ui_Intro.h"
#include "myitem.h"
#include "sendaction.h"



#define maxOptions 3
#define QPUSH_STYLE_START "QPushButton{color:white;border: 0px; border-radius:6px;font: bold;outline: none}QPushButton:focus:!pressed{border-style: outset;border-width: 4px;border-color: #555555;}"
#define QPUSH_STYLE_OPEN "QPushButton{color:white;border: 0px; border-radius:6px;font: bold;outline: none}QPushButton:focus:!pressed{border-style: outset;border-width: 4px;border-color: #555555;}"
#define QPUSH_STYLE_OFF "QPushButton{color:white;border: 0px; border-radius:6px;font: bold;outline: none}QPushButton:focus:!pressed{border-style: outset;border-width: 4px;border-color: #555555;}"
#define QLABEL_STYLE_HELP "QLabel{color: rgb(153, 153, 153);font: bold 10pt;text-decoration: underline;}QLabel:focus:!pressed{border-style: outset;border-width: 2px;border-bottom-color: #555555;}"
#define QMESAGE_STYLE_INFO "QDialog {background-color:rgb(255,255,255); background-image: url(:/new/prefix1/infoDialog.png); }"
#define QMESAGE_STYLE_HELP_INTRO "QDialog {background-color:rgba(255,255,255,0); background-image: url(:/new/prefix1/helpIntro.png); }"
#define QMESAGE_STYLE_HELP_XBOX  "QDialog {background-image: url(:/new/prefix1/helpControllerLayout.png);}"
#define QMESAGE_STYLE_CONFIRM "QDialog {background-color:rgb(255,255,255); background-image: url(:/new/prefix1/confirmDialog.png);}"

#define QKEY_NORMAL_STYLE "font-size: 18pt; font-weight: bold; background-color: rgb(89, 96, 102); color: rgb(255, 255, 255);"
#define QKEY_SELECT_STYLE "font-size: 18pt; font-weight: bold; background-color: rgb(181, 205, 217); color: rgb(0, 0, 0);"
#define QKEY_NORMAL_ERASE_STYLE "background-color: rgb(89, 96, 102); image: url(:/new/prefix1/eraser.png);"
#define QKEY_NORMAL_BACKSPACE_STYLE "background-color: rgb(89, 96, 102);image: url(:/new/prefix1/backspace.png);"
#define QKEY_SELECT_ERASE_STYLE      "background-color: rgb(181, 205, 217); image: url(:/new/prefix1/eraserBlack.png);"
#define QKEY_SELECT_BACKSPACE_STYLE  "background-color: rgb(181, 205, 217); image: url(:/new/prefix1/backspaceBlack.png);"

class MainApp : public QWidget
{
    Q_OBJECT
public:
    explicit MainApp(QWidget *parent=0);


public slots:
    void createProjectList();
    void updateControlStatus(bool isConnected);
    void joystickButtonEventMenu(QString button,QGameControllerButtonEvent* event);
    void joystickAxisEventMenu(QString axis, int value);
    void joystickButtonEventHelp(QString button,QGameControllerButtonEvent* event);
    void joystickAxisEventHelp(QString axis, int value);
    void joystickButtonEventOpen(QString button,QGameControllerButtonEvent* event);
    void joystickAxisEventOpen(QString axis, int value);
    void joystickButtonEventMessage(QString button,QGameControllerButtonEvent* event);
    void joystickButtonEventOffMessage(QString button,QGameControllerButtonEvent* event);
    void joystickButtonEventKeyBoard(QString button,QGameControllerButtonEvent* event);
    void joystickAxisEventKeyBoard(QString axis, int value);
    void handleCloseKeyboardEvent(bool cancelled,QString result);    
    void preCloseMessage();
    void showHome(bool fromMissionWidget);
    void reconnectJoystick();
    void controlCrash();
    void successExport(bool success);
    void controlOut();
    void exploreMissionSlot();



    private:    
        QPushButton *btnNew, *btnOff, *btnOpen;
        QLabel *lblHelp, *lblListWidget, *lblTitle, *lblShadow, *lblGamepadError, *lblRepairMessage, *lblLoading;
        QLineEdit *newMission;
        QListWidget *projectList;
        JoystickWidget *joystick;        
        MissionWidget *mission;
        ExportManager *exm;
        QString missionsPath, missionExploreName;
        QStringList    *secretKeyList;
        QLineEdit *resultKeyBoard;
        QDialog *toast, *help;
        QStringList *projectListStrings, *helpList;
        QBitArray *projectListBools;
        QStackedWidget *stackedWidget;
        QGroupBox *openMissionBox, *keyBoardBox;
        MissionWidget *missionWidget;
        MissionExplorer *missionExplorer;
        Ui::NautilusCommander ui;
        QPushButton *createNewKey(QString keyValue);
        QVBoxLayout *generateKeyboard(void);
        QPushButton *keyboardMatrix[4][10];
        SendAction *sendAction;
        QProcess rumble;
        int focused, openProjectRow, secretKey, keyRow,keyCol, helpIdx;
        bool isOpen, isWorkingOffline, isRobotOnline, isMissionWidget, isExploreMission;
        void showMessage(QString message, bool okCancelbtns);
        void initWelcomeScreen();        
        void launchKeyBoard();
        void showToast(QString message, int time);
        void setNormalkey();
        void setSelectkey();
        void handleNewBtn(QString missionName);
        void runMission(QString missionName);        
        void deleteMission(QString missionName,QListWidgetItem *item);
        void handleButtonOff();
        void closeMessage(bool reconectMenu);
        bool checkRobot();
        void exploreMission(QString missionName);
        bool missionNameExist(QString newMissionName);


};

#endif // MAINAPP_H
