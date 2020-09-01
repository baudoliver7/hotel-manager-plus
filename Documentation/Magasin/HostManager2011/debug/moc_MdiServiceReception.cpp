/****************************************************************************
** Meta object code from reading C++ file 'MdiServiceReception.h'
**
** Created: Sat 17. Dec 04:47:05 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MdiServiceReception.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MdiServiceReception.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MdiServiceReception[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x05,
      30,   20,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      46,   43,   20,   20, 0x0a,
      82,   79,   20,   20, 0x0a,
     120,   43,   20,   20, 0x0a,
     154,   20,   20,   20, 0x08,
     183,   20,   20,   20, 0x08,
     208,   20,   20,   20, 0x08,
     253,   20,   20,   20, 0x08,
     295,   20,   20,   20, 0x08,
     337,   20,   20,   20, 0x08,
     376,   20,   20,   20, 0x08,
     401,   20,   20,   20, 0x08,
     421,   20,   20,   20, 0x08,
     443,   20,   20,   20, 0x08,
     456,   20,   20,   20, 0x08,
     504,  498,   20,   20, 0x08,
     557,   20,   20,   20, 0x08,
     588,   20,   20,   20, 0x08,
     616,   20,   20,   20, 0x08,
     645,   20,   20,   20, 0x08,
     684,   20,   20,   20, 0x08,
     735,   20,   20,   20, 0x08,
     782,   20,   20,   20, 0x08,
     810,  498,   20,   20, 0x08,
     855,   20,   20,   20, 0x08,
     884,   20,   20,   20, 0x08,
     919,   20,   20,   20, 0x08,
     955,   20,   20,   20, 0x08,
     988,  986,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MdiServiceReception[] = {
    "MdiServiceReception\0\0closed()\0"
    "bdModifiee()\0cl\0remplirOccuperUneChambre(client)\0"
    "rv\0remplirOccuperUneChambre(reservation)\0"
    "remplirReserverUneChambre(client)\0"
    "updateBtnCharge(QModelIndex)\0"
    "on_btn_charger_clicked()\0"
    "on_lineEditPrenomReserv_textChanged(QString)\0"
    "on_lineEditNomReserv_textChanged(QString)\0"
    "on_lineEditPrenomOcc_textChanged(QString)\0"
    "on_lineEditNomOcc_textChanged(QString)\0"
    "on_btn_effacer_clicked()\0actualiserFenetre()\0"
    "afficherLesChambres()\0rafraichir()\0"
    "on_spinBoxNbJoursReserv_valueChanged(int)\0"
    "index\0on_comboBoxDureeJoursReserv_currentIndexChanged(int)\0"
    "on_btn_contactReserv_clicked()\0"
    "on_btn_calendrier_clicked()\0"
    "on_btn_initialiser_clicked()\0"
    "on_spinBoxNbJoursOcc_valueChanged(int)\0"
    "on_comboBoxTypeClient_currentIndexChanged(QString)\0"
    "on_comboBoxTypeCh_currentIndexChanged(QString)\0"
    "on_btn_contactOcc_clicked()\0"
    "on_comboBoxDureeOcc_currentIndexChanged(int)\0"
    "on_btn_enregistrer_clicked()\0"
    "chargerIdentifiantsChDispo_occup()\0"
    "chargerIdentifiantsChDispo_reserv()\0"
    "actualiserEtatBtnEnregistrer()\0l\0"
    "arrangerParOrdreCroissant(QStringList&)\0"
};

const QMetaObject MdiServiceReception::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MdiServiceReception,
      qt_meta_data_MdiServiceReception, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MdiServiceReception::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MdiServiceReception::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MdiServiceReception::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MdiServiceReception))
        return static_cast<void*>(const_cast< MdiServiceReception*>(this));
    return QWidget::qt_metacast(_clname);
}

int MdiServiceReception::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: closed(); break;
        case 1: bdModifiee(); break;
        case 2: remplirOccuperUneChambre((*reinterpret_cast< client(*)>(_a[1]))); break;
        case 3: remplirOccuperUneChambre((*reinterpret_cast< reservation(*)>(_a[1]))); break;
        case 4: remplirReserverUneChambre((*reinterpret_cast< client(*)>(_a[1]))); break;
        case 5: updateBtnCharge((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 6: on_btn_charger_clicked(); break;
        case 7: on_lineEditPrenomReserv_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: on_lineEditNomReserv_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: on_lineEditPrenomOcc_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: on_lineEditNomOcc_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: on_btn_effacer_clicked(); break;
        case 12: actualiserFenetre(); break;
        case 13: afficherLesChambres(); break;
        case 14: rafraichir(); break;
        case 15: on_spinBoxNbJoursReserv_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: on_comboBoxDureeJoursReserv_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: on_btn_contactReserv_clicked(); break;
        case 18: on_btn_calendrier_clicked(); break;
        case 19: on_btn_initialiser_clicked(); break;
        case 20: on_spinBoxNbJoursOcc_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: on_comboBoxTypeClient_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: on_comboBoxTypeCh_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: on_btn_contactOcc_clicked(); break;
        case 24: on_comboBoxDureeOcc_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: on_btn_enregistrer_clicked(); break;
        case 26: chargerIdentifiantsChDispo_occup(); break;
        case 27: chargerIdentifiantsChDispo_reserv(); break;
        case 28: actualiserEtatBtnEnregistrer(); break;
        case 29: arrangerParOrdreCroissant((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 30;
    }
    return _id;
}

// SIGNAL 0
void MdiServiceReception::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MdiServiceReception::bdModifiee()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
