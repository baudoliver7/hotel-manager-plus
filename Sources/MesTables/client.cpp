#include "client.h"

client::client()
{
    constructeur();
}

client::client(int codeClient)
{
    constructeur(codeClient);
}

client::client(const QSqlRecord & record)
{
    constructeur(record);
}

client::client(const client & cl)
{
    constructeur(cl);
}

QVariant client::cle() const
{
    return codeDuClient();
}

QString client::libelleDeCle() const
{
    return m_record.fieldName(Client::Id::CodeClient);
}

QString client::tableName() const
{
    return Client::Libelle;
}

int client::codeDuClient()const
{
    if(!m_record.isNull(Client::Id::CodeClient))
    {
       return m_record.value(Client::Id::CodeClient).toInt();
    }else
    {
       return 0;
    }
}

QString client::nom()const
{
    return m_record.value(Client::Id::Nom).toString();
}

QString client::prenoms()const
{
    return m_record.value(Client::Id::Prenoms).toString();
}

QDate client::dateDeNaissance()const
{
    return m_record.value(Client::Id::DateDeNaissance).toDate();
}

QString client::lieuDeNaissance()const
{
    return m_record.value(Client::Id::LieuDeNaissance).toString();
}

QString client::profession()const
{
    return m_record.value(Client::Id::Profession).toString();
}

QString client::domicileHabituel()const
{
    return m_record.value(Client::Id::DomicileHabituel).toString();
}

QString client::nationalite()const
{
    return m_record.value(Client::Id::Nationalite).toString();
}

QString client::pere()const
{
    return m_record.value(Client::Id::Pere).toString();
}

QString client::mere()const
{
    return m_record.value(Client::Id::Mere).toString();
}

bool client::homme()const
{
    return m_record.value(Client::Id::Homme).toBool();
}

QString client::contacts()const
{
    QString ct =  client::contacts(cel(),tel(),email(),boitePostale());

    QString ctVide = client::contacts(QString(),QString(),QString(),QString());

    if(ct == ctVide)
        return QString();
    else
        return ct;
}

QStringList client::listeDeContacts(QString contacts)
{
   return contacts.split("|");
}

QString client::cel()const
{
    return m_record.value(Client::Id::Cel).toString();
}

QString client::tel()const
{
    return m_record.value(Client::Id::Tel).toString();
}

QString client::email()const
{
    return m_record.value(Client::Id::Email).toString();
}

QString client::boitePostale()const
{
    return m_record.value(Client::Id::BP).toString();
}

QString client::nomComplet()const
{
    return QObject::tr("%1 %2").arg(nom()).arg(prenoms());
}

QString client::contacts(QString cel, QString tel, QString email, QString bp)
{
    return (cel+ "|"
            +tel+"|"
            +email+"|"
            +bp);
}

void client::setNom(QString nom)
{
    m_record.setValue(Client::Id::Nom, nom);
    tableModifiee(true);
}

void client::setPrenoms(QString prenoms)
{
    m_record.setValue(Client::Id::Prenoms, prenoms);
    tableModifiee(true);
}

void client::setHomme(bool homme)
{
    m_record.setValue(Client::Id::Homme, homme);
    tableModifiee(true);
}

void client::setContacts(QString contacts)
{
    QStringList listeDeContacts = contacts.split("|");
    if(listeDeContacts.first() != contacts)
    {
        setCel(listeDeContacts.at(0));
        setTel(listeDeContacts.at(1));
        setEmail(listeDeContacts.at(2));
        setBoitePostale(listeDeContacts.at(3));
        tableModifiee(true);
    }
}

void client::setCel(QString cel)
{
    m_record.setValue(Client::Id::Cel, cel);
    tableModifiee(true);
}

void client::setTel(QString tel)
{
    m_record.setValue(Client::Id::Tel, tel);
    tableModifiee(true);
}

void client::setEmail(QString email)
{
    m_record.setValue(Client::Id::Email, email);
    tableModifiee(true);
}

void client::setBoitePostale(QString boitePostale)
{
    m_record.setValue(Client::Id::BP, boitePostale);
    tableModifiee(true);
}

void client::setCode(int code)
{
    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(tableName(), QObject::tr("%1 = %2").arg(codeDuClientName()).arg(code));
    if(!records.isEmpty())
    {
        m_record = records.at(0);
    }else
    {
        clear();
    }
}

void client::setDateDeNaissance(QDate date)
{
    m_record.setValue(Client::Id::DateDeNaissance, date);
    tableModifiee(true);
}

void client::setLieuDeNaissance(QString lieu)
{
    m_record.setValue(Client::Id::LieuDeNaissance, lieu);
    tableModifiee(true);
}

void client::setPere(QString nom)
{
    m_record.setValue(Client::Id::Pere, nom);
    tableModifiee(true);
}

void client::setMere(QString nom)
{
    m_record.setValue(Client::Id::Mere, nom);
    tableModifiee(true);
}

void client::setProfession(QString nom)
{
    m_record.setValue(Client::Id::Profession, nom);
    tableModifiee(true);
}

void client::setDomicileHabituel(QString domicile)
{
    m_record.setValue(Client::Id::DomicileHabituel, domicile);
    tableModifiee(true);
}

void client::setNationalite(QString nationalite)
{
    m_record.setValue(Client::Id::Nationalite, nationalite);
    tableModifiee(true);
}
