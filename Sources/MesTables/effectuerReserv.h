#ifndef EFFECTUERRESERV_H
#define EFFECTUERRESERV_H

#include "MesTables_global.h"

/* classes qt */
#include <QStringList>
#include <QDateTime>

/* classes personnalisées */
#include "InfosSurBD.h"
#include "Entree.h"

class MESTABLESSHARED_EXPORT effectuerReserv : public Entree
{
public:
    effectuerReserv();
    effectuerReserv(int NumEffectuer);
    effectuerReserv(const QSqlRecord & record);
    effectuerReserv(const effectuerReserv & rc);

    void setDate(QDateTime dateTime);
    void setMatriculeRecepteur(QString matricule);
    void setIdentiteCh(QString identite);
    void setNumReserv(int num);

    QDateTime date()const;
    QString matriculeRecepteur()const;
    int numEffectuer()const;
    QString identiteCh()const;
    int numReserv()const;

    inline QString dateName()const{return m_fieldsName.at(EffectuerReserv::Id::Date);};
    inline QString MatriculeRecepteurName()const{return m_fieldsName.at(EffectuerReserv::Id::MatriculeRecepteur);};
    inline QString numEffectuerName()const{return m_fieldsName.at(EffectuerReserv::Id::NumEffectuer);};
    inline QString identiteChName()const{return m_fieldsName.at(EffectuerReserv::Id::IdentiteCh);};
    inline QString numReservName()const{return m_fieldsName.at(AnnulerReserv::Id::NumReservation);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

    static effectuerReserv selectionner(int numReserv);
};

#endif // EFFECTUERRESERV_H
