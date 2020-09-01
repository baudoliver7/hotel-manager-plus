#ifndef OPERATIONCOMPTECLIENT_H
#define OPERATIONCOMPTECLIENT_H

#include "MesTables_global.h"

#include <QDate>

#include "Entree.h"

class MESTABLESSHARED_EXPORT operationCompteClient : public Entree
{
public:
    operationCompteClient();
    operationCompteClient(int id);
    operationCompteClient(const QSqlRecord & record);
    operationCompteClient(const operationCompteClient & s);

    void setDate(QDateTime date);
    void setLibelle(QString libelle);
    void setDebit(int debit);
    void setCredit(int credit);
    void setSolde(int solde);
    void setIdCompteClient(int id);
    void setMatriculeAgent(QString matricule);

    int idOpCompteClient()const;
    QDateTime date()const;
    QString libelle()const;
    int debit()const;
    int credit()const;
    int solde()const;
    int idCompteClient()const;
    QString matriculeAgent()const;

    inline QString idOpCompteClientName()const{return m_fieldsName.at(OperationCompteClient::Id::IdCompteClient);};
    inline QString dateName()const{return m_fieldsName.at(OperationCompteClient::Id::Date);};
    inline QString libelleName()const{return m_fieldsName.at(OperationCompteClient::Id::Libelle);};
    inline QString debitName()const{return m_fieldsName.at(OperationCompteClient::Id::Debit);};
    inline QString creditName()const{return m_fieldsName.at(OperationCompteClient::Id::Credit);};
    inline QString soldeName()const{return m_fieldsName.at(OperationCompteClient::Id::Solde);};
    inline QString idCompteClientName()const{return m_fieldsName.at(OperationCompteClient::Id::IdCompteClient);};
    inline QString matriculeAgentName()const{return m_fieldsName.at(OperationCompteClient::Id::MatriculeAgent);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin
};

#endif // OPERATIONCOMPTECLIENT_H
