#ifndef TABLERESTO_H
#define TABLERESTO_H

#include "MesTables_global.h"

#include "Entree.h"

class MESTABLESSHARED_EXPORT tableResto : public Entree
{
public:
    tableResto();
    tableResto(int id);
    tableResto(QString libelle);
    tableResto(const QSqlRecord & record);
    tableResto(const tableResto & s);

    void setLibelle(QString libelle);
    void setOccupee(bool occupee);
    void setSupprime(bool supprime);
    void setEstBar(bool bar);

    QString libelle()const;
    int idTableResto()const;
    bool occupee()const;
    bool supprime()const;
    bool estBar()const;

    inline QString libelleName()const{return m_fieldsName.at(TableResto::Id::Libelle);};
    inline QString idTableRestoName()const{return m_fieldsName.at(TableResto::Id::IdTableResto);};
    inline QString occupeeName()const{return m_fieldsName.at(TableResto::Id::Occupee);};
    inline QString supprimeName()const{return m_fieldsName.at(TableResto::Id::Supprime);};
    inline QString estBarName()const{return m_fieldsName.at(TableResto::Id::EstBar);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin
};

#endif // TABLERESTO_H
