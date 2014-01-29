/****************************************************************************
** Meta object code from reading C++ file 'imageactionwidget.h'
**
** Created: Wed 20. Nov 21:59:13 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dsp-lab4/imageactionwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageactionwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImageActionWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   30,   18,   18, 0x0a,
      63,   30,   18,   18, 0x0a,
      94,   18,   18,   18, 0x0a,
     123,   18,   18,   18, 0x0a,
     140,   18,   18,   18, 0x0a,
     160,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ImageActionWidget[] = {
    "ImageActionWidget\0\0finished()\0pixmap\0"
    "loadSourceImage(QPixmap*)\0"
    "loadDestinationImage(QPixmap*)\0"
    "loadDestinationImage(QImage)\0"
    "setProgress(int)\0setProgressMax(int)\0"
    "apply()\0"
};

void ImageActionWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ImageActionWidget *_t = static_cast<ImageActionWidget *>(_o);
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->loadSourceImage((*reinterpret_cast< QPixmap*(*)>(_a[1]))); break;
        case 2: _t->loadDestinationImage((*reinterpret_cast< QPixmap*(*)>(_a[1]))); break;
        case 3: _t->loadDestinationImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 4: _t->setProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setProgressMax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->apply(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ImageActionWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ImageActionWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ImageActionWidget,
      qt_meta_data_ImageActionWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImageActionWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImageActionWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImageActionWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageActionWidget))
        return static_cast<void*>(const_cast< ImageActionWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ImageActionWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ImageActionWidget::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
