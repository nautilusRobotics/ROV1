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
    QLabel *label_btnY;
    QLabel *label;
    QLabel *label_cross;
    QLabel *label_screenshot;
    QFrame *line_2;
    QLabel *label_take;
    QFrame *line_3;
    QLabel *label_onoff;
    QLabel *label_lights;
    QFrame *line_4;
    QLabel *label_Record;
    QLabel *label_video;
    QFrame *line_5;
    QLabel *label_move;
    QLabel *label_camera;
    QFrame *line_6;
    QGroupBox *statusOkBox;
    QLabel *label_Controls_3;
    QLabel *label_2;
    QGroupBox *statusErrorBox;
    QLabel *lblError;
    QLabel *label_4;
    QLabel *labelControlBatt_2;
    QLabel *lblMissionName;
    QLabel *label_depthIco;
    QLabel *labelControlBatt_3;
    QLabel *labelControlBatt_4;
    QLabel *labelControlBatt_5;
    QLabel *label_depthIco_2;
    QGroupBox *statusVideoOff;
    QLabel *label_Controls_6;
    QLabel *label_5;
    QGroupBox *statusVideoOn;
    QLabel *label_Controls_7;
    QLabel *label_6;
    QLabel *label_leftRL;
    QLabel *label_AleftUD_3;
    QLabel *label_3;
    QLabel *labelControlBatt_6;
    QSlider *panCamera;
    QSlider *tiltCamera;
    QLabel *label_center;
    QLabel *label_take_4;
    QLabel *labelControlBatt_7;
    QLabel *label_switchOn;
    QLabel *label_switchOff;
    QFrame *line_9;
    QFrame *line_10;
    QLabel *label_turnROV;
    QLabel *label_submerge;
    QLabel *label_move_4;
    QLabel *label_AleftUD_4;
    QFrame *line_11;
    QLabel *label_fordward;
    QLabel *label_backwards;
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
    QLabel *lblDefault;
    QLabel *label_btnA_3;
    QLabel *label_nav;
    QFrame *line_12;
    QLabel *lblPic;

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
        label_TipCross->setGeometry(QRect(1072, 905, 32, 32));
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
        keyQ->setGeometry(QRect(30, 90, 60, 83));
        keyQ->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyW = new QPushButton(keyboardGroup);
        keyW->setObjectName(QStringLiteral("keyW"));
        keyW->setGeometry(QRect(100, 90, 60, 83));
        keyW->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
