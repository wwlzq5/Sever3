/****************************************************************************
** Meta object code from reading C++ file 'IOCard.h'
**
** Created: Mon Aug 30 16:15:30 2021
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../IOCard.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IOCard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IOCardClass[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      31,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_IOCardClass[] = {
    "IOCardClass\0\0slot_ClearTable()\0"
    "slot_checkBoxCheck()\0"
};

void IOCardClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        IOCardClass *_t = static_cast<IOCardClass *>(_o);
        switch (_id) {
        case 0: _t->slot_ClearTable(); break;
        case 1: _t->slot_checkBoxCheck(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData IOCardClass::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject IOCardClass::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_IOCardClass,
      qt_meta_data_IOCardClass, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &IOCardClass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *IOCardClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *IOCardClass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IOCardClass))
        return static_cast<void*>(const_cast< IOCardClass*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int IOCardClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE