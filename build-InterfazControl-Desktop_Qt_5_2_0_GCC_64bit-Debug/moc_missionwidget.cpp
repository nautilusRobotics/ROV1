/****************************************************************************
** Meta object code from reading C++ file 'missionwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../InterfazControl/missionwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'missionwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MissionWidget_t {
    QByteArrayData data[12];
    char stringdata[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MissionWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MissionWidget_t qt_meta_stringdata_MissionWidget = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 18),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 11),
QT_MOC_LITERAL(4, 46, 19),
QT_MOC_LITERAL(5, 66, 14),
QT_MOC_LITERAL(6, 81, 16),
QT_MOC_LITERAL(7, 98, 5),
QT_MOC_LITERAL(8, 104, 15),
QT_MOC_LITERAL(9, 120, 11),
QT_MOC_LITERAL(10, 132, 15),
QT_MOC_LITERAL(11, 148, 16)
    },
    "MissionWidget\0updatePlayerStatus\0\0"
    "isConnected\0updateControlStatus\0"
    "takeScreenshot\0updateRobotDepth\0value\0"
    "updateRecording\0isRecording\0handleButtonOff\0"
    "handleButtonHome\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MissionWidget[] = {

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
       1,    1,   49,    2, 0x0a,
       4,    1,   52,    2, 0x0a,
       5,    0,   55,    2, 0x0a,
       6,    1,   56,    2, 0x0a,
       8,    1,   59,    2, 0x0a,
      10,    0,   62,    2, 0x0a,
      11,    0,   63,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MissionWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MissionWidget *_t = static_cast<MissionWidget *>(_o);
        switch (_id) {
        case 0: _t->updatePlayerStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->updateControlStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->takeScreenshot(); break;
        case 3: _t->updateRobotDepth((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->updateRecording((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->handleButtonOff(); break;
        case 6: _t->handleButtonHome(); break;
        default: ;
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
