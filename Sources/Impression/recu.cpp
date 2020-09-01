#include "recu.h"

recu::recu(const operationService &op)
{
    m_infosHotel = infosHotel(1);

    m_op = op;
    m_view = new QGraphicsView();

    m_scene = new QGraphicsScene();
    m_view->setScene(m_scene);

    m_image = new QGraphicsPixmapItem(QPixmap(":/images/reçu.png"));
    m_scene->addItem(m_image);

    m_logo = new QGraphicsPixmapItem(m_infosHotel.logo());
    m_scene->addItem(m_logo);
    qreal scale = 100 / m_logo->boundingRect().width();

    m_logo->setScale(scale);
    m_logo->setPos(900, 200);

    m_view->setFixedSize(m_scene->width() + 15, m_scene->height() + 15);

    m_x0 = m_image->x();
    m_y0 = m_image->y();

    m_abscisses << 250
                << 250
                << 250
                << 740
                << 213
                << 900
                << 900
                << 900
                << 900
                << 740
                << 300
                << 90
                << 580
                << 772
                << 940
                << 740;

   m_ordonnees << 390
               << 418
               << 445
               << 460
               << 145
               << 260
               << 280
               << 300
               << 320
               << 430
               << 501
               << 614
               << 614
               << 614
               << 614
               << 490;

    for(int i = 0; i < m_abscisses.count(); i++)
    {
        m_items[i] = new QGraphicsTextItem();
        QFont f;
        f.setFamily("Garamond");
        f.setPointSize(14);
        m_items[i]->setFont(f);

        if(i == Contact || i == NomClient || i == Profession)
        {
            // agrandir le caractère
            QFont f1;
            f1.setPointSize(14);
            f1.setBold(true);
            m_items[i]->setFont(f1);
        }

        if(i == NomHotel)
        {
            // agrandir le caractère
            QFont f;
            f.setFamily("Verdana");
            f.setPointSize(18);
            m_items[i]->setFont(f);
        }

        m_scene->addItem(m_items[i]);
        m_items[i]->setPos(m_x0 + m_abscisses.at(i), m_y0 + m_ordonnees.at(i));
    }

    construireRecu();
}

recu::~recu()
{
    delete m_view;
}

void recu::setText(Champ champ, QString valeur)
{
    m_items[champ]->setPlainText(valeur);
}

void recu::setText(Champ champ, QString valeur, int position)
{
    m_items[champ + 5 * (position - 1)]->setPlainText(valeur);
}

void recu::construireRecu()
{
    QDate now = Horloge::currentDate();

    setText(NumFacture, m_op.recu());
    setText(DateFacture, now.toString(Qt::SystemLocaleDate));

    int montantVerse = m_op.montantEncaisse();
    int montantRestant = 0;
    QString mode = modeDePayement(m_op.idModeDePayement()).mode();
    int idOp = m_op.idTypeOperation();
    int idClient = 0;
    int idGroupe = 0;

    occupation oc;
    repasCompletResto rcr;
    reservation rv;

    switch(m_op.idTypeRecu())
    {
    case recuInitial::IdLocation:
        if(m_op.libelle().contains("groupe"))
        {
            groupe gp(idOp);
            idGroupe = idOp;
            montantRestant = gp.resteFraisLocation() + gp.resteFraisSup();
        }else
        {
            oc = occupation(idOp);
            montantRestant = oc.reste();
            idClient = oc.codeClient();
        }
        break;
    case recuInitial::IdReservation:
        if(m_op.libelle().contains("groupe"))
        {
            idGroupe = idOp;
        }else
        {
            rv = reservation(idOp);
            idClient = rv.codeClient();
        }
        break;
    case recuInitial::IdRestauration:
        if(m_op.libelle().contains("groupe"))
        {
            groupe gp(idOp);
            idGroupe = idOp;
            montantRestant = gp.fraisRestoNonPayes();
        }else
        {
            rcr = repasCompletResto(idOp);
            montantRestant = rcr.reste();
            idClient = rcr.codeClient();
        }
        break;
    case recuInitial::IdRestitutionRestauration:
        if(m_op.libelle().contains("groupe"))
        {
            idGroupe = idOp;
        }else
        {
            rcr = repasCompletResto(idOp);
            idClient = rcr.codeClient();
        }
        break;
    case recuInitial::IdRestitutionLocation:
        if(m_op.libelle().contains("groupe"))
        {
            idGroupe = idOp;
        }else
        {
            oc = occupation(idOp);
            idClient = oc.codeClient();
        }
        break;
    default:
        // depot ou retrait sur compte client
        int idCompteClient = operationCompteClient(idOp).idCompteClient();
        idClient = compteClient(idCompteClient).codeClient();
    }

    setText(MontantVerse   , MesTables::moneyToString(montantVerse));
    setText(MontantRestant , MesTables::moneyToString(montantRestant));
    setText(ModeDePaye     , mode);
    setText(NomHotel       , m_infosHotel.nom().toUpper());
    setText(SituationGeo   , m_infosHotel.situationGeo());
    setText(BPHotel        , m_infosHotel.bp());
    setText(TelHotel       , QString("Tél : %1").arg(m_infosHotel.numeroTel()));
    setText(Objet          , m_op.libelle());
    setText(Matricule      , m_op.matriculeAgent());

    if(!m_infosHotel.siteWeb().isEmpty())
    {
        setText(SiteWeb    , QString("Site Web : %1").arg(m_infosHotel.siteWeb()));
    }

    QString nomClient;
    QString contact;
    QString profession;

    if(m_op.libelle().contains("groupe"))
    {
        groupe gp(idGroupe);
        nomClient = gp.libelle();
        client cl(gp.idResponsable());
        if(cl.tel().isEmpty())
        {
            contact = cl.tel();
        }else
        {
            contact = cl.cel();
        }

        setText(CodeClient, QString("GP %1").arg(idGroupe));
    }else
    {
        client cl(idClient);

        nomClient = cl.nomComplet();
        contact = cl.cel();
        profession = cl.profession();

        setText(CodeClient, QString("CL %1").arg(cl.codeDuClient()));
    }

    setText(NomClient      , nomClient);
    setText(Contact        , contact);
    setText(Profession     , profession);
}
