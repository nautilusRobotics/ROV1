/***************************************************************************
 *   Copyright (C) 2014 M Wellings                                         *
 *   info@openforeveryone.co.uk                                            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License version 2 as     *
 *   published by the Free Software Foundation                             *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "joystickwidget.h" 

//#define USER_DEBUG_J

#ifdef Q_PROCESSOR_ARM
extern QString createPath(QString path);
#endif

JoystickWidget::JoystickWidget(QWidget *parent): QWidget(parent){


    //sendAction=new SendAction();

    /************************************DEFINICION DE MAPEO DEL CONTROL************************************************************************************/
    buttonsXbox<<  button_Y<<button_B<<button_A<<button_X<<button_LB<<button_RB<<button_LT<<button_RT<<button_back<<button_start<<button_LaBtn<<button_RaBtn;
    axisXbox<< axis_left_horizontal<<axis_left_vertical<<axis_right_horizontal<<axis_right_vertical<<axis_cross_horizontal<<axis_cross_vertical ;
    /*******************************************************************************************************************************************************/

    gameController=NULL;


}

void JoystickWidget::init(){
    setController();

}

void JoystickWidget::handleQGameControllerAxisEvent(QGameControllerAxisEvent* event)
{
    int axis = event->axis();
    float num=1000;
    int value=(int)(event->value()*num);
#ifdef USER_DEBUG_J
    qDebug("handleQGameControllerAxisEvent");
    qDebug("Value In joysctick %d", value );
#endif
    //sendAction->axisEvent(axisXbox.at(axis),value);
    emit joystickAxisEvent(axisXbox.at(axis),value);
    delete event;   //QGameControllerEvents unlike QEvents are not deleted automatically.
}

void JoystickWidget::handleQGameControllerButtonEvent(QGameControllerButtonEvent* event)
{

    int button = event->button();
    QString btn=buttonsXbox.at(button);


#ifdef USER_DEBUG_J
  qDebug("handleQGameControllerButtonEvent");
#endif

    //sendAction->buttonEvent(btn,event);
    emit joystickButtonEvent(btn,event);

    delete event;   //QGameControllerEvents unlike QEvents are not deleted automatically.
}

void JoystickWidget::handleQGameControllerDisconnectEvent(QGameControllerDisconnectEvent* event){
#ifdef USER_DEBUG_J
    qDebug("Control Desconectado");
#endif
    emit updateStatus(false);
    gameController=NULL;

    delete event;
}

void JoystickWidget::setController(){
   QGameController *temp_controller=new QGameController(JS, this);

   if(temp_controller->isValid() && gameController==NULL){

    emit updateStatus(true);

    gameController=temp_controller;
    connect(gameController, SIGNAL(gameControllerAxisEvent(QGameControllerAxisEvent*)), this, SLOT(handleQGameControllerAxisEvent(QGameControllerAxisEvent*)));
    connect(gameController, SIGNAL(gameControllerButtonEvent(QGameControllerButtonEvent*)), this, SLOT(handleQGameControllerButtonEvent(QGameControllerButtonEvent*)));
    connect(gameController, SIGNAL(gameControllerDisconnectEvent(QGameControllerDisconnectEvent*)), this, SLOT(handleQGameControllerDisconnectEvent(QGameControllerDisconnectEvent*)));



    QTimer *timer = new QTimer(this);
    timer->setInterval(15);
    connect(timer, SIGNAL(timeout()), gameController, SLOT(readGameController()));
    timer->start();
   }
   else
   {
       emit updateStatus(false);
       delete temp_controller;
   }
}

bool JoystickWidget::reconnect(){

    QGameController *temp_controller=new QGameController(JS, this);
    bool resp=true;
    if(temp_controller->isValid() && gameController==NULL){

     gameController=temp_controller;
     connect(gameController, SIGNAL(gameControllerAxisEvent(QGameControllerAxisEvent*)), this, SLOT(handleQGameControllerAxisEvent(QGameControllerAxisEvent*)));
     connect(gameController, SIGNAL(gameControllerButtonEvent(QGameControllerButtonEvent*)), this, SLOT(handleQGameControllerButtonEvent(QGameControllerButtonEvent*)));
     connect(gameController, SIGNAL(gameControllerDisconnectEvent(QGameControllerDisconnectEvent*)), this, SLOT(handleQGameControllerDisconnectEvent(QGameControllerDisconnectEvent*)));

     QTimer *timer = new QTimer(this);
     timer->setInterval(15);
     connect(timer, SIGNAL(timeout()), gameController, SLOT(readGameController()));
     timer->start();

#ifdef Q_PROCESSOR_ARM
        QString run=createPath("controlOn.py");
        QProcess initControl;
        initControl.start(run);
        initControl.waitForFinished();
        initControl.close();
#endif

    }
    else
    {
        resp=false;
        delete temp_controller;
    }

    return resp;

}

bool JoystickWidget::isValidController(){
  if(gameController==NULL)
      return false;
  return gameController->isValid();
}

JoystickWidget::~JoystickWidget ()
{

}
