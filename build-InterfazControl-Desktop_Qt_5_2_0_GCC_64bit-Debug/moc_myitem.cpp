/****************************************************************************
** Meta object code from reading C++ file 'myitem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../InterfazControl/myitem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myitem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_myItem_t {
    QByteArrayData data[10];
    char stringdata[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_myItem_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_myItem_t qt_meta_stringdata_myItem = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 14),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 12),
QT_MOC_LITERAL(4, 36, 16),
QT_MOC_LITERAL(5, 53, 13),
QT_MOC_LITERAL(6, 67, 12),
QT_MOC_LITERAL(7, 80, 14),
QT_MOC_LITERAL(8, 95, 12),
QT_MOC_LITERAL(9, 108, 13)
    },
    "myItem\0continueSignal\0\0deleteSignal\0"
    "QListWidgetItem*\0exploreSignal\0"
    "exportSignal\0handleContinue\0handleDelete\0"
    "handleExplore\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_myItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06,
       3,    2,   52,    2, 0x06,
       5,    1,   57,    2, 0x06,
       6,    0,   60,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    0,   61,    2, 0x0a,
       8,    0,   62,    2, 0x0a,
       9,    0,   63,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void myItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        myItem *_t = static_cast<myItem *>(_o);
        switch (_id) {
        case 0: _t->continueSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->deleteSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 2: _t->exploreSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->exportSignal(); break;
        case 4: _t->handleContinue(); break;
        case 5: _t->handleDelete(); break;
        case 6: _t->handleExplore(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (myItem::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&myItem::continueSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (myItem::*_t)(QString , QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&myItem::deleteSignal)) {
                *result = 1;
            }
        }
        {
            typedef void (myItem::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&myItem::exploreSignal)) {
                *result = 2;
            }
        }
        {
            typedef void (myItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&myItem::exportSignal)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject myItem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_myItem.data,
      qt_meta_data_myItem,  qt_static_metacall, 0, 0}
};


const QMetaObject *myItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *myItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_myItem.stringdata))
        return static_cast<void*>(const_cast< myItem*>(this));
    return QWidget::qt_metacast(_clname);
}

int myItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void myItem::continueSignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void myItem::deleteSignal(QString _t1, QListWidgetItem * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void myItem::exploreSignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void myItem::exportSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
