#include "factureRestoIndividu.h"

factureRestoIndividu::factureRestoIndividu(const repasCompletResto & rcr)
{
    m_infosHotel = infosHotel(1);

    m_rcr = rcr;
    m_view = new QGraphicsView();

    m_scene = new QGraphicsScene();
    m_view->setScene(m_scene);

    m_image = new QGraphicsPixmapItem(QPixmap(":/images/facture resto individu A4.png"));
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
                << 700
                << 213
                << 900
                << 900
                << 900
                << 900
                << 700
                << 233
                << 233
                << 1000
                << 1000
                << 1000
                << 1000
                << 1000
                << 842
                << 912 // Unit
                << 1000
                << 930
                << 80
                << 572
                << 650
                << 850
                << 1000;

   m_ordonnees << 492
               << 513
               << 533
               << 555
               << 145
               << 260
               << 280
               << 300
               << 320
               << 530
               << 558
               << 581
               << 1260      // TotalHT
               << 1302      // TVA
               << 1382      // TotalTTC
               << 1426      // PayementRecu
               << 1466      // NetAPayer
               << 1298      // TauxTVA
               << 1464      // UniteNetAPayer
               << 1343      // TT
               << 1339      // TauxTT
               << 684
               << 684
               << 684
               << 684
               << 684;

    for(int i = 0; i < m_abscisses.count(); i++)
    {
        m_items[i] = new QGraphicsTextItem();
        QFont f;
        f.setFamily("Garamond");
        f.setPointSize(14);
        m_items[i]->setFont(f);

        if(i == Contact || i == NomClient)
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

    // créer les autres lignes
    int ligne = 0;
    for(int i = m_abscisses.count(); i < m_abscisses.count() + 5 * 15; i +=5)
    {
        ligne++;
        int k = i - 1;
        for(int j = Menu1; j <= TotalHT1; j++)
        {
            k++;
            m_items[k] = new QGraphicsTextItem();
            QFont f;
            f.setFamily("Garamond");
            f.setPointSize(14);
            m_items[k]->setFont(f);

            m_scene->addItem(m_items[k]);
            m_items[k]->setPos(m_x0 + m_abscisses.at(j), m_y0 + m_ordonnees.at(j) + 40 * ligne);
        }
    }

    construireFacture();
}

factureRestoIndividu::~factureRestoIndividu()
{
    delete m_view;
}

void factureRestoIndividu::setText(Champ champ, QString valeur)
{
    m_items[champ]->setPlainText(valeur);
}

void factureRestoIndividu::setText(Champ champ, QString valeur, int position)
{
    m_items[champ + 5 * (position - 1)]->setPlainText(valeur);
}

void factureRestoIndividu::construireFacture()
{
    taux tauxTVA = taux(taux::TVA);
    taux tauxTT = taux(taux::TT);

    float tauxTotal = tauxTT.valeur() + tauxTVA.valeur();

    QDate now = Horloge::currentDate();

    setText(NumFacture, m_rcr.facture());
    setText(DateFacture, now.toString(Qt::SystemLocaleDate));

    if(m_rcr.codeClient() > 0)
        setText(CodeClient, QString("CL %1").arg(m_rcr.codeClient()));
    else
        setText(CodeClient, QString("RT %1").arg(m_rcr.idRepasCResto()));

    client cl(m_rcr.codeClient());

    if(cl.existe())
    {
        setText(NomClient      , QString("%1").arg(cl.nomComplet()));
        setText(Contact        , cl.cel());
    }

    setText(NomHotel       , m_infosHotel.nom().toUpper());
    setText(SituationGeo   , m_infosHotel.situationGeo());
    setText(BPHotel        , m_infosHotel.bp());
    setText(TelHotel       , QString("Tél : %1").arg(m_infosHotel.numeroTel()));
    setText(DateArrivee    , m_rcr.dateArrivee().date().toString(Qt::SystemLocaleDate));

    tableResto table(m_rcr.idTableResto());
    setText(TableOccupee   , table.libelle());

    if(!m_infosHotel.siteWeb().isEmpty())
    {
        setText(SiteWeb    , QString("Site Web : %1").arg(m_infosHotel.siteWeb()));
    }

    // afficher les menus
    QList<QSqlRecord> records;
    records = m_rcr.conso_resto_records();

    for(int row = 0; row < records.count(); row++)
    {
        consoResto cr(records.at(row));
        menuResto mr(cr.idMenu());
        setText(Menu1     , mr.libelle(), row + 1);
        setText(NbMenu1   , QString::number(cr.nbMenu()), row + 1);

        int prixSRTTC = mr.prix();
        int tvaSR = (int)MesTables::tva(prixSRTTC, tauxTVA.valeur(), tauxTotal);
        int ttSR = (int)MesTables::tt(prixSRTTC, tauxTT.valeur(), tauxTotal);
        int prixSRHT = prixSRTTC - tvaSR - ttSR;

        int prixTTC = cr.coutTotal() / cr.nbMenu();
        int tva = (int)MesTables::tva(prixTTC, tauxTVA.valeur(), tauxTotal);
        int tt = (int)MesTables::tt(prixTTC, tauxTT.valeur(), tauxTotal);
        int prixHT = prixTTC - tva - tt;

        setText(PrixUnitaire1  , MesTables::doubleToAllMoney(prixSRHT), row + 1);
        setText(Remise1        , MesTables::doubleToAllMoney(prixSRHT - prixHT), row + 1);
        setText(TotalHT1       , MesTables::doubleToAllMoney(prixHT * cr.nbMenu()), row + 1);
    }

    int totalTTC = m_rcr.totalAPayer();
    int tvaTotal = (int)MesTables::tva(totalTTC, tauxTVA.valeur(), tauxTotal);
    int ttTotal = (int)MesTables::tva(totalTTC, tauxTT.valeur(), tauxTotal);
    int totalHT = m_rcr.totalAPayer() - tvaTotal - ttTotal;

    setText(TotalHT          , MesTables::doubleToAllMoney(totalHT));
    setText(TVA              , MesTables::doubleToAllMoney(tvaTotal));
    setText(TT               , MesTables::doubleToAllMoney(ttTotal));

    setText(TotalTTC       , MesTables::doubleToAllMoney(totalTTC));

    int fraisRestoPayes = m_rcr.montantTotalEncaisse();
    setText(PayementRecu , MesTables::doubleToAllMoney(fraisRestoPayes));

    int netAPayer = totalTTC - fraisRestoPayes;
    setText(NetAPayer      , MesTables::doubleToAllMoney(netAPayer));
    setText(TauxTVA        , QString("(%1 %)").arg(tauxTVA.valeur() * 100));
    setText(TauxTT         , QString("(%1 %)").arg(tauxTT.valeur() * 100));
    setText(UniteNetAPayer , "F CFA");
}


