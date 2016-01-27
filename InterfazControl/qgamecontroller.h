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

#ifndef QGameController_H
#define QGameController_H

#define QT_NO_DEBUG_OUTPUT


#include <QObject>
#include "qgamecontroller-global.h"

QT_BEGIN_NAMESPACE
class QGameControllerPrivate;
class QGameControllerEventPrivate;
class QGameControllerAxisEventPrivate;
class QGameControllerButtonEventPrivate;
class QGameControllerDisconnectEventPrivate;


class QGAMECONTROLLER_EXPORT QGameControllerEvent
{
    Q_DECLARE_PRIVATE(QGameControllerEvent)
public:
    QGameControllerEvent(uint controllerId);
    bool controllerId();
    ~QGameControllerEvent();
protected:
    QGameControllerEvent(uint controllerId, QGameControllerEventPrivate &d);
    QGameControllerEventPrivate* const d_ptr;
};

class QGAMECONTROLLER_EXPORT QGameControllerButtonEvent : public QGameControllerEvent
{
    Q_DECLARE_PRIVATE(QGameControllerButtonEvent)
public:
    QGameControllerButtonEvent(uint controllerId, uint button, bool pressed);
    uint button();
    bool pressed();
};

class QGAMECONTROLLER_EXPORT QGameControllerDisconnectEvent : public QGameControllerEvent
{
    Q_DECLARE_PRIVATE(QGameControllerDisconnectEvent)
public:
    QGameControllerDisconnectEvent(uint controllerId,bool connect);
    bool connect();
};

class QGAMECONTROLLER_EXPORT QGameControllerAxisEvent : public QGameControllerEvent
{
    Q_DECLARE_PRIVATE(QGameControllerAxisEvent)
public:
    QGameControllerAxisEvent(uint controllerId, uint axis, float value);
    uint axis();
    float value();
};

class QGAMECONTROLLER_EXPORT QGameController : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(QGameController)
public:
    explicit QGameController(uint id = 0, QObject *parent = 0);
    uint axisCount();
    uint buttonCount();
    float axisValue(uint axis);
    bool buttonValue(uint button);
    QString description();
    uint id();
    bool isValid();
signals:

public slots:    
    void readGameController();
signals:
    void gameControllerEvent(QGameControllerEvent *event);
    void gameControllerButtonEvent(QGameControllerButtonEvent *event);
    void gameControllerAxisEvent(QGameControllerAxisEvent *event);
    void gameControllerDisconnectEvent(QGameControllerDisconnectEvent *event);

private:
    QGameControllerPrivate* const d_ptr;
    Q_DISABLE_COPY(QGameController)
};

QT_END_NAMESPACE

#endif // QGameController_H
