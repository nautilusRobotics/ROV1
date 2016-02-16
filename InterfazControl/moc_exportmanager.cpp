/****************************************************************************
** Meta object code from reading C++ file 'exportmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "exportmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'exportmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ExportManager_t {
    QByteArrayData data[11];
    char stringdata[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ExportManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ExportManager_t qt_meta_stringdata_ExportManager = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 7),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 13),
QT_MOC_LITERAL(4, 37, 12),
QT_MOC_LITERAL(5, 50, 7),
QT_MOC_LITERAL(6, 58, 8),
QT_MOC_LITERAL(7, 67, 17),
QT_MOC_LITERAL(8, 85, 6),
QT_MOC_LITERAL(9, 92, 27),
QT_MOC_LITERAL(10, 120, 5)
    },
    "ExportManager\0success\0\0acceptDialogs\0"
    "launchDialog\0saveUsb\0indexUSB\0"
    "joystickButtonUSB\0button\0"
    "QGameControllerButtonEvent*\0event\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExportManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       3,    0,   42,    2, 0x0a,
       4,    0,   43,    2, 0x0a,
       5,    1,   44,    2, 0x0a,
       7,    2,   47,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    1,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 9,    8,   10,

       0        // eod
};

void ExportManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ExportManager *_t = static_cast<ExportManager *>(_o);
        switch (_id) {
        case 0: _t->success((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->acceptDialogs(); break;
        case 2: _t->launchDialog(); break;
        case 3: { bool _r = _t->saveUsb((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: _t->joystickButtonUSB((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QGameControllerButtonEvent*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ExportManager::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ExportManager::success)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ExportManager::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ExportManager.data,
      qt_meta_data_ExportManager,  qt_static_metacall, 0, 0}
};


const QMetaObject *ExportManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExportManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ExportManager.stringdata))
        return static_cast<void*>(const_cast< ExportManager*>(this));
    return QWidget::qt_metacast(_clname);
}

int ExportManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void ExportManager::success(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
