#ifndef FACTURERESTOINDIVIDU_H
#define FACTURERESTOINDIVIDU_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>

#include "client.h"
#include "repasCompletResto.h"
#include "MesTables.h"
#include "infosHotel.h"
#include "tableResto.h"

#define ITEMS_COUNT 150

class factureRestoIndividu
{
public:
    enum Champ
    {
        NumFacture = 0, DateFacture = 1, CodeClient = 2, Contact = 3, NomHotel = 4,
        SituationGeo = 5, BPHotel = 6, TelHotel = 7, SiteWeb = 8, NomClient = 9, DateArrivee = 10,
        TableOccupee = 11, TotalHT = 12, TVA = 13, TotalTTC = 14, PayementRecu = 15, NetAPayer = 16,
        TauxTVA = 17, UniteNetAPayer = 18, Menu1 = 19, NbMenu1 = 20, PrixUnitaire1 = 21, Remise1 = 22,
        TotalHT1 = 23
    };

public:
    factureRestoIndividu(const repasCompletResto & rcr);

    void setText(Champ champ, QString valeur);
    void setText(Champ champ, QString valeur, int position);
    QGraphicsView * view(){return m_view;};
    QGraphicsScene * scene(){return m_scene;};

private:
    void construireFacture();

    infosHotel m_infosHotel;
    repasCompletResto m_rcr;
    QGraphicsView * m_view;
    QGraphicsScene * m_scene;
    QGraphicsPixmapItem * m_image;
    QGraphicsPixmapItem * m_logo;
    qreal m_x0;
    qreal m_y0;
    QList<qreal> m_abscisses;
    QList<qreal> m_ordonnees;
    QGraphicsTextItem * m_items[ITEMS_COUNT];
};

#endif // FACTURERESTOINDIVIDU_H