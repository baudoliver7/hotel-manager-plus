#ifndef FACTUREHOTELINDIVIDU_H
#define FACTUREHOTELINDIVIDU_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>

#include "occupation.h"
#include "client.h"
#include "chambre.h"
#include "typeDeClient.h"
#include "typeDeChambre.h"
#include "profileClient.h"
#include "MesTables.h"
#include "infosHotel.h"

class factureHotelIndividu
{
public:
    enum Champ
    {
        NumFacture = 0, DateFacture = 1, CodeClient = 2, TypeClient = 3, Chambre1 = 4, TypeChambre1 = 5,
        DateArrivee1 = 6, NbDeNuits1 = 7, ProfileClient1 = 8, PrixParNuit1 = 9, Remise1 = 10,
        TotalHT1 = 11, TotalTTC = 12, TVA = 13, TotalHTGlobal = 14, PenaliteRetard = 15, MontantDuResto = 16,
        PaiementsRecus = 17, NetAPayer = 18, UniteMonnaie = 19, ValTaux = 20, NomClient = 21, Contact = 22,
        Profession = 23, NomHotel = 24, SituationGeo = 25, BPHotel = 26, TelHotel = 27, SiteWeb = 28
    };

public:
    factureHotelIndividu(const occupation & oc);

    void setText(Champ champ, QString valeur);
    QGraphicsView * view(){return m_view;};
    QGraphicsScene * scene(){return m_scene;};

private:
    void construireFacture();

    infosHotel m_infosHotel;
    occupation m_occup;
    QGraphicsView * m_view;
    QGraphicsScene * m_scene;
    QGraphicsPixmapItem * m_image;
    QGraphicsPixmapItem * m_logo;
    qreal m_x0;
    qreal m_y0;
    QList<qreal> m_abscisses;
    QList<qreal> m_ordonnees;
    QGraphicsTextItem * m_items[29];
};

#endif // FACTUREHOTELINDIVIDU_H
