#ifndef AGENT_H
#define AGENT_H

#include "MesTables_global.h"

/* classes qt */
#include <QDate>
#include <QDateTime>

/* classes personnalisées */
#include "Entree.h"

/* mes définitions */
#define ACTIF "Actif"
#define EN_ATTENTE "En attente"
#define SUSPENDU "Suspendu"

class MESTABLESSHARED_EXPORT agent : public Entree
{
public:
    enum Statut
    {
        EnAttente = 0, Actif = 1, Suspendu = 2
    };

    enum SexePrecis
    {
        Monsieur = 0, Madame = 1, Demoiselle = 2
    };

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

public:
    agent();
    agent(const QString & matricule);
    agent(const QSqlRecord & record);
    agent(const agent & rp);

    QString nom()const;
    QString prenoms()const;
    QString password()const;
    QString login()const;
    QString tel()const;
    QString cel()const;
    QString email()const;
    QString bp()const;
    QString matricule()const;
    QString sexePrecis()const;
    QString residence()const;
    Statut statut()const;
    QString statutToString()const;
    QDateTime dateInscription()const;
    QDateTime dateActivation()const;
    bool connecte()const;
    int idService() const;
    bool etatFinConnection()const;
    int codeDeSortie()const;
    bool activites()const;

    inline QString nomName()const{return m_fieldsName.at(Agent::Id::Nom);};
    inline QString prenomsName()const{return m_fieldsName.at(Agent::Id::Prenoms);};
    QString passwordName()const;
    QString loginName()const;
    inline QString telName()const{return m_fieldsName.at(Agent::Id::Tel);};
    inline QString celName()const{return m_fieldsName.at(Agent::Id::Cel);};
    inline QString emailName()const{return m_fieldsName.at(Agent::Id::Email);};
    inline QString bpName()const{return m_fieldsName.at(Agent::Id::BP);};
    inline QString matriculeName()const{return m_fieldsName.at(Agent::Id::Matricule);};
    inline QString sexePrecisName()const{return m_fieldsName.at(Agent::Id::SexePrecis);};
    inline QString residenceName()const{return m_fieldsName.at(Agent::Id::Residence);};
    inline QString statutName()const{return m_fieldsName.at(Agent::Id::Statut);};
    inline QString dateActivationName()const{return m_fieldsName.at(Agent::Id::DateActivation);};
    inline QString dateInscriptionName()const{return m_fieldsName.at(Agent::Id::DateInscription);};
    inline QString connecteName()const{return m_fieldsName.at(Agent::Id::Connecte);};
    inline QString etatFinConnectionName()const{return m_fieldsName.at(Agent::Id::EtatFinConnecte);};
    inline QString idServiceName()const{return m_fieldsName.at(Agent::Id::IdService);};

    void setNom(QString nom);
    void setPrenoms(QString prenoms);
    void setPassword(QString password);
    void setLogin(QString login);
    void setTel(QString tel);
    void setCel(QString cel);
    void setEmail(QString email);
    void setBP(QString bp);
    void setMatricule(QString matricule);
    void setSexePrecis(QString sexe);
    void setResidence(QString residence);
    void setStatut(Statut statut);
    void setContacts(QString contacts);
    void setDateActivation(QDateTime date);
    void setDateInscription(QDateTime date);
    void setConnecte(bool connecte);
    void setIdService(int id);
    void setEtatFinConnection(bool mauvais);
    void setCodeDeSortie(int code);
    void setActivites(bool activite);

public:
    static QStringList listeDeContacts(QString contacts);
    static QString contacts(QString cel, QString tel, QString email, QString bp);
    static QString statutToString(Statut s);
    static Statut qStringToStatut(QString s);
    static QStringList listeSexePrecis();
    static QStringList listeServices();
    static QList<QSqlRecord> agentsConnectes();
};

#endif // AGENT_H
