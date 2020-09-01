#ifndef CLIENT_H
#define CLIENT_H

#include "MesTables_global.h"

#include "Entree.h"
#include "occupation.h"
#include "recevoirOccup.h"

class MESTABLESSHARED_EXPORT client: public Entree
{
public:
    enum Contacts
    {
        Cel = 0, Tel = 1, Email = 2, BoitePostale = 3
    };

public:
    client();
    client(int codeClient);
    client(const QSqlRecord & record);
    client(const client & cl);

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

    int codeDuClient()const;
    QString nom()const;
    QString prenoms()const;
    bool homme()const;
    QDate dateDeNaissance()const;
    QString lieuDeNaissance()const;
    QString pere()const;
    QString mere()const;
    QString profession()const;
    QString domicileHabituel()const;
    QString nationalite()const;
    QString contacts()const;
    QString cel()const;
    QString tel()const;
    QString email()const;
    QString boitePostale()const;
    QString nomComplet()const;

    inline QString codeDuClientName()const{return m_fieldsName.at(Client::Id::CodeClient);};
    inline QString nomName()const{return m_fieldsName.at(Client::Id::Nom);};
    inline QString prenomsName()const{return m_fieldsName.at(Client::Id::Prenoms);};
    inline QString hommeName()const{return m_fieldsName.at(Client::Id::Homme);};
    inline QString celName()const{return m_fieldsName.at(Client::Id::Cel);};
    inline QString telName()const{return m_fieldsName.at(Client::Id::Tel);};
    inline QString emailName()const{return m_fieldsName.at(Client::Id::Email);};
    inline QString boitePostaleName()const{return m_fieldsName.at(Client::Id::BP);};
    inline QString dateDeNaissanceName()const{return m_fieldsName.at(Client::Id::DateDeNaissance);};
    inline QString lieuDeNaissanceName()const{return m_fieldsName.at(Client::Id::LieuDeNaissance);};
    inline QString pereName()const{return m_fieldsName.at(Client::Id::Pere);};
    inline QString mereName()const{return m_fieldsName.at(Client::Id::Mere);};
    inline QString professionName()const{return m_fieldsName.at(Client::Id::Profession);};
    inline QString domocileHabituelName()const{return m_fieldsName.at(Client::Id::DomicileHabituel);};
    inline QString nationaliteName()const{return m_fieldsName.at(Client::Id::Nationalite);};

    void setNom(QString nom);
    void setPrenoms(QString prenoms);
    void setHomme(bool homme);
    void setContacts(QString contacts);
    void setCel(QString cel);
    void setTel(QString tel);
    void setEmail(QString email);
    void setBoitePostale(QString boitePostale);
    void setCode(int code);
    void setDateDeNaissance(QDate date);
    void setLieuDeNaissance(QString lieu);
    void setPere(QString nom);
    void setMere(QString nom);
    void setProfession(QString nom);
    void setDomicileHabituel(QString domicile);
    void setNationalite(QString nationalite);


public:
     static QString contacts(QString cel, QString tel, QString email, QString bp);
     static QStringList listeDeContacts(QString contacts);
};

#endif // CLIENT_H