""));
        keyE = new QPushButton(keyboardGroup);
        keyE->setObjectName(QStringLiteral("keyE"));
        keyE->setGeometry(QRect(170, 90, 60, 83));
        keyE->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyR = new QPushButton(keyboardGroup);
        keyR->setObjectName(QStringLiteral("keyR"));
        keyR->setGeometry(QRect(240, 90, 60, 83));
        keyR->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyT = new QPushButton(keyboardGroup);
        keyT->setObjectName(QStringLiteral("keyT"));
        keyT->setGeometry(QRect(310, 90, 60, 83));
        keyT->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyY = new QPushButton(keyboardGroup);
        keyY->setObjectName(QStringLiteral("keyY"));
        keyY->setGeometry(QRect(380, 90, 60, 83));
        keyY->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyU = new QPushButton(keyboardGroup);
        keyU->setObjectName(QStringLiteral("keyU"));
        keyU->setGeometry(QRect(450, 90, 60, 83));
        keyU->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyI = new QPushButton(keyboardGroup);
        keyI->setObjectName(QStringLiteral("keyI"));
        keyI->setGeometry(QRect(520, 90, 60, 83));
        keyI->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyO = new QPushButton(keyboardGroup);
        keyO->setObjectName(QStringLiteral("keyO"));
        keyO->setGeometry(QRect(590, 90, 60, 83));
        keyO->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyP = new QPushButton(keyboardGroup);
        keyP->setObjectName(QStringLiteral("keyP"));
        keyP->setGeometry(QRect(660, 90, 60, 83));
        keyP->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyA = new QPushButton(keyboardGroup);
        keyA->setObjectName(QStringLiteral("keyA"));
        keyA->setGeometry(QRect(60, 190, 60, 83));
        keyA->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyS = new QPushButton(keyboardGroup);
        keyS->setObjectName(QStringLiteral("keyS"));
        keyS->setGeometry(QRect(130, 190, 60, 83));
        keyS->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyD = new QPushButton(keyboardGroup);
        keyD->setObjectName(QStringLiteral("keyD"));
        keyD->setGeometry(QRect(200, 190, 60, 83));
        keyD->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyF = new QPushButton(keyboardGroup);
        keyF->setObjectName(QStringLiteral("keyF"));
        keyF->setGeometry(QRect(270, 190, 60, 83));
        keyF->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyG = new QPushButton(keyboardGroup);
        keyG->setObjectName(QStringLiteral("keyG"));
        keyG->setGeometry(QRect(340, 190, 60, 83));
        keyG->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyH = new QPushButton(keyboardGroup);
        keyH->setObjectName(QStringLiteral("keyH"));
        keyH->setGeometry(QRect(410, 190, 60, 83));
        keyH->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyJ = new QPushButton(keyboardGroup);
        keyJ->setObjectName(QStringLiteral("keyJ"));
        keyJ->setGeometry(QRect(480, 190, 60, 83));
        keyJ->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyK = new QPushButton(keyboardGroup);
        keyK->setObjectName(QStringLiteral("keyK"));
        keyK->setGeometry(QRect(550, 190, 60, 83));
        keyK->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyL = new QPushButton(keyboardGroup);
        keyL->setObjectName(QStringLiteral("keyL"));
        keyL->setGeometry(QRect(620, 190, 60, 83));
        keyL->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyB = new QPushButton(keyboardGroup);
        keyB->setObjectName(QStringLiteral("keyB"));
        keyB->setGeometry(QRect(410, 290, 60, 83));
        keyB->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyZ = new QPushButton(keyboardGroup);
        keyZ->setObjectName(QStringLiteral("keyZ"));
        keyZ->setGeometry(QRect(130, 290, 60, 83));
        keyZ->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyC = new QPushButton(keyboardGroup);
        keyC->setObjectName(QStringLiteral("keyC"));
        keyC->setGeometry(QRect(270, 290, 60, 83));
        keyC->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyX = new QPushButton(keyboardGroup);
        keyX->setObjectName(QStringLiteral("keyX"));
        keyX->setGeometry(QRect(200, 290, 60, 83));
        keyX->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyM = new QPushButton(keyboardGroup);
        keyM->setObjectName(QStringLiteral("keyM"));
        keyM->setGeometry(QRect(550, 290, 60, 83));
        keyM->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyV = new QPushButton(keyboardGroup);
        keyV->setObjectName(QStringLiteral("keyV"));
        keyV->setGeometry(QRect(340, 290, 60, 83));
        keyV->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyN = new QPushButton(keyboardGroup);
        keyN->setObjectName(QStringLiteral("keyN"));
        keyN->setGeometry(QRect(480, 290, 60, 83));
        keyN->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keySpace = new QPushButton(keyboardGroup);
        keySpace->setObjectName(QStringLiteral("keySpace"));
        keySpace->setGeometry(QRect(200, 380, 351, 83));
        keySpace->setStyleSheet(QLatin1String("border: 20px; border-radius:15px;\n"
"background-color: rgb(89, 96, 102);\n"
"font-size: 18pt;\n"
"font-weight: bold;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        keyBackspace = new QPushButton(keyboardGroup);
        keyBackspace->setObjectName(QStringLiteral("keyBackspace"));
        keyBackspace->setGeometry(QRect(633, 290, 81, 83));
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
        keyEnter->setGeometry(QRect(560, 380, 161, 83));
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
        mission_page = new QWidget();
        mission_page->setObjectName(QStringLiteral("mission_page"));
        mission_page->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/backVideo.svg);"));
        mplayerWG = new QMPwidget(mission_page);
        mplayerWG->setObjectName(QStringLiteral("mplayerWG"));
        mplayerWG->setEnabled(false);
        mplayerWG->setGeometry(QRect(80, 80, 1600, 1000));
        mplayerWG->setStyleSheet(QStringLiteral("background-image: url(null);"));
        label_goHome = new QLabel(mission_page);
        label_goHome->setObjectName(QStringLiteral("label_goHome"));
        label_goHome->setGeometry(QRect(120, 30, 221, 21));
        label_goHome->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(153, 153, 153);\n"
"font: bold 11pt;"));
        label_title_2 = new QLabel(mission_page);
        label_title_2->setObjectName(QStringLiteral("label_title_2"));
        label_title_2->setGeometry(QRect(700, 30, 521, 21));
        label_title_2->setStyleSheet(QLatin1String("font: bold 20pt;\n"
"background-image: url(null);"));
        label_missionName = new QLabel(mission_page);
        label_missionName->setObjectName(QStringLiteral("label_missionName"));
        label_missionName->setGeometry(QRect(1370, 30, 131, 21));
        label_missionName->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(153, 153, 153);\n"
