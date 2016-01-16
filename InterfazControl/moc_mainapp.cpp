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
    QByteArrayData data[25];
    char stringdata[413];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainApp_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainApp_t qt_meta_stringdata_MainApp = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 17),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 19),
QT_MOC_LITERAL(4, 47, 11),
QT_MOC_LITERAL(5, 59, 23),
QT_MOC_LITERAL(6, 83, 6),
QT_MOC_LITERAL(7, 90, 27),
QT_MOC_LITERAL(8, 118, 5),
QT_MOC_LITERAL(9, 124, 21),
QT_MOC_LITERAL(10, 146, 4),
QT_MOC_LITERAL(11, 151, 5),
QT_MOC_LITERAL(12, 157, 23),
QT_MOC_LITERAL(13, 181, 21),
QT_MOC_LITERAL(14, 203, 26),
QT_MOC_LITERAL(15, 230, 29),
QT_MOC_LITERAL(16, 260, 27),
QT_MOC_LITERAL(17, 288, 25),
QT_MOC_LITERAL(18, 314, 24),
QT_MOC_LITERAL(19, 339, 9),
QT_MOC_LITERAL(20, 349, 6),
QT_MOC_LITERAL(21, 356, 15),
QT_MOC_LITERAL(22, 372, 8),
QT_MOC_LITERAL(23, 381, 17),
QT_MOC_LITERAL(24, 399, 12)
    },
    "MainApp\0createProjectList\0\0"
    "updateControlStatus\0isConnected\0"
    "joystickButtonEventMenu\0button\0"
    "QGameControllerButtonEvent*\0event\0"
    "joystickAxisEventMenu\0axis\0value\0"
    "joystickButtonEventOpen\0joystickAxisEventOpen\0"
    "joystickButtonEventMessage\0"
    "joystickButtonEventOffMessage\0"
    "joystickButtonEventKeyBoard\0"
    "joystickAxisEventKeyBoard\0"
    "handleCloseKeyboardEvent\0cancelled\0"
    "result\0preCloseMessage\0showHome\0"
    "reconnectJoystick\0controlCrash\0"
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
       1,    0,   89,    2, 0x0a,
       3,    1,   90,    2, 0x0a,
       5,    2,   93,    2, 0x0a,
       9,    2,   98,    2, 0x0a,
      12,    2,  103,    2, 0x0a,
      13,    2,  108,    2, 0x0a,
      14,    2,  113,    2, 0x0a,
      15,    2,  118,    2, 0x0a,
      16,    2,  123,    2, 0x0a,
      17,    2,  128,    2, 0x0a,
      18,    2,  133,    2, 0x0a,
      21,    0,  138,    2, 0x0a,
      22,    0,  139,    2, 0x0a,
      23,    0,  140,    2, 0x0a,
      24,    0,  141,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    6,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   10,   11,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    6,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   10,   11,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    6,    8,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    6,    8,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    6,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   10,   11,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,   19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainApp *_t = static_cast<MainApp *>(_o);
        switch (_id) {
        case 0: _t->createProjectList(); break;
        case 1: _t->updateControlStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->joystickButtonEventMenu((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QGameControllerButtonEvent*(*)>(_a[2]))); break;
        case 3: _t->joystickAxisEventMenu((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->joystickButtonEventOpen((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QGameControllerButtonEvent*(*)>(_a[2]))); break;
        case 5: _t->joystickAxisEventOpen((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->joystickButtonEventMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QGameControllerButtonEvent*(*)>(_a[2]))); break;
        case 7: _t->joystickButtonEventOffMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QGameControllerButtonEvent*(*)>(_a[2]))); break;
        case 8: _t->joystickButtonEventKeyBoard((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QGameControllerButtonEvent*(*)>(_a[2]))); break;
        case 9: _t->joystickAxisEventKeyBoard((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->handleCloseKeyboardEvent((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->preCloseMessage(); break;
        case 12: _t->showHome(); break;
        case 13: _t->reconnectJoystick(); break;
        case 14: _t->controlCrash(); break;
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
