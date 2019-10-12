/****************************************************************************
** Meta object code from reading C++ file 'choice1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../2019_01_17/choice1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'choice1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_choice1_t {
    QByteArrayData data[7];
    char stringdata[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_choice1_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_choice1_t qt_meta_stringdata_choice1 = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 9),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 9),
QT_MOC_LITERAL(4, 29, 9),
QT_MOC_LITERAL(5, 39, 9),
QT_MOC_LITERAL(6, 49, 9)
    },
    "choice1\0mySignal1\0\0mySignal2\0mySignal3\0"
    "mySignal4\0mySignal5\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_choice1[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06,
       3,    0,   40,    2, 0x06,
       4,    0,   41,    2, 0x06,
       5,    0,   42,    2, 0x06,
       6,    0,   43,    2, 0x06,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void choice1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        choice1 *_t = static_cast<choice1 *>(_o);
        switch (_id) {
        case 0: _t->mySignal1(); break;
        case 1: _t->mySignal2(); break;
        case 2: _t->mySignal3(); break;
        case 3: _t->mySignal4(); break;
        case 4: _t->mySignal5(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (choice1::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&choice1::mySignal1)) {
                *result = 0;
            }
        }
        {
            typedef void (choice1::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&choice1::mySignal2)) {
                *result = 1;
            }
        }
        {
            typedef void (choice1::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&choice1::mySignal3)) {
                *result = 2;
            }
        }
        {
            typedef void (choice1::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&choice1::mySignal4)) {
                *result = 3;
            }
        }
        {
            typedef void (choice1::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&choice1::mySignal5)) {
                *result = 4;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject choice1::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_choice1.data,
      qt_meta_data_choice1,  qt_static_metacall, 0, 0}
};


const QMetaObject *choice1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *choice1::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_choice1.stringdata))
        return static_cast<void*>(const_cast< choice1*>(this));
    return QWidget::qt_metacast(_clname);
}

int choice1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void choice1::mySignal1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void choice1::mySignal2()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void choice1::mySignal3()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void choice1::mySignal4()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void choice1::mySignal5()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