"font: bold 11pt;"));
        progressBattRov = new QProgressBar(mission_page);
        progressBattRov->setObjectName(QStringLiteral("progressBattRov"));
        progressBattRov->setGeometry(QRect(1720, 130, 161, 23));
        progressBattRov->setStyleSheet(QLatin1String("QProgressBar {border: 2px solid grey;border-radius: 5px; text-align: center; background-image:  url(:/null); }\n"
"QProgressBar::chunk {background-color: #37A2E5;width: 20px}"));
        progressBattRov->setValue(1);
        label_rovBatt = new QLabel(mission_page);
        label_rovBatt->setObjectName(QStringLiteral("label_rovBatt"));
        label_rovBatt->setGeometry(QRect(1760, 160, 91, 31));
        label_rovBatt->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(153, 153, 153);\n"
"font:  11pt;"));
        labelControlBatt = new QLabel(mission_page);
        labelControlBatt->setObjectName(QStringLiteral("labelControlBatt"));
        labelControlBatt->setGeometry(QRect(1740, 250, 121, 21));
        labelControlBatt->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(153, 153, 153);\n"
"font: 11pt;"));
        progressBattControl = new QProgressBar(mission_page);
        progressBattControl->setObjectName(QStringLiteral("progressBattControl"));
        progressBattControl->setGeometry(QRect(1720, 220, 161, 23));
        progressBattControl->setStyleSheet(QLatin1String("QProgressBar {border: 2px solid grey;border-radius: 5px; text-align: center; background-image:  url(:/null); }\n"
"QProgressBar::chunk {background-color:  rgb(146, 255, 116);width: 20px;}"));
        progressBattControl->setValue(1);
        label_btnA = new QLabel(mission_page);
        label_btnA->setObjectName(QStringLiteral("label_btnA"));
        label_btnA->setGeometry(QRect(25, 190, 32, 32));
        label_btnA->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/xboxA32.png);"));
        label_Controls = new QLabel(mission_page);
        label_Controls->setObjectName(QStringLiteral("label_Controls"));
        label_Controls->setGeometry(QRect(3, 150, 72, 15));
        label_Controls->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(255, 255, 255);\n"
"font: bold 11pt;"));
        line = new QFrame(mission_page);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 171, 80, 16));
        line->setStyleSheet(QLatin1String("background-image: url(null);\n"
""));
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
        label_btnY = new QLabel(mission_page);
        label_btnY->setObjectName(QStringLiteral("label_btnY"));
        label_btnY->setGeometry(QRect(25, 414, 32, 32));
        label_btnY->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/xboxY32.png);"));
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
        label_screenshot->setGeometry(QRect(2, 314, 78, 16));
        label_screenshot->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        line_2 = new QFrame(mission_page);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 250, 80, 16));
        line_2->setStyleSheet(QLatin1String("background-image: url(null);\n"
""));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_take = new QLabel(mission_page);
        label_take->setObjectName(QStringLiteral("label_take"));
        label_take->setGeometry(QRect(23, 297, 31, 21));
        label_take->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        line_3 = new QFrame(mission_page);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(0, 327, 80, 16));
        line_3->setStyleSheet(QLatin1String("background-image: url(null);\n"
""));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_onoff = new QLabel(mission_page);
        label_onoff->setObjectName(QStringLiteral("label_onoff"));
        label_onoff->setGeometry(QRect(20, 370, 51, 21));
        label_onoff->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        label_lights = new QLabel(mission_page);
        label_lights->setObjectName(QStringLiteral("label_lights"));
        label_lights->setGeometry(QRect(20, 390, 41, 16));
        label_lights->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        line_4 = new QFrame(mission_page);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(0, 400, 80, 16));
        line_4->setStyleSheet(QLatin1String("background-image: url(null);\n"
""));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_Record = new QLabel(mission_page);
        label_Record->setObjectName(QStringLiteral("label_Record"));
        label_Record->setGeometry(QRect(17, 445, 51, 16));
        label_Record->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        label_video = new QLabel(mission_page);
        label_video->setObjectName(QStringLiteral("label_video"));
        label_video->setGeometry(QRect(20, 460, 41, 16));
        label_video->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        line_5 = new QFrame(mission_page);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(0, 470, 80, 16));
        line_5->setStyleSheet(QLatin1String("background-image: url(null);\n"
""));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        label_move = new QLabel(mission_page);
        label_move->setObjectName(QStringLiteral("label_move"));
        label_move->setGeometry(QRect(20, 520, 41, 16));
        label_move->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        label_camera = new QLabel(mission_page);
        label_camera->setObjectName(QStringLiteral("label_camera"));
        label_camera->setGeometry(QRect(14, 536, 51, 16));
        label_camera->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        line_6 = new QFrame(mission_page);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(0, 550, 80, 16));
        line_6->setStyleSheet(QLatin1String("background-image: url(null);\n"
""));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        statusOkBox = new QGroupBox(mission_page);
        statusOkBox->setObjectName(QStringLiteral("statusOkBox"));
        statusOkBox->setGeometry(QRect(1680, 1000, 240, 80));
        statusOkBox->setStyleSheet(QLatin1String("background-image: url(null);\n"
"background-color: rgb(244, 244, 244);\n"
"color: rgb(153, 153, 153);\n"
"font: bold 11pt;"));
        label_Controls_3 = new QLabel(statusOkBox);
        label_Controls_3->setObjectName(QStringLiteral("label_Controls_3"));
        label_Controls_3->setGeometry(QRect(60, 40, 151, 16));
        label_Controls_3->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(163, 175, 179);\n"
