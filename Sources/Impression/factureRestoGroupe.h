#ifndef FACTURERESTOGROUPE_H
#define FACTURERESTOGROUPE_H

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

#define ITEMS_COUNT 28

class IMPRESSIONSHARED_EXPORT factureRestoGroupe
{
public:
    enum Champ
    {
        NumFacture = 0, DateFacture = 1, CodeClient = 2, TypeClient = 3, Contact = 4, Profession = 5,
        NomHotel = 6, SituationGeo = 7, BPHotel = 8, TelHotel = 9, SiteWeb = 10, NomDuRespo = 11,
        NbPersPrevues = 12, NbPersRecues = 13, DateArriveeOff = 14,
        FraisRestoHT = 15, Remise = 16, TotalHT = 17, TVA = 18, TotalTTC = 19, PayementRecu = 20,
        NetAPayer = 21, NomClient = 22, UniteMontant = 23, TauxTVA = 24, UniteNetAPayer = 25,
        TT = 26, TauxTT = 27
    };

public:
    factureRestoGroupe(const groupe & gp);
    ~factureRestoGroupe();

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

#endif // FACTURERESTOGROUPE_H