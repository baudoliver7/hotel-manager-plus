#include "factureHotelIndividu.h"

factureHotelIndividu::factureHotelIndividu(const occupation & oc)
{
    m_infosHotel = infosHotel(1);

    m_occup = oc;
    m_view = new QGraphicsView();

    m_scene = new QGraphicsScene();
    m_view->setScene(m_scene);

    m_image = new QGraphicsPixmapItem(QPixmap(":/images/Facture individuelle.png"));
    m_scene->addItem(m_image);

    m_logo = new QGraphicsPixmapItem(m_infosHotel.logo());
    m_scene->addItem(m_logo);
    qreal scale = 100 / m_logo->boundingRect().width();

    m_logo->setScale(scale);
    m_logo->setPos(900, 200);

    m_view->setFixedSize(m_scene->width() + 15, m_scene->height() + 15);

    m_x0 = m_image->x();
    m_y0 = m_image->y();

    m_abscisses << 233
                << 233
                << 233
                << 233
                << 80
                << 165
                << 520
                << 620
                << 680
                << 810
                << 930
                << 1035
                << 1035
                << 1035
                << 1035
                << 1035
                << 1035
                << 1035
                << 1035
                << 927
                << 962
                << 700
                << 700
                << 700
                << 213
                << 900
                << 900
                << 900
                << 900;

    m_ordonnees << 492
                << 513
                << 533
                << 555
                << 765
                << 765
                << 765
                << 765
                << 765
                << 765
                << 765
                << 765
                << 1287    // Total TTC
                << 1254
                << 1213
                << 1330    // Penalite retard
                << 1386
                << 1442
                << 1500
                << 1505
                << 1247
                << 550
                << 580
                << 610
                << 145
                << 260
                << 280
                << 300
                << 320;

    for(int i = 0; i < m_abscisses.count(); i++)
    {
        m_items[i] = new QGraphicsTextItem();
        QFont f;
        f.setFamily("Garamond");
        f.setPointSize(14);
        m_items[i]->setFont(f);

        if(i == Profession || i == Contact || i == NomClient)
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
//
//        if((Champ)i == NomHotel)
//        {
//            // agrandir le caractère
//            QFont f;
//            f.setPointSize(14);
//            f.setFamily("Helvetica [Cronyx]");
//            m_items[i]->setFont(f);
//        }

        m_scene->addItem(m_items[i]);
        m_items[i]->setPos(m_x0 + m_abscisses.at(i), m_y0 + m_ordonnees.at(i));
    }

    construireFacture();
}

void factureHotelIndividu::setText(Champ champ, QString valeur)
{
    m_items[champ]->setPlainText(valeur);
}

void factureHotelIndividu::construireFacture()
{
    QDate now = Horloge::currentDate();

    setText(NumFacture, m_occup.facture());
    setText(DateFacture, now.toString(Qt::SystemLocaleDate));
    setText(CodeClient, QString("CL %1").arg(m_occup.codeClient()));

    client cl(m_occup.codeClient());
    profileClient p(m_occup.idProfileClient());
    chambre ch(m_occup.chambreOccupee());
    prixChambreTTC prixNuit(ch.idTypeChambre(), p.idProfile());

    setText(TypeClient, typeDeClient(p.idTypeClient()).type());
    setText(Chambre1, ch.identifiant());
    setText(TypeChambre1, typeDeChambre(ch.idTypeChambre()).type());
    setText(DateArrivee1, m_occup.datedEntree().date().toString(Qt::SystemLocaleDate));
    setText(NbDeNuits1, QString::number(m_occup.dureeOccupation()));
    setText(ProfileClient1, p.profile());

    int tva = (int)MesTables::doubleToMoney(prixNuit.tva());
    int prixHT = prixNuit.prixTTC() - tva;
    setText(PrixParNuit1, MesTables::moneyToString(prixHT));

    int prixTTCActu = m_occup.cout() / m_occup.dureeOccupation();
    taux tauxTVA = taux(taux::TVA);
    int tvaActu = (int)MesTables::doubleToMoney(prixTTCActu * tauxTVA.valeur());
    int prixHTActu = prixTTCActu - tvaActu;

    setText(Remise1        , MesTables::moneyToString(prixHT - prixHTActu));
    setText(TotalHT1       , MesTables::moneyToString(prixHTActu * m_occup.dureeOccupation()));
    setText(PenaliteRetard , MesTables::moneyToString(m_occup.fraisSupplementaire()));
    setText(TVA            , MesTables::moneyToString(tvaActu * m_occup.dureeOccupation()));
    setText(TotalHTGlobal  , MesTables::moneyToString(prixHTActu * m_occup.dureeOccupation()));
    setText(TotalTTC       , MesTables::moneyToString(m_occup.cout()));

    int fraisRestoNonPayes = m_occup.fraisRestoNonPayes();

    setText(MontantDuResto , MesTables::moneyToString(fraisRestoNonPayes));
    setText(PaiementsRecus , MesTables::moneyToString(m_occup.payee()));

    int netAPayer = m_occup.reste() + m_occup.fraisSupPayee() + fraisRestoNonPayes;
    setText(NetAPayer      , MesTables::moneyToString(netAPayer));
    setText(UniteMonnaie   , "(F CFA)");
    setText(ValTaux        , QString("(%1 %)").arg(tauxTVA.valeur() * 100));
    setText(NomClient      , cl.nomComplet());
    setText(Contact        , cl.cel());
    setText(Profession     , cl.profession());
    setText(NomHotel       , m_infosHotel.nom().toUpper());
    setText(SituationGeo   , m_infosHotel.situationGeo());
    setText(BPHotel        , m_infosHotel.bp());
    setText(TelHotel       , QString("Tél : %1").arg(m_infosHotel.numeroTel()));

    if(!m_infosHotel.siteWeb().isEmpty())
    {
        setText(SiteWeb    , QString("Site Web : %1").arg(m_infosHotel.siteWeb()));
    }
}