"font: bold 11pt;"));
        label_2 = new QLabel(statusOkBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 30, 32, 32));
        label_2->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/ok.png);"));
        label_2->setFrameShadow(QFrame::Plain);
        statusErrorBox = new QGroupBox(mission_page);
        statusErrorBox->setObjectName(QStringLiteral("statusErrorBox"));
        statusErrorBox->setGeometry(QRect(1680, 1000, 240, 80));
        statusErrorBox->setStyleSheet(QLatin1String("background-image: url(null);\n"
"background-color: rgb(244, 244, 244);\n"
"color: rgb(153, 153, 153);\n"
"font: bold 11pt;"));
        lblError = new QLabel(statusErrorBox);
        lblError->setObjectName(QStringLiteral("lblError"));
        lblError->setGeometry(QRect(50, 30, 181, 31));
        lblError->setStyleSheet(QLatin1String("\n"
"color: rgb(163, 175, 179);\n"
"font: bold 11pt;"));
        label_4 = new QLabel(statusErrorBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 30, 32, 32));
        label_4->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/alert.png);"));
        label_4->setFrameShadow(QFrame::Plain);
        labelControlBatt_2 = new QLabel(mission_page);
        labelControlBatt_2->setObjectName(QStringLiteral("labelControlBatt_2"));
        labelControlBatt_2->setGeometry(QRect(1750, 350, 91, 31));
        labelControlBatt_2->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(153, 153, 153);\n"
"font:  11pt;"));
        lblMissionName = new QLabel(mission_page);
        lblMissionName->setObjectName(QStringLiteral("lblMissionName"));
        lblMissionName->setGeometry(QRect(1510, 30, 131, 21));
        lblMissionName->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(153, 153, 153);\n"
"font: bold 11pt;"));
        label_depthIco = new QLabel(mission_page);
        label_depthIco->setObjectName(QStringLiteral("label_depthIco"));
        label_depthIco->setGeometry(QRect(1830, 320, 32, 32));
        label_depthIco->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/depth.png);"));
        label_depthIco->setFrameShape(QFrame::NoFrame);
        labelControlBatt_3 = new QLabel(mission_page);
        labelControlBatt_3->setObjectName(QStringLiteral("labelControlBatt_3"));
        labelControlBatt_3->setGeometry(QRect(1740, 320, 81, 41));
        labelControlBatt_3->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(153, 153, 153);\n"
"font: bold 30pt;"));
        labelControlBatt_4 = new QLabel(mission_page);
        labelControlBatt_4->setObjectName(QStringLiteral("labelControlBatt_4"));
        labelControlBatt_4->setGeometry(QRect(1760, 440, 61, 41));
        labelControlBatt_4->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(153, 153, 153);\n"
