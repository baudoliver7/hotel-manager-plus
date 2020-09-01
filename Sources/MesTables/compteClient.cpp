#include "compteClient.h"

compteClient::compteClient()
{
    constructeur();
}

compteClient::compteClient(const QSqlRecord &record)
{
    constructeur(record);
}

compteClient::compteClient(const compteClient & s)
{
    constructeur(s);
}

compteClient::compteClient(int id)
{
    constructeur(id);
}

int compteClient::idCompteClient()const
{
    return m_record.value(CompteClient::Id::IdCompteClient).toInt();
}

int compteClient::codeClient()const
{
    return m_record.value(CompteClient::Id::CodeClient).toInt();
}

int compteClient::solde()const
{
    return m_record.value(CompteClient::Id::Solde).toInt();
}

QString compteClient::libelle()const
{
    return m_record.value(CompteClient::Id::Libelle).toString();
}

QVariant compteClient::cle() const
{
    return idCompteClient();
}

QString compteClient::libelleDeCle() const
{
    return m_record.fieldName(CompteClient::Id::IdCompteClient);
}

QString compteClient::tableName() const
{
    return CompteClient::Libelle;
}

void compteClient::setCodeClient(int id)
{
    m_record.setValue(CompteClient::Id::CodeClient, id);
    tableModifiee(true);
}

void compteClient::setLibelle(QString libelle)
{
    m_record.setValue(CompteClient::Id::Libelle, libelle);
    tableModifiee(true);
}

void compteClient::setSolde(int solde)
{
    m_record.setValue(CompteClient::Id::Solde, solde);
    tableModifiee(true);
}

QList<QSqlRecord> compteClient::compteClient_records(int idClient)
{
    compteClient cc;
    QString condition = QObject::tr("%1 = %2").arg(cc.codeClientName()).arg(idClient);

    return InfosSurBD::enregistrements(cc.tableName(), condition);
}
