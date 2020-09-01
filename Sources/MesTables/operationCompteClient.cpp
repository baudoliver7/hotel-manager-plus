#include "operationCompteClient.h"

operationCompteClient::operationCompteClient()
{
    constructeur();
}

operationCompteClient::operationCompteClient(const QSqlRecord &record)
{
    constructeur(record);
}

operationCompteClient::operationCompteClient(const operationCompteClient & s)
{
    constructeur(s);
}

operationCompteClient::operationCompteClient(int id)
{
    constructeur(id);
}

int operationCompteClient::idCompteClient()const
{
    return m_record.value(OperationCompteClient::Id::IdCompteClient).toInt();
}

int operationCompteClient::idOpCompteClient()const
{
    return m_record.value(OperationCompteClient::Id::IdOpCompteClient).toInt();
}

QDateTime operationCompteClient::date()const
{
    return m_record.value(OperationCompteClient::Id::Date).toDateTime();
}

QString operationCompteClient::libelle()const
{
    return m_record.value(OperationCompteClient::Id::Libelle).toString();
}

int operationCompteClient::debit()const
{
    return m_record.value(OperationCompteClient::Id::Debit).toInt();
}

int operationCompteClient::credit()const
{
    return m_record.value(OperationCompteClient::Id::Credit).toInt();
}

int operationCompteClient::solde()const
{
    return m_record.value(OperationCompteClient::Id::Solde).toInt();
}

QString operationCompteClient::matriculeAgent()const
{
    return m_record.value(OperationCompteClient::Id::Libelle).toString();
}

QVariant operationCompteClient::cle() const
{
    return idOpCompteClient();
}

QString operationCompteClient::libelleDeCle() const
{
    return m_record.fieldName(OperationCompteClient::Id::IdOpCompteClient);
}

QString operationCompteClient::tableName() const
{
    return OperationCompteClient::Libelle;
}

void operationCompteClient::setDate(QDateTime date)
{
    m_record.setValue(OperationCompteClient::Id::Date, date);
    tableModifiee(true);
}

void operationCompteClient::setLibelle(QString libelle)
{
    m_record.setValue(OperationCompteClient::Id::Libelle, libelle);
    tableModifiee(true);
}

void operationCompteClient::setDebit(int debit)
{
    m_record.setValue(OperationCompteClient::Id::Debit, debit);
    tableModifiee(true);
}

void operationCompteClient::setCredit(int credit)
{
    m_record.setValue(OperationCompteClient::Id::Credit, credit);
    tableModifiee(true);
}

void operationCompteClient::setSolde(int solde)
{
    m_record.setValue(OperationCompteClient::Id::Solde, solde);
    tableModifiee(true);
}

void operationCompteClient::setIdCompteClient(int id)
{
    m_record.setValue(OperationCompteClient::Id::IdCompteClient, id);
    tableModifiee(true);
}

void operationCompteClient::setMatriculeAgent(QString matricule)
{
    m_record.setValue(OperationCompteClient::Id::MatriculeAgent, matricule);
    tableModifiee(true);
}