"font: bold 30pt;"));
        labelControlBatt_5 = new QLabel(mission_page);
        labelControlBatt_5->setObjectName(QStringLiteral("labelControlBatt_5"));
        labelControlBatt_5->setGeometry(QRect(1740, 480, 131, 31));
        labelControlBatt_5->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(153, 153, 153);\n"
"font:  11pt;"));
        label_depthIco_2 = new QLabel(mission_page);
        label_depthIco_2->setObjectName(QStringLiteral("label_depthIco_2"));
        label_depthIco_2->setGeometry(QRect(1830, 440, 32, 32));
        label_depthIco_2->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/temp.png);"));
        label_depthIco_2->setFrameShape(QFrame::NoFrame);
        statusVideoOff = new QGroupBox(mission_page);
        statusVideoOff->setObjectName(QStringLiteral("statusVideoOff"));
        statusVideoOff->setGeometry(QRect(1680, 920, 240, 80));
        statusVideoOff->setStyleSheet(QLatin1String("background-image: url(null);\n"
"background-color: rgb(244, 244, 244);\n"
"color: rgb(153, 153, 153);\n"
"font: bold 11pt;"));
        label_Controls_6 = new QLabel(statusVideoOff);
        label_Controls_6->setObjectName(QStringLiteral("label_Controls_6"));
        label_Controls_6->setGeometry(QRect(60, 40, 151, 16));
        label_Controls_6->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(163, 175, 179);\n"
"font: bold 11pt;"));
        label_5 = new QLabel(statusVideoOff);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 30, 32, 32));
        label_5->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/recordOff.png);"));
        label_5->setFrameShadow(QFrame::Plain);
        statusVideoOn = new QGroupBox(mission_page);
        statusVideoOn->setObjectName(QStringLiteral("statusVideoOn"));
        statusVideoOn->setGeometry(QRect(1680, 920, 240, 80));
        statusVideoOn->setStyleSheet(QLatin1String("background-image: url(null);\n"
"background-color: rgb(244, 244, 244);\n"
"color: rgb(153, 153, 153);\n"
"font: bold 11pt;"));
        label_Controls_7 = new QLabel(statusVideoOn);
        label_Controls_7->setObjectName(QStringLiteral("label_Controls_7"));
        label_Controls_7->setGeometry(QRect(60, 40, 151, 16));
        label_Controls_7->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(163, 175, 179);\n"
"font: bold 11pt;"));
        label_6 = new QLabel(statusVideoOn);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 30, 32, 32));
        label_6->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/recordOn.png);"));
        label_6->setFrameShadow(QFrame::Plain);
        label_leftRL = new QLabel(mission_page);
        label_leftRL->setObjectName(QStringLiteral("label_leftRL"));
        label_leftRL->setGeometry(QRect(6, 571, 70, 50));
        label_leftRL->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/xboxLlr.png);"));
        label_AleftUD_3 = new QLabel(mission_page);
        label_AleftUD_3->setObjectName(QStringLiteral("label_AleftUD_3"));
        label_AleftUD_3->setGeometry(QRect(15, 790, 50, 70));
        label_AleftUD_3->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/xboxRud.png);"));
        label_3 = new QLabel(mission_page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1770, 560, 50, 50));
        label_3->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/camera50x50.png);"));
        labelControlBatt_6 = new QLabel(mission_page);
        labelControlBatt_6->setObjectName(QStringLiteral("labelControlBatt_6"));
        labelControlBatt_6->setGeometry(QRect(1740, 640, 131, 31));
        labelControlBatt_6->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(153, 153, 153);\n"
