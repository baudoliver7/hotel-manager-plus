#ifndef EMETTRERESERV_H
#define EMETTRERESERV_H

#include "MesTables_global.h"

/* classes qt */
#include <QStringList>
#include <QDateTime>

/* classes personnalisées */
#include "InfosSurBD.h"
#include "Entree.h"

class MESTABLESSHARED_EXPORT emettreReserv : public Entree
{
public:
    emettreReserv();
    emettreReserv(int NumEmettre);
    emettreReserv(const QSqlRecord & record);
    emettreReserv(const emettreReserv & rc);

    void setDate(QDateTime dateTime);
    void setMatriculeRecepteur(QString matricule);
    void setIdentiteCh(QString identite);
    void setNumReserv(int num);

    QDateTime date()const;
    QString matriculeRecepteur()const;
    int numEmettre()const;
    QString identiteCh()const;
    int numReserv()const;

    inline QString dateName()const{return m_fieldsName.at(EmettreReserv::Id::Date);};
    inline QString matriculeRecepteurName()const{return m_fieldsName.at(EmettreReserv::Id::MatriculeRecepteur);};
    inline QString numEmettreName()const{return m_fieldsName.at(EmettreReserv::Id::NumEmettre);};
    inline QString identiteChName()const{return m_fieldsName.at(EmettreReserv::Id::IdentiteCh);};
    inline QString numReservName()const{return m_fieldsName.at(AnnulerReserv::Id::NumReservation);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

    static emettreReserv selectionner(int numReserv);
};

#endif // EMETTRERESERV_H
