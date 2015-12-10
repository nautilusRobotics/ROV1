#ifndef MAINAPP_H
#define MAINAPP_H

#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QPixmap>
#include <QLineEdit>
#include <QToolTip>
#include <QMessageBox>
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

#include "widgetKeyBoard.h"
#include "ui_Intro.h"
#include "myitem.h"





#define maxOptions 3
#define QPUSH_STYLE_START "QPushButton{color:white;border: 0px; border-radius:6px;font: bold;outline: none}QPushButton:focus:!pressed{border-style: outset;border-width: 4px;border-color: #555555;}"
#define QPUSH_STYLE_OPEN "QPushButton{color:white;border: 0px; border-radius:6px;font: bold;outline: none}QPushButton:focus:!pressed{border-style: outset;border-width: 4px;border-color: #555555;}"
#define QPUSH_STYLE_OFF "QPushButton{color:white;border: 0px; border-radius:6px;font: bold;outline: none}QPushButton:focus:!pressed{border-style: outset;border-width: 4px;border-color: #555555;}"
#define QLABEL_STYLE_HELP "QLabel{color: rgb(153, 153, 153);font: bold 10pt;text-decoration: underline;}QLabel:focus:!pressed{border-style: outset;border-width: 2px;border-bottom-color: #555555;}"
#define QMESAGE_STYLE "QMessageBox {background-color: #f5f5f5;} QPushButton{color: #f5f5f5 ; background-color:#f5f5f5 ; border: 0px}"



class MainApp : public QWidget
{
    Q_OBJECT
public:
    explicit MainApp(QWidget *parent=0);


public slots:
    void handleNewBtn(QString missionName);
    void createProjectList();
    void runMission(QString missionName);
    void exploreMission(QString missionName);
    void deleteMission(QString missionName,QListWidgetItem *item);    
    void handleButtonOff();
    void updateControlStatus(bool isConnected);
    void joystickButtonEventMenu(QString button,QGameControllerButtonEvent* event);
    void joystickAxisEventMenu(QString axis, int value);
    void joystickButtonEventOpen(QString button,QGameControllerButtonEvent* event);
    void joystickAxisEventOpen(QString axis, int value);
    void joystickButtonEventMessage(QString button,QGameControllerButtonEvent* event);

    void handleCloseKeyboardEvent(bool cancelled,QString result);
    void closeMessage();
    void showHome();


    private:    
        QPushButton *btnNew, *btnOff, *btnOpen;
        QLabel *lblHelp, *lblListWidget, *lblTitle, *lblShadow;
        QLineEdit *newMission;
        QListWidget *projectList;
        JoystickWidget *joystick;        
        MissionWidget *mission;
        ExportManager *exm;
        QString missionsPath;
        QStringList     *keysList;
        QVBoxLayout *keyBoardLayout;
        widgetKeyBoard *keyboard;
        QLineEdit *resultTextBox;
        QMessageBox *toast;
        QStringList *projectListStrings;
        QBitArray *projectListBools;
        QStackedWidget *stackedWidget;
        QGroupBox *openMissionBox;
        MissionWidget *missionWidget;
        MissionExplorer *missionExplorer;
        Ui::NautilusCommander ui;
        QPushButton *createNewKey(QString keyValue);
        QVBoxLayout *generateKeyboard(void);
        bool isKeyboard, isOpenProjectMenu;
        int focused, openProjectRow;
        bool isOpen;
        void showMessage(QString message, bool okCancelbtns);
        void initWelcomeScreen();        
        void lauchKeyBoard();
        void showToast(QString message, int time);

};

#endif // MAINAPP_H
