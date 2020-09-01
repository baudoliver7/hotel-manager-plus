#ifndef FACTUREINITIAL_H
#define FACTUREINITIAL_H

#include "MesTables_global.h"

#include "Entree.h"

class MESTABLESSHARED_EXPORT factureInitial : public Entree
{
public:
    enum IdFacture
    {
        IdReception = 1, IdRestaurant = 2, IdBar = 3
    };

public:
    factureInitial();
    factureInitial(int id);
    factureInitial(const QSqlRecord & record);
    factureInitial(const factureInitial & s);

    void setIdService(int idService);
    void setTypeDeFacture(QString type);
    void setInitial(QString initial);
    void setNumero(int num);

    int idFactureInitial()const;
    int idService()const;
    QString typeDeFacture()const;
    QString initial()const;
    int numero()const;

    inline QString idFactureInitialName()const{return m_fieldsName.at(FactureInitial::Id::IdFactureInitial);};
    inline QString idServiceName()const{return m_fieldsName.at(FactureInitial::Id::IdService);};
    inline QString typeDeFactureName()const{return m_fieldsName.at(FactureInitial::Id::TypeDeFacture);};
    inline QString initialName()const{return m_fieldsName.at(FactureInitial::Id::Initial);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin
};

#endif // FACTUREINITIAL_H
