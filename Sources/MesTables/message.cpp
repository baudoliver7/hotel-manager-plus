#include "message.h"

message::message()
{
    constructeur();
}

message::message(const QSqlRecord &record)
{
    constructeur(record);
}

message::message(const message & s)
{
    constructeur(s);
}

message::message(int NumMsg)
{
    constructeur(NumMsg);
}

void message::setContenu(QString contenu)
{
    m_record.setValue(Message::Id::Contenu, contenu);
    tableModifiee(true);
}

void message::setDestinateur(QString matricule)
{
    m_record.setValue(Message::Id::Destinataire, matricule);
    tableModifiee(true);
}

void message::setExpediteur(QString matricule)
{
    m_record.setValue(Message::Id::Expediteur, matricule);
    tableModifiee(true);
}

void message::setHeuredEnvoi(QDateTime heure)
{
    m_record.setValue(Message::Id::HeureEnvoi, heure);
    tableModifiee(true);
}

void message::setLue(bool lue)
{
    m_record.setValue(Message::Id::Lue, lue);
    tableModifiee(true);
}

int message::numMsg()const
{
    return m_record.value(Message::Id::NumMsg).toInt();
}

QString message::contenu()const
{
    return m_record.value(Message::Id::Contenu).toString();
}

QString message::expediteur()const
{
    return m_record.value(Message::Id::Expediteur).toString();
}

QString message::destinateur()const
{
    return m_record.value(Message::Id::Destinataire).toString();
}

QDateTime message::heuredEnvoi()const
{
    return m_record.value(Message::Id::HeureEnvoi).toDateTime();
}

bool message::lue()const
{
    return m_record.value(Message::Id::Contenu).toBool();
}

QVariant message::cle() const
{
    return numMsg();
}

QString message::libelleDeCle() const
{
    return m_record.fieldName(Message::Id::NumMsg);
}

QString message::tableName() const
{
    return Message::Libelle;
}
