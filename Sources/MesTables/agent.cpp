#include "agent.h"

agent::agent()
{
    constructeur();
}

agent::agent(const QString & matricule)
{
    constructeur(QVariant(matricule));
}

agent::agent(const QSqlRecord &record)
{
    constructeur(record);
}

agent::agent(const agent &rp)
{
    constructeur(rp);
}

QString agent::nom()const
{
    return m_record.value(Agent::Id::Nom).toString();
}

QString agent::prenoms()const
{
    return m_record.value(Agent::Id::Prenoms).toString();
}

QString agent::password()const
{
    return m_record.value(Agent::Id::Password).toString();
}

QString agent::login()const
{
    return m_record.value(Agent::Id::Login).toString();
}

QString agent::tel()const
{
    return m_record.value(Agent::Id::Tel).toString();
}

QString agent::cel()const
{
    return m_record.value(Agent::Id::Cel).toString();
}

QString agent::email()const
{
    return m_record.value(Agent::Id::Email).toString();
}

QString agent::bp()const
{
    return m_record.value(Agent::Id::BP).toString();
}

QString agent::matricule()const
{
    return m_record.value(Agent::Id::Matricule).toString();
}

QString agent::sexePrecis()const
{
    return m_record.value(Agent::Id::SexePrecis).toString();
}

QString agent::residence()const
{
    return m_record.value(Agent::Id::Residence).toString();
}

agent::Statut agent::statut()const
{
    QString s = m_record.value(Agent::Id::Statut).toString();
    return qStringToStatut(s);
}

QString agent::statutToString() const
{
    return m_record.value(Agent::Id::Statut).toString();
}

QString agent::passwordName()const
{
    return m_fieldsName.at(Agent::Id::Password);
}

QDateTime agent::dateInscription() const
{
    return m_record.value(Agent::Id::DateInscription).toDateTime();
}

QDateTime agent::dateActivation() const
{
    return m_record.value(Agent::Id::DateActivation).toDateTime();
}

bool agent::connecte() const
{
    return m_record.value(Agent::Id::Connecte).toBool();
}

int agent::idService() const
{
    return m_record.value(Agent::Id::IdService).toInt();
}

bool agent::etatFinConnection() const
{
    return m_record.value(Agent::Id::EtatFinConnecte).toBool();
}

int agent::codeDeSortie() const
{
    return m_record.value(Agent::Id::CodeDeSortie).toInt();
}

bool agent::activites() const
{
    return m_record.value(Agent::Id::Activites).toBool();
}

QString agent::loginName()const
{
    return m_fieldsName.at(Agent::Id::Login);
}

void agent::setNom(QString nom)
{
    m_record.setValue(Agent::Id::Nom, nom);
    tableModifiee(true);
}

void agent::setPrenoms(QString prenoms)
{
    m_record.setValue(Agent::Id::Prenoms, prenoms);
    tableModifiee(true);
}

void agent::setPassword(QString password)
{
    m_record.setValue(Agent::Id::Password, password);
    tableModifiee(true);
}

void agent::setLogin(QString login)
{
    m_record.setValue(Agent::Id::Login, login);
    tableModifiee(true);
}

void agent::setTel(QString tel)
{
    m_record.setValue(Agent::Id::Tel, tel);
    tableModifiee(true);
}

void agent::setCel(QString cel)
{
    m_record.setValue(Agent::Id::Cel, cel);
    tableModifiee(true);
}

void agent::setEmail(QString email)
{
    m_record.setValue(Agent::Id::Email, email);
    tableModifiee(true);
}

void agent::setBP(QString bp)
{
    m_record.setValue(Agent::Id::BP, bp);
    tableModifiee(true);
}

void agent::setMatricule(QString matricule)
{
    m_record.setValue(Agent::Id::Matricule, matricule);
    tableModifiee(true);
}

void agent::setSexePrecis(QString sexe)
{
    m_record.setValue(Agent::Id::SexePrecis, sexe);
    tableModifiee(true);
}

void agent::setResidence(QString residence)
{
    m_record.setValue(Agent::Id::Residence, residence);
    tableModifiee(true);
}

void agent::setStatut(Statut statut)
{
    m_record.setValue(Agent::Id::Statut, statutToString(statut));
    tableModifiee(true);
}

void agent::setContacts(QString contacts)
{
    QStringList listeDeContacts = contacts.split("|");
    if(listeDeContacts.first() != contacts)
    {
        setCel(listeDeContacts.at(0));
        setTel(listeDeContacts.at(1));
        setEmail(listeDeContacts.at(2));
        setBP(listeDeContacts.at(3));
        tableModifiee(true);
    }
}

void agent::setDateActivation(QDateTime date)
{
    m_record.setValue(Agent::Id::DateActivation, date);
    tableModifiee(true);
}

void agent::setDateInscription(QDateTime date)
{
    m_record.setValue(Agent::Id::DateInscription, date);
    tableModifiee(true);
}

void agent::setConnecte(bool connecte)
{
    m_record.setValue(Agent::Id::Connecte, connecte);
    tableModifiee(true);
}

void agent::setIdService(int id)
{
    m_record.setValue(Agent::Id::IdService, id);
    tableModifiee(true);
}

void agent::setEtatFinConnection(bool mauvais)
{
    m_record.setValue(Agent::Id::EtatFinConnecte, mauvais);
    tableModifiee(true);
}

void agent::setCodeDeSortie(int nb)
{
    m_record.setValue(Agent::Id::CodeDeSortie, nb);
    tableModifiee(true);
}

void agent::setActivites(bool activite)
{
    m_record.setValue(Agent::Id::Activites, activite);
    tableModifiee(true);
}

QStringList agent::listeDeContacts(QString contacts)
{
   return contacts.split("|");
}

QString agent::contacts(QString cel, QString tel, QString email, QString bp)
{
    return (cel+ "|"
            +tel+"|"
            +email+"|"
            +bp);
}

QString agent::statutToString(Statut s)
{
    QStringList l;
    l << EN_ATTENTE << ACTIF << SUSPENDU;

    return l.at(s);
}

agent::Statut agent::qStringToStatut(QString s)
{
    QStringList l;
    l << EN_ATTENTE << ACTIF << SUSPENDU;

    return (Statut)l.indexOf(s);
}

QVariant agent::cle() const
{
    return matricule();
}

QString agent::libelleDeCle() const
{
    return m_record.fieldName(Agent::Id::Matricule);
}

QString agent::tableName() const
{
    return Agent::Libelle;
}

QStringList agent::listeSexePrecis()
{
    QStringList l;
    l << "M." << "Mme" << "Mlle";
    return l;
}

QStringList agent::listeServices()
{
    QStringList l;
    l << "Administration" << "Réception" << "Comptabilité";
    return l;
}

QList<QSqlRecord> agent::agentsConnectes()
{
    QList<QSqlRecord> agents;
    agents << InfosSurBD::enregistrements(Agent::Libelle, QObject::tr("%1 = '%2' AND %3 = %4")
                                              .arg(agent().statutName()).arg(statutToString(agent::Actif))
                                              .arg(agent().connecteName()).arg(true));

    return agents;
}
