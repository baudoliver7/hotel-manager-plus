#include "chambre.h"

bool chambre::m_pile = true;
QTimer * chambre::s_timer = new QTimer();

bool chambre::operator ==(const chambre & ch)const
{
    return ch.identifiant() == identifiant();
}

bool chambre::operator ==(const chambre * ch)const
{
    return ch->identifiant() == identifiant();
}

chambre::chambre(QWidget *parent)
{
    constructeur();

    m_parent = parent;
    m_datePassee = false;
    this->setAcceptsHoverEvents(true);
    this->setCursor(Qt::ArrowCursor);
    m_textItem  = new QGraphicsTextItem(QString());
    QFont font = m_textItem->font();
    font.setBold(true);
    m_textItem->setFont(font);

    m_type = QString();
    this->setPixmap(QPixmap(":/images/chambre libre clickée.png"));
}

chambre::chambre(const QString &identifiant, QWidget *parent)
{
    constructeur(identifiant);

    m_parent = parent;
    m_datePassee = false;
    this->setAcceptHoverEvents(true);
    this->setCursor(Qt::ArrowCursor);
    m_textItem  = new QGraphicsTextItem(this->identifiant());
    QFont font = m_textItem->font();
    font.setBold(true);
    m_textItem->setFont(font);
    //actualiserEtat();

    tableModifiee(false);
}

chambre::chambre(const QSqlRecord &record, QWidget *parent)
{
    constructeur(record);

    m_parent = parent;
    m_datePassee = false;
    this->setAcceptHoverEvents(true);
    this->setCursor(Qt::ArrowCursor);
    m_textItem  = new QGraphicsTextItem(identifiant());
    QFont font = m_textItem->font();
    font.setBold(true);
    m_textItem->setFont(font);
    //actualiserEtat();

    tableModifiee(false);
}

chambre::chambre(const chambre &ch)
{
    constructeur(ch);

    m_parent = ch.m_parent;
    m_datePassee = ch.m_datePassee;
    this->setAcceptHoverEvents(true);
    m_textItem = new QGraphicsTextItem(ch.m_textItem);
    QFont font = m_textItem->font();
    font.setBold(true);
    m_textItem->setFont(font);
    this->setCursor(Qt::ArrowCursor);
    //actualiserEtat();
}

chambre::~chambre()
{
    delete m_textItem;
    disconnect(this, SLOT(clignoter()));
}

void chambre::actualiser()
{
    Entree::actualiser();
    //actualiserEtat();
}

bool chambre::libre()const
{
    return !occupee();
}

int chambre::type()const
{
    return Type;
}

void chambre::actualiserEtat()
{
    m_datePassee = false;

    if(occupee())
    {
        this->setPixmap(QPixmap(":/images/chambre occupée clickée.png"));
        QString occupant;
        QString heureDEntree;
        QString heureDeSortie;

        occupation oc(*this);
        if(oc.existe())
        {
            client cl (recevoirOccup::selectionner(oc.numOccupation()).codeClient());
            occupant = cl.nom() + " " + cl.prenoms();

            if(oc.datedEntree().date() == Horloge::currentDate())
            {
                heureDEntree = QObject::tr("aujourd'hui à %1").arg(oc.datedEntree().time().toString("HH:mm"));
            }else
            {
                if(oc.datedEntree().date() == Horloge::currentDate().addDays(1))
                {
                    heureDEntree = QObject::tr("demain à %1").arg(oc.datedEntree().time().toString("HH:mm"));
                }else
                {
                    if(oc.datedEntree().date() == Horloge::currentDate().addDays(-1))
                    {
                        heureDEntree = QObject::tr("hier à %1").arg(oc.datedEntree().time().toString("HH:mm"));
                    }else
                    {
                        heureDEntree = oc.datedEntree().toString(Qt::SystemLocaleLongDate);
                    }
                }
            }

            if(oc.datedSortie().date() == Horloge::currentDate())
            {
                heureDeSortie = QObject::tr("aujourd'hui à %1").arg(oc.datedSortie().time().toString("HH:mm"));
            }else
            {
                if(oc.datedSortie().date() == Horloge::currentDate().addDays(1))
                {
                    heureDeSortie = QObject::tr("demain à %1").arg(oc.datedSortie().time().toString("HH:mm"));
                }else
                {
                    if(oc.datedSortie().date() == Horloge::currentDate().addDays(-1))
                    {
                        heureDeSortie = QObject::tr("hier à %1").arg(oc.datedSortie().time().toString("HH:mm"));
                    }else
                    {
                        heureDeSortie = oc.datedSortie().toString(Qt::SystemLocaleLongDate);
                    }
                }
            }

            if(oc.datedSortie() < Horloge::currentDateTime())
            {
                heureDeSortie.append(" (date passée)");
                m_datePassee = true;

                //connect(s_timer, SIGNAL(timeout()), this, SLOT(clignoter()));
            }
        }

        setToolTip(QObject::tr(" Locataire : %1 \n Date d'entrée : %2 \n Date de sortie : %3").arg(occupant).arg(heureDEntree).arg(heureDeSortie));
    }else
    {
        setToolTip(QString());
        this->setPixmap(QPixmap(":/images/chambre libre clickée.png"));
    }

    // programmer après
    m_type = QString();
}

void chambre::clignoter()
{
   if(m_datePassee)
   {
        if(m_pile)
       {
           // pile
           setPixmap(QPixmap(":/images/chambre occupée clickée.png"));
       }else
       {
           // face
           setPixmap(QPixmap(":/images/chambre occupée.png"));
       }
   }
}

