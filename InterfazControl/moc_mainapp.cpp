/****************************************************************************
** Meta object code from reading C++ file 'mainapp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainapp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainapp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainApp_t {
    QByteArrayData data[28];
    char stringdata[398];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainApp_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainApp_t qt_meta_stringdata_MainApp = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 12),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 11),
QT_MOC_LITERAL(4, 34, 17),
QT_MOC_LITERAL(5, 52, 10),
QT_MOC_LITERAL(6, 63, 14),
QT_MOC_LITERAL(7, 78, 13),
QT_MOC_LITERAL(8, 92, 16),
QT_MOC_LITERAL(9, 109, 4),
QT_MOC_LITERAL(10, 114, 15),
QT_MOC_LITERAL(11, 130, 19),
QT_MOC_LITERAL(12, 150, 11),
QT_MOC_LITERAL(13, 162, 23),
QT_MOC_LITERAL(14, 186, 6),
QT_MOC_LITERAL(15, 193, 27),
QT_MOC_LITERAL(16, 221, 5),
QT_MOC_LITERAL(17, 227, 21),
QT_MOC_LITERAL(18, 249, 4),
QT_MOC_LITERAL(19, 254, 5),
QT_MOC_LITERAL(20, 260, 23),
QT_MOC_LITERAL(21, 284, 21),
QT_MOC_LITERAL(22, 306, 26),
QT_MOC_LITERAL(23, 333, 24),
QT_MOC_LITERAL(24, 358, 9),
QT_MOC_LITERAL(25, 368, 6),
QT_MOC_LITERAL(26, 375, 12),
QT_MOC_LITERAL(27, 388, 8)
    },
    "MainApp\0handleNewBtn\0\0missionName\0"
    "createProjectList\0runMission\0"
    "exploreMission\0deleteMission\0"
    "QListWidgetItem*\0item\0handleButtonOff\0"
    "updateControlStatus\0isConnected\0"
    "joystickButtonEventMenu\0button\0"
    "QGameControllerButtonEvent*\0event\0"
    "joystickAxisEventMenu\0axis\0value\0"
    "joystickButtonEventOpen\0joystickAxisEventOpen\0"
    "joystickButtonEventMessage\0"
    "handleCloseKeyboardEvent\0cancelled\0"
    "result\0closeMessage\0showHome\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainApp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x0a,
       4,    0,   92,    2, 0x0a,
       5,    1,   93,    2, 0x0a,
       6,    1,   96,    2, 0x0a,
       7,    2,   99,    2, 0x0a,
      10,    0,  104,    2, 0x0a,
      11,    1,  105,    2, 0x0a,
      13,    2,  108,    2, 0x0a,
      17,    2,  113,    2, 0x0a,
      20,    2,  118,    2, 0x0a,
      21,    2,  123,    2, 0x0a,
      22,    2,  128,    2, 0x0a,
      23,    2,  133,    2, 0x0a,
      26,    0,  138,    2, 0x0a,
      27,    0,  139,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 8,    3,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 15,   14,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   18,   19,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 15,   14,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   18,   19,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 15,   14,   16,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,   24,   25,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainApp *_t = static_cast<MainApp *>(_o);
        switch (_id) {
        case 0: _t->handleNewBtn((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->createProjectList(); break;
        case 2: _t->runMission((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->exploreMission((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->deleteMission((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 5: _t->handleButtonOff(); break;
        case 6: _t->updateControlStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->joystickButtonEventMenu((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QGameControllerButtonEvent*(*)>(_a[2]))); break;
        case 8: _t->joystickAxisEventMenu((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->joystickButtonEventOpen((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QGameControllerButtonEvent*(*)>(_a[2]))); break;
        case 10: _t->joystickAxisEventOpen((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->joystickButtonEventMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QGameControllerButtonEvent*(*)>(_a[2]))); break;
        case 12: _t->handleCloseKeyboardEvent((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 13: _t->closeMessage(); break;
        case 14: _t->showHome(); break;
        default: ;
        }
    }
}

const QMetaObject MainApp::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainApp.data,
      qt_meta_data_MainApp,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainApp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainApp.stringdata))
        return static_cast<void*>(const_cast< MainApp*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
