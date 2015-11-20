#ifndef INTROXBOX_H
#define INTROXBOX_H

#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QPixmap>
#include <QLineEdit>
#include <QToolTip>
#include <missionwidget.h>
#include <QMessageBox>
#include <QStyle>
#include <QListWidget>
#include <myitem.h>
#include <QDirIterator>
#include <QFileInfo>
#include <QShowEvent>
#include <QGraphicsScene>
#include "missionexplorer.h"
#include "exportmanager.h"
#include "qgamecontroller.h"
#include "joystickwidget.h"
#include "qgamecontroller.h"
#include "widgetKeyBoard.h"
#include "ui_Intro.h"

#define maxOptions 3
#define QPUSH_STYLE_START "QPushButton{color:white;border: 0px; border-radius:6px;font: bold;outline: none}QPushButton:focus:!pressed{border-style: outset;border-width: 4px;border-color: #555555;}"
#define QPUSH_STYLE_OPEN "QPushButton{color:white;border: 0px; border-radius:6px;font: bold;outline: none}QPushButton:focus:!pressed{border-style: outset;border-width: 4px;border-color: #555555;}"
#define QPUSH_STYLE_OFF "QPushButton{color:white;border: 0px; border-radius:6px;font: bold;outline: none}QPushButton:focus:!pressed{border-style: outset;border-width: 4px;border-color: #555555;}"
#define QLABEL_STYLE_HELP "QLabel{color: rgb(153, 153, 153);font: bold 10pt;text-decoration: underline;}QLabel:focus:!pressed{border-style: outset;border-width: 2px;border-bottom-color: #555555;}"
#define QMESAGE_STYLE "QMessageBox {background-color: #f5f5f5; border-style: outset; border-width:3px;border-color:black} QPushButton{color: #f5f5f5 ; background-color:#f5f5f5 ; border: 0px} QLabel {color: black; font:13pt}"


class IntroXbox : public QWidget
{
    Q_OBJECT
public:
    explicit IntroXbox(QWidget *parent=0);


public slots:
    void handleNewBtn(QString missionName);
    void createProjectList();
    void runMission(QString missionName);
    void exploreMission(QString missionName);
    void deleteMission(QString missionName,QListWidgetItem *item);
    void reOpen();
    void handleButtonOff();
    void updateControlStatus(bool isConnected);
    void handleJoystickButtonEvent(QString button,QGameControllerButtonEvent* event);
    void handleJoystickAxisEvent(QString axis, int value);
    void handleCloseKeyboardEvent(bool cancelled,QString result);
    void closeToast();

    private:    
    QPushButton *btnNew, *btnOff, *btnOpen;
    QLabel *lblHelp;
    QLineEdit *newMission;
    QListWidget *projectList;
    JoystickWidget *joystick;
    SendAction* sendAction;
    MissionWidget *mission;
    ExportManager *exm;
    QString missionsPath;
    QStringList     *keysList;
    QVBoxLayout *keyBoardLayout;
    widgetKeyBoard *keyboard;
    QLineEdit *resultTextBox;
    QMessageBox *toast;
    bool isKeyboard;
    int focused;
    void showMessage(QString message);
    QPushButton *createNewKey(QString keyValue);
    QVBoxLayout *generateKeyboard(void);
    void lauchKeyBoard();
    void showToast(QString message, int time);
    bool isOpen;
    Ui::NautilusCommander ui;

protected:
      void showEvent(QShowEvent *ev);

};

#endif // INTROXBOX_H
