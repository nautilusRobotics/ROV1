/****************************************************************************
** Meta object code from reading C++ file 'missionexplorer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "missionexplorer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'missionexplorer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MissionExplorer_t {
    QByteArrayData data[15];
    char stringdata[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MissionExplorer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MissionExplorer_t qt_meta_stringdata_MissionExplorer = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 12),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 10),
QT_MOC_LITERAL(4, 41, 13),
QT_MOC_LITERAL(5, 55, 9),
QT_MOC_LITERAL(6, 65, 4),
QT_MOC_LITERAL(7, 70, 5),
QT_MOC_LITERAL(8, 76, 11),
QT_MOC_LITERAL(9, 88, 6),
QT_MOC_LITERAL(10, 95, 27),
QT_MOC_LITERAL(11, 123, 5),
QT_MOC_LITERAL(12, 129, 12),
QT_MOC_LITERAL(13, 142, 19),
QT_MOC_LITERAL(14, 162, 11)
    },
    "MissionExplorer\0returnToHome\0\0controlOut\0"
    "displaySource\0axisEvent\0axis\0value\0"
    "buttonEvent\0button\0QGameControllerButtonEvent*\0"
    "event\0sliderChange\0updateControlStatus\0"
    "isConnected\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MissionExplorer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x05,
       3,    0,   50,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       4,    0,   51,    2, 0x0a,
       5,    2,   52,    2, 0x0a,
       8,    2,   57,    2, 0x0a,
      12,    1,   62,    2, 0x0a,
      13,    1,   65,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 10,    9,   11,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Bool,   14,

       0        // eod
};

void MissionExplorer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MissionExplorer *_t = static_cast<MissionExplorer *>(_o);
        switch (_id) {
        case 0: _t->returnToHome(); break;
        case 1: _t->controlOut(); break;
        case 2: _t->displaySource(); break;
        case 3: _t->axisEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->buttonEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QGameControllerButtonEvent*(*)>(_a[2]))); break;
        case 5: _t->sliderChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->updateControlStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MissionExplorer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MissionExplorer::returnToHome)) {
                *result = 0;
            }
        }
        {
            typedef void (MissionExplorer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MissionExplorer::controlOut)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject MissionExplorer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MissionExplorer.data,
      qt_meta_data_MissionExplorer,  qt_static_metacall, 0, 0}
};


const QMetaObject *MissionExplorer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MissionExplorer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MissionExplorer.stringdata))
        return static_cast<void*>(const_cast< MissionExplorer*>(this));
    return QWidget::qt_metacast(_clname);
}

int MissionExplorer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void MissionExplorer::returnToHome()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MissionExplorer::controlOut()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
