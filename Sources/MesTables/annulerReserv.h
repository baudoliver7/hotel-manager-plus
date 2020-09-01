#ifndef ANNULERRESERV_H
#define ANNULERRESERV_H

#include "MesTables_global.h"

/* classes qt */
#include <QStringList>
#include <QDateTime>

/* classes personnalisées */
#include "InfosSurBD.h"
#include "Entree.h"

class MESTABLESSHARED_EXPORT annulerReserv : public Entree
{
public:
    annulerReserv();
    annulerReserv(int NumEffectuer);
    annulerReserv(const QSqlRecord & record);
    annulerReserv(const annulerReserv & rc);

    void setDate(QDateTime dateTime);
    void setMatriculeRecepteur(QString matricule);
    void setIdentiteCh(QString identite);
    void setNumReserv(int num);

    QDateTime date()const;
    QString matriculeRecepteur()const;
    int numAnnuler()const;
    QString identiteCh()const;
    int numReserv()const;

    inline QString dateName()const{return m_fieldsName.at(AnnulerReserv::Id::Date);};
    inline QString MatriculeRecepteurName()const{return m_fieldsName.at(AnnulerReserv::Id::MatriculeRecepteur);};
    inline QString numAnnulerName()const{return m_fieldsName.at(AnnulerReserv::Id::NumAnnuler);};
    inline QString identiteChName()const{return m_fieldsName.at(AnnulerReserv::Id::IdentiteCh);};
    inline QString numReservName()const{return m_fieldsName.at(AnnulerReserv::Id::NumReservation);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

    static annulerReserv selectionner(int numReserv);
};

#endif // ANNULERRESERV_H
