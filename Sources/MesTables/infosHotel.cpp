#include "infosHotel.h"

infosHotel::infosHotel()
{
    constructeur();
}

infosHotel::infosHotel(const infosHotel &s)
{
    constructeur(s);
}

infosHotel::infosHotel(const QSqlRecord &record)
{
    constructeur(record);
}

infosHotel::infosHotel(int id)
{
    constructeur(id);
}

QVariant infosHotel::cle() const
{
    return idInfosHotel();
}

QString infosHotel::libelleDeCle() const
{
    return m_record.fieldName(InfosHotel::Id::IdInfosHotel);
}

QString infosHotel::tableName() const
{
    return InfosHotel::Libelle;
}

int infosHotel::idInfosHotel()const
{
    return m_record.value(InfosHotel::Id::IdInfosHotel).toInt();
}

int infosHotel::numRecu()const
{
    return m_record.value(InfosHotel::Id::NumRecu).toInt();
}

QString infosHotel::nom()const
{
    return m_record.value(InfosHotel::Id::Nom).toString();
}

QString infosHotel::situationGeo()const
{
    return m_record.value(InfosHotel::Id::SituationGeo).toString();
}

QString infosHotel::numeroCel()const
{
    return m_record.value(InfosHotel::Id::NumeroCel).toString();
}

QString infosHotel::numeroTel()const
{
    return m_record.value(InfosHotel::Id::NumeroTel).toString();
}

QString infosHotel::email()const
{
    return m_record.value(InfosHotel::Id::Email).toString();
}

QString infosHotel::bp()const
{
    return m_record.value(InfosHotel::Id::BP).toString();
}

QString infosHotel::siteWeb()const
{
    return m_record.value(InfosHotel::Id::SiteWeb).toString();
}

QString infosHotel::ville()const
{
    return m_record.value(InfosHotel::Id::Ville).toString();
}

QPixmap infosHotel::logo()const
{
    QPixmap p;
    p.loadFromData(m_record.value(InfosHotel::Id::Logo).toByteArray());
    return p;
}

void infosHotel::setNom(QString nom)
{
    m_record.setValue(InfosHotel::Id::Nom, nom);
    tableModifiee(true);
}

void infosHotel::setNumeroCel(QString cel)
{
    m_record.setValue(InfosHotel::Id::NumeroCel, cel);
    tableModifiee(true);
}

void infosHotel::setNumeroTel(QString tel)
{
    m_record.setValue(InfosHotel::Id::NumeroTel, tel);
    tableModifiee(true);
}

void infosHotel::setSituationGeo(QString lieu)
{
    m_record.setValue(InfosHotel::Id::SituationGeo, lieu);
    tableModifiee(true);
}

void infosHotel::setEmail(QString email)
{
    m_record.setValue(InfosHotel::Id::Email, email);
    tableModifiee(true);
}

void infosHotel::setBP(QString bp)
{
    m_record.setValue(InfosHotel::Id::BP, bp);
    tableModifiee(true);
}

void infosHotel::setSiteWeb(QString site)
{
    m_record.setValue(InfosHotel::Id::SiteWeb, site);
    tableModifiee(true);
}

void infosHotel::setVille(QString ville)
{
    m_record.setValue(InfosHotel::Id::Ville, ville);
    tableModifiee(true);
}

void infosHotel::setNumRecu(int recu)
{
    m_record.setValue(InfosHotel::Id::NumRecu, recu);
    tableModifiee(true);
}

void infosHotel::setLogo(QString fileName)
{
    QPixmap p(fileName);
    QPixmap pixmap = p.scaledToHeight(60);
    QByteArray bytes;
    QBuffer buffer(&bytes);
    buffer.open(QIODevice::WriteOnly);
    pixmap.save(&buffer, "PNG");
    m_record.setValue(InfosHotel::Id::Logo, bytes);
    tableModifiee(true);
}

void infosHotel::setContacts(QString contacts)
{
    QStringList listeDeContacts = contacts.split("|");
    if(listeDeContacts.first() != contacts)
    {
        setNumeroCel(listeDeContacts.at(0));
        setNumeroTel(listeDeContacts.at(1));
        setEmail(listeDeContacts.at(2));
        setBP(listeDeContacts.at(3));
        tableModifiee(true);
    }
}

QString infosHotel::contacts()const
{
    return (numeroCel()+ "|"
            +numeroTel()+"|"
            +email()+"|"
            +bp());
}
