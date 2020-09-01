#ifndef CONFIGSERVICECOMPTA_H
#define CONFIGSERVICECOMPTA_H

#include "MesTables_global.h"

#include "Entree.h"

class MESTABLESSHARED_EXPORT configServiceCompta : public Entree
{
public:
    enum IdAction
    {
        CaisseRecept = 1, Banque = 2, ClientRecept = 3, LocationRecept = 4, AvanceRecept = 5,
        VenteNourritureResto = 6, TVADeductibleCompta = 7, TVACollecteeCompta = 8, PenaliteRetardRecept = 9,
        TaxeTouristique = 10
    };

    configServiceCompta();
    configServiceCompta(int idCsc);
    configServiceCompta(const QSqlRecord & record);
    configServiceCompta(const configServiceCompta & csc);

    void setAction(QString ot);
    void setCompteAssocie(int numero);
    void setIdSe(int numero);

    int idCsc()const;
    QString action()const;
    int compteAssocie()const;
    int idSe()const;

    inline QString idCscName()const{return m_fieldsName.at(ConfigServiceCompta::Id::IdCsc);};
    inline QString actionName()const{return m_fieldsName.at(ConfigServiceCompta::Id::Action);};
    inline QString compteAssocieName()const{return m_fieldsName.at(ConfigServiceCompta::Id::CompteAssocie);};
    inline QString idSeName()const{return m_fieldsName.at(ConfigServiceCompta::Id::IdSe);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin
};

#endif // CONFIGSERVICECOMPTA_H
