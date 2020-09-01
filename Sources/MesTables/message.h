#ifndef MESSAGE_H
#define MESSAGE_H

#include "MesTables_global.h"

#include <QDateTime>
#include "Entree.h"

class MESTABLESSHARED_EXPORT message : public Entree
{
public:
    message();
    message(int NumMsg);
    message(const QSqlRecord & record);
    message(const message & s);

    int numMsg()const;
    QString contenu()const;
    QString expediteur()const;
    QString destinateur()const;
    QDateTime heuredEnvoi()const;
    bool lue()const;

    void setContenu(QString contenu);
    void setExpediteur(QString matricule);
    void setDestinateur(QString matricule);
    void setHeuredEnvoi(QDateTime heure);
    void setLue(bool lue);

    inline QString numMsgName()const{return m_fieldsName.at(Message::Id::NumMsg);};
    inline QString contenuName()const{return m_fieldsName.at(Message::Id::Contenu);};
    inline QString expediteurName()const{return m_fieldsName.at(Message::Id::Expediteur);};
    inline QString destinataireName()const{return m_fieldsName.at(Message::Id::Destinataire);};
    inline QString heuredEnvoiName()const{return m_fieldsName.at(Message::Id::HeureEnvoi);};
    inline QString lueName()const{return m_fieldsName.at(Message::Id::Lue);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin
};

#endif // MESSAGE_H
