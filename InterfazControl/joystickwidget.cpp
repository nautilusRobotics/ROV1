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
#include <QTimer>
#include <QVBoxLayout>
#include <QHBoxLayout>
//#include USER_DEBUG_J

JoystickWidget::JoystickWidget(QWidget *parent, QLabel *status, QPushButton *btn) :
    QWidget(parent)
{
    this->setWindowTitle("Game Controller Tester");
    //QVBoxLayout *layout = new QVBoxLayout(this);

    labelStatusController=status;
    btnConnect=btn;
    connect(btnConnect, SIGNAL (released()), this, SLOT (setController()));



    sendAction=new SendAction();

    buttonsXbox<<  button_Y<<button_B<<button_A<<button_X<<button_LB<<button_RB<<button_LT<<button_RT<<button_back<<button_start<<button_LaBtn<<button_RaBtn;
    axisXbox<< axis_left_horizontal<<axis_left_vertical<<axis_right_horizontal<<axis_right_vertical<<axis_cross_horizontal<<axis_cross_vertical ;

    gameController=NULL;
    setController();

    if(isValidController() && labelStatusController!=NULL){
        labelStatusController->setText("Control: Conectado");
        labelStatusController->setStyleSheet("QLabel {  color : white; }");
        btnConnect->setEnabled(false);
    }
    else{
        labelStatusController->setText("Control: Desconectado");
        labelStatusController->setStyleSheet("QLabel {  color : red; }");
        btnConnect->setEnabled(true);
    }

    /*
    if(!gameController==NULL){
    if (gameController->isValid())
        {
            QList<QSlider*> sliders;
            QList<QLabel*> buttonLabels;

            QLabel *label = new QLabel(gameController->description(), this);
            layout->addWidget(label);
            QHBoxLayout *buttonLayout = new QHBoxLayout();
            for (uint i = 0; i < gameController->buttonCount(); i++)
            {
                QString btn=buttonsXbox.at(i);
                QLabel *label = new QLabel(QString (btn+": <b><font color=grey>U</font></b>"), this);
                label->setMargin(2);
                buttonLabels.append(label);
                buttonLayout->addWidget(label);
            }
            layout->addItem(buttonLayout);
            for (uint i = 0; i < gameController->axisCount(); i++)
            {
                QString axis=axisXbox.at(i);
                QLabel *label = new QLabel(QString ("Axis "+axis+": "), this);
                QSlider *slider = new QSlider(Qt::Horizontal, this);
                slider->setEnabled(false);
                slider->setTickPosition(QSlider::TicksBothSides);
                slider->setTickInterval(1000/4);
                slider->setMinimum(-1000);
                slider->setMaximum(1000);
                slider->setValue(0);
                sliders.append(slider);
                QHBoxLayout *hlayout = new QHBoxLayout();
                hlayout->addWidget(label);
                hlayout->addWidget(slider);
                layout->addItem(hlayout);
            }

            buttonLabelsMap.insert(JS2, buttonLabels);
            slidersMap.insert(JS2, sliders);


        }
    }*/
}


void JoystickWidget::handleQGameControllerAxisEvent(QGameControllerAxisEvent* event)
{

    int axis = event->axis();
 /*   QList<QSlider*> sliders = slidersMap.value(JS2);//slidersMap.value(event->controllerId());
    Q_ASSERT(axis < sliders.count());
    QSlider *bar = sliders.at(axis);
    bar->setValue(event->value()*1000);*/
    uint value=event->value()*1000;
#ifdef USER_DEBUG_J_J
    qDebug("handleQGameControllerAxisEvent");
    qDebUSER_DEBUG_J_Jug("Value %d", value );
#endif
    sendAction->axisEvent(axisXbox.at(axis),value);
    delete event;   //QGameControllerEvents unlike QEvents are not deleted automatically.
}

void JoystickWidget::handleQGameControllerButtonEvent(QGameControllerButtonEvent* event)
{

    int button = event->button();
  /*  QList<QLabel*> buttonLabels = buttonLabelsMap.value(JS2);//buttonLabelsMap.value(event->controllerId());
    Q_ASSERT(button < buttonLabels.count());
    QLabel *label = buttonLabels.at(button);*/

    QString btn=buttonsXbox.at(button);
   /* if (event->pressed())
        label->setText(QString (btn+": <b><font color=green>D</font></b>"));
    else
        label->setText(QString (btn+": <b><font color=grey>U</font></b>") );*/

#ifdef USER_DEBUG_J_J
  qDebug("handleQGameControllerButtonEvent");
#endif

    sendAction->buttonEvent(btn);
    delete event;   //QGameControllerEvents unlike QEvents are not deleted automatically.
}

void JoystickWidget::handleQGameControllerDisconnectEvent(QGameControllerDisconnectEvent* event){
#ifdef USER_DEBUG_J
    qDebug("Control Desconectado");
#endif
    labelStatusController->setText("Control: Desconectado");
    labelStatusController->setStyleSheet("QLabel {  color : red; }");
    btnConnect->setEnabled(true);
    gameController=NULL;

    delete event;
}

SendAction* JoystickWidget::getSendAction(){
    return sendAction;
}

void JoystickWidget::setController(){
   QGameController *temp_controller=new QGameController(JS2, this);
   if(temp_controller->isValid() && gameController==NULL){
   labelStatusController->setText("Control: Conectado");
   labelStatusController->setStyleSheet("QLabel {  color : white; }");
   btnConnect->setEnabled(false);

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
       labelStatusController->setText("Control: Desconectado");
       btnConnect->setEnabled(true);
       delete temp_controller;
   }
}

bool JoystickWidget::isValidController(){
  if(gameController==NULL)
      return false;
  return gameController->isValid();
}

JoystickWidget::~JoystickWidget ()
{

}
