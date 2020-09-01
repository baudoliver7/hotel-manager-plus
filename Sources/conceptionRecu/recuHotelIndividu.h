#ifndef RECUHOTELINDIVIDU_H
#define RECUHOTELINDIVIDU_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>

class recuHotelIndividu
{
public:
    enum Champ
    {
        NumFacture = 0, DateFacture = 1, CodeClient = 2, TypeClient = 3, Chambre1 = 4, TypeChambre1 = 5,
        DateArrivee1 = 6, NbDeNuits1 = 7, ProfileClient1 = 8, PrixParNuit1 = 9, Remise1 = 10,
        TotalHT1 = 11, PenaliteRetard = 12, TVA = 13, TotalHTGlobal = 14, TotalTTC = 15, MontantDuResto = 16,
        PaiementsRecus = 17, NetAPayer = 18, UniteMonnaie = 19, ValTaux = 20
    };

public:
    recuHotelIndividu();
};

#endif // RECUHOTELINDIVIDU_H
