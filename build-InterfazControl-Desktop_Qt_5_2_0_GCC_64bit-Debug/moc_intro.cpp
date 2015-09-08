/****************************************************************************
** Meta object code from reading C++ file 'intro.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../InterfazControl/intro.h"
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
    QByteArrayData data[10];
    char stringdata[118];
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
QT_MOC_LITERAL(4, 38, 15),
QT_MOC_LITERAL(5, 54, 11),
QT_MOC_LITERAL(6, 66, 14),
QT_MOC_LITERAL(7, 81, 13),
QT_MOC_LITERAL(8, 95, 16),
QT_MOC_LITERAL(9, 112, 4)
    },
    "intro\0handleNewBtn\0\0createProjectList\0"
    "continueMission\0missionName\0exploreMission\0"
    "deleteMission\0QListWidgetItem*\0item\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_intro[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a,
       3,    0,   40,    2, 0x0a,
       4,    1,   41,    2, 0x0a,
       6,    1,   44,    2, 0x0a,
       7,    2,   47,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 8,    5,    9,

       0        // eod
};

void intro::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        intro *_t = static_cast<intro *>(_o);
        switch (_id) {
        case 0: _t->handleNewBtn(); break;
        case 1: _t->createProjectList(); break;
        case 2: _t->continueMission((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->exploreMission((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->deleteMission((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
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
QT_END_MOC_NAMESPACE
