#include "PlanComptable.h"

planComptable::planComptable()
{
    constructeur();
}

planComptable::planComptable(int numCpt)
{
    constructeur(numCpt);
}

planComptable::planComptable(const QSqlRecord &record)
{
    constructeur(record);
}

planComptable::planComptable(const planComptable & pc)
{
    constructeur(pc);
}

int planComptable::numCpt()const
{
    return m_record.value(PlanComptable::Id::NumeroCpt).toInt();
}

QString planComptable::libelle() const
{
    return m_record.value(PlanComptable::Id::Libelle).toString();
}

QString planComptable::libellePerso() const
{
    return m_record.value(PlanComptable::Id::LibellePerso).toString();
}

bool planComptable::utilise() const
{
    return m_record.value(PlanComptable::Id::Utilise).toBool();
}

int planComptable::classe()const
{
    return m_record.value(PlanComptable::Id::Classe).toInt();
}

void planComptable::setNumCpt(int numCpt)
{
    m_record.setValue(PlanComptable::Id::NumeroCpt, numCpt);
    tableModifiee(true);
}

void planComptable::setLibelle(QString libelle)
{
    m_record.setValue(PlanComptable::Id::Libelle, libelle);
    tableModifiee(true);
}

void planComptable::setLibellePerso(QString libelle)
{
    m_record.setValue(PlanComptable::Id::LibellePerso, libelle);
    tableModifiee(true);
}

void planComptable::setClasse(int classe)
{
    m_record.setValue(PlanComptable::Id::Classe, classe);
    tableModifiee(true);
}

void planComptable::setUtilise(bool utilise)
{
    m_record.setValue(PlanComptable::Id::Utilise, utilise);
    tableModifiee(true);
}

QVariant planComptable::cle() const
{
    return numCpt();
}

QString planComptable::libelleDeCle() const
{
    return m_record.fieldName(PlanComptable::Id::NumeroCpt);
}

QString planComptable::tableName() const
{
    return PlanComptable::Libelle;
}

// fonctions spécialisées

QList<QSqlRecord> planComptable::pc_records(int classe)
{
    planComptable pc;
    QString condition = QObject::tr("%1 = %2")
                        .arg(pc.classeName())
                        .arg(classe);

    return InfosSurBD::enregistrements(PlanComptable::Libelle, condition);
}

QList<QSqlRecord> planComptable::pc_records(int classe, bool utilise, int nbChiffre)
{
    planComptable pc;
    QString condition = QObject::tr("%1 = %2 AND %3 = %4")
                        .arg(pc.classeName())
                        .arg(classe)
                        .arg(pc.utiliseName())
                        .arg(utilise);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(PlanComptable::Libelle, condition);

    QList<QSqlRecord> pcs;
    foreach(QSqlRecord record, records)
    {
        planComptable p(record);

        if(QString::number(p.numCpt()).size() == nbChiffre)
        {
            pcs << record;
        }
    }

    return pcs;
}

QList<QSqlRecord> planComptable::pc_records(bool utilise)
{
    planComptable pc;
    QString condition = QObject::tr("%1 = %2")
                        .arg(pc.utiliseName())
                        .arg(utilise);

    return InfosSurBD::enregistrements(PlanComptable::Libelle, condition);
}

QList<QSqlRecord> planComptable::pc_childs_records(int classe, bool utilise, int compteParent)
{
    int nbChiffre = QString::number(compteParent).size() + 1;

    planComptable pc;
    QString condition = QObject::tr("%1 = %2 AND %3 = %4")
                        .arg(pc.classeName())
                        .arg(classe)
                        .arg(pc.utiliseName())
                        .arg(utilise);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(PlanComptable::Libelle, condition);

    QList<QSqlRecord> pcs;
    foreach(QSqlRecord record, records)
    {
        planComptable p(record);

        QString numCptStr = QString::number(p.numCpt());
        QString compteParentStr = numCptStr;
        compteParentStr.resize(nbChiffre - 1);
        if((numCptStr.size() == nbChiffre) && (compteParentStr.toInt() == compteParent))
        {
            pcs << record;
        }
    }

    return pcs;
}

QList<QSqlRecord> planComptable::pc_all_childs_records(int classe, bool utilise, int compteParent)
{
    planComptable pc;
    QString condition = QObject::tr("%1 = %2 AND %3 = %4")
                        .arg(pc.classeName())
                        .arg(classe)
                        .arg(pc.utiliseName())
                        .arg(utilise);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(PlanComptable::Libelle, condition);

    QList<QSqlRecord> pcs;
    foreach(QSqlRecord record, records)
    {
        planComptable p(record);

        QString compteParentStr = QString::number(p.numCpt());
        compteParentStr.resize(QString::number(compteParent).size());

        if(compteParentStr.toInt() == compteParent)
        {
            pcs << record;
        }
    }

    return pcs;
}

QList<QSqlRecord> planComptable::pc_all_parents_records(bool utilise, int sousCompte)
{
    QList<QSqlRecord> resultats;

    QString sousCompteStr = QString::number(sousCompte);

    for(int i = sousCompteStr.size() - 1; i > 1; i--)
    {
        QString compteParentDirect = sousCompteStr;
        compteParentDirect.resize(i);

        planComptable pc;
        QString condition = QObject::tr("%1 = %2 AND %3 = %4")
                            .arg(pc.utiliseName())
                            .arg(utilise)
                            .arg(pc.numCptName())
                            .arg(compteParentDirect.toInt());

        resultats << InfosSurBD::enregistrements(PlanComptable::Libelle, condition);
    }

    return resultats;
}

bool planComptable::estVide()const
{
    QString numCptName = InfosSurBD::fieldsNames(OperationsComptables::Libelle).at(OperationsComptables::Id::NumeroCpt);
    QString condition = QObject::tr("%1 = %2").arg(numCptName).arg(numCpt());

    return InfosSurBD::enregistrements(OperationsComptables::Libelle, condition).isEmpty();
}

QString planComptable::libelleComplet()const
{
    return QObject::tr("%1 %2").arg(numCpt()).arg(libelle());
}

QString planComptable::libellePersoComplet()const
{
    return QObject::tr("%1 %2").arg(numCpt()).arg(libellePerso());
}