void chambre::MouseOver(bool over)
{
    if(over)
    {
        if(occupee())
        {
            this->setPixmap(QPixmap(":/images/chambre occupée.png"));
        }

        if(libre())
        {
            this->setPixmap(QPixmap(":/images/chambre libre.png"));
        }

    }else
    {
        if(occupee())
        {
            this->setPixmap(QPixmap(":/images/chambre occupée clickée.png"));
        }

        if(libre())
        {
            this->setPixmap(QPixmap(":/images/chambre libre clickée.png"));
        }
    }
}

void chambre::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    this->MouseOver(true);
}

void chambre::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    this->MouseOver(false);
}

void chambre::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
//    if(this->occupee())
//    {
//        QMenu menu;
//    //    QAction *occuperAction = menu.addAction("Occuper");
//    //    QAction *reserverAction = menu.addAction("Réserver");
//        //QAction *libererAction = menu.addAction("Libérer");
//        menu.addAction("Libérer");
//    //
//    //    if(!m_libre)
//    //    {
//    //        occuperAction->setEnabled(false);
//    //    }else
//    //    {
//    //        libererAction->setEnabled(false);
//    //    }
//    //
//        QAction *selectedAction = menu.exec(event->screenPos());
//
//        if(selectedAction)
//        {
//            emit liberer(*this);
//        }
//    }
}

void chambre::setVisible(bool visible)
{
    QGraphicsPixmapItem::setVisible(visible);
    m_textItem->setVisible(visible);
}

void chambre::setPos(qreal x, qreal y)
{
    QGraphicsPixmapItem::setPos(x,y);
    double c_x = x + sceneBoundingRect().width()/2 - m_textItem->sceneBoundingRect().width()/2;
    double c_y = y + sceneBoundingRect().height()/2;
    m_textItem->setPos(c_x,c_y);
}

QString chambre::identifiant()const
{
    return m_record.value(Chambre::Id::Identifiant).toString();
}

bool chambre::horsService()const
{
    return m_record.value(Chambre::Id::HorsService).toBool();
}

bool chambre::occupee()const
{
    return m_record.value(Chambre::Id::Occupee).toBool();
}

int chambre::idTypeChambre()const
{
    return m_record.value(Chambre::Id::IdTypeChambre).toInt();
}

int chambre::idEtage()const
{
    return m_record.value(Chambre::Id::IdEtage).toInt();
}

void chambre::setIdentifiant(QString identifiant)
{
    m_record.setValue(Chambre::Id::Identifiant, identifiant);
    m_textItem->setPlainText(identifiant);
    tableModifiee(true);
}

void chambre::setIdTypeChambre(int id)
{
    m_record.setValue(Chambre::Id::IdTypeChambre, id);
    tableModifiee(true);
}

void chambre::setIdEtage(int id)
{
    m_record.setValue(Chambre::Id::IdEtage, id);
    tableModifiee(true);
}

void chambre::setHorsService(bool HS)
{
    m_record.setValue(Chambre::Id::HorsService, HS);
    tableModifiee(true);
}

void chambre::setOccupee(bool occupee)
{
    m_record.setValue(Chambre::Id::Occupee, occupee);
    tableModifiee(true);
}

QVariant chambre::cle() const
{
    return identifiant();
}

QString chambre::libelleDeCle() const
{
    return m_record.fieldName(Chambre::Id::Identifiant);
}

QString chambre::tableName() const
{
    return Chambre::Libelle;
}

QList<QSqlRecord> chambre::chambresDeCeType(int idType)
{
    chambre ch;
    QString condition = QObject::tr("%1 = %2")
                        .arg(ch.idTypeChambreName())
                        .arg(idType);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(Chambre::Libelle, condition);

    return records;
}

QList<QSqlRecord> chambre::chambresDeCeTypeLibres(int idType)
{
    chambre ch;
    typeDeChambre t;
    QString condition1 = QObject::tr("%1 = %2")
                        .arg(ch.idTypeChambreName())
                        .arg(idType);

    QString condition = QObject::tr("%1 = %2 AND %3 = %4 AND %5 IN (SELECT %6 FROM %7 WHERE %8 = %9) AND %10")
                        .arg(ch.horsServiceName())
                        .arg(false)
                        .arg(ch.occupeeName())
                        .arg(false)
                        .arg(ch.idTypeChambreName()) // voir si son type est disponible
                        .arg(t.idTypeDeChambreName())
                        .arg(t.tableName())
                        .arg(t.disponibleName())
                        .arg(true)
                        .arg(condition1);

    return InfosSurBD::enregistrements(Chambre::Libelle, condition);
}

QList<QSqlRecord> chambre::chambresDeCeTypeOccupees(int idType)
{
    chambre ch;
    typeDeChambre t;
    QString condition1 = QObject::tr("%1 = %2")
                        .arg(ch.idTypeChambreName())
                        .arg(idType);

    QString condition = QObject::tr("%1 = %2 AND %3 = %4 AND %5 IN (SELECT %6 FROM %7 WHERE %8 = %9) AND %10")
                        .arg(ch.horsServiceName())
                        .arg(false)
                        .arg(ch.occupeeName())
                        .arg(true)
                        .arg(ch.idTypeChambreName()) // voir si son type est disponible
                        .arg(t.idTypeDeChambreName())
                        .arg(t.tableName())
                        .arg(t.disponibleName())
                        .arg(true)
                        .arg(condition1);

    return InfosSurBD::enregistrements(Chambre::Libelle, condition);
}
