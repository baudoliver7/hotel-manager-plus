#ifndef GROUPELIAISON_H
#define GROUPELIAISON_H

#include "MesTables_global.h"

#include "Entree.h"

class MESTABLESSHARED_EXPORT groupeLiaison : public Entree
{
public:
    groupeLiaison();
    groupeLiaison(int id);
    groupeLiaison(int idClient, int idGroupe);
    groupeLiaison(const QSqlRecord & record);
    groupeLiaison(const groupeLiaison & s);

    void setIdGroupe(int id);
    void setCodeClient(int id);

    int idGroupeLiaison()const;
    int idGroupe()const;
    int codeClient()const;

    inline QString idGroupeLiaisonName()const{return m_fieldsName.at(GroupeLiaison::Id::IdGroupeLiaison);};
    inline QString idGroupeName()const{return m_fieldsName.at(GroupeLiaison::Id::IdGroupe);};
    inline QString codeClientName()const{return m_fieldsName.at(GroupeLiaison::Id::CodeClient);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

public:
    static QList<QSqlRecord> groupe_liaison_records(int idGroupe);
};

#endif // GROUPELIAISON_H
