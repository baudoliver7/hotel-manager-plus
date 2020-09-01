#ifndef FACTUREHOTELGROUPE_H
#define FACTUREHOTELGROUPE_H

#include "Impression_global.h"

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
#include "groupe.h"

#define ITEMS_COUNT 32

class IMPRESSIONSHARED_EXPORT factureHotelGroupe
{
public:
    enum Champ
    {
        NumFacture = 0, DateFacture = 1, CodeClient = 2, TypeClient = 3, Contact = 4, Profession = 5,
        NomHotel = 6, SituationGeo = 7, BPHotel = 8, TelHotel = 9, SiteWeb = 10, NomDuRespo = 11,
        NbPersonnes = 12, DateArriveeOff = 13, NbNuitOff = 14, AvancePercu = 15, NbChambre = 16,
        FraisLocationHT = 17, Remise = 18, TotalHT = 19, TVA = 20,
        TotalTTC = 21, PenaliteRetard = 22, FraisRestoTTC = 23, PayementRecu = 24, NetAPayer = 25,
        NomClient = 26, UniteMontant = 27, TauxTVA = 28, UniteNetAPayer = 29, TT = 30, TauxTT = 31,
        FraisBarTTC = 32
    };

public:
    factureHotelGroupe(const groupe & gp);
    ~factureHotelGroupe();

    void setText(Champ champ, QString valeur);
    void setText(Champ champ, QString valeur, int position);
    QGraphicsView * view(){return m_view;};
    QGraphicsScene * scene(){return m_scene;};

private:
    void construireFacture();

    infosHotel m_infosHotel;
    groupe m_group;
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

#endif // FACTUREHOTELGROUPE_H
