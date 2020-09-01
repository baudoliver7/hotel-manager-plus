#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include "ListeDeChambres.h"
#include "Ascenceur.h"
#include <QGraphicsScene>
#include <QString>

class Ascenceur;

class Afficheur
{    
public:
    enum
    {
      nbreChambresMaxAffichees = 15, nbreMaxDeChambresSurUneLigne = 5, nbreMaxDeChambresSurUneColonne = 3
    };

    Afficheur(QGraphicsScene * scene);
    ~Afficheur();
    void afficherUneChambre(Chambre * ch, int ligne, int colonne);
    void afficherDesChambres(int iDdeb, int nbreDeChambre, ListeDeChambres<Chambre*> liste, bool libre);
    void afficherDesChambres(int iDdeb, ListeDeChambres<Chambre *> liste, bool libre);
    float echX()const;
    float echY()const;
    inline Ascenceur * ascenceurChLibre(){return m_ascenceur_chLibre;};
    inline Ascenceur * ascenceurChOccupee(){return m_ascenceur_chOccupee;};

private:
    QGraphicsScene * m_scene;
    Ascenceur * m_ascenceur_chLibre;
    Ascenceur * m_ascenceur_chOccupee;
    QPixmap m_pixmap;
    float m_c1;
    float scale;

    float abscisse(int i, int j);
    float ordonnee(int i, int j);

    float i1()const;
    float i2()const;

    float c1()const;
    float c2()const;

    float e1()const;
    float e2()const;

    float h()const;
    float d()const;


public:
    static void effacerDesChambres(ListeDeChambres<Chambre *> liste);

};

#endif // AFFICHEUR_H
