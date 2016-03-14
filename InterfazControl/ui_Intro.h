/********************************************************************************
** Form generated from reading UI file 'Intro.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTRO_H
#define UI_INTRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include <qmpwidget.h>

QT_BEGIN_NAMESPACE

class Ui_NautilusCommander
{
public:
    QStackedWidget *stackedWidget;
    QWidget *intro_page;
    QPushButton *btnNew;
    QPushButton *btnOff;
    QPushButton *btnOpen;
    QLabel *label_bckgd;
    QLabel *label_logo;
    QLabel *label_wwtdo;
    QLabel *label_or;
    QLabel *label_logoN;
    QLabel *label_logoC;
    QLabel *label_title;
    QLabel *label_need;
    QLabel *lblHelp;
    QGroupBox *openMissionBox;
    QListWidget *listWidget;
    QLabel *lblListWidget;
    QLabel *lblShadow;
    QLabel *lblGamepad;
    QLabel *lblRepair;
    QLabel *label_Tips;
    QLabel *label_tipA;
    QLabel *label_TipCross;
    QGroupBox *keyboardGroup;
    QLineEdit *keyboardLine;
    QPushButton *keyQ;
    QPushButton *keyW;
    QPushButton *keyE;
    QPushButton *keyR;
    QPushButton *keyT;
    QPushButton *keyY;
    QPushButton *keyU;
    QPushButton *keyI;
    QPushButton *keyO;
    QPushButton *keyP;
    QPushButton *keyA;
    QPushButton *keyS;
    QPushButton *keyD;
    QPushButton *keyF;
    QPushButton *keyG;
    QPushButton *keyH;
    QPushButton *keyJ;
    QPushButton *keyK;
    QPushButton *keyL;
    QPushButton *keyB;
    QPushButton *keyZ;
    QPushButton *keyC;
    QPushButton *keyX;
    QPushButton *keyM;
    QPushButton *keyV;
    QPushButton *keyN;
    QPushButton *keySpace;
    QPushButton *keyBackspace;
    QPushButton *keyCancel;
    QPushButton *keyEnter;
    QPushButton *keyErase;
    QLabel *label_tipKeyB;
    QLabel *label_loading;
    QWidget *mission_page;
    QMPwidget *mplayerWG;
    QLabel *label_goHome;
    QLabel *label_title_2;
    QLabel *label_missionName;
    QProgressBar *progressBattRov;
    QLabel *label_rovBatt;
    QLabel *labelControlBatt;
    QProgressBar *progressBattControl;
    QLabel *label_btnA;
    QLabel *label_Controls;
    QFrame *line;
    QLabel *label_btnB;
    QLabel *label_btnX;
    QLabel *label;
    QLabel *label_cross;
    QLabel *label_screenshot;
    QFrame *line_2;
    QLabel *label_take;
    QFrame *line_3;
    QFrame *line_4;
    QLabel *label_Record;
    QLabel *label_video;
    QLabel *label_move;
    QLabel *label_camera;
    QFrame *line_6;
    QGroupBox *statusOkBox;
    QLabel *label_Controls_3;
    QLabel *lblOkIcon;
    QGroupBox *statusErrorBox;
    QLabel *lblError;
    QLabel *lblErrorIcon;
    QLabel *labelControlBatt_2;
    QLabel *lblMissionName;
    QLabel *label_depthIco;
    QLabel *labelControlBatt_3;
    QLabel *labelControlBatt_4;
    QLabel *labelControlBatt_5;
    QLabel *label_tempIco;
    QGroupBox *statusVideoOff;
    QLabel *label_Controls_6;
    QLabel *label_5;
    QGroupBox *statusVideoOn;
    QLabel *label_Controls_7;
    QLabel *label_6;
    QLabel *label_leftRL;
    QLabel *label_ARightUD;
    QLabel *label_camera_pic;
    QLabel *labelControlBatt_6;
    QSlider *panCamera;
    QSlider *tiltCamera;
    QLabel *label_center;
    QLabel *label_cameraCenter;
    QLabel *labelControlBatt_7;
    QLabel *label_switchOn;
    QLabel *label_switchOff;
    QFrame *line_9;
    QFrame *line_10;
    QLabel *label_turnROV;
    QLabel *label_submerge;
    QLabel *label_emerge;
    QLabel *label_AleftUD;
    QFrame *line_11;
    QLabel *label_forwards;
    QLabel *label_backwards;
    QLabel *label_speedLB;
    QLabel *label_speed;
    QLabel *label_speed_down;
    QFrame *line_13;
    QLabel *label_speedRB;
    QLabel *label_speed_2;
    QLabel *label_speed_up;
    QFrame *line_14;
    QDial *dial;
    QLabel *label_dialBack;
    QLabel *labelControlBatt_8;
    QLabel *labelControlBatt_9;
    QLabel *labelControlBatt_10;
    QFrame *line_15;
    QLabel *label_btnY;
    QLabel *label_toggle;
    QLabel *label_toggle_2;
    QLabel *labelBackMW;
    QLabel *label_toastSS;
    QWidget *explore_page;
    QMPwidget *mplayerEx;
    QLabel *label_goHome_2;
    QListWidget *listWidgetEx;
    QLabel *label_title_3;
    QLabel *label_missionName_2;
    QLabel *lblMissionNameEx;
    QLabel *label_Controls_2;
    QLabel *label_xboxIco;
    QFrame *line_7;
    QFrame *line_8;
    QLabel *label_btnA_2;
    QLabel *label_select;
    QLabel *label_btnA_3;
    QLabel *label_nav;
    QFrame *line_12;
    QLabel *lblPic;
    QLabel *lblbackEx;
    QGroupBox *groupPlayer;
    QSlider *playerSlider;
    QLabel *lblPlayStopIcon;
    QLabel *label_btnB_play;
    QLabel *label_palyStop;
    QFrame *line_16;

    void setupUi(QWidget *NautilusCommander)
    {
        if (NautilusCommander->objectName().isEmpty())
            NautilusCommander->setObjectName(QStringLiteral("NautilusCommander"));
        NautilusCommander->resize(1920, 1080);
        NautilusCommander->setFocusPolicy(Qt::NoFocus);
        NautilusCommander->setStyleSheet(QStringLiteral(""));
        stackedWidget = new QStackedWidget(NautilusCommander);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1920, 1080));
        stackedWidget->setLineWidth(0);
        intro_page = new QWidget();
        intro_page->setObjectName(QStringLiteral("intro_page"));
        intro_page->setStyleSheet(QStringLiteral(""));
        btnNew = new QPushButton(intro_page);
        btnNew->setObjectName(QStringLiteral("btnNew"));
        btnNew->setGeometry(QRect(850, 464, 556, 87));
        btnNew->setStyleSheet(QLatin1String("color:white;border: 20px; border-radius:6px;\n"
"border-color: rgb(0, 0, 0);\n"
"font: bold 12pt;\n"
"\n"
""));
        btnOff = new QPushButton(intro_page);
        btnOff->setObjectName(QStringLiteral("btnOff"));
        btnOff->setGeometry(QRect(848, 753, 558, 87));
        btnOff->setStyleSheet(QLatin1String("color:rgb(255, 255, 255);border: 0px; border-radius:6px;\n"
"font: bold 13pt;\n"
""));
        btnOpen = new QPushButton(intro_page);
        btnOpen->setObjectName(QStringLiteral("btnOpen"));
        btnOpen->setGeometry(QRect(850, 654, 556, 89));
        btnOpen->setStyleSheet(QLatin1String("color:white;border: 20px; border-radius:6px;\n"
"border-color: rgb(0, 0, 0);\n"
"font: bold 12pt;\n"
""));
        label_bckgd = new QLabel(intro_page);
        label_bckgd->setObjectName(QStringLiteral("label_bckgd"));
        label_bckgd->setGeometry(QRect(0, 0, 1920, 1080));
        label_bckgd->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/nautilusBack1920x1080.png);"));
        label_logo = new QLabel(intro_page);
        label_logo->setObjectName(QStringLiteral("label_logo"));
        label_logo->setGeometry(QRect(480, 430, 131, 129));
        label_logo->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/nautilus128x128.svg);"));
        label_wwtdo = new QLabel(intro_page);
        label_wwtdo->setObjectName(QStringLiteral("label_wwtdo"));
        label_wwtdo->setGeometry(QRect(1030, 400, 221, 16));
        label_wwtdo->setStyleSheet(QLatin1String("color: rgb(153, 153, 153);\n"
"font: bold 11pt;"));
        label_or = new QLabel(intro_page);
        label_or->setObjectName(QStringLiteral("label_or"));
        label_or->setGeometry(QRect(1118, 600, 21, 16));
        label_or->setStyleSheet(QLatin1String("color: rgb(153, 153, 153);\n"
"font: bold 11pt;"));
        label_logoN = new QLabel(intro_page);
        label_logoN->setObjectName(QStringLiteral("label_logoN"));
        label_logoN->setGeometry(QRect(490, 600, 111, 16));
        label_logoN->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 15pt"));
        label_logoC = new QLabel(intro_page);
        label_logoC->setObjectName(QStringLiteral("label_logoC"));
        label_logoC->setGeometry(QRect(480, 620, 141, 16));
        label_logoC->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 15pt"));
        label_title = new QLabel(intro_page);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(980, 260, 321, 16));
        label_title->setStyleSheet(QStringLiteral("font: bold 13pt"));
        label_need = new QLabel(intro_page);
        label_need->setObjectName(QStringLiteral("label_need"));
        label_need->setGeometry(QRect(1290, 910, 41, 16));
        label_need->setStyleSheet(QLatin1String("color: rgb(153, 153, 153);\n"
"font: bold 10pt;"));
        lblHelp = new QLabel(intro_page);
        lblHelp->setObjectName(QStringLiteral("lblHelp"));
        lblHelp->setGeometry(QRect(1330, 910, 61, 16));
        lblHelp->setFocusPolicy(Qt::StrongFocus);
        lblHelp->setStyleSheet(QLatin1String("color: rgb(153, 153, 153);\n"
"font: bold 10pt;\n"
"text-decoration: underline;"));
        openMissionBox = new QGroupBox(intro_page);
        openMissionBox->setObjectName(QStringLiteral("openMissionBox"));
        openMissionBox->setEnabled(true);
        openMissionBox->setGeometry(QRect(787, 202, 669, 750));
        openMissionBox->setStyleSheet(QStringLiteral("background-image: url(null);"));
        listWidget = new QListWidget(openMissionBox);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(41, 140, 591, 561));
        listWidget->setFocusPolicy(Qt::NoFocus);
        listWidget->setStyleSheet(QStringLiteral("background-color: rgb(245, 245, 245);"));
        lblListWidget = new QLabel(openMissionBox);
        lblListWidget->setObjectName(QStringLiteral("lblListWidget"));
        lblListWidget->setGeometry(QRect(54, 707, 565, 31));
        lblListWidget->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/helpOpen.png);"));
        lblShadow = new QLabel(intro_page);
        lblShadow->setObjectName(QStringLiteral("lblShadow"));
        lblShadow->setEnabled(true);
        lblShadow->setGeometry(QRect(0, 0, 1920, 1080));
        lblShadow->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 128);"));
        lblGamepad = new QLabel(intro_page);
        lblGamepad->setObjectName(QStringLiteral("lblGamepad"));
        lblGamepad->setEnabled(true);
        lblGamepad->setGeometry(QRect(0, 0, 1920, 1080));
        lblGamepad->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/gamepadError.png);"));
        lblGamepad->setFrameShape(QFrame::NoFrame);
        lblRepair = new QLabel(intro_page);
        lblRepair->setObjectName(QStringLiteral("lblRepair"));
        lblRepair->setGeometry(QRect(0, 0, 1920, 1080));
        lblRepair->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/repairMessage.png);"));
        label_Tips = new QLabel(intro_page);
        label_Tips->setObjectName(QStringLiteral("label_Tips"));
        label_Tips->setGeometry(QRect(860, 905, 401, 31));
        label_Tips->setStyleSheet(QLatin1String("color: rgb(58, 58, 58);\n"
""));
        label_tipA = new QLabel(intro_page);
        label_tipA->setObjectName(QStringLiteral("label_tipA"));
        label_tipA->setGeometry(QRect(896, 907, 32, 32));
        label_tipA->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/xboxA32.png);"));
        label_TipCross = new QLabel(intro_page);
        label_TipCross->setObjectName(QStringLiteral("label_TipCross"));
        label_TipCross->setGeometry(QRect(1079, 905, 32, 32));
        label_TipCross->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/xboxCross32.png);"));
        keyboardGroup = new QGroupBox(intro_page);
        keyboardGroup->setObjectName(QStringLiteral("keyboardGroup"));
        keyboardGroup->setGeometry(QRect(620, 290, 771, 481));
        keyboardGroup->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(39, 43, 44);"));
        keyboardLine = new QLineEdit(keyboardGroup);
        keyboardLine->setObjectName(QStringLiteral("keyboardLine"));
        keyboardLine->setGeometry(QRect(0, 40, 771, 31));
        keyboardLine->setCursor(QCursor(Qt::PointingHandCursor));
        keyboardLine->setFocusPolicy(Qt::NoFocus);
        keyboardLine->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        keyQ = new QPushButton(keyboardGroup);
        keyQ->setObjectName(QStringLiteral("keyQ"));
        keyQ->setGeometry(QRect(40, 90, 60, 83));
        keyQ->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyW = new QPushButton(keyboardGroup);
        keyW->setObjectName(QStringLiteral("keyW"));
        keyW->setGeometry(QRect(110, 90, 60, 83));
        keyW->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
""));
        keyE = new QPushButton(keyboardGroup);
        keyE->setObjectName(QStringLiteral("keyE"));
        keyE->setGeometry(QRect(180, 90, 60, 83));
        keyE->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyR = new QPushButton(keyboardGroup);
        keyR->setObjectName(QStringLiteral("keyR"));
        keyR->setGeometry(QRect(250, 90, 60, 83));
        keyR->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyT = new QPushButton(keyboardGroup);
        keyT->setObjectName(QStringLiteral("keyT"));
        keyT->setGeometry(QRect(320, 90, 60, 83));
        keyT->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyY = new QPushButton(keyboardGroup);
        keyY->setObjectName(QStringLiteral("keyY"));
        keyY->setGeometry(QRect(390, 90, 60, 83));
        keyY->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyU = new QPushButton(keyboardGroup);
        keyU->setObjectName(QStringLiteral("keyU"));
        keyU->setGeometry(QRect(460, 90, 60, 83));
        keyU->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyI = new QPushButton(keyboardGroup);
        keyI->setObjectName(QStringLiteral("keyI"));
        keyI->setGeometry(QRect(530, 90, 60, 83));
        keyI->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyO = new QPushButton(keyboardGroup);
        keyO->setObjectName(QStringLiteral("keyO"));
        keyO->setGeometry(QRect(600, 90, 60, 83));
        keyO->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyP = new QPushButton(keyboardGroup);
        keyP->setObjectName(QStringLiteral("keyP"));
        keyP->setGeometry(QRect(670, 90, 60, 83));
        keyP->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyA = new QPushButton(keyboardGroup);
        keyA->setObjectName(QStringLiteral("keyA"));
        keyA->setGeometry(QRect(70, 190, 60, 83));
        keyA->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyS = new QPushButton(keyboardGroup);
        keyS->setObjectName(QStringLiteral("keyS"));
        keyS->setGeometry(QRect(140, 190, 60, 83));
        keyS->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyD = new QPushButton(keyboardGroup);
        keyD->setObjectName(QStringLiteral("keyD"));
        keyD->setGeometry(QRect(210, 190, 60, 83));
        keyD->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyF = new QPushButton(keyboardGroup);
        keyF->setObjectName(QStringLiteral("keyF"));
        keyF->setGeometry(QRect(280, 190, 60, 83));
        keyF->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyG = new QPushButton(keyboardGroup);
        keyG->setObjectName(QStringLiteral("keyG"));
        keyG->setGeometry(QRect(350, 190, 60, 83));
        keyG->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyH = new QPushButton(keyboardGroup);
        keyH->setObjectName(QStringLiteral("keyH"));
        keyH->setGeometry(QRect(420, 190, 60, 83));
        keyH->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyJ = new QPushButton(keyboardGroup);
        keyJ->setObjectName(QStringLiteral("keyJ"));
        keyJ->setGeometry(QRect(490, 190, 60, 83));
        keyJ->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyK = new QPushButton(keyboardGroup);
        keyK->setObjectName(QStringLiteral("keyK"));
        keyK->setGeometry(QRect(560, 190, 60, 83));
        keyK->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyL = new QPushButton(keyboardGroup);
        keyL->setObjectName(QStringLiteral("keyL"));
        keyL->setGeometry(QRect(630, 190, 60, 83));
        keyL->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyB = new QPushButton(keyboardGroup);
        keyB->setObjectName(QStringLiteral("keyB"));
        keyB->setGeometry(QRect(420, 290, 60, 83));
        keyB->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyZ = new QPushButton(keyboardGroup);
        keyZ->setObjectName(QStringLiteral("keyZ"));
        keyZ->setGeometry(QRect(140, 290, 60, 83));
        keyZ->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyC = new QPushButton(keyboardGroup);
        keyC->setObjectName(QStringLiteral("keyC"));
        keyC->setGeometry(QRect(280, 290, 60, 83));
        keyC->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyX = new QPushButton(keyboardGroup);
        keyX->setObjectName(QStringLiteral("keyX"));
        keyX->setGeometry(QRect(210, 290, 60, 83));
        keyX->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyM = new QPushButton(keyboardGroup);
        keyM->setObjectName(QStringLiteral("keyM"));
        keyM->setGeometry(QRect(560, 290, 60, 83));
        keyM->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyV = new QPushButton(keyboardGroup);
        keyV->setObjectName(QStringLiteral("keyV"));
        keyV->setGeometry(QRect(350, 290, 60, 83));
        keyV->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyN = new QPushButton(keyboardGroup);
        keyN->setObjectName(QStringLiteral("keyN"));
        keyN->setGeometry(QRect(490, 290, 60, 83));
        keyN->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keySpace = new QPushButton(keyboardGroup);
        keySpace->setObjectName(QStringLiteral("keySpace"));
        keySpace->setGeometry(QRect(210, 380, 351, 83));
        keySpace->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyBackspace = new QPushButton(keyboardGroup);
        keyBackspace->setObjectName(QStringLiteral("keyBackspace"));
        keyBackspace->setGeometry(QRect(650, 290, 81, 83));
        keyBackspace->setStyleSheet(QLatin1String("background-color: rgb(89, 96, 102);\n"
"image: url(:/new/prefix1/backspace.png);\n"
"\n"
""));
        keyCancel = new QPushButton(keyboardGroup);
        keyCancel->setObjectName(QStringLiteral("keyCancel"));
        keyCancel->setGeometry(QRect(30, 380, 161, 83));
        keyCancel->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyEnter = new QPushButton(keyboardGroup);
        keyEnter->setObjectName(QStringLiteral("keyEnter"));
        keyEnter->setGeometry(QRect(570, 380, 161, 83));
        keyEnter->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyErase = new QPushButton(keyboardGroup);
        keyErase->setObjectName(QStringLiteral("keyErase"));
        keyErase->setGeometry(QRect(30, 290, 81, 83));
        keyErase->setStyleSheet(QLatin1String("background-color: rgb(89, 96, 102);\n"
"image: url(:/new/prefix1/eraser.png);\n"
"\n"
""));
        label_tipKeyB = new QLabel(keyboardGroup);
        label_tipKeyB->setObjectName(QStringLiteral("label_tipKeyB"));
        label_tipKeyB->setGeometry(QRect(30, 10, 361, 16));
        label_tipKeyB->setStyleSheet(QLatin1String("font-size: 12pt;\n"
"font-weight: bold;\n"
"color: rgb(148, 148, 148);"));
        label_loading = new QLabel(intro_page);
        label_loading->setObjectName(QStringLiteral("label_loading"));
        label_loading->setGeometry(QRect(903, 454, 291, 71));
        label_loading->setStyleSheet(QLatin1String("color:  rgb(255, 255, 255);\n"
"font: bold 40pt;"));
        stackedWidget->addWidget(intro_page);
        label_bckgd->raise();
        btnNew->raise();
        btnOff->raise();
        btnOpen->raise();
        label_logo->raise();
        label_wwtdo->raise();
        label_or->raise();
        label_logoN->raise();
        label_logoC->raise();
        label_title->raise();
        label_need->raise();
        lblHelp->raise();
        label_Tips->raise();
        label_tipA->raise();
        label_TipCross->raise();
        openMissionBox->raise();
        lblShadow->raise();
        lblGamepad->raise();
        lblRepair->raise();
        keyboardGroup->raise();
        label_loading->raise();
        mission_page = new QWidget();
        mission_page->setObjectName(QStringLiteral("mission_page"));
        mission_page->setStyleSheet(QStringLiteral(""));
        mplayerWG = new QMPwidget(mission_page);
        mplayerWG->setObjectName(QStringLiteral("mplayerWG"));
        mplayerWG->setEnabled(false);
        mplayerWG->setGeometry(QRect(80, 80, 1600, 1000));
        mplayerWG->setStyleSheet(QStringLiteral(""));
        label_goHome = new QLabel(mission_page);
        label_goHome->setObjectName(QStringLiteral("label_goHome"));
        label_goHome->setGeometry(QRect(112, 30, 221, 21));
        label_goHome->setStyleSheet(QLatin1String("color: rgb(153, 153, 153);\n"
"font: bold 11pt;"));
        label_title_2 = new QLabel(mission_page);
        label_title_2->setObjectName(QStringLiteral("label_title_2"));
        label_title_2->setGeometry(QRect(700, 30, 401, 21));
        label_title_2->setStyleSheet(QLatin1String("font: bold 20pt;\n"
""));
        label_missionName = new QLabel(mission_page);
        label_missionName->setObjectName(QStringLiteral("label_missionName"));
        label_missionName->setGeometry(QRect(1370, 30, 131, 21));
        label_missionName->setStyleSheet(QLatin1String("color: rgb(153, 153, 153);\n"
"font: bold 11pt;"));
        progressBattRov = new QProgressBar(mission_page);
        progressBattRov->setObjectName(QStringLiteral("progressBattRov"));
        progressBattRov->setGeometry(QRect(1710, 100, 181, 23));
        progressBattRov->setStyleSheet(QLatin1String("QProgressBar {border: 2px solid grey;border-radius: 5px; text-align: center; }\n"
"QProgressBar::chunk {background-color: #37A2E5;width: 20px}"));
        progressBattRov->setMaximum(100);
        progressBattRov->setValue(90);
        label_rovBatt = new QLabel(mission_page);
        label_rovBatt->setObjectName(QStringLiteral("label_rovBatt"));
        label_rovBatt->setGeometry(QRect(1760, 130, 91, 31));
        label_rovBatt->setStyleSheet(QLatin1String("color: rgb(153, 153, 153);\n"
"font:  11pt;"));
        labelControlBatt = new QLabel(mission_page);
        labelControlBatt->setObjectName(QStringLiteral("labelControlBatt"));
        labelControlBatt->setGeometry(QRect(1740, 200, 121, 21));
        labelControlBatt->setStyleSheet(QLatin1String("color: rgb(153, 153, 153);\n"
"font: 11pt;"));
        progressBattControl = new QProgressBar(mission_page);
        progressBattControl->setObjectName(QStringLiteral("progressBattControl"));
        progressBattControl->setGeometry(QRect(1710, 170, 181, 23));
        progressBattControl->setStyleSheet(QLatin1String("QProgressBar {border: 2px solid grey;border-radius: 5px; text-align: center;}\n"
"QProgressBar::chunk {background-color:  rgb(146, 255, 116);width: 20px;}"));
        progressBattControl->setValue(90);
        label_btnA = new QLabel(mission_page);
        label_btnA->setObjectName(QStringLiteral("label_btnA"));
        label_btnA->setGeometry(QRect(25, 190, 32, 32));
        label_btnA->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/xboxA32.png);"));
        label_Controls = new QLabel(mission_page);
        label_Controls->setObjectName(QStringLiteral("label_Controls"));
        label_Controls->setGeometry(QRect(0, 150, 81, 16));
        label_Controls->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 11pt;"));
        label_Controls->setAlignment(Qt::AlignCenter);
        line = new QFrame(mission_page);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 171, 80, 16));
        line->setStyleSheet(QStringLiteral(""));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_btnB = new QLabel(mission_page);
        label_btnB->setObjectName(QStringLiteral("label_btnB"));
        label_btnB->setGeometry(QRect(25, 261, 32, 32));
        label_btnB->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/xobxB32.png);"));
        label_btnX = new QLabel(mission_page);
        label_btnX->setObjectName(QStringLiteral("label_btnX"));
        label_btnX->setGeometry(QRect(25, 340, 32, 32));
        label_btnX->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/xboxX32.png);"));
        label = new QLabel(mission_page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 90, 55, 55));
        label->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/xboxcntrl55.svg);"));
        label_cross = new QLabel(mission_page);
        label_cross->setObjectName(QStringLiteral("label_cross"));
        label_cross->setGeometry(QRect(25, 490, 32, 32));
        label_cross->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/xboxCross32.png);"));
        label_screenshot = new QLabel(mission_page);
        label_screenshot->setObjectName(QStringLiteral("label_screenshot"));
        label_screenshot->setGeometry(QRect(0, 240, 81, 16));
        label_screenshot->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 8.5pt;"));
        label_screenshot->setAlignment(Qt::AlignCenter);
        line_2 = new QFrame(mission_page);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 250, 80, 16));
        line_2->setStyleSheet(QStringLiteral(""));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_take = new QLabel(mission_page);
        label_take->setObjectName(QStringLiteral("label_take"));
        label_take->setGeometry(QRect(5, 220, 71, 21));
        label_take->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        label_take->setAlignment(Qt::AlignCenter);
        line_3 = new QFrame(mission_page);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(0, 327, 80, 16));
        line_3->setStyleSheet(QStringLiteral(""));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(mission_page);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(0, 400, 80, 16));
        line_4->setStyleSheet(QStringLiteral(""));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_Record = new QLabel(mission_page);
        label_Record->setObjectName(QStringLiteral("label_Record"));
        label_Record->setGeometry(QRect(0, 293, 81, 20));
        label_Record->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        label_Record->setAlignment(Qt::AlignCenter);
        label_video = new QLabel(mission_page);
        label_video->setObjectName(QStringLiteral("label_video"));
        label_video->setGeometry(QRect(0, 310, 81, 20));
        label_video->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        label_video->setAlignment(Qt::AlignCenter);
        label_move = new QLabel(mission_page);
        label_move->setObjectName(QStringLiteral("label_move"));
        label_move->setGeometry(QRect(0, 526, 81, 20));
        label_move->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        label_move->setAlignment(Qt::AlignCenter);
        label_camera = new QLabel(mission_page);
        label_camera->setObjectName(QStringLiteral("label_camera"));
        label_camera->setGeometry(QRect(0, 541, 81, 20));
        label_camera->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 8.7pt;"));
        label_camera->setAlignment(Qt::AlignCenter);
        line_6 = new QFrame(mission_page);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(0, 474, 80, 16));
        line_6->setStyleSheet(QStringLiteral(""));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        statusOkBox = new QGroupBox(mission_page);
        statusOkBox->setObjectName(QStringLiteral("statusOkBox"));
        statusOkBox->setGeometry(QRect(1680, 1000, 240, 80));
        statusOkBox->setStyleSheet(QLatin1String("background-color: rgb(244, 244, 244);\n"
"color: rgb(153, 153, 153);\n"
"font: bold 11pt;"));
        label_Controls_3 = new QLabel(statusOkBox);
        label_Controls_3->setObjectName(QStringLiteral("label_Controls_3"));
        label_Controls_3->setGeometry(QRect(60, 40, 151, 16));
        label_Controls_3->setStyleSheet(QLatin1String("color: rgb(163, 175, 179);\n"
"font: bold 11pt;"));
        lblOkIcon = new QLabel(statusOkBox);
        lblOkIcon->setObjectName(QStringLiteral("lblOkIcon"));
        lblOkIcon->setGeometry(QRect(10, 30, 32, 32));
        lblOkIcon->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/ok.png);"));
        lblOkIcon->setFrameShadow(QFrame::Plain);
        statusErrorBox = new QGroupBox(mission_page);
        statusErrorBox->setObjectName(QStringLiteral("statusErrorBox"));
        statusErrorBox->setGeometry(QRect(1680, 1000, 240, 80));
        statusErrorBox->setStyleSheet(QLatin1String("background-color: rgb(244, 244, 244);\n"
"color: rgb(153, 153, 153);\n"
"font: bold 11pt;"));
        lblError = new QLabel(statusErrorBox);
        lblError->setObjectName(QStringLiteral("lblError"));
        lblError->setGeometry(QRect(50, 30, 181, 31));
        lblError->setStyleSheet(QLatin1String("color: rgb(163, 175, 179);\n"
"font: bold 11pt;"));
        lblErrorIcon = new QLabel(statusErrorBox);
        lblErrorIcon->setObjectName(QStringLiteral("lblErrorIcon"));
        lblErrorIcon->setGeometry(QRect(10, 30, 32, 32));
        lblErrorIcon->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/alert.png);"));
        lblErrorIcon->setFrameShadow(QFrame::Plain);
        labelControlBatt_2 = new QLabel(mission_page);
        labelControlBatt_2->setObjectName(QStringLiteral("labelControlBatt_2"));
        labelControlBatt_2->setGeometry(QRect(1750, 290, 91, 31));
        labelControlBatt_2->setStyleSheet(QLatin1String("color: rgb(153, 153, 153);\n"
"font:  11pt;"));
        lblMissionName = new QLabel(mission_page);
        lblMissionName->setObjectName(QStringLiteral("lblMissionName"));
        lblMissionName->setGeometry(QRect(1510, 30, 131, 21));
        lblMissionName->setStyleSheet(QLatin1String("color: rgb(153, 153, 153);\n"
"font: bold 11pt;"));
        label_depthIco = new QLabel(mission_page);
        label_depthIco->setObjectName(QStringLiteral("label_depthIco"));
        label_depthIco->setGeometry(QRect(1830, 260, 32, 32));
        label_depthIco->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/depth.png);"));
        label_depthIco->setFrameShape(QFrame::NoFrame);
        labelControlBatt_3 = new QLabel(mission_page);
        labelControlBatt_3->setObjectName(QStringLiteral("labelControlBatt_3"));
        labelControlBatt_3->setGeometry(QRect(1740, 260, 81, 41));
        labelControlBatt_3->setStyleSheet(QLatin1String("color: rgb(153, 153, 153);\n"
"font: bold 30pt;"));
        labelControlBatt_4 = new QLabel(mission_page);
        labelControlBatt_4->setObjectName(QStringLiteral("labelControlBatt_4"));
        labelControlBatt_4->setGeometry(QRect(1760, 360, 61, 41));
        labelControlBatt_4->setStyleSheet(QLatin1String("color: rgb(153, 153, 153);\n"
"font: bold 30pt;"));
        labelControlBatt_5 = new QLabel(mission_page);
        labelControlBatt_5->setObjectName(QStringLiteral("labelControlBatt_5"));
        labelControlBatt_5->setGeometry(QRect(1740, 400, 131, 31));
        labelControlBatt_5->setStyleSheet(QLatin1String("color: rgb(153, 153, 153);\n"
"font:  11pt;"));
        label_tempIco = new QLabel(mission_page);
        label_tempIco->setObjectName(QStringLiteral("label_tempIco"));
        label_tempIco->setGeometry(QRect(1830, 360, 32, 32));
        label_tempIco->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/temp.png);"));
        label_tempIco->setFrameShape(QFrame::NoFrame);
        statusVideoOff = new QGroupBox(mission_page);
        statusVideoOff->setObjectName(QStringLiteral("statusVideoOff"));
        statusVideoOff->setGeometry(QRect(1680, 920, 240, 80));
        statusVideoOff->setStyleSheet(QLatin1String("background-color: rgb(244, 244, 244);\n"
"color: rgb(153, 153, 153);\n"
"font: bold 11pt;"));
        label_Controls_6 = new QLabel(statusVideoOff);
        label_Controls_6->setObjectName(QStringLiteral("label_Controls_6"));
        label_Controls_6->setGeometry(QRect(60, 40, 151, 16));
        label_Controls_6->setStyleSheet(QLatin1String("color: rgb(163, 175, 179);\n"
"font: bold 11pt;"));
        label_5 = new QLabel(statusVideoOff);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 30, 32, 32));
        label_5->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/recordOff.png);"));
        label_5->setFrameShadow(QFrame::Plain);
        statusVideoOn = new QGroupBox(mission_page);
        statusVideoOn->setObjectName(QStringLiteral("statusVideoOn"));
        statusVideoOn->setGeometry(QRect(1680, 920, 240, 80));
        statusVideoOn->setStyleSheet(QLatin1String("background-color: rgb(244, 244, 244);\n"
"color: rgb(153, 153, 153);\n"
"font: bold 11pt;"));
        label_Controls_7 = new QLabel(statusVideoOn);
        label_Controls_7->setObjectName(QStringLiteral("label_Controls_7"));
        label_Controls_7->setGeometry(QRect(60, 40, 151, 16));
        label_Controls_7->setStyleSheet(QLatin1String("color: rgb(163, 175, 179);\n"
"font: bold 11pt;"));
        label_6 = new QLabel(statusVideoOn);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 30, 32, 32));
        label_6->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/recordOn.png);"));
        label_6->setFrameShadow(QFrame::Plain);
        label_leftRL = new QLabel(mission_page);
        label_leftRL->setObjectName(QStringLiteral("label_leftRL"));
        label_leftRL->setGeometry(QRect(6, 575, 70, 50));
        label_leftRL->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/xboxLlr.png);"));
        label_ARightUD = new QLabel(mission_page);
        label_ARightUD->setObjectName(QStringLiteral("label_ARightUD"));
        label_ARightUD->setGeometry(QRect(15, 794, 50, 70));
        label_ARightUD->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/xboxRud.png);"));
        label_camera_pic = new QLabel(mission_page);
        label_camera_pic->setObjectName(QStringLiteral("label_camera_pic"));
        label_camera_pic->setGeometry(QRect(1770, 480, 50, 50));
        label_camera_pic->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/camera50x50.png);"));
        labelControlBatt_6 = new QLabel(mission_page);
        labelControlBatt_6->setObjectName(QStringLiteral("labelControlBatt_6"));
        labelControlBatt_6->setGeometry(QRect(1740, 560, 131, 31));
        labelControlBatt_6->setStyleSheet(QLatin1String("color: rgb(153, 153, 153);\n"
"font:  11pt;"));
        panCamera = new QSlider(mission_page);
        panCamera->setObjectName(QStringLiteral("panCamera"));
        panCamera->setGeometry(QRect(1751, 550, 90, 12));
        panCamera->setFocusPolicy(Qt::NoFocus);
        panCamera->setStyleSheet(QLatin1String("QSlider::groove:horizontal {border: 0px solid #999999;height: 10px;border-radius: 10px;}\n"
"QSlider::add-page{background: rgb(91, 107, 117);border-top-right-radius: 5px;border-bottom-right-radius: 5px;border-top-left-radius: 0px;border-bottom-left-radius: 0px;}\n"
"QSlider::sub-page:qlineargradient {background: rgb(91, 107, 117);border-top-right-radius: 0px;border-bottom-right-radius: 0px;border-top-left-radius: 5px;border-bottom-left-radius: 5px;}\n"
"QSlider::handle:horizontal {width: 10px; background-image: url(:/new/prefix1/dotGreen.png)}\n"
""));
        panCamera->setMinimum(3);
        panCamera->setMaximum(19);
        panCamera->setValue(11);
        panCamera->setOrientation(Qt::Horizontal);
        panCamera->setInvertedAppearance(false);
        panCamera->setTickPosition(QSlider::NoTicks);
        tiltCamera = new QSlider(mission_page);
        tiltCamera->setObjectName(QStringLiteral("tiltCamera"));
        tiltCamera->setGeometry(QRect(1840, 455, 10, 90));
        tiltCamera->setFocusPolicy(Qt::NoFocus);
        tiltCamera->setStyleSheet(QLatin1String("QSlider::groove:vertical {border: 0px solid #999999;width: 10px;border-radius: 5px;}\n"
"QSlider::add-page{background: rgb(91, 107, 117);border-top-right-radius: 5px;border-bottom-right-radius: 5px;border-top-left-radius: 5px;border-bottom-left-radius: 5px;}\n"
"QSlider::sub-page:qlineargradient {background: rgb(91, 107, 117);border-top-right-radius: 5px;border-bottom-right-radius: 5px;border-top-left-radius: 5px;border-bottom-left-radius: 5px;}\n"
"QSlider::handle:vertical{height: 10px; background-image: url(:/new/prefix1/dotGreen.png)}\n"
""));
        tiltCamera->setMinimum(8);
        tiltCamera->setMaximum(14);
        tiltCamera->setValue(11);
        tiltCamera->setOrientation(Qt::Vertical);
        label_center = new QLabel(mission_page);
        label_center->setObjectName(QStringLiteral("label_center"));
        label_center->setGeometry(QRect(0, 370, 81, 21));
        label_center->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        label_center->setAlignment(Qt::AlignCenter);
        label_cameraCenter = new QLabel(mission_page);
        label_cameraCenter->setObjectName(QStringLiteral("label_cameraCenter"));
        label_cameraCenter->setGeometry(QRect(0, 386, 81, 21));
        label_cameraCenter->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 8.7pt;"));
        label_cameraCenter->setAlignment(Qt::AlignCenter);
        labelControlBatt_7 = new QLabel(mission_page);
        labelControlBatt_7->setObjectName(QStringLiteral("labelControlBatt_7"));
        labelControlBatt_7->setGeometry(QRect(1780, 660, 51, 31));
        labelControlBatt_7->setStyleSheet(QLatin1String("color: rgb(153, 153, 153);\n"
"font:  11pt;"));
        label_switchOn = new QLabel(mission_page);
        label_switchOn->setObjectName(QStringLiteral("label_switchOn"));
        label_switchOn->setGeometry(QRect(1770, 600, 64, 64));
        label_switchOn->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/switchOn.png);"));
        label_switchOff = new QLabel(mission_page);
        label_switchOff->setObjectName(QStringLiteral("label_switchOff"));
        label_switchOff->setGeometry(QRect(1770, 600, 64, 64));
        label_switchOff->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/switchOff.png);"));
        line_9 = new QFrame(mission_page);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setGeometry(QRect(0, 654, 80, 16));
        line_9->setStyleSheet(QStringLiteral(""));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);
        line_10 = new QFrame(mission_page);
        line_10->setObjectName(QStringLiteral("line_10"));
        line_10->setGeometry(QRect(0, 774, 80, 16));
        line_10->setStyleSheet(QStringLiteral(""));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);
        label_turnROV = new QLabel(mission_page);
        label_turnROV->setObjectName(QStringLiteral("label_turnROV"));
        label_turnROV->setGeometry(QRect(0, 634, 81, 16));
        label_turnROV->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        label_turnROV->setAlignment(Qt::AlignCenter);
        label_submerge = new QLabel(mission_page);
        label_submerge->setObjectName(QStringLiteral("label_submerge"));
        label_submerge->setGeometry(QRect(7, 864, 71, 16));
        label_submerge->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        label_submerge->setAlignment(Qt::AlignCenter);
        label_emerge = new QLabel(mission_page);
        label_emerge->setObjectName(QStringLiteral("label_emerge"));
        label_emerge->setGeometry(QRect(5, 878, 71, 20));
        label_emerge->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        label_emerge->setAlignment(Qt::AlignCenter);
        label_AleftUD = new QLabel(mission_page);
        label_AleftUD->setObjectName(QStringLiteral("label_AleftUD"));
        label_AleftUD->setGeometry(QRect(15, 668, 50, 70));
        label_AleftUD->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/xboxLud.png);"));
        line_11 = new QFrame(mission_page);
        line_11->setObjectName(QStringLiteral("line_11"));
        line_11->setGeometry(QRect(0, 890, 80, 16));
        line_11->setStyleSheet(QStringLiteral(""));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);
        label_forwards = new QLabel(mission_page);
        label_forwards->setObjectName(QStringLiteral("label_forwards"));
        label_forwards->setGeometry(QRect(0, 740, 81, 16));
        label_forwards->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        label_forwards->setAlignment(Qt::AlignCenter);
        label_backwards = new QLabel(mission_page);
        label_backwards->setObjectName(QStringLiteral("label_backwards"));
        label_backwards->setGeometry(QRect(0, 757, 81, 16));
        label_backwards->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 8.5pt;"));
        label_backwards->setAlignment(Qt::AlignCenter);
        label_speedLB = new QLabel(mission_page);
        label_speedLB->setObjectName(QStringLiteral("label_speedLB"));
        label_speedLB->setGeometry(QRect(14, 901, 50, 50));
        label_speedLB->setStyleSheet(QStringLiteral("background-image:   url(:/new/prefix1/XboxLb48.png)"));
        label_speed = new QLabel(mission_page);
        label_speed->setObjectName(QStringLiteral("label_speed"));
        label_speed->setGeometry(QRect(-5, 946, 81, 20));
        label_speed->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 8.7pt;"));
        label_speed->setAlignment(Qt::AlignCenter);
        label_speed_down = new QLabel(mission_page);
        label_speed_down->setObjectName(QStringLiteral("label_speed_down"));
        label_speed_down->setGeometry(QRect(-3, 962, 81, 20));
        label_speed_down->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        label_speed_down->setAlignment(Qt::AlignCenter);
        line_13 = new QFrame(mission_page);
        line_13->setObjectName(QStringLiteral("line_13"));
        line_13->setGeometry(QRect(0, 980, 80, 16));
        line_13->setStyleSheet(QStringLiteral(""));
        line_13->setFrameShape(QFrame::HLine);
        line_13->setFrameShadow(QFrame::Sunken);
        label_speedRB = new QLabel(mission_page);
        label_speedRB->setObjectName(QStringLiteral("label_speedRB"));
        label_speedRB->setGeometry(QRect(14, 990, 50, 50));
        label_speedRB->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/XboxRb48.png)"));
        label_speed_2 = new QLabel(mission_page);
        label_speed_2->setObjectName(QStringLiteral("label_speed_2"));
        label_speed_2->setGeometry(QRect(-1, 1036, 81, 20));
        label_speed_2->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 8.7pt;"));
        label_speed_2->setAlignment(Qt::AlignCenter);
        label_speed_up = new QLabel(mission_page);
        label_speed_up->setObjectName(QStringLiteral("label_speed_up"));
        label_speed_up->setGeometry(QRect(1, 1050, 81, 20));
        label_speed_up->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        label_speed_up->setAlignment(Qt::AlignCenter);
        line_14 = new QFrame(mission_page);
        line_14->setObjectName(QStringLiteral("line_14"));
        line_14->setGeometry(QRect(0, 1060, 80, 16));
        line_14->setStyleSheet(QStringLiteral(""));
        line_14->setFrameShape(QFrame::HLine);
        line_14->setFrameShadow(QFrame::Sunken);
        dial = new QDial(mission_page);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(1735, 717, 141, 111));
        dial->setStyleSheet(QStringLiteral(""));
        dial->setMinimum(1);
        dial->setMaximum(22);
        dial->setSingleStep(5);
        dial->setValue(20);
        dial->setSliderPosition(20);
        dial->setTracking(true);
        dial->setOrientation(Qt::Horizontal);
        dial->setInvertedAppearance(false);
        dial->setInvertedControls(false);
        dial->setWrapping(false);
        dial->setNotchesVisible(true);
        label_dialBack = new QLabel(mission_page);
        label_dialBack->setObjectName(QStringLiteral("label_dialBack"));
        label_dialBack->setGeometry(QRect(1740, 710, 131, 125));
        label_dialBack->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/dialBack.png);"));
        labelControlBatt_8 = new QLabel(mission_page);
        labelControlBatt_8->setObjectName(QStringLiteral("labelControlBatt_8"));
        labelControlBatt_8->setGeometry(QRect(1782, 831, 51, 31));
        labelControlBatt_8->setStyleSheet(QLatin1String("color: rgb(153, 153, 153);\n"
"font:  11pt;"));
        labelControlBatt_9 = new QLabel(mission_page);
        labelControlBatt_9->setObjectName(QStringLiteral("labelControlBatt_9"));
        labelControlBatt_9->setGeometry(QRect(1710, 790, 31, 31));
        labelControlBatt_9->setStyleSheet(QLatin1String("color: rgb(153, 153, 153);\n"
"font:  11pt;"));
        labelControlBatt_10 = new QLabel(mission_page);
        labelControlBatt_10->setObjectName(QStringLiteral("labelControlBatt_10"));
        labelControlBatt_10->setGeometry(QRect(1867, 790, 31, 31));
        labelControlBatt_10->setStyleSheet(QLatin1String("color: rgb(153, 153, 153);\n"
"font:  11pt;"));
        line_15 = new QFrame(mission_page);
        line_15->setObjectName(QStringLiteral("line_15"));
        line_15->setGeometry(QRect(0, 560, 80, 16));
        line_15->setStyleSheet(QStringLiteral(""));
        line_15->setFrameShape(QFrame::HLine);
        line_15->setFrameShadow(QFrame::Sunken);
        label_btnY = new QLabel(mission_page);
        label_btnY->setObjectName(QStringLiteral("label_btnY"));
        label_btnY->setGeometry(QRect(25, 413, 32, 32));
        label_btnY->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/xboxY32.png);"));
        label_toggle = new QLabel(mission_page);
        label_toggle->setObjectName(QStringLiteral("label_toggle"));
        label_toggle->setGeometry(QRect(0, 440, 81, 21));
        label_toggle->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        label_toggle->setAlignment(Qt::AlignCenter);
        label_toggle_2 = new QLabel(mission_page);
        label_toggle_2->setObjectName(QStringLiteral("label_toggle_2"));
        label_toggle_2->setGeometry(QRect(0, 458, 81, 21));
        label_toggle_2->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        label_toggle_2->setAlignment(Qt::AlignCenter);
        labelBackMW = new QLabel(mission_page);
        labelBackMW->setObjectName(QStringLiteral("labelBackMW"));
        labelBackMW->setGeometry(QRect(0, 0, 1920, 1080));
        labelBackMW->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/backVideo.svg);"));
        label_toastSS = new QLabel(mission_page);
        label_toastSS->setObjectName(QStringLiteral("label_toastSS"));
        label_toastSS->setGeometry(QRect(580, 58, 591, 21));
        label_toastSS->setStyleSheet(QLatin1String("background-color: rgb(70, 70, 70);\n"
"font: 13pt ; font: bold;\n"
"color: white;\n"
" border-width: 1px;\n"
" border-style: solid;\n"
"  border-radius: 10px;"));
        label_toastSS->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(mission_page);
        labelBackMW->raise();
        mplayerWG->raise();
        label_goHome->raise();
        label_title_2->raise();
        label_missionName->raise();
        progressBattRov->raise();
        label_rovBatt->raise();
        labelControlBatt->raise();
        progressBattControl->raise();
        label_btnA->raise();
        label_Controls->raise();
        line->raise();
        label_btnB->raise();
        label_btnX->raise();
        label->raise();
        label_cross->raise();
        label_screenshot->raise();
        line_2->raise();
        label_take->raise();
        line_3->raise();
        line_4->raise();
        label_Record->raise();
        label_video->raise();
        label_move->raise();
        label_camera->raise();
        line_6->raise();
        statusOkBox->raise();
        statusErrorBox->raise();
        labelControlBatt_2->raise();
        lblMissionName->raise();
        label_depthIco->raise();
        labelControlBatt_3->raise();
        labelControlBatt_4->raise();
        labelControlBatt_5->raise();
        label_tempIco->raise();
        statusVideoOn->raise();
        statusVideoOff->raise();
        label_leftRL->raise();
        label_ARightUD->raise();
        label_camera_pic->raise();
        labelControlBatt_6->raise();
        panCamera->raise();
        tiltCamera->raise();
        label_center->raise();
        label_cameraCenter->raise();
        labelControlBatt_7->raise();
        label_switchOn->raise();
        label_switchOff->raise();
        line_9->raise();
        line_10->raise();
        label_turnROV->raise();
        label_submerge->raise();
        label_emerge->raise();
        label_AleftUD->raise();
        line_11->raise();
        label_forwards->raise();
        label_backwards->raise();
        label_speedLB->raise();
        label_speed->raise();
        label_speed_down->raise();
        line_13->raise();
        label_speedRB->raise();
        label_speed_2->raise();
        label_speed_up->raise();
        line_14->raise();
        label_dialBack->raise();
        dial->raise();
        labelControlBatt_8->raise();
        labelControlBatt_9->raise();
        labelControlBatt_10->raise();
        line_15->raise();
        label_btnY->raise();
        label_toggle->raise();
        label_toggle_2->raise();
        label_toastSS->raise();
        explore_page = new QWidget();
        explore_page->setObjectName(QStringLiteral("explore_page"));
        explore_page->setStyleSheet(QStringLiteral(""));
        mplayerEx = new QMPwidget(explore_page);
        mplayerEx->setObjectName(QStringLiteral("mplayerEx"));
        mplayerEx->setGeometry(QRect(80, 80, 1600, 942));
        mplayerEx->setStyleSheet(QStringLiteral(""));
        label_goHome_2 = new QLabel(explore_page);
        label_goHome_2->setObjectName(QStringLiteral("label_goHome_2"));
        label_goHome_2->setGeometry(QRect(112, 30, 221, 21));
        label_goHome_2->setStyleSheet(QLatin1String("color: rgb(153, 153, 153);\n"
"font: bold 11pt;"));
        listWidgetEx = new QListWidget(explore_page);
        listWidgetEx->setObjectName(QStringLiteral("listWidgetEx"));
        listWidgetEx->setGeometry(QRect(1680, 80, 240, 1000));
        listWidgetEx->setFocusPolicy(Qt::NoFocus);
        listWidgetEx->setStyleSheet(QStringLiteral("background-color: rgb(245, 245, 245);"));
        label_title_3 = new QLabel(explore_page);
        label_title_3->setObjectName(QStringLiteral("label_title_3"));
        label_title_3->setGeometry(QRect(680, 20, 571, 31));
        label_title_3->setStyleSheet(QLatin1String("font: bold 20pt;\n"
""));
        label_missionName_2 = new QLabel(explore_page);
        label_missionName_2->setObjectName(QStringLiteral("label_missionName_2"));
        label_missionName_2->setGeometry(QRect(1370, 30, 131, 21));
        label_missionName_2->setStyleSheet(QLatin1String("color: rgb(153, 153, 153);\n"
"font: bold 11pt;"));
        lblMissionNameEx = new QLabel(explore_page);
        lblMissionNameEx->setObjectName(QStringLiteral("lblMissionNameEx"));
        lblMissionNameEx->setGeometry(QRect(1510, 30, 131, 21));
        lblMissionNameEx->setStyleSheet(QLatin1String("color: rgb(153, 153, 153);\n"
"font: bold 11pt;"));
        label_Controls_2 = new QLabel(explore_page);
        label_Controls_2->setObjectName(QStringLiteral("label_Controls_2"));
        label_Controls_2->setGeometry(QRect(3, 149, 72, 15));
        label_Controls_2->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 11pt;"));
        label_xboxIco = new QLabel(explore_page);
        label_xboxIco->setObjectName(QStringLiteral("label_xboxIco"));
        label_xboxIco->setGeometry(QRect(10, 89, 55, 55));
        label_xboxIco->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/xboxcntrl55.svg);"));
        line_7 = new QFrame(explore_page);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setGeometry(QRect(0, 170, 80, 16));
        line_7->setStyleSheet(QLatin1String("background-image: url(null);\n"
""));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        line_8 = new QFrame(explore_page);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setGeometry(QRect(0, 250, 80, 16));
        line_8->setStyleSheet(QStringLiteral(""));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        label_btnA_2 = new QLabel(explore_page);
        label_btnA_2->setObjectName(QStringLiteral("label_btnA_2"));
        label_btnA_2->setGeometry(QRect(25, 190, 32, 32));
        label_btnA_2->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/xboxA32.png);"));
        label_select = new QLabel(explore_page);
        label_select->setObjectName(QStringLiteral("label_select"));
        label_select->setGeometry(QRect(20, 230, 51, 21));
        label_select->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        label_btnA_3 = new QLabel(explore_page);
        label_btnA_3->setObjectName(QStringLiteral("label_btnA_3"));
        label_btnA_3->setGeometry(QRect(15, 270, 50, 50));
        label_btnA_3->setStyleSheet(QStringLiteral("background-image:url(:/new/prefix1/xboxCross50.png)"));
        label_nav = new QLabel(explore_page);
        label_nav->setObjectName(QStringLiteral("label_nav"));
        label_nav->setGeometry(QRect(2, 320, 76, 21));
        label_nav->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        label_nav->setAlignment(Qt::AlignCenter);
        line_12 = new QFrame(explore_page);
        line_12->setObjectName(QStringLiteral("line_12"));
        line_12->setGeometry(QRect(0, 340, 80, 16));
        line_12->setStyleSheet(QLatin1String("background-image: url(null);\n"
""));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);
        lblPic = new QLabel(explore_page);
        lblPic->setObjectName(QStringLiteral("lblPic"));
        lblPic->setGeometry(QRect(80, 80, 1600, 1000));
        lblPic->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/explorerDefault2.png);"));
        lblbackEx = new QLabel(explore_page);
        lblbackEx->setObjectName(QStringLiteral("lblbackEx"));
        lblbackEx->setGeometry(QRect(0, 0, 1920, 1080));
        lblbackEx->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/backVideo.svg);"));
        groupPlayer = new QGroupBox(explore_page);
        groupPlayer->setObjectName(QStringLiteral("groupPlayer"));
        groupPlayer->setGeometry(QRect(79, 1020, 1602, 80));
        groupPlayer->setStyleSheet(QStringLiteral("background-color: rgb(243, 240, 236);"));
        groupPlayer->setFlat(false);
        playerSlider = new QSlider(groupPlayer);
        playerSlider->setObjectName(QStringLiteral("playerSlider"));
        playerSlider->setGeometry(QRect(100, 23, 1481, 16));
        playerSlider->setStyleSheet(QLatin1String("QSlider::groove:horizontal {border: 1px solid #999999;height: 10px;border-radius: 5px;}\n"
"QSlider::handle:horizontal {width: 10px; background-image: url(:/new/prefix1/dotOrange.png)}\n"
"QSlider::add-page:qlineargradient {background: lightgrey;border-top-right-radius: 5px;border-bottom-right-radius: 5px;border-top-left-radius: 0px;border-bottom-left-radius: 0px;}\n"
"QSlider::sub-page:qlineargradient {background: #408af1 ;border-top-right-radius: 0px;border-bottom-right-radius: 0px;border-top-left-radius:5px;border-bottom-left-radius: 5px;}\n"
""));
        playerSlider->setMaximum(100);
        playerSlider->setPageStep(10);
        playerSlider->setValue(50);
        playerSlider->setOrientation(Qt::Horizontal);
        lblPlayStopIcon = new QLabel(groupPlayer);
        lblPlayStopIcon->setObjectName(QStringLiteral("lblPlayStopIcon"));
        lblPlayStopIcon->setGeometry(QRect(42, 8, 48, 50));
        lblPlayStopIcon->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/play50.png);"));
        label_btnB_play = new QLabel(explore_page);
        label_btnB_play->setObjectName(QStringLiteral("label_btnB_play"));
        label_btnB_play->setGeometry(QRect(24, 364, 32, 32));
        label_btnB_play->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/xobxB32.png);"));
        label_palyStop = new QLabel(explore_page);
        label_palyStop->setObjectName(QStringLiteral("label_palyStop"));
        label_palyStop->setGeometry(QRect(0, 400, 79, 21));
        label_palyStop->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        label_palyStop->setAlignment(Qt::AlignCenter);
        line_16 = new QFrame(explore_page);
        line_16->setObjectName(QStringLiteral("line_16"));
        line_16->setGeometry(QRect(0, 420, 80, 16));
        line_16->setStyleSheet(QLatin1String("background-image: url(null);\n"
""));
        line_16->setFrameShape(QFrame::HLine);
        line_16->setFrameShadow(QFrame::Sunken);
        stackedWidget->addWidget(explore_page);
        lblbackEx->raise();
        mplayerEx->raise();
        label_goHome_2->raise();
        listWidgetEx->raise();
        label_title_3->raise();
        label_missionName_2->raise();
        lblMissionNameEx->raise();
        label_Controls_2->raise();
        label_xboxIco->raise();
        line_7->raise();
        line_8->raise();
        label_btnA_2->raise();
        label_select->raise();
        label_btnA_3->raise();
        label_nav->raise();
        line_12->raise();
        lblPic->raise();
        groupPlayer->raise();
        label_btnB_play->raise();
        label_palyStop->raise();
        line_16->raise();
        QWidget::setTabOrder(btnNew, btnOpen);
        QWidget::setTabOrder(btnOpen, btnOff);
        QWidget::setTabOrder(btnOff, lblHelp);
        QWidget::setTabOrder(lblHelp, listWidget);

        retranslateUi(NautilusCommander);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(NautilusCommander);
    } // setupUi

    void retranslateUi(QWidget *NautilusCommander)
    {
        NautilusCommander->setWindowTitle(QApplication::translate("NautilusCommander", "Nautilus Commander", 0));
        btnNew->setText(QApplication::translate("NautilusCommander", "START NEW MISSION", 0));
        btnOff->setText(QApplication::translate("NautilusCommander", "TURN OFF", 0));
        btnOpen->setText(QApplication::translate("NautilusCommander", "OPEN MISSION", 0));
        label_bckgd->setText(QString());
        label_logo->setText(QString());
        label_wwtdo->setText(QApplication::translate("NautilusCommander", "\302\277What do you want to do?", 0));
        label_or->setText(QApplication::translate("NautilusCommander", "Or", 0));
        label_logoN->setText(QApplication::translate("NautilusCommander", "NAUTILUS", 0));
        label_logoC->setText(QApplication::translate("NautilusCommander", "COMMANDER", 0));
        label_title->setText(QApplication::translate("NautilusCommander", "Welcome to Nautilus Commander", 0));
        label_need->setText(QApplication::translate("NautilusCommander", "Need", 0));
        lblHelp->setText(QApplication::translate("NautilusCommander", "Help?", 0));
        openMissionBox->setTitle(QString());
        lblListWidget->setText(QString());
        lblShadow->setText(QString());
        lblGamepad->setText(QString());
        lblRepair->setText(QString());
        label_Tips->setText(QApplication::translate("NautilusCommander", "Press           to Accept              Use           to Select", 0));
        label_tipA->setText(QString());
        label_TipCross->setText(QString());
        keyboardGroup->setTitle(QString());
        keyboardLine->setInputMask(QString());
        keyQ->setText(QApplication::translate("NautilusCommander", "Q", 0));
        keyW->setText(QApplication::translate("NautilusCommander", "W", 0));
        keyE->setText(QApplication::translate("NautilusCommander", "E", 0));
        keyR->setText(QApplication::translate("NautilusCommander", "R", 0));
        keyT->setText(QApplication::translate("NautilusCommander", "T", 0));
        keyY->setText(QApplication::translate("NautilusCommander", "Y", 0));
        keyU->setText(QApplication::translate("NautilusCommander", "U", 0));
        keyI->setText(QApplication::translate("NautilusCommander", "I", 0));
        keyO->setText(QApplication::translate("NautilusCommander", "O", 0));
        keyP->setText(QApplication::translate("NautilusCommander", "P", 0));
        keyA->setText(QApplication::translate("NautilusCommander", "A", 0));
        keyS->setText(QApplication::translate("NautilusCommander", "S", 0));
        keyD->setText(QApplication::translate("NautilusCommander", "D", 0));
        keyF->setText(QApplication::translate("NautilusCommander", "F", 0));
        keyG->setText(QApplication::translate("NautilusCommander", "G", 0));
        keyH->setText(QApplication::translate("NautilusCommander", "H", 0));
        keyJ->setText(QApplication::translate("NautilusCommander", "J", 0));
        keyK->setText(QApplication::translate("NautilusCommander", "K", 0));
        keyL->setText(QApplication::translate("NautilusCommander", "L", 0));
        keyB->setText(QApplication::translate("NautilusCommander", "B", 0));
        keyZ->setText(QApplication::translate("NautilusCommander", "Z", 0));
        keyC->setText(QApplication::translate("NautilusCommander", "C", 0));
        keyX->setText(QApplication::translate("NautilusCommander", "X", 0));
        keyM->setText(QApplication::translate("NautilusCommander", "M", 0));
        keyV->setText(QApplication::translate("NautilusCommander", "V", 0));
        keyN->setText(QApplication::translate("NautilusCommander", "N", 0));
        keySpace->setText(QApplication::translate("NautilusCommander", "space", 0));
        keyBackspace->setText(QString());
        keyCancel->setText(QApplication::translate("NautilusCommander", "Cancel", 0));
        keyEnter->setText(QApplication::translate("NautilusCommander", "Enter", 0));
        keyErase->setText(QString());
        label_tipKeyB->setText(QApplication::translate("NautilusCommander", "Please enter a name for your new mission: ", 0));
#ifndef QT_NO_WHATSTHIS
        label_loading->setWhatsThis(QApplication::translate("NautilusCommander", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label_loading->setText(QApplication::translate("NautilusCommander", "Loading...", 0));
        label_goHome->setText(QApplication::translate("NautilusCommander", "Press           Back to Home", 0));
        label_title_2->setText(QApplication::translate("NautilusCommander", "Nautilus ROV Commander ", 0));
        label_missionName->setText(QApplication::translate("NautilusCommander", "Mission Name: ", 0));
        label_rovBatt->setText(QApplication::translate("NautilusCommander", "ROV Battery ", 0));
        labelControlBatt->setText(QApplication::translate("NautilusCommander", "Control Battery", 0));
        label_btnA->setText(QString());
        label_Controls->setText(QApplication::translate("NautilusCommander", "Controls:", 0));
        label_btnB->setText(QString());
        label_btnX->setText(QString());
        label->setText(QString());
        label_cross->setText(QString());
        label_screenshot->setText(QApplication::translate("NautilusCommander", "Photo", 0));
        label_take->setText(QApplication::translate("NautilusCommander", "Take", 0));
        label_Record->setText(QApplication::translate("NautilusCommander", "Record", 0));
        label_video->setText(QApplication::translate("NautilusCommander", "Video", 0));
        label_move->setText(QApplication::translate("NautilusCommander", "Move", 0));
        label_camera->setText(QApplication::translate("NautilusCommander", "Camera", 0));
        statusOkBox->setTitle(QApplication::translate("NautilusCommander", "Status", 0));
        label_Controls_3->setText(QApplication::translate("NautilusCommander", "Running Normally", 0));
        lblOkIcon->setText(QString());
        statusErrorBox->setTitle(QApplication::translate("NautilusCommander", "Status", 0));
        lblError->setText(QApplication::translate("NautilusCommander", "Error", 0));
        lblErrorIcon->setText(QString());
        labelControlBatt_2->setText(QApplication::translate("NautilusCommander", "Depth (m)", 0));
        lblMissionName->setText(QString());
        label_depthIco->setText(QString());
        labelControlBatt_3->setText(QApplication::translate("NautilusCommander", "125", 0));
        labelControlBatt_4->setText(QApplication::translate("NautilusCommander", "30", 0));
        labelControlBatt_5->setText(QApplication::translate("NautilusCommander", "Temperature(\302\260C)", 0));
        label_tempIco->setText(QString());
        statusVideoOff->setTitle(QApplication::translate("NautilusCommander", "Video", 0));
        label_Controls_6->setText(QApplication::translate("NautilusCommander", "Recording Off", 0));
        label_5->setText(QString());
        statusVideoOn->setTitle(QApplication::translate("NautilusCommander", "Video", 0));
        label_Controls_7->setText(QApplication::translate("NautilusCommander", "Recording...", 0));
        label_6->setText(QString());
        label_leftRL->setText(QString());
        label_ARightUD->setText(QString());
        label_camera_pic->setText(QString());
        labelControlBatt_6->setText(QApplication::translate("NautilusCommander", "Camera Position", 0));
        label_center->setText(QApplication::translate("NautilusCommander", "Center", 0));
        label_cameraCenter->setText(QApplication::translate("NautilusCommander", "Camera", 0));
        labelControlBatt_7->setText(QApplication::translate("NautilusCommander", "Lights", 0));
        label_switchOn->setText(QString());
        label_switchOff->setText(QString());
        label_turnROV->setText(QApplication::translate("NautilusCommander", "Turn ROV", 0));
        label_submerge->setText(QApplication::translate("NautilusCommander", "Submerge", 0));
        label_emerge->setText(QApplication::translate("NautilusCommander", "Emerge", 0));
        label_AleftUD->setText(QString());
        label_forwards->setText(QApplication::translate("NautilusCommander", " Forwards", 0));
        label_backwards->setText(QApplication::translate("NautilusCommander", "Backwards", 0));
        label_speedLB->setText(QString());
        label_speed->setText(QApplication::translate("NautilusCommander", "Speed", 0));
        label_speed_down->setText(QApplication::translate("NautilusCommander", "Down", 0));
        label_speedRB->setText(QString());
        label_speed_2->setText(QApplication::translate("NautilusCommander", "Speed", 0));
        label_speed_up->setText(QApplication::translate("NautilusCommander", "Up", 0));
        label_dialBack->setText(QString());
        labelControlBatt_8->setText(QApplication::translate("NautilusCommander", "Speed", 0));
        labelControlBatt_9->setText(QApplication::translate("NautilusCommander", "min", 0));
        labelControlBatt_10->setText(QApplication::translate("NautilusCommander", "max", 0));
        label_btnY->setText(QString());
        label_toggle->setText(QApplication::translate("NautilusCommander", "Toggle", 0));
        label_toggle_2->setText(QApplication::translate("NautilusCommander", "Lights", 0));
        labelBackMW->setText(QString());
        label_toastSS->setText(QApplication::translate("NautilusCommander", "Photo taken", 0));
        label_goHome_2->setText(QApplication::translate("NautilusCommander", "Press           Back to Home", 0));
        label_title_3->setText(QApplication::translate("NautilusCommander", "Nautilus Commander Explore Mission", 0));
        label_missionName_2->setText(QApplication::translate("NautilusCommander", "Mission Name: ", 0));
        lblMissionNameEx->setText(QString());
        label_Controls_2->setText(QApplication::translate("NautilusCommander", "Controls:", 0));
        label_xboxIco->setText(QString());
        label_btnA_2->setText(QString());
        label_select->setText(QApplication::translate("NautilusCommander", "Select", 0));
        label_btnA_3->setText(QString());
        label_nav->setText(QApplication::translate("NautilusCommander", "Navigate", 0));
        lblPic->setText(QString());
        lblbackEx->setText(QString());
        groupPlayer->setTitle(QString());
        lblPlayStopIcon->setText(QString());
        label_btnB_play->setText(QString());
        label_palyStop->setText(QApplication::translate("NautilusCommander", "Play/Stop", 0));
    } // retranslateUi

};

namespace Ui {
    class NautilusCommander: public Ui_NautilusCommander {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTRO_H
