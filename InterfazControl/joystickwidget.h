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

#ifndef JOYSTICKWIDGET_H
#define JOYSTICKWIDGET_H

#include <QWidget>
#include <QString>
#include <QTimer>
#include "qgamecontroller.h"
#include "sendaction.h"
#include "player.h"


#ifdef Q_PROCESSOR_X86
#define JS 0
#endif

#ifdef Q_PROCESSOR_ARM
#define JS 0
#endif


#define axis_left_horizontal  "LH"
#define axis_left_vertical    "LV"
#define axis_right_horizontal "RH"
#define axis_right_vertical   "RV"
#define axis_cross_horizontal "CV"
#define axis_cross_vertical   "CH"
#define button_Y  "Y"
#define button_B  "B"
#define button_A  "A"
#define button_X  "X"
#define button_LB  "LB"
#define button_RB  "RB"
#define button_LT  "LT"
#define button_RT  "RT"
#define button_back  "back"
#define button_start  "start"
#define button_LaBtn  "LA_btn"
#define button_RaBtn  "RA_btn"


class SendAction;

class JoystickWidget : public QWidget
{
    Q_OBJECT


public:
    explicit JoystickWidget(QWidget *parent = 0);
    ~JoystickWidget();
    bool isValidController();
    void init();
    bool reconnect();

signals:
   void updateStatus(bool isConnected);
   void joystickAxisEvent(QString axis, int value);
   void joystickButtonEvent(QString btn, QGameControllerButtonEvent *event);

private:
    QMap<uint, QList<QSlider*> > slidersMap;
    QMap<uint, QList<QLabel*> > buttonLabelsMap;
    QStringList buttonsXbox, axisXbox;   
    QGameController *gameController;    
    QPushButton *btnConnect;



private slots:
    void handleQGameControllerAxisEvent(QGameControllerAxisEvent *event);
    void handleQGameControllerButtonEvent(QGameControllerButtonEvent *event);
    void handleQGameControllerDisconnectEvent(QGameControllerDisconnectEvent* event);
    void setController();
};

#endif // JOYSTICKWIDGET_H
