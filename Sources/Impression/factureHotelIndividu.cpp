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
                << 962      // ValTaux (valeur taux TVA)
                << 700
                << 700
                << 700
                << 213
                << 900
                << 900
                << 900
                << 900
                << 1035
                << 962
                << 1035;

    m_ordonnees << 492      // NumFacture
                << 513      // DateFacture
                << 533      // CodeClient
                << 555      // TypeClient
                << 765      // Chambre1
                << 765      // TypeChambre1
                << 765      // DateArrivee1
                << 765      // NbDeNuits1
                << 765      // ProfileClient1
                << 765      // PrixParNuit1
                << 765      // Remise1
                << 765      // TotalHT1
                << 1148    // Total TTC
                << 1050    // TVA
                << 1010    // TotalHTGlobal
                << 1192    // Penalite retard
                << 1248    // MontantDuResto
                << 1362    // Paiements reçus
                << 1422    // Net à payer
                << 1432    // Unité monnaie (Net à payer)
                << 1046    // ValTaux (valeur taux TVA)
                << 550     // NomClient
                << 580     // Contact
                << 610     // Profession
                << 145     // NomHotel
                << 260     // SituationGeo
                << 280     // BPHotel
                << 300     // TelHotel
                << 320     // SiteWeb
                << 1100    // TT
                << 1105    // TauxTT
                << 1302;   // Montant du Bar

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

factureHotelIndividu::~factureHotelIndividu()
{
    delete m_view;
}

void factureHotelIndividu::setText(Champ champ, QString valeur)
{
    m_items[champ]->setPlainText(valeur);
}

void factureHotelIndividu::construireFacture()
{
    taux tauxTT(taux::TT);
    taux tauxTVA = taux(taux::TVA);

    float tauxTotal = tauxTT.valeur() + tauxTVA.valeur();

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

    int tva = (int)MesTables::tva(prixNuit.prixTTC(), tauxTVA.valeur(), tauxTotal);
    int tt = (int)MesTables::tt(prixNuit.prixTTC(), tauxTT.valeur(), tauxTotal);
    int prixHT = prixNuit.prixTTC() - tva - tt;
    setText(PrixParNuit1, MesTables::doubleToAllMoney(prixHT));

    int prixTTCActu = m_occup.cout() / m_occup.dureeOccupation();
    int tvaActu = (int)MesTables::tva(prixTTCActu, tauxTVA.valeur(), tauxTotal);
    int ttActu = (int)MesTables::tt(prixTTCActu, tauxTT.valeur(), tauxTotal);
    int prixHTActu = prixTTCActu - tvaActu - ttActu;

    setText(Remise1        , MesTables::doubleToAllMoney(prixHT - prixHTActu));
    setText(TotalHT1       , MesTables::doubleToAllMoney(prixHTActu * m_occup.dureeOccupation()));
    setText(PenaliteRetard , MesTables::doubleToAllMoney(m_occup.fraisSupplementaire()));
    setText(TVA            , MesTables::doubleToAllMoney(tvaActu * m_occup.dureeOccupation()));
    setText(TT             , MesTables::doubleToAllMoney(ttActu * m_occup.dureeOccupation()));
    setText(TotalHTGlobal  , MesTables::doubleToAllMoney(prixHTActu * m_occup.dureeOccupation()));
    setText(TotalTTC       , MesTables::doubleToAllMoney(m_occup.cout()));

    int fraisRestoTTC = m_occup.fraisResto();
    int fraisBarTTC = m_occup.fraisBar();

    setText(MontantDuResto , MesTables::doubleToAllMoney(fraisRestoTTC));
    setText(MontantDuBar , MesTables::doubleToAllMoney(fraisBarTTC));

    int sommeTotalPayee = m_occup.payee() + m_occup.fraisSupPayee() + m_occup.fraisRestoPayes();
    setText(PaiementsRecus , MesTables::doubleToAllMoney(sommeTotalPayee));

    int netAPayer = m_occup.cout() + m_occup.fraisSupplementaire() + fraisRestoTTC + fraisBarTTC - sommeTotalPayee;
    setText(NetAPayer      , MesTables::doubleToAllMoney(netAPayer));
    setText(UniteMonnaie   , "(F CFA)");
    setText(ValTaux        , QString("(%1 %)").arg(tauxTVA.valeur() * 100));
    setText(TauxTT         , QString("(%1 %)").arg(tauxTT.valeur() * 100));
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
