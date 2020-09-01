#include "pieceIdentiteClient.h"

pieceIdentiteClient::pieceIdentiteClient()
{
    constructeur();
}

pieceIdentiteClient::pieceIdentiteClient(const pieceIdentiteClient &s)
{
    constructeur(s);
}

pieceIdentiteClient::pieceIdentiteClient(const QSqlRecord &record)
{
    constructeur(record);
}

pieceIdentiteClient::pieceIdentiteClient(int id)
{
    constructeur(id);
}

QVariant pieceIdentiteClient::cle() const
{
    return idPieceIdentite();
}

QString pieceIdentiteClient::libelleDeCle() const
{
    return m_record.fieldName(PieceIdentiteClient::Id::IdPieceIdentiteClient);
}

QString pieceIdentiteClient::tableName() const
{
    return PieceIdentiteClient::Libelle;
}

int pieceIdentiteClient::idPieceIdentite()const
{
    return m_record.value(PieceIdentiteClient::Id::IdPieceIdentiteClient).toInt();
}

QString pieceIdentiteClient::nature()const
{
    return m_record.value(PieceIdentiteClient::Id::Nature).toString();
}

QDate pieceIdentiteClient::dateDelivrance()const
{
    return m_record.value(PieceIdentiteClient::Id::DateDelivrance).toDate();
}

QString pieceIdentiteClient::lieuDelivrance()const
{
    return m_record.value(PieceIdentiteClient::Id::LieuDelivrance).toString();
}

QString pieceIdentiteClient::agentDelivreur()const
{
    return m_record.value(PieceIdentiteClient::Id::AgentDelivreur).toString();
}

QDate pieceIdentiteClient::dateReception()const
{
    return m_record.value(PieceIdentiteClient::Id::DateReception).toDate();
}

QString pieceIdentiteClient::numero()const
{
     return m_record.value(PieceIdentiteClient::Id::Numero).toString();
}

int pieceIdentiteClient::numOccupation()const
{
     return m_record.value(PieceIdentiteClient::Id::CodeClient).toInt();
}

int pieceIdentiteClient::codeClient()const
{
     return m_record.value(PieceIdentiteClient::Id::CodeClient).toInt();
}

void pieceIdentiteClient::setNature(QString nature)
{
    m_record.setValue(PieceIdentiteClient::Id::Nature, nature);
    tableModifiee(true);
}

void pieceIdentiteClient::setNumero(QString numero)
{
    m_record.setValue(PieceIdentiteClient::Id::Numero, numero);
    tableModifiee(true);
}

void pieceIdentiteClient::setLieuDelivrance(QString lieu)
{
    m_record.setValue(PieceIdentiteClient::Id::LieuDelivrance, lieu);
    tableModifiee(true);
}

void pieceIdentiteClient::setDateReception(QDate date)
{
    m_record.setValue(PieceIdentiteClient::Id::DateReception, date);
    tableModifiee(true);
}

void pieceIdentiteClient::setNumOccupation(int numOccup)
{
    m_record.setValue(PieceIdentiteClient::Id::NumOccupation, numOccup);
    tableModifiee(true);
}

void pieceIdentiteClient::setDateDelivrance(QDate date)
{
    m_record.setValue(PieceIdentiteClient::Id::DateDelivrance, date);
    tableModifiee(true);
}

void pieceIdentiteClient::setCodeClient(int code)
{
    m_record.setValue(PieceIdentiteClient::Id::CodeClient, code);
    tableModifiee(true);
}

void pieceIdentiteClient::setAgentDelivreur(QString nom)
{
    m_record.setValue(PieceIdentiteClient::Id::AgentDelivreur, nom);
    tableModifiee(true);
}

QList<QSqlRecord> pieceIdentiteClient::pic_records(int codeClient)
{
    pieceIdentiteClient p;
    QString condition = QObject::tr("%1 = %2")
                        .arg(p.codeClientName())
                        .arg(codeClient);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(Client::Libelle, condition);

    return records;
}

pieceIdentiteClient pieceIdentiteClient::selectionnerPieceDuClient(int numOccupation)
{
    pieceIdentiteClient p;
    QString condition = QObject::tr("%1 = %2")
                        .arg(p.numOccupName())
                        .arg(numOccupation);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(PieceIdentiteClient::Libelle, condition);

    if(records.isEmpty())
        return pieceIdentiteClient();

    return pieceIdentiteClient(records.first());
}
