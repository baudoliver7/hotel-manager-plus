#include "groupeLiaison.h"

groupeLiaison::groupeLiaison()
{
    constructeur();
}

groupeLiaison::groupeLiaison(const QSqlRecord &record)
{
    constructeur(record);
}

groupeLiaison::groupeLiaison(const groupeLiaison & s)
{
    constructeur(s);
}

groupeLiaison::groupeLiaison(int id)
{
    constructeur(id);
}

groupeLiaison::groupeLiaison(int idClient, int idGroupe)
{
    constructeur();

    QString condition = QObject::tr("%1 = %2 AND %3 = %4")
                        .arg(codeClientName())
                        .arg(idClient)
                        .arg(idGroupeName())
                        .arg(idGroupe);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(GroupeLiaison::Libelle, condition);

    if(!records.isEmpty())
        m_record = records.first();
}

int groupeLiaison::idGroupeLiaison()const
{
    return m_record.value(GroupeLiaison::Id::IdGroupeLiaison).toInt();
}

int groupeLiaison::idGroupe()const
{
    return m_record.value(GroupeLiaison::Id::IdGroupe).toInt();
}

int groupeLiaison::codeClient()const
{
    return m_record.value(GroupeLiaison::Id::CodeClient).toInt();
}

QVariant groupeLiaison::cle() const
{
    return idGroupeLiaison();
}

QString groupeLiaison::libelleDeCle() const
{
    return m_record.fieldName(GroupeLiaison::Id::IdGroupeLiaison);
}

QString groupeLiaison::tableName() const
{
    return GroupeLiaison::Libelle;
}

void groupeLiaison::setCodeClient(int id)
{
    m_record.setValue(GroupeLiaison::Id::CodeClient, id);
    tableModifiee(true);
}

void groupeLiaison::setIdGroupe(int id)
{
    m_record.setValue(GroupeLiaison::Id::IdGroupe, id);
    tableModifiee(true);
}

QList<QSqlRecord> groupeLiaison::groupe_liaison_records(int idGroupe)
{
    groupeLiaison grl;
    QString condition = QString("%1 = %2").arg(grl.idGroupeName()).arg(idGroupe);

    return InfosSurBD::enregistrements(grl.tableName(), condition);
}