"font:  11pt;"));
        panCamera = new QSlider(mission_page);
        panCamera->setObjectName(QStringLiteral("panCamera"));
        panCamera->setGeometry(QRect(1751, 630, 90, 12));
        panCamera->setFocusPolicy(Qt::NoFocus);
        panCamera->setStyleSheet(QLatin1String("QSlider{background-image: url(null);}\n"
"QSlider::groove:horizontal {border: 0px solid #999999;height: 10px;border-radius: 10px;}\n"
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
        tiltCamera->setGeometry(QRect(1840, 535, 10, 90));
        tiltCamera->setFocusPolicy(Qt::NoFocus);
        tiltCamera->setStyleSheet(QLatin1String("QSlider{background-image: url(null);}\n"
"QSlider::groove:vertical {border: 0px solid #999999;width: 10px;border-radius: 5px;}\n"
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
        label_center->setGeometry(QRect(20, 220, 51, 21));
        label_center->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        label_take_4 = new QLabel(mission_page);
        label_take_4->setObjectName(QStringLiteral("label_take_4"));
        label_take_4->setGeometry(QRect(16, 232, 51, 21));
        label_take_4->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        labelControlBatt_7 = new QLabel(mission_page);
        labelControlBatt_7->setObjectName(QStringLiteral("labelControlBatt_7"));
        labelControlBatt_7->setGeometry(QRect(1780, 740, 51, 31));
        labelControlBatt_7->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(153, 153, 153);\n"
"font:  11pt;"));
        label_switchOn = new QLabel(mission_page);
        label_switchOn->setObjectName(QStringLiteral("label_switchOn"));
        label_switchOn->setGeometry(QRect(1770, 680, 64, 64));
        label_switchOn->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/switchOn.png);"));
        label_switchOff = new QLabel(mission_page);
        label_switchOff->setObjectName(QStringLiteral("label_switchOff"));
        label_switchOff->setGeometry(QRect(1770, 680, 64, 64));
        label_switchOff->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/switchOff.png);"));
        line_9 = new QFrame(mission_page);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setGeometry(QRect(0, 650, 80, 16));
        line_9->setStyleSheet(QLatin1String("background-image: url(null);\n"
""));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);
        line_10 = new QFrame(mission_page);
        line_10->setObjectName(QStringLiteral("line_10"));
        line_10->setGeometry(QRect(0, 770, 80, 16));
        line_10->setStyleSheet(QLatin1String("background-image: url(null);\n"
""));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);
        label_turnROV = new QLabel(mission_page);
        label_turnROV->setObjectName(QStringLiteral("label_turnROV"));
        label_turnROV->setGeometry(QRect(10, 630, 71, 16));
        label_turnROV->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        label_submerge = new QLabel(mission_page);
        label_submerge->setObjectName(QStringLiteral("label_submerge"));
        label_submerge->setGeometry(QRect(7, 860, 71, 16));
        label_submerge->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        label_move_4 = new QLabel(mission_page);
        label_move_4->setObjectName(QStringLiteral("label_move_4"));
        label_move_4->setGeometry(QRect(15, 874, 61, 16));
        label_move_4->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        label_AleftUD_4 = new QLabel(mission_page);
        label_AleftUD_4->setObjectName(QStringLiteral("label_AleftUD_4"));
        label_AleftUD_4->setGeometry(QRect(15, 664, 50, 70));
        label_AleftUD_4->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/xboxLud.png);"));
        line_11 = new QFrame(mission_page);
        line_11->setObjectName(QStringLiteral("line_11"));
        line_11->setGeometry(QRect(0, 886, 80, 16));
        line_11->setStyleSheet(QLatin1String("background-image: url(null);\n"
""));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);
        label_fordward = new QLabel(mission_page);
        label_fordward->setObjectName(QStringLiteral("label_fordward"));
        label_fordward->setGeometry(QRect(4, 736, 71, 16));
        label_fordward->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        label_backwards = new QLabel(mission_page);
        label_backwards->setObjectName(QStringLiteral("label_backwards"));
        label_backwards->setGeometry(QRect(5, 753, 71, 16));
        label_backwards->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        stackedWidget->addWidget(mission_page);
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
        label_btnY->raise();
        label->raise();
        label_cross->raise();
        label_screenshot->raise();
        line_2->raise();
        label_take->raise();
        line_3->raise();
        label_onoff->raise();
        label_lights->raise();
        line_4->raise();
        label_Record->raise();
        label_video->raise();
        line_5->raise();
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
        label_depthIco_2->raise();
        statusVideoOn->raise();
        statusVideoOff->raise();
        label_leftRL->raise();
        label_AleftUD_3->raise();
        label_3->raise();
        labelControlBatt_6->raise();
        panCamera->raise();
        tiltCamera->raise();
        label_center->raise();
        label_take_4->raise();
        labelControlBatt_7->raise();
        label_switchOn->raise();
        label_switchOff->raise();
        line_9->raise();
        line_10->raise();
        label_turnROV->raise();
        label_submerge->raise();
        label_move_4->raise();
        label_AleftUD_4->raise();
        line_11->raise();
        label_fordward->raise();
        label_backwards->raise();
        explore_page = new QWidget();
        explore_page->setObjectName(QStringLiteral("explore_page"));
        explore_page->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/backVideo.svg);"));
        mplayerEx = new QMPwidget(explore_page);
        mplayerEx->setObjectName(QStringLiteral("mplayerEx"));
        mplayerEx->setGeometry(QRect(80, 80, 1600, 1000));
        mplayerEx->setStyleSheet(QStringLiteral("background-image: url(null);"));
        label_goHome_2 = new QLabel(explore_page);
        label_goHome_2->setObjectName(QStringLiteral("label_goHome_2"));
        label_goHome_2->setGeometry(QRect(120, 30, 221, 21));
        label_goHome_2->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(153, 153, 153);\n"
