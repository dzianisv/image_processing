/****************************************************************************
** Meta object code from reading C++ file 'imagecontainer.h'
**
** Created: Wed 20. Nov 17:23:46 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dsp-lab4/imagecontainer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagecontainer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImageContainer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   16,   15,   15, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ImageContainer[] = {
    "ImageContainer\0\0pixmap\0loaded(QPixmap*)\0"
};

void ImageContainer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ImageContainer *_t = static_cast<ImageContainer *>(_o);
        switch (_id) {
        case 0: _t->loaded((*reinterpret_cast< QPixmap*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ImageContainer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ImageContainer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ImageContainer,
      qt_meta_data_ImageContainer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImageContainer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImageContainer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImageContainer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageContainer))
        return static_cast<void*>(const_cast< ImageContainer*>(this));
    return QObject::qt_metacast(_clname);
}

int ImageContainer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ImageContainer::loaded(QPixmap * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
