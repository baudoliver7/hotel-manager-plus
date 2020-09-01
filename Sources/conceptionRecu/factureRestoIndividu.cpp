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
    qreal scale = 100 / m_logo->boundingRect().width();

    m_logo->setScale(scale);
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
                << 912
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
               << 1343
               << 1386
               << 1429
               << 1472
               << 1505
               << 1379
               << 1504
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
    QDate now = Horloge::currentDate();

    setText(NumFacture, m_rcr.facture());
    setText(DateFacture, now.toString(Qt::SystemLocaleDate));
    setText(CodeClient, QString("CL %1").arg(m_rcr.codeClient()));

    int fraisRestoTTC = m_rcr.totalAPayer();
    int tvaResto = (int)MesTables::doubleToMoney(fraisRestoTTC * tauxTVA.valeur());
    int fraisRestoHT = fraisRestoTTC - tvaResto;

    int fraisRestoTTCSR = m_rcr.totalAPayerSanSRemise();
    int tvaRestoSR = (int)MesTables::doubleToMoney(fraisRestoTTCSR * tauxTVA.valeur());
    int fraisRestoHTSR = fraisRestoTTCSR - tvaRestoSR;

    setText(TotalHT          , MesTables::moneyToString(fraisRestoHT));
    setText(TVA              , MesTables::moneyToString(tvaResto));

    int totalTTC = tvaResto + fraisRestoHT;
    setText(TotalTTC       , MesTables::moneyToString(totalTTC));

    int fraisRestoPayes = m_rcr.montantTotalEncaisse();
    setText(PayementRecu , MesTables::moneyToString(fraisRestoPayes));

    int netAPayer = totalTTC - fraisRestoPayes;
    setText(NetAPayer      , MesTables::moneyToString(netAPayer));
    setText(TauxTVA        , QString("(%1 %)").arg(tauxTVA.valeur() * 100));
    setText(UniteNetAPayer , "F CFA");

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
        int tvaSR = (int)MesTables::doubleToMoney(prixSRTTC * tauxTVA.valeur());
        int prixSRHT = prixSRTTC - tvaSR;

        int prixTTC = cr.coutTotal() / cr.nbMenu();
        int tva = (int)MesTables::doubleToMoney(prixTTC * tauxTVA.valeur());
        int prixHT = prixTTC - tva;

        setText(PrixUnitaire1  , MesTables::moneyToString(prixSRHT), row + 1);
        setText(Remise1        , MesTables::moneyToString(prixSRHT - prixHT), row + 1);
        setText(TotalHT1       , MesTables::moneyToString(prixHT), row + 1);
    }
}