"font: bold 11pt;"));
        listWidgetEx = new QListWidget(explore_page);
        listWidgetEx->setObjectName(QStringLiteral("listWidgetEx"));
        listWidgetEx->setGeometry(QRect(1680, 80, 256, 1000));
        listWidgetEx->setStyleSheet(QLatin1String("background-image: url(null);\n"
"background-color: rgb(242, 242, 242);"));
        label_title_3 = new QLabel(explore_page);
        label_title_3->setObjectName(QStringLiteral("label_title_3"));
        label_title_3->setGeometry(QRect(680, 20, 571, 31));
        label_title_3->setStyleSheet(QLatin1String("font: bold 20pt;\n"
"background-image: url(null);"));
        label_missionName_2 = new QLabel(explore_page);
        label_missionName_2->setObjectName(QStringLiteral("label_missionName_2"));
        label_missionName_2->setGeometry(QRect(1370, 30, 131, 21));
        label_missionName_2->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(153, 153, 153);\n"
"font: bold 11pt;"));
        lblMissionNameEx = new QLabel(explore_page);
        lblMissionNameEx->setObjectName(QStringLiteral("lblMissionNameEx"));
        lblMissionNameEx->setGeometry(QRect(1510, 30, 131, 21));
        lblMissionNameEx->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(153, 153, 153);\n"
