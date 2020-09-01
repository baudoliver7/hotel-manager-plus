#include "consoResto.h"

consoResto::consoResto()
{
    constructeur();
}

consoResto::consoResto(const QSqlRecord &record)
{
    constructeur(record);
}

consoResto::consoResto(const consoResto & s)
{
    constructeur(s);
}

consoResto::consoResto(int idConsoResto)
{
    constructeur(idConsoResto);
}

int consoResto::idConsoResto()const
{
    return m_record.value(ConsoResto::Id::IdConsoResto).toInt();
}

int consoResto::idMenu()const
{
    return m_record.value(ConsoResto::Id::IdMenu).toInt();
}

int consoResto::nbMenu()const
{
    return m_record.value(ConsoResto::Id::NbMenu).toInt();
}

int consoResto::coutTotal()const
{
    return m_record.value(ConsoResto::Id::CoutTotal).toInt();
}

int consoResto::idRepasCResto()const
{
    return m_record.value(ConsoResto::Id::IdRestoCResto).toInt();
}

QVariant consoResto::cle() const
{
    return idConsoResto();
}

QString consoResto::libelleDeCle() const
{
    return m_record.fieldName(ConsoResto::Id::IdConsoResto);
}

QString consoResto::tableName() const
{
    return ConsoResto::Libelle;
}

void consoResto::setIdMenu(int menu)
{
    m_record.setValue(ConsoResto::Id::IdMenu, menu);
    tableModifiee(true);
}

void consoResto::setNbMenu(int nb)
{
    m_record.setValue(ConsoResto::Id::NbMenu, nb);
    tableModifiee(true);
}

void consoResto::setCoutTotal(int cout)
{
    m_record.setValue(ConsoResto::Id::CoutTotal, cout);
    tableModifiee(true);
}

void consoResto::setIdRepasCResto(int id)
{
    m_record.setValue(ConsoResto::Id::IdRestoCResto, id);
    tableModifiee(true);
}

QList<QSqlRecord> consoResto::consoResto_records(int idRepasCResto)
{
    consoResto cr;
    QString condition = QObject::tr("%1 = %2")
                        .arg(cr.idRepasCRestoName())
                        .arg(idRepasCResto);

    return InfosSurBD::enregistrements(ConsoResto::Libelle, condition);
}
