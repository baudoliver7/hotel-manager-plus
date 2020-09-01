#ifndef CHAMBRERESERVEE_H
#define CHAMBRERESERVEE_H

#include "MesTables_global.h"

/* classes qt */
#include <QDate>
#include <QDateTime>

/* classes personnalisées */
#include "Entree.h"
#include "horloge.h"
#include "HeureLimite.h"
#include "chambre.h"
#include "annulerReserv.h"
#include "effectuerReserv.h"

class MESTABLESSHARED_EXPORT chambreReservee : public Entree
{
public:
    chambreReservee();
    chambreReservee(int id);
    chambreReservee(const QSqlRecord & record);
    chambreReservee(const chambreReservee & ch);
    chambreReservee(int numReserv, QString ch);

    int idChambreReservee()const;
    int numReservation()const;
    QString identiteCh()const;
    bool terminee()const;
    int cout()const;
    int avance()const;
    int reste()const;

    inline QString numReservName()const{return m_fieldsName.at(ChambreReservee::Id::NumReservation);};
    inline QString identiteChName()const{return m_fieldsName.at(ChambreReservee::Id::IdentiteCh);};
    inline QString termineeName()const{return m_fieldsName.at(ChambreReservee::Id::Terminee);};
    inline QString coutName()const{return m_fieldsName.at(ChambreReservee::Id::Cout);};
    inline QString avanceName()const{return m_fieldsName.at(ChambreReservee::Id::Avance);};
    inline QString idChambreReserveeName()const{return m_fieldsName.at(ChambreReservee::Id::IdChambreReservee);};

    void setIdentiteCh(QString identite);
    void setTerminer(bool ter);
    void setCout(int cout);
    void setAvance(int avance);
    void setNumReservation(int id);

    // fonctions spéciales
    bool estEnCours()const;
    bool estReglee()const;
    bool executee()const;
    bool annulee()const;

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

public:
    static QList<QSqlRecord> chambresReserveesEnCours();
    static QList<QSqlRecord> chambresReserveesEnCours(int idTypeDeChambre);
    static QList<QSqlRecord> chambre_reservee_records(int numReservation);
};

#endif // CHAMBRERESERVEE_H
