/****************************************************************************
** Meta object code from reading C++ file 'widgetWarning.h'
**
** Created: Mon Aug 30 16:15:30 2021
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../widgetWarning.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetWarning.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget_Warning[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      40,   16,   15,   15, 0x0a,
      70,   15,   15,   15, 0x0a,
      89,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Widget_Warning[] = {
    "Widget_Warning\0\0warningType,warningInfo\0"
    "slot_ShowMessage(int,QString)\0"
    "slots_HideWidget()\0slots_StopAlert()\0"
};

void Widget_Warning::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Widget_Warning *_t = static_cast<Widget_Warning *>(_o);
        switch (_id) {
        case 0: _t->slot_ShowMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->slots_HideWidget(); break;
        case 2: _t->slots_StopAlert(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Widget_Warning::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Widget_Warning::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget_Warning,
      qt_meta_data_Widget_Warning, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget_Warning::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget_Warning::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget_Warning::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget_Warning))
        return static_cast<void*>(const_cast< Widget_Warning*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget_Warning::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
