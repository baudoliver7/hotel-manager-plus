/****************************************************************************
** Meta object code from reading C++ file 'DgRechercherUneReserv.h'
**
** Created: Sat 17. Dec 04:47:13 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DgRechercherUneReserv.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DgRechercherUneReserv.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DgRechercherUneReserv[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   23,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
      57,   22,   22,   22, 0x08,
      91,   22,   22,   22, 0x08,
     109,   22,   22,   22, 0x08,
     120,   22,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DgRechercherUneReserv[] = {
    "DgRechercherUneReserv\0\0rv\0"
    "remplirOccupation(reservation)\0"
    "updateEtatBtnsWidget(QModelIndex)\0"
    "rafraichirTable()\0executer()\0supprimer()\0"
};

const QMetaObject DgRechercherUneReserv::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DgRechercherUneReserv,
      qt_meta_data_DgRechercherUneReserv, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DgRechercherUneReserv::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DgRechercherUneReserv::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DgRechercherUneReserv::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DgRechercherUneReserv))
        return static_cast<void*>(const_cast< DgRechercherUneReserv*>(this));
    return QDialog::qt_metacast(_clname);
}

int DgRechercherUneReserv::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: remplirOccupation((*reinterpret_cast< reservation(*)>(_a[1]))); break;
        case 1: updateEtatBtnsWidget((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: rafraichirTable(); break;
        case 3: executer(); break;
        case 4: supprimer(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DgRechercherUneReserv::remplirOccupation(reservation _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
