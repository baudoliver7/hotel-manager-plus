#ifndef INFOSHOTEL_H
#define INFOSHOTEL_H

#include "MesTables_global.h"

#include <QTime>
#include <QDateTime>
#include <QPixmap>
#include <QBuffer>

#include "Entree.h"

class MESTABLESSHARED_EXPORT infosHotel : public Entree
{
public:
    infosHotel();
    infosHotel(int id);
    infosHotel(const QSqlRecord & record);
    infosHotel(const infosHotel & infos);

    void setNom(QString nom);
    void setSituationGeo(QString lieu);
    void setNumeroTel(QString tel);
    void setNumeroCel(QString cel);
    void setEmail(QString email);
    void setBP(QString bp);
    void setSiteWeb(QString site);
    void setLogo(QString fileName);
    void setVille(QString ville);
    void setNumRecu(int recu);
    void setContacts(QString contacts);

    int idInfosHotel()const;
    QString nom()const;
    QString situationGeo()const;
    QString numeroTel()const;
    QString numeroCel()const;
    QString email()const;
    QString bp()const;
    QString siteWeb()const;
    QPixmap logo()const;
    QString ville()const;
    int numRecu()const;
    QString contacts()const;

    inline QString idInfosHotelName()const{return m_fieldsName.at(InfosHotel::Id::IdInfosHotel);};
    inline QString nomName()const{return m_fieldsName.at(InfosHotel::Id::Nom);};
    inline QString situationGeoName()const{return m_fieldsName.at(InfosHotel::Id::SituationGeo);};
    inline QString numeroTelName()const{return m_fieldsName.at(InfosHotel::Id::NumeroTel);};
    inline QString numeroCelName()const{return m_fieldsName.at(InfosHotel::Id::NumeroCel);};
    inline QString emailName()const{return m_fieldsName.at(InfosHotel::Id::Email);};
    inline QString bpName()const{return m_fieldsName.at(InfosHotel::Id::BP);};
    inline QString siteWebName()const{return m_fieldsName.at(InfosHotel::Id::SiteWeb);};
    inline QString villeName()const{return m_fieldsName.at(InfosHotel::Id::Ville);};
    inline QString numRecuName()const{return m_fieldsName.at(InfosHotel::Id::NumRecu);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin
};

#endif // INFOSHOTEL_H
