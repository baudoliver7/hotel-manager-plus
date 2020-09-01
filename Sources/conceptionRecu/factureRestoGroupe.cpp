#include "factureRestoGroupe.h"

factureRestoGroupe::factureRestoGroupe(const groupe &gp)
{
    m_infosHotel = infosHotel(1);

    m_group = gp;
    m_view = new QGraphicsView();

    m_scene = new QGraphicsScene();
    m_view->setScene(m_scene);

    m_image = new QGraphicsPixmapItem(QPixmap(":/images/Facture resto groupe 1.png"));
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
                << 700
                << 700
                << 213
                << 900
                << 900
                << 900
                << 900
                << 80
                << 500
                << 755
                << 930
                << 650
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
                << 225;

   m_ordonnees << 492
               << 513
               << 533
               << 555
               << 580
               << 610
               << 145
               << 260
               << 280
               << 300
               << 320
               << 775
               << 775
               << 775
               << 775
               << 775
               << 977
               << 1027
               << 1077
               << 1127
               << 1177
               << 1227
               << 1277
               << 550
               << 912
               << 1132
               << 1280;

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

void factureRestoGroupe::setText(Champ champ, QString valeur)
{
    m_items[champ]->setPlainText(valeur);
}

void factureRestoGroupe::setText(Champ champ, QString valeur, int position)
{
    m_items[champ + 9 * (position - 1)]->setPlainText(valeur);
}

void factureRestoGroupe::construireFacture()
{
    taux tauxTVA = taux(taux::TVA);
    QDate now = Horloge::currentDate();

    setText(NumFacture, m_group.facture());
    setText(DateFacture, now.toString(Qt::SystemLocaleDate));
    setText(CodeClient, QString("GP %1").arg(m_group.idGroupe()));

    int fraisRestoTTC = m_group.fraisRestoTotal();
    int tvaResto = (int)MesTables::doubleToMoney(fraisRestoTTC * tauxTVA.valeur());
    int fraisRestoHT = fraisRestoTTC - tvaResto;

    int fraisRestoTTCSR = m_group.fraisRestoTotalSansRemise();
    int tvaRestoSR = (int)MesTables::doubleToMoney(fraisRestoTTCSR * tauxTVA.valeur());
    int fraisRestoHTSR = fraisRestoTTCSR - tvaRestoSR;

    setText(FraisRestoHT     , MesTables::moneyToString(fraisRestoHTSR));
    setText(Remise           , MesTables::moneyToString(fraisRestoHTSR - fraisRestoHT));

    setText(TotalHT          , MesTables::moneyToString(fraisRestoHT));
    setText(TVA              , MesTables::moneyToString(tvaResto));

    int totalTTC = tvaResto + fraisRestoHT;
    setText(TotalTTC       , MesTables::moneyToString(totalTTC));

    int fraisRestoPayes = m_group.fraisRestoPayes();
    setText(PayementRecu , MesTables::moneyToString(fraisRestoPayes));

    int netAPayer = totalTTC - fraisRestoPayes;
    setText(NetAPayer      , MesTables::moneyToString(netAPayer));
    setText(UniteMontant   , "F CFA");
    setText(TauxTVA        , QString("(%1 %)").arg(tauxTVA.valeur() * 100));
    setText(UniteNetAPayer , "F CFA");

    client cl(m_group.idResponsable()); // responsable
    profileClient p(m_group.idProfileClient());
    setText(TypeClient     , typeDeClient(p.idTypeClient()).type());
    setText(NomClient      , QString("%1").arg(m_group.libelle()));
    setText(Contact        , cl.cel());
    setText(Profession     , cl.profession());
    setText(NomHotel       , m_infosHotel.nom().toUpper());
    setText(SituationGeo   , m_infosHotel.situationGeo());
    setText(BPHotel        , m_infosHotel.bp());
    setText(TelHotel       , QString("Tél : %1").arg(m_infosHotel.numeroTel()));
    setText(NomDuRespo     , cl.nomComplet());
    setText(NbPersonnes    , QString::number(m_group.nbPersPrevues()));
    setText(DateArriveeOff , m_group.dateOccupation().date().toString(Qt::SystemLocaleDate));
    setText(NbNuitOff      , QString::number(m_group.dureeOccupation()));
    setText(NbChambre      , QString::number(m_group.occupations_des_membres_records().count()));

    if(!m_infosHotel.siteWeb().isEmpty())
    {
        setText(SiteWeb    , QString("Site Web : %1").arg(m_infosHotel.siteWeb()));
    }
}

