#include "annulerOccup.h"

annulerOccup::annulerOccup()
{
    constructeur();
}

annulerOccup::annulerOccup(const QSqlRecord &record)
{
    constructeur(record);
}

annulerOccup::annulerOccup(const annulerOccup & rc)
{
    constructeur(rc);
}

annulerOccup::annulerOccup(int NumAnnuler)
{
    constructeur(NumAnnuler);
}

QString annulerOccup::matriculeRecepteur()const
{
    return m_record.value(AnnulerOccup::Id::MatriculeRecepteur).toString();
}

QDateTime annulerOccup::date()const
{
    return m_record.value(AnnulerOccup::Id::Date).toDateTime();
}

int annulerOccup::codeClient()const
{
    return m_record.value(AnnulerOccup::Id::CodeClient).toInt();
}

int annulerOccup::numOccup()const
{
    return m_record.value(AnnulerOccup::Id::NumOccupation).toInt();
}

int annulerOccup::numAnnuler()const
{
    return m_record.value(AnnulerOccup::Id::NumAnnuler).toInt();
}

void annulerOccup::setCodeClient(int code)
{
    m_record.setValue(AnnulerOccup::Id::CodeClient, code);
    tableModifiee(true);
}

void annulerOccup::setNumOccup(int num)
{
    m_record.setValue(AnnulerOccup::Id::NumOccupation, num);
    tableModifiee(true);
}

void annulerOccup::setDate(QDateTime dateTime)
{
    m_record.setValue(AnnulerOccup::Id::Date, dateTime);
    tableModifiee(true);
}

void annulerOccup::setMatriculeRecepteur(QString matricule)
{
    m_record.setValue(AnnulerOccup::Id::MatriculeRecepteur, matricule);
    tableModifiee(true);
}

QVariant annulerOccup::cle() const
{
    return numAnnuler();
}

QString annulerOccup::libelleDeCle() const
{
    return m_record.fieldName(AnnulerOccup::Id::NumAnnuler);
}

QString annulerOccup::tableName() const
{
    return AnnulerOccup::Libelle;
}

annulerOccup annulerOccup::selectionner(int numOccup)
{
    QString condition = QObject::tr("%1 = %2").arg(annulerOccup().numOccupName())
                                              .arg(numOccup);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(AnnulerOccup::Libelle, condition);

    if(!records.isEmpty())
    {
        return annulerOccup(records.first());
    }else
    {
        return annulerOccup();
    }
}


