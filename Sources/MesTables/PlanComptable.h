#ifndef PLANCOMPTABLE_H
#define PLANCOMPTABLE_H

#include "MesTables_global.h"

#include "Entree.h"

class MESTABLESSHARED_EXPORT planComptable: public Entree
{
public:
    planComptable();
    planComptable(int numCpt);
    planComptable(const QSqlRecord & record);
    planComptable(const planComptable & pc);

    int numCpt()const;
    QString libelle()const;
    bool utilise()const;
    int classe()const;
    QString libellePerso()const;

    inline QString numCptName()const{return m_fieldsName.at(PlanComptable::Id::NumeroCpt);};
    inline QString libelleName()const{return m_fieldsName.at(PlanComptable::Id::Libelle);};
    inline QString utiliseName()const{return m_fieldsName.at(PlanComptable::Id::Utilise);};
    inline QString classeName()const{return m_fieldsName.at(PlanComptable::Id::Classe);};
    inline QString libellePersoName()const{return m_fieldsName.at(PlanComptable::Id::LibellePerso);};

    void setNumCpt(int numCpt);
    void setLibelle(QString libelle);
    void setUtilise(bool utilise);
    void setClasse(int classe);
    void setLibellePerso(QString libelle);

    //fonctions spécialisées
    bool estVide()const;
    QString libelleComplet()const;
    QString libellePersoComplet()const;

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

public:
    static QList<QSqlRecord> pc_records(int classe);
    static QList<QSqlRecord> pc_records(bool utilise);
    static QList<QSqlRecord> pc_records(int classe, bool utilise, int nbChiffre);
    static QList<QSqlRecord> pc_childs_records(int classe, bool utilise, int compteParent);
    static QList<QSqlRecord> pc_all_childs_records(int classe, bool utilise, int compteParent);
    static QList<QSqlRecord> pc_all_parents_records(bool utilise, int sousCompte);

};

#endif // PLANCOMPTABLE_H
