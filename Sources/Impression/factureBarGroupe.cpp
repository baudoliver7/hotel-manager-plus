#include "factureBarGroupe.h"

factureBarGroupe::factureBarGroupe(const groupe &gp)
{
    m_infosHotel = infosHotel(1);

    m_group = gp;
    m_view = new QGraphicsView();

    m_scene = new QGraphicsScene();
    m_view->setScene(m_scene);

    m_image = new QGraphicsPixmapItem(QPixmap(":/images/Facture bar groupe 1.png"));
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
                << 700
                << 700
                << 213
                << 900
                << 900
                << 900
                << 900
                << 80
                << 580      // NbPersPrevues
                << 820      // NbPersRecues
                << 950
                << 950
                << 950
                << 950
                << 950
                << 950
                << 950
                << 950
                << 700
                << 1032
                << 130
                << 225
                << 950
                << 250;

   m_ordonnees << 492       // NumFacture
               << 513       // DateFacture
               << 533       // CodeClient
               << 555       // TypeClient
               << 580       // Contact
               << 610       // Profession
               << 145       // NomHotel
               << 260       // SituationGeo
               << 280       // BPHotel
               << 300       // TelHotel
               << 320       // SiteWeb
               << 775       // NomDuRespo
               << 775       // NbPersPrevues
               << 775       // NbPersRecues
               << 775       // DateArriveeOff
               << 977       // FraisBarHT
               << 1027      // Remise
               << 1077      // TotalHT
               << 1127      // TVA
               << 1227      // TotalTTC
               << 1277      // PayementRecu
               << 1327      // NetAPayer
               << 550       // NomClient
               << 912       // UniteMontant
               << 1132      // TauxTVA
               << 1330      // UniteNetAPayer
               << 1177      // TT
               << 1177  ;   // TauxTT

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

        if(i == UniteMontant)
        {
            m_items[i]->setFont(f);
            m_items[i]->setDefaultTextColor(Qt::white);
        }

        m_scene->addItem(m_items[i]);
        m_items[i]->setPos(m_x0 + m_abscisses.at(i), m_y0 + m_ordonnees.at(i));
    }

    construireFacture();
}

factureBarGroupe::~factureBarGroupe()
{
    delete m_view;
}

void factureBarGroupe::setText(Champ champ, QString valeur)
{
    m_items[champ]->setPlainText(valeur);
}

void factureBarGroupe::setText(Champ champ, QString valeur, int position)
{
    m_items[champ + 9 * (position - 1)]->setPlainText(valeur);
}

void factureBarGroupe::construireFacture()
{
    taux tauxTVA = taux(taux::TVA);
    taux tauxTT = taux(taux::TT);

    float tauxTotal = tauxTVA.valeur() + tauxTT.valeur();

    QDate now = Horloge::currentDate();

    setText(NumFacture, m_group.facture());
    setText(DateFacture, now.toString(Qt::SystemLocaleDate));
    setText(CodeClient, QString("GP %1").arg(m_group.idGroupe()));

    int fraisBarTTC = m_group.fraisBarTotal();
    int tvaBar = (int)MesTables::tva(fraisBarTTC, tauxTVA.valeur(), tauxTotal);
    int ttBar = (int)MesTables::tt(fraisBarTTC, tauxTT.valeur(), tauxTotal);
    int fraisBarHT = fraisBarTTC - tvaBar - ttBar;

    int fraisBarTTCSR = m_group.fraisBarTotalSansRemise();
    int tvaBarSR = (int)MesTables::tva(fraisBarTTCSR, tauxTVA.valeur(), tauxTotal);
    int ttBarSR = (int)MesTables::tt(fraisBarTTCSR, tauxTT.valeur(), tauxTotal);
    int fraisBarHTSR = fraisBarTTCSR - tvaBarSR - ttBarSR;

    setText(FraisBarHT     , MesTables::doubleToAllMoney(fraisBarHTSR));
    setText(Remise           , MesTables::doubleToAllMoney(fraisBarHTSR - fraisBarHT));

    setText(TotalHT          , MesTables::doubleToAllMoney(fraisBarHT));
    setText(TVA              , MesTables::doubleToAllMoney(tvaBar));
    setText(TT               , MesTables::doubleToAllMoney(ttBar));

    int totalTTC = ttBar + tvaBar + fraisBarHT;
    setText(TotalTTC       , MesTables::doubleToAllMoney(totalTTC));

    int fraisBarPayes = m_group.fraisBarPayes();
    setText(PayementRecu , MesTables::doubleToAllMoney(fraisBarPayes));

    int netAPayer = totalTTC - fraisBarPayes;
    setText(NetAPayer      , MesTables::doubleToAllMoney(netAPayer));
    setText(UniteMontant   , "F CFA");
    setText(TauxTVA        , QString("(%1 %)").arg(tauxTVA.valeur() * 100));
    setText(TauxTT        , QString("(%1 %)").arg(tauxTT.valeur() * 100));
    setText(UniteNetAPayer , "F CFA");

    client cl(m_group.idResponsable()); // responsable
    profileClient p(m_group.idProfileClient());
    setText(TypeClient     , typeDeClient(p.idTypeClient()).type());
    setText(NomClient      , QString("%1").arg(m_group.libelle()));

    if(!m_group.tel().isEmpty())
        setText(Contact        , m_group.tel());
    else
        setText(Contact        , m_group.cel());

    setText(NomHotel       , m_infosHotel.nom().toUpper());
    setText(SituationGeo   , m_infosHotel.situationGeo());
    setText(BPHotel        , m_infosHotel.bp());
    setText(TelHotel       , QString("Tél : %1").arg(m_infosHotel.numeroTel()));
    setText(NomDuRespo     , cl.nomComplet());
    setText(NbPersPrevues  , QString::number(m_group.nbPersPrevues()));
    setText(NbPersRecues   , QString::number(m_group.nbPersEnregistrees()));
    setText(DateArriveeOff , m_group.dateOccupation().date().toString(Qt::SystemLocaleDate));

    if(!m_infosHotel.siteWeb().isEmpty())
    {
        setText(SiteWeb    , QString("Site Web : %1").arg(m_infosHotel.siteWeb()));
    }
}

