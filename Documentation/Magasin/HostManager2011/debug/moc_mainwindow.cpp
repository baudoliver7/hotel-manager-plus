/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat 17. Dec 04:47:00 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   12,   11,   11, 0x05,
      38,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      70,   62,   11,   11, 0x08,
     120,   11,   11,   11, 0x08,
     166,   11,   11,   11, 0x08,
     211,   11,   11,   11, 0x08,
     251,   11,   11,   11, 0x08,
     286,   11,   11,   11, 0x08,
     319,   11,   11,   11, 0x08,
     348,   11,   11,   11, 0x08,
     376,   11,   11,   11, 0x08,
     403,   11,   11,   11, 0x08,
     428,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0cl\0remplirOccuper(client)\0"
    "remplirReserver(client)\0checked\0"
    "on_actionActiver_son_de_compagnon_triggered(bool)\0"
    "on_actionRechercherUneReservation_triggered()\0"
    "on_actionRechercherUneOccupation_triggered()\0"
    "on_actionRechercherUnClient_triggered()\0"
    "on_actionSeDeconnecter_triggered()\0"
    "on_actionSeConnecter_triggered()\0"
    "on_actionQuitter_triggered()\0"
    "fermerMdiServiceReception()\0"
    "etablirEtat_Deconnection()\0"
    "etablirEtat_Connection()\0rechercherUnClient()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: remplirOccuper((*reinterpret_cast< client(*)>(_a[1]))); break;
        case 1: remplirReserver((*reinterpret_cast< client(*)>(_a[1]))); break;
        case 2: on_actionActiver_son_de_compagnon_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: on_actionRechercherUneReservation_triggered(); break;
        case 4: on_actionRechercherUneOccupation_triggered(); break;
        case 5: on_actionRechercherUnClient_triggered(); break;
        case 6: on_actionSeDeconnecter_triggered(); break;
        case 7: on_actionSeConnecter_triggered(); break;
        case 8: on_actionQuitter_triggered(); break;
        case 9: fermerMdiServiceReception(); break;
        case 10: etablirEtat_Deconnection(); break;
        case 11: etablirEtat_Connection(); break;
        case 12: rechercherUnClient(); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::remplirOccuper(client _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::remplirReserver(client _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
