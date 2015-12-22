/****************************************************************************
** Meta object code from reading C++ file 'qgamecontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qgamecontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgamecontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QGameController_t {
    QByteArrayData data[12];
    char stringdata[251];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QGameController_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QGameController_t qt_meta_stringdata_QGameController = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 19),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 21),
QT_MOC_LITERAL(4, 59, 5),
QT_MOC_LITERAL(5, 65, 25),
QT_MOC_LITERAL(6, 91, 27),
QT_MOC_LITERAL(7, 119, 23),
QT_MOC_LITERAL(8, 143, 25),
QT_MOC_LITERAL(9, 169, 29),
QT_MOC_LITERAL(10, 199, 31),
QT_MOC_LITERAL(11, 231, 18)
    },
    "QGameController\0gameControllerEvent\0"
    "\0QGameControllerEvent*\0event\0"
    "gameControllerButtonEvent\0"
    "QGameControllerButtonEvent*\0"
    "gameControllerAxisEvent\0"
    "QGameControllerAxisEvent*\0"
    "gameControllerDisconnectEvent\0"
    "QGameControllerDisconnectEvent*\0"
    "readGameController\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGameController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06,
       5,    1,   42,    2, 0x06,
       7,    1,   45,    2, 0x06,
       9,    1,   48,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      11,    0,   51,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void, 0x80000000 | 8,    4,
    QMetaType::Void, 0x80000000 | 10,    4,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void QGameController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QGameController *_t = static_cast<QGameController *>(_o);
        switch (_id) {
        case 0: _t->gameControllerEvent((*reinterpret_cast< QGameControllerEvent*(*)>(_a[1]))); break;
        case 1: _t->gameControllerButtonEvent((*reinterpret_cast< QGameControllerButtonEvent*(*)>(_a[1]))); break;
        case 2: _t->gameControllerAxisEvent((*reinterpret_cast< QGameControllerAxisEvent*(*)>(_a[1]))); break;
        case 3: _t->gameControllerDisconnectEvent((*reinterpret_cast< QGameControllerDisconnectEvent*(*)>(_a[1]))); break;
        case 4: _t->readGameController(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QGameController::*_t)(QGameControllerEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGameController::gameControllerEvent)) {
                *result = 0;
            }
        }
        {
            typedef void (QGameController::*_t)(QGameControllerButtonEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGameController::gameControllerButtonEvent)) {
                *result = 1;
            }
        }
        {
            typedef void (QGameController::*_t)(QGameControllerAxisEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGameController::gameControllerAxisEvent)) {
                *result = 2;
            }
        }
        {
            typedef void (QGameController::*_t)(QGameControllerDisconnectEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGameController::gameControllerDisconnectEvent)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject QGameController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QGameController.data,
      qt_meta_data_QGameController,  qt_static_metacall, 0, 0}
};


const QMetaObject *QGameController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGameController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QGameController.stringdata))
        return static_cast<void*>(const_cast< QGameController*>(this));
    return QObject::qt_metacast(_clname);
}

int QGameController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QGameController::gameControllerEvent(QGameControllerEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QGameController::gameControllerButtonEvent(QGameControllerButtonEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QGameController::gameControllerAxisEvent(QGameControllerAxisEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QGameController::gameControllerDisconnectEvent(QGameControllerDisconnectEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
