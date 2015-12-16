/****************************************************************************
** Meta object code from reading C++ file 'introxbox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "introxbox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'introxbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IntroXbox_t {
    QByteArrayData data[25];
    char stringdata[327];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_IntroXbox_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_IntroXbox_t qt_meta_stringdata_IntroXbox = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 12),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 11),
QT_MOC_LITERAL(4, 36, 17),
QT_MOC_LITERAL(5, 54, 10),
QT_MOC_LITERAL(6, 65, 14),
QT_MOC_LITERAL(7, 80, 13),
QT_MOC_LITERAL(8, 94, 16),
QT_MOC_LITERAL(9, 111, 4),
QT_MOC_LITERAL(10, 116, 6),
QT_MOC_LITERAL(11, 123, 15),
QT_MOC_LITERAL(12, 139, 19),
QT_MOC_LITERAL(13, 159, 11),
QT_MOC_LITERAL(14, 171, 25),
QT_MOC_LITERAL(15, 197, 6),
QT_MOC_LITERAL(16, 204, 27),
QT_MOC_LITERAL(17, 232, 5),
QT_MOC_LITERAL(18, 238, 23),
QT_MOC_LITERAL(19, 262, 4),
QT_MOC_LITERAL(20, 267, 5),
QT_MOC_LITERAL(21, 273, 24),
QT_MOC_LITERAL(22, 298, 9),
QT_MOC_LITERAL(23, 308, 6),
QT_MOC_LITERAL(24, 315, 10)
    },
    "IntroXbox\0handleNewBtn\0\0missionName\0"
    "createProjectList\0runMission\0"
    "exploreMission\0deleteMission\0"
    "QListWidgetItem*\0item\0reOpen\0"
    "handleButtonOff\0updateControlStatus\0"
    "isConnected\0handleJoystickButtonEvent\0"
    "button\0QGameControllerButtonEvent*\0"
    "event\0handleJoystickAxisEvent\0axis\0"
    "value\0handleCloseKeyboardEvent\0cancelled\0"
    "result\0closeToast\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IntroXbox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x0a,
       4,    0,   77,    2, 0x0a,
       5,    1,   78,    2, 0x0a,
       6,    1,   81,    2, 0x0a,
       7,    2,   84,    2, 0x0a,
      10,    0,   89,    2, 0x0a,
      11,    0,   90,    2, 0x0a,
      12,    1,   91,    2, 0x0a,
      14,    2,   94,    2, 0x0a,
      18,    2,   99,    2, 0x0a,
      21,    2,  104,    2, 0x0a,
      24,    0,  109,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 8,    3,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 16,   15,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   19,   20,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,   22,   23,
    QMetaType::Void,

       0        // eod
};

void IntroXbox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IntroXbox *_t = static_cast<IntroXbox *>(_o);
        switch (_id) {
        case 0: _t->handleNewBtn((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->createProjectList(); break;
        case 2: _t->runMission((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->exploreMission((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->deleteMission((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 5: _t->reOpen(); break;
        case 6: _t->handleButtonOff(); break;
        case 7: _t->updateControlStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->handleJoystickButtonEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QGameControllerButtonEvent*(*)>(_a[2]))); break;
        case 9: _t->handleJoystickAxisEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->handleCloseKeyboardEvent((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->closeToast(); break;
        default: ;
        }
    }
}

const QMetaObject IntroXbox::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_IntroXbox.data,
      qt_meta_data_IntroXbox,  qt_static_metacall, 0, 0}
};


const QMetaObject *IntroXbox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IntroXbox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IntroXbox.stringdata))
        return static_cast<void*>(const_cast< IntroXbox*>(this));
    return QWidget::qt_metacast(_clname);
}

int IntroXbox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
