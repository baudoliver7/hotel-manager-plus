#ifndef CHAMBRE_H
#define CHAMBRE_H

#include "MesTables_global.h"

/* classes qt */
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QAction>
#include <QMenu>
#include <QGraphicsSceneContextMenuEvent>
#include <QDate>
#include <QTimer>
#include "occupation.h"
#include "recevoirOccup.h"
#include "client.h"
#include "typeDeChambre.h"

/* classes personnalisées */
#include "Entree.h"

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
QT_END_NAMESPACE


class occupation;
class passe;

class MESTABLESSHARED_EXPORT chambre : public QObject, public QGraphicsPixmapItem, public Entree
{
    Q_OBJECT
public:
    enum {Type = UserType + 1};

    bool operator==(const chambre & ch)const;
    bool operator==(const chambre * ch)const;

signals:
    void liberer(chambre ch);

public:
    chambre(QWidget * parent = 0);
    chambre(const QString & identifiant, QWidget * parent = 0);
    chambre(const QSqlRecord & record, QWidget * parent = 0);
    chambre(const chambre & ch);
    ~chambre();

    void actualiser();

    bool libre()const;
    int type() const;

    inline QGraphicsTextItem * textItem(){return m_textItem;};

    void setVisible(bool visible);
    void setPos(qreal x, qreal y);

    void setIdentifiant(QString identifiant);
    void setIdTypeChambre(int id);
    void setHorsService(bool HS);
    void setOccupee(bool occupee);
    void setIdEtage(int id);

    inline QString identifiantName()const{return m_fieldsName.at(Chambre::Id::Identifiant);};
    inline QString idTypeChambreName()const{return m_fieldsName.at(Chambre::Id::IdTypeChambre);};
    inline QString horsServiceName()const{return m_fieldsName.at(Chambre::Id::HorsService);};
    inline QString occupeeName()const{return m_fieldsName.at(Chambre::Id::Occupee);};
    inline QString idEtageName()const{return m_fieldsName.at(Chambre::Id::IdEtage);};

    QString identifiant()const;
    int idTypeChambre()const;
    bool horsService()const;
    bool occupee()const;
    int idEtage()const;

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

protected:

    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

private:
    void MouseOver(bool over);

private:
    QGraphicsTextItem * m_textItem;
    QString m_type;
    QWidget * m_parent;
    bool m_datePassee;

    static QTimer * s_timer;
    void actualiserEtat();

public slots:
    void clignoter();

public:
    static bool m_pile;
    static QList<QSqlRecord> chambresDeCeType(int idType);
    static QList<QSqlRecord> chambresDeCeTypeLibres(int idType);
    static QList<QSqlRecord> chambresDeCeTypeOccupees(int idType);
};

#endif // CHAMBRE_H
