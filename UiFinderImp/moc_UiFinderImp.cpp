/****************************************************************************
** Meta object code from reading C++ file 'UiFinderImp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "UiFinderImp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UiFinderImp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UiFinderImp_t {
    QByteArrayData data[7];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UiFinderImp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UiFinderImp_t qt_meta_stringdata_UiFinderImp = {
    {
QT_MOC_LITERAL(0, 0, 11), // "UiFinderImp"
QT_MOC_LITERAL(1, 12, 13), // "ClickFileName"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "p_FileName"
QT_MOC_LITERAL(4, 38, 19), // "OnViewDoubleClicked"
QT_MOC_LITERAL(5, 58, 7), // "p_Index"
QT_MOC_LITERAL(6, 66, 14) // "OnDragFileName"

    },
    "UiFinderImp\0ClickFileName\0\0p_FileName\0"
    "OnViewDoubleClicked\0p_Index\0OnDragFileName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UiFinderImp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   32,    2, 0x08 /* Private */,
       6,    1,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    5,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void UiFinderImp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UiFinderImp *_t = static_cast<UiFinderImp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ClickFileName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->OnViewDoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->OnDragFileName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UiFinderImp::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UiFinderImp::ClickFileName)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject UiFinderImp::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_UiFinderImp.data,
      qt_meta_data_UiFinderImp,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UiFinderImp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UiFinderImp::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UiFinderImp.stringdata0))
        return static_cast<void*>(const_cast< UiFinderImp*>(this));
    return QDialog::qt_metacast(_clname);
}

int UiFinderImp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void UiFinderImp::ClickFileName(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE