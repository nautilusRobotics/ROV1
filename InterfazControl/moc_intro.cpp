/****************************************************************************
** Meta object code from reading C++ file 'intro.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "intro.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'intro.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_intro_t {
    QByteArrayData data[12];
    char stringdata[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_intro_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_intro_t qt_meta_stringdata_intro = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 12),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 17),
QT_MOC_LITERAL(4, 38, 10),
QT_MOC_LITERAL(5, 49, 11),
QT_MOC_LITERAL(6, 61, 14),
QT_MOC_LITERAL(7, 76, 13),
QT_MOC_LITERAL(8, 90, 16),
QT_MOC_LITERAL(9, 107, 4),
QT_MOC_LITERAL(10, 112, 6),
QT_MOC_LITERAL(11, 119, 15)
    },
    "intro\0handleNewBtn\0\0createProjectList\0"
    "runMission\0missionName\0exploreMission\0"
    "deleteMission\0QListWidgetItem*\0item\0"
    "reOpen\0handleButtonOff\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_intro[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a,
       3,    0,   50,    2, 0x0a,
       4,    1,   51,    2, 0x0a,
       6,    1,   54,    2, 0x0a,
       7,    2,   57,    2, 0x0a,
      10,    0,   62,    2, 0x0a,
      11,    0,   63,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 8,    5,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void intro::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        intro *_t = static_cast<intro *>(_o);
        switch (_id) {
        case 0: _t->handleNewBtn(); break;
        case 1: _t->createProjectList(); break;
        case 2: _t->runMission((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->exploreMission((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->deleteMission((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 5: _t->reOpen(); break;
        case 6: _t->handleButtonOff(); break;
        default: ;
        }
    }
}

const QMetaObject intro::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_intro.data,
      qt_meta_data_intro,  qt_static_metacall, 0, 0}
};


const QMetaObject *intro::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *intro::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_intro.stringdata))
        return static_cast<void*>(const_cast< intro*>(this));
    return QWidget::qt_metacast(_clname);
}

int intro::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
