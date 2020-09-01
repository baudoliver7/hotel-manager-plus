#ifndef CONSORESTO_H
#define CONSORESTO_H

#include "MesTables_global.h"

/* classes qt */
#include <QDateTime>
#include <QStringList>

/* classes personnalisées */
#include "Entree.h"

class MESTABLESSHARED_EXPORT consoResto : public Entree
{
public:
    consoResto();
    consoResto(int idConsoResto);
    consoResto(const QSqlRecord & record);
    consoResto(const consoResto & s);

    void setIdMenu(int menu);
    void setNbMenu(int nb);
    void setCoutTotal(int cout);
    void setIdRepasCResto(int id);

    int idConsoResto()const;
    int idMenu()const;
    int nbMenu()const;
    int coutTotal()const;
    int idRepasCResto()const;

    inline QString idConsoRestoName()const{return m_fieldsName.at(ConsoResto::Id::IdConsoResto);};
    inline QString idMenuName()const{return m_fieldsName.at(ConsoResto::Id::IdMenu);};
    inline QString nbMenuName()const{return m_fieldsName.at(ConsoResto::Id::NbMenu);};
    inline QString idRepasCRestoName()const{return m_fieldsName.at(ConsoResto::Id::IdRestoCResto);};
    inline QString coutTotalName()const{return m_fieldsName.at(ConsoResto::Id::CoutTotal);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

public:
    static QList<QSqlRecord> consoResto_records(int idRepasCResto);
};

#endif // CONSORESTO_H
