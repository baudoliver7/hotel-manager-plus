#ifndef PIECEIDENTITECLIENT_H
#define PIECEIDENTITECLIENT_H

#include "MesTables_global.h"

#include <QTime>
#include <QDateTime>

#include "Entree.h"

class MESTABLESSHARED_EXPORT pieceIdentiteClient : public Entree
{
public:
    pieceIdentiteClient();
    pieceIdentiteClient(int id);
    pieceIdentiteClient(const QSqlRecord & record);
    pieceIdentiteClient(const pieceIdentiteClient & infos);

    void setNature(QString nature);
    void setNumero(QString numero);
    void setDateDelivrance(QDate date);
    void setLieuDelivrance(QString lieu);
    void setAgentDelivreur(QString nom);
    void setCodeClient(int code);
    void setDateReception(QDate date);
    void setNumOccupation(int numOccup);

    int idPieceIdentite()const;
    QString nature()const;
    QString numero()const;
    QDate dateDelivrance()const;
    QString lieuDelivrance()const;
    QString agentDelivreur()const;
    int codeClient()const;
    QDate dateReception()const;
    int numOccupation()const;

    inline QString idPieceIdentiteName()const{return m_fieldsName.at(PieceIdentiteClient::Id::IdPieceIdentiteClient);};
    inline QString natureName()const{return m_fieldsName.at(PieceIdentiteClient::Id::Nature);};
    inline QString dateDelivranceName()const{return m_fieldsName.at(PieceIdentiteClient::Id::DateDelivrance);};
    inline QString lieuDelivranceName()const{return m_fieldsName.at(PieceIdentiteClient::Id::LieuDelivrance);};
    inline QString agentDelivreurName()const{return m_fieldsName.at(PieceIdentiteClient::Id::AgentDelivreur);};
    inline QString codeClientName()const{return m_fieldsName.at(PieceIdentiteClient::Id::CodeClient);};
    inline QString dateReceptionName()const{return m_fieldsName.at(PieceIdentiteClient::Id::DateReception);};
    inline QString numOccupName()const{return m_fieldsName.at(PieceIdentiteClient::Id::NumOccupation);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

public:
    static QList<QSqlRecord> pic_records(int codeClient);
    static pieceIdentiteClient selectionnerPieceDuClient(int numOccupation);
};

#endif // PIECEIDENTITECLIENT_H
