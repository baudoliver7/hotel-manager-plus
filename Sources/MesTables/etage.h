#ifndef ETAGE_H
#define ETAGE_H

#include "MesTables_global.h"

#include "Entree.h"

class MESTABLESSHARED_EXPORT etage : public Entree
{
public:
    etage();
    etage(int id);
    etage(const QSqlRecord & record);
    etage(const etage & s);

    void setNiveau(QString niveau);

    int idEtage()const;
    QString niveau()const;

    inline QString idEtageName()const{return m_fieldsName.at(Etage::Id::IdEtage);};
    inline QString niveauName()const{return m_fieldsName.at(Etage::Id::Niveau);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

public:
    static QStringList niveaux();
    static QList<QSqlRecord> etage_records();
};

#endif // ETAGE_H
