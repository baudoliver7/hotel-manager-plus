#include "Afficheur.h"

Afficheur::Afficheur(QGraphicsScene *scene)
{
    m_scene = scene;
    m_pixmap = Chambre().pixmap();
    scale = 1.0;
    m_ascenceur_chLibre = new Ascenceur(m_scene,this, true);
    m_ascenceur_chOccupee = new Ascenceur(m_scene,this, false);
}

Afficheur::~Afficheur()
{
    delete m_ascenceur_chLibre;
    delete m_ascenceur_chOccupee;
}

void Afficheur::afficherUneChambre(Chambre *ch, int ligne, int colonne)
{
    float longeur = m_scene->width();
    scale = qMin(echX(), echY());
    Chambre ch1; ch1.setScale(scale);
    m_c1 = ch1.pixmap().width();

    if((ligne <= Afficheur::nbreMaxDeChambresSurUneColonne && ligne >=1) && (colonne <= Afficheur::nbreMaxDeChambresSurUneLigne && colonne >= 1))
    {
        ch->setScale(scale);
        ch->setVisible(true);
        ch->setPos(abscisse(ligne, colonne), ordonnee(ligne, colonne));

        if(!ch->libre())
        {
            // translater horizontalement de b/2
            ch->setPos(ch->x() + longeur/2 + 10.0, ch->y());
        }
    }
}

void Afficheur::afficherDesChambres(int iDdeb, int nbreDeChambre, ListeDeChambres<Chambre *> liste, bool libre)
{
    int idebut;
    int ifin;
    if(libre)
    {
        idebut = 0;
        ifin = liste.getNbreDeChambresLibres() - 1;
    }else
    {
        idebut = liste.getNbreDeChambresLibres();
        ifin = liste.size() - 1;
    }

    if(libre)
    {
        Afficheur::effacerDesChambres(liste.chambresLibres());
    }else
    {
        Afficheur::effacerDesChambres(liste.chambresOccupees());
    }

    int iderniereCh = qMin(nbreDeChambre,(int)Afficheur::nbreChambresMaxAffichees) + iDdeb - 1;
    int i = iDdeb;
    int k = 0;

    while(i <= iderniereCh)
    {
        k++; // maximum 3 fois
        for(int j = 1 ; j <= Afficheur::nbreMaxDeChambresSurUneLigne; j++)
        {
            if( i <= iderniereCh)
            {               
                Afficheur::afficherUneChambre(liste.at(i),k,j);
                i++;
            }
        }      
    }

    if(libre)
    {
        m_ascenceur_chLibre->setScale(scale);
        m_ascenceur_chLibre->setPos(m_scene->width()/2.0
                                    - m_ascenceur_chLibre->sceneBoundingRect().width()
                                    - 10.0,
                                    m_scene->height() / 2.0 - m_ascenceur_chLibre->sceneBoundingRect().height()/2.0);
    }else
    {
        m_ascenceur_chOccupee->setScale(scale);
        m_ascenceur_chOccupee->setPos(m_scene->width() - m_ascenceur_chOccupee->sceneBoundingRect().width(),
                                      m_scene->height() / 2.0 - m_ascenceur_chOccupee->sceneBoundingRect().height()/2.0);
    }
}

void Afficheur::afficherDesChambres(int iDdeb, ListeDeChambres<Chambre *> liste, bool libre)
{
    int idebut;
    int ifin;
    if(libre)
    {
        idebut = 0;
        ifin = liste.getNbreDeChambresLibres() - 1;
    }else
    {
        idebut = liste.getNbreDeChambresLibres();
        ifin = liste.size()-1;
    }

    if(libre)
    {
        Afficheur::effacerDesChambres(liste.chambresLibres());
    }else
    {
        Afficheur::effacerDesChambres(liste.chambresOccupees());
    }

    int nbChMaxiAafficher = qMin(ifin - iDdeb + 1, (int)Afficheur::nbreChambresMaxAffichees);
    int iderniereCh = iDdeb + (nbChMaxiAafficher - 1);
    int i = iDdeb;
    int k = 0;

    while(i <= iderniereCh)
    {
        k++; // maximum 3 fois
        for(int j = 1 ; j <= Afficheur::nbreMaxDeChambresSurUneLigne; j++)
        {
            if( i <= iderniereCh)
            {
                Afficheur::afficherUneChambre(liste.at(i),k,j);
                i++;
            }
        }      
    }

    if(libre)
    {
        m_ascenceur_chLibre->setScale(scale);
        m_ascenceur_chLibre->setPos(m_scene->width()/2.0
                                    - m_ascenceur_chLibre->sceneBoundingRect().width()
                                    - 10.0,
                                    m_scene->height() / 2.0 - m_ascenceur_chLibre->sceneBoundingRect().height()/2.0);
    }else
    {
        m_ascenceur_chOccupee->setScale(scale);
        m_ascenceur_chOccupee->setPos(m_scene->width() - m_ascenceur_chOccupee->sceneBoundingRect().width(),
                                      m_scene->height() / 2.0 - m_ascenceur_chOccupee->sceneBoundingRect().height()/2.0);
    }
}

float Afficheur::echX()const
{
    return c1() / m_pixmap.width();
}

float Afficheur::echY()const
{
    return c2() / m_pixmap.height();
}

void Afficheur::effacerDesChambres(ListeDeChambres<Chambre *> liste)
{
    for(int i = 0; i < liste.size(); i++)
    {
        liste.at(i)->setVisible(false);
    }
}

float Afficheur::abscisse(int i, int j)
{
    return i1() + (j - 1) * (m_c1 + e1());
}

float Afficheur::ordonnee(int i, int j)
{
    return i2() + (i - 1) * (c2() + e2());
}

float Afficheur::i1()const
{
    float longueur = m_scene->width();
    return longueur / 64.0;
}

float Afficheur::c1()const
{
    float longueur = m_scene->width();
    return longueur * (2.0/ 25.0);
}

float Afficheur::e1()const
{
    float longueur = m_scene->width();
    return (longueur / 2.0 - (5 * m_c1 + i1() + d()))/5.0;
}

float Afficheur::d()const
{
    float longueur = m_scene->width();
    return longueur / 64.0;
}

float Afficheur::i2()const
{
    float largeur = m_scene->height();
    return largeur / 10.0;
}

float Afficheur::c2()const
{
    float largeur = m_scene->height();
    return largeur * (16.0/75.0);
}

float Afficheur::e2()const
{
    float largeur = m_scene->height();
    return largeur * (2.0/25.0);
}

float Afficheur::h()const
{
    float largeur = m_scene->height();
    return largeur * (20.0/ 25.0);
}
