/****************************************************************************
** Meta object code from reading C++ file 'missionwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "missionwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'missionwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MissionWidget_t {
    QByteArrayData data[18];
    char stringdata[226];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MissionWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MissionWidget_t qt_meta_stringdata_MissionWidget = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 12),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 9),
QT_MOC_LITERAL(4, 38, 18),
QT_MOC_LITERAL(5, 57, 11),
QT_MOC_LITERAL(6, 69, 19),
QT_MOC_LITERAL(7, 89, 16),
QT_MOC_LITERAL(8, 106, 5),
QT_MOC_LITERAL(9, 112, 15),
QT_MOC_LITERAL(10, 128, 11),
QT_MOC_LITERAL(11, 140, 16),
QT_MOC_LITERAL(12, 157, 9),
QT_MOC_LITERAL(13, 167, 4),
QT_MOC_LITERAL(14, 172, 11),
QT_MOC_LITERAL(15, 184, 6),
QT_MOC_LITERAL(16, 191, 27),
QT_MOC_LITERAL(17, 219, 5)
    },
    "MissionWidget\0returnToHome\0\0saveVideo\0"
    "updatePlayerStatus\0isConnected\0"
    "updateControlStatus\0updateRobotDepth\0"
    "value\0updateRecording\0isRecording\0"
    "handleButtonHome\0axisEvent\0axis\0"
    "buttonEvent\0button\0QGameControllerButtonEvent*\0"
    "event\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MissionWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x05,
       3,    0,   60,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       4,    1,   61,    2, 0x0a,
       6,    1,   64,    2, 0x0a,
       7,    1,   67,    2, 0x0a,
       9,    1,   70,    2, 0x0a,
      11,    0,   73,    2, 0x0a,
      12,    2,   74,    2, 0x0a,
      14,    2,   79,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   13,    8,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 16,   15,   17,

       0        // eod
};

void MissionWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MissionWidget *_t = static_cast<MissionWidget *>(_o);
        switch (_id) {
        case 0: _t->returnToHome(); break;
        case 1: _t->saveVideo(); break;
        case 2: _t->updatePlayerStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->updateControlStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->updateRobotDepth((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->updateRecording((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->handleButtonHome(); break;
        case 7: _t->axisEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->buttonEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QGameControllerButtonEvent*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MissionWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MissionWidget::returnToHome)) {
                *result = 0;
            }
        }
        {
            typedef void (MissionWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MissionWidget::saveVideo)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject MissionWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MissionWidget.data,
      qt_meta_data_MissionWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *MissionWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MissionWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MissionWidget.stringdata))
        return static_cast<void*>(const_cast< MissionWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MissionWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MissionWidget::returnToHome()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MissionWidget::saveVideo()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE