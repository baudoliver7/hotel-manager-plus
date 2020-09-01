#ifndef COMPTECLIENT_H
#define COMPTECLIENT_H

#include "MesTables_global.h"

#include "Entree.h"

class MESTABLESSHARED_EXPORT compteClient : public Entree
{
public:
    compteClient();
    compteClient(int id);
    compteClient(const QSqlRecord & record);
    compteClient(const compteClient & s);

    void setCodeClient(int id);
    void setLibelle(QString libelle);
    void setSolde(int solde);

    int idCompteClient()const;
    QString libelle()const;
    int codeClient()const;
    int solde()const;

    inline QString idCompteClientName()const{return m_fieldsName.at(CompteClient::Id::IdCompteClient);};
    inline QString libelleName()const{return m_fieldsName.at(CompteClient::Id::Libelle);};
    inline QString codeClientName()const{return m_fieldsName.at(CompteClient::Id::CodeClient);};
    inline QString soldeName()const{return m_fieldsName.at(CompteClient::Id::Solde);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

public:
    static QList<QSqlRecord> compteClient_records(int idClient);
};

#endif // COMPTECLIENT_H
