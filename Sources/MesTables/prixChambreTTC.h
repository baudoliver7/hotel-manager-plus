#ifndef PRIXCHAMBRETTC_H
#define PRIXCHAMBRETTC_H

#include "MesTables_global.h"

/* classes qt */
#include <QStringList>

/* classes personnalisées */
#include "Entree.h"
#include "client.h"
#include "taux.h"

class MESTABLESSHARED_EXPORT prixChambreTTC : public Entree
{
public:
    prixChambreTTC();
    prixChambreTTC(int idPrixTTC);
    prixChambreTTC(const QSqlRecord & record);
    prixChambreTTC(const prixChambreTTC & t);
    prixChambreTTC(int idTypeDeChambre, int idProfile);

    void setPrixTTC(int prix);
    void setIdProfile(int id);
    void setIdTypeChambre(int id);

    int prixTTC()const;
    int idProfile()const;
    int idTypeChambre()const;
    int idPrixChambreTTC()const;
    int tva()const;

    inline QString idPrixChambreName()const{return m_fieldsName.at(PrixChambreTTC::Id::IdPrixChambreTTC);};
    inline QString prixTTCName()const{return m_fieldsName.at(PrixChambreTTC::Id::PrixTTC);};
    inline QString idTypeChambreName()const{return m_fieldsName.at(PrixChambreTTC::Id::IdTypeChambre);};
    inline QString idProfileName()const{return m_fieldsName.at(PrixChambreTTC::Id::IdProfile);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin
};

#endif // PRIXCHAMBRETTC_H
