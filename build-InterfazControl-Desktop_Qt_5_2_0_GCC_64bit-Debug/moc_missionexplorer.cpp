/****************************************************************************
** Meta object code from reading C++ file 'missionexplorer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../InterfazControl/missionexplorer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'missionexplorer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MissionExplorer_t {
    QByteArrayData data[8];
    char stringdata[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MissionExplorer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MissionExplorer_t qt_meta_stringdata_MissionExplorer = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 4),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 5),
QT_MOC_LITERAL(4, 28, 13),
QT_MOC_LITERAL(5, 42, 10),
QT_MOC_LITERAL(6, 53, 8),
QT_MOC_LITERAL(7, 62, 19)
    },
    "MissionExplorer\0play\0\0pause\0displaySource\0"
    "playCLiked\0setState\0QMediaPlayer::State\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MissionExplorer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06,
       3,    0,   40,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    0,   41,    2, 0x0a,
       5,    0,   42,    2, 0x0a,
       6,    1,   43,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,

       0        // eod
};

void MissionExplorer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MissionExplorer *_t = static_cast<MissionExplorer *>(_o);
        switch (_id) {
        case 0: _t->play(); break;
        case 1: _t->pause(); break;
        case 2: _t->displaySource(); break;
        case 3: _t->playCLiked(); break;
        case 4: _t->setState((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::State >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MissionExplorer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MissionExplorer::play)) {
                *result = 0;
            }
        }
        {
            typedef void (MissionExplorer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MissionExplorer::pause)) {
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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void MissionExplorer::play()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MissionExplorer::pause()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
