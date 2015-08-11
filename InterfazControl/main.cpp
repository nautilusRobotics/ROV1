#include <QApplication>
#include <QGridLayout>
#include <QShowEvent> 
#include <QFileDialog> 
#include <QTextEdit>
#include <QToolBar>
#include <QPushButton>
#include <QWindow>
#include <QGraphicsOpacityEffect>
#include <QProgressBar>
#include <QObject>
#include <QWidget>
#include <QStatusBar>

#include "player.h"
#include "qmpwidget.h"
#include "mainwindow.h"
#include "qgamecontroller.h"
#include "joystickwidget.h"
#include "qgamecontroller.h"




int main(int argc, char *argv[])
{
    //------------------------------Init------------------------------------------
    QApplication app(argc, argv);
    QString prefix = QCoreApplication::applicationDirPath();

    QMPwidget widget;
    QGridLayout layout(&widget);
    widget.setLayout(&layout); 

    /******************************** ToolBar Buttons  *********************************************/
    QPushButton *button_control = new QPushButton();
    button_control->setIcon(QIcon(prefix+"/icons/control.png"));
    button_control->setIconSize(QSize(32,32));


    QPushButton *button_1 = new QPushButton();
    button_1->setIcon(QIcon(prefix+"/icons/nautilus.svg"));
    button_1->setIconSize(QSize(32,32));


    QPushButton *button_camara = new QPushButton();
    button_camara->setIcon(QIcon(prefix+"/icons/camara.png"));
    button_camara->setIconSize(QSize(32,32));

    QToolBar toolbar;
    toolbar.addWidget(button_1);
    toolbar.addWidget(button_control);
    toolbar.addWidget(button_camara);
    layout.addWidget(&toolbar,0,0);
    /***********************************************************************************************/


    /********************************  Player  *****************************************************/
    QStringList argumentos;
    argumentos.push_back("-user");
    argumentos.push_back("admin");
    argumentos.push_back("-passwd");
    argumentos.push_back("12345");
    QLabel statusBarPlayer;
    Player player(argumentos, "rtsp://10.5.5.110:554//Streaming/Channels/1", &widget,&statusBarPlayer);
    player.setFixedSize(1260,550);
    layout.addWidget(&player, 1, 0);
    /***********************************************************************************************/



    /********************************  Joystick *****************************************************/
    QLabel statusBarJoystick;
    JoystickWidget joystick(0,&statusBarJoystick,button_control);
    SendAction* sa =joystick.getSendAction();
    sa->setMaximumSize(1280,50);
    layout.addWidget(sa,2,0);
   /***********************************************************************************************/

    QProgressBar battery;
    battery.setValue(100);
    battery.setStyleSheet("QProgressBar {border: 2px solid white;border-radius: 10px; text-align: center;padding: 1px;}  QProgressBar::chunk { width: 10px;  background: qlineargradient(x1: 0, y1: 0, x2: 5, y2: 0, stop: 0 green, stop: 1 white);}");
    battery.setFixedSize(200,25);
    layout.addWidget(&battery,2,1);

    QProgressBar depth;
    depth.setValue(50);
    depth.setStyleSheet("QProgressBar {border: 2px solid white;border-radius: 10px; text-align: center;padding: 1px;}  QProgressBar::chunk { width: 10px;  background: qlineargradient(x1: 0, y1: 0, x2: 5, y2: 0, stop: 0 green, stop: 1 white);}");

    depth.setFixedSize(200,25);
    layout.addWidget(&depth,2,2);


    QLabel statusBar2;
    statusBar2.setText("Robot: Conectado");

    QLabel statusBar4;
    statusBar4.setText("Camara2: Conectada");

    layout.addWidget(&statusBarJoystick,3,0);
    layout.addWidget(&statusBar2,3,1);
    layout.addWidget(&statusBarPlayer,3,2);
    layout.addWidget(&statusBar4,3,3);

     widget.setGeometry(400,Qt::AlignCenter,1280,720);
     widget.setFixedSize(1280,720);
     QIcon icon(prefix+"/icons/nautilus.svg");
     widget.setWindowIcon(icon);   
     widget.show();
     widget.fixRepaint();

     return app.exec();
}