"font: bold 11pt;"));
        label_Controls_2 = new QLabel(explore_page);
        label_Controls_2->setObjectName(QStringLiteral("label_Controls_2"));
        label_Controls_2->setGeometry(QRect(3, 149, 72, 15));
        label_Controls_2->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(255, 255, 255);\n"
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
        line_8->setStyleSheet(QLatin1String("background-image: url(null);\n"
""));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        label_btnA_2 = new QLabel(explore_page);
        label_btnA_2->setObjectName(QStringLiteral("label_btnA_2"));
        label_btnA_2->setGeometry(QRect(25, 190, 32, 32));
        label_btnA_2->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/xboxA32.png);"));
        label_select = new QLabel(explore_page);
        label_select->setObjectName(QStringLiteral("label_select"));
        label_select->setGeometry(QRect(20, 230, 51, 21));
        label_select->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
        lblDefault = new QLabel(explore_page);
        lblDefault->setObjectName(QStringLiteral("lblDefault"));
        lblDefault->setGeometry(QRect(80, 80, 1600, 1000));
        lblDefault->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/explorerDefault2.png);"));
        label_btnA_3 = new QLabel(explore_page);
        label_btnA_3->setObjectName(QStringLiteral("label_btnA_3"));
        label_btnA_3->setGeometry(QRect(15, 270, 50, 50));
        label_btnA_3->setStyleSheet(QStringLiteral("background-image:url(:/new/prefix1/xboxCross50.png)"));
        label_nav = new QLabel(explore_page);
        label_nav->setObjectName(QStringLiteral("label_nav"));
        label_nav->setGeometry(QRect(12, 320, 71, 21));
        label_nav->setStyleSheet(QLatin1String("background-image: url(null);\n"
"color: rgb(255, 255, 255);\n"
"font: bold 9pt;"));
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
        lblPic->setStyleSheet(QStringLiteral("background-image: url(:null);"));
        stackedWidget->addWidget(explore_page);
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
        label_tipKeyB->setText(QApplication::translate("NautilusCommander", "Please enter the new mission's name: ", 0));
        label_goHome->setText(QApplication::translate("NautilusCommander", "Press           Back to Home", 0));
        label_title_2->setText(QApplication::translate("NautilusCommander", "Nautilus Commander ROV Control", 0));
        label_missionName->setText(QApplication::translate("NautilusCommander", "Mission Name: ", 0));
        label_rovBatt->setText(QApplication::translate("NautilusCommander", "ROV Battery ", 0));
        labelControlBatt->setText(QApplication::translate("NautilusCommander", "Control Battery", 0));
        label_btnA->setText(QString());
        label_Controls->setText(QApplication::translate("NautilusCommander", "Controls:", 0));
        label_btnB->setText(QString());
        label_btnX->setText(QString());
        label_btnY->setText(QString());
        label->setText(QString());
        label_cross->setText(QString());
        label_screenshot->setText(QApplication::translate("NautilusCommander", "Screenshot", 0));
        label_take->setText(QApplication::translate("NautilusCommander", "Take", 0));
        label_onoff->setText(QApplication::translate("NautilusCommander", "On/Off ", 0));
        label_lights->setText(QApplication::translate("NautilusCommander", "Lights", 0));
        label_Record->setText(QApplication::translate("NautilusCommander", "Record", 0));
        label_video->setText(QApplication::translate("NautilusCommander", "Video", 0));
        label_move->setText(QApplication::translate("NautilusCommander", "Move", 0));
        label_camera->setText(QApplication::translate("NautilusCommander", "Camera", 0));
        statusOkBox->setTitle(QApplication::translate("NautilusCommander", "Status", 0));
        label_Controls_3->setText(QApplication::translate("NautilusCommander", "Running Normally", 0));
        label_2->setText(QString());
        statusErrorBox->setTitle(QApplication::translate("NautilusCommander", "Status", 0));
        lblError->setText(QApplication::translate("NautilusCommander", "Error", 0));
        label_4->setText(QString());
        labelControlBatt_2->setText(QApplication::translate("NautilusCommander", "Depth (m)", 0));
        lblMissionName->setText(QString());
        label_depthIco->setText(QString());
        labelControlBatt_3->setText(QApplication::translate("NautilusCommander", "125", 0));
        labelControlBatt_4->setText(QApplication::translate("NautilusCommander", "30", 0));
        labelControlBatt_5->setText(QApplication::translate("NautilusCommander", "Temperature(\302\260C)", 0));
        label_depthIco_2->setText(QString());
        statusVideoOff->setTitle(QApplication::translate("NautilusCommander", "Video", 0));
        label_Controls_6->setText(QApplication::translate("NautilusCommander", "Recording Off", 0));
        label_5->setText(QString());
        statusVideoOn->setTitle(QApplication::translate("NautilusCommander", "Video", 0));
        label_Controls_7->setText(QApplication::translate("NautilusCommander", "Recording...", 0));
        label_6->setText(QString());
        label_leftRL->setText(QString());
        label_AleftUD_3->setText(QString());
        label_3->setText(QString());
        labelControlBatt_6->setText(QApplication::translate("NautilusCommander", "Camera Position", 0));
        label_center->setText(QApplication::translate("NautilusCommander", "Center", 0));
        label_take_4->setText(QApplication::translate("NautilusCommander", "Camera", 0));
        labelControlBatt_7->setText(QApplication::translate("NautilusCommander", "Lights", 0));
        label_switchOn->setText(QString());
        label_switchOff->setText(QString());
        label_turnROV->setText(QApplication::translate("NautilusCommander", "Turn ROV", 0));
        label_submerge->setText(QApplication::translate("NautilusCommander", "Submerge", 0));
        label_move_4->setText(QApplication::translate("NautilusCommander", "Emerge", 0));
        label_AleftUD_4->setText(QString());
        label_fordward->setText(QApplication::translate("NautilusCommander", "Fordwards", 0));
        label_backwards->setText(QApplication::translate("NautilusCommander", "Backwards", 0));
        label_goHome_2->setText(QApplication::translate("NautilusCommander", "Press           Back to Home", 0));
        label_title_3->setText(QApplication::translate("NautilusCommander", "Nautilus Commander Explore Mission", 0));
        label_missionName_2->setText(QApplication::translate("NautilusCommander", "Mission Name: ", 0));
        lblMissionNameEx->setText(QString());
        label_Controls_2->setText(QApplication::translate("NautilusCommander", "Controls:", 0));
        label_xboxIco->setText(QString());
        label_btnA_2->setText(QString());
        label_select->setText(QApplication::translate("NautilusCommander", "Select", 0));
        lblDefault->setText(QString());
        label_btnA_3->setText(QString());
        label_nav->setText(QApplication::translate("NautilusCommander", "Navigate", 0));
        lblPic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NautilusCommander: public Ui_NautilusCommander {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTRO_H
