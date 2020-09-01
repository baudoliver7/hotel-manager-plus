#include "PiloteChambreGraphicView.h"

PiloteChambreGraphicView::PiloteChambreGraphicView(QGraphicsScene *scene)
{
    m_scene = scene;
    m_afficheur = new Afficheur(m_scene);
}

void PiloteChambreGraphicView::rangerParOrdreCroissant(ListeDeChambres<Chambre *> chambres)
{

}

void PiloteChambreGraphicView::afficher(ListeDeChambres<Chambre *> chambres)
{  
   m_afficheur->ascenceurChLibre()->setListeDesChambres(chambres);
   m_afficheur->ascenceurChOccupee()->setListeDesChambres(chambres);
}

void PiloteChambreGraphicView::rafraichir()
{
    m_afficheur->afficherDesChambres(  m_afficheur->ascenceurChLibre()->idPremiereCh()
                                     , m_afficheur->ascenceurChLibre()->chambres()
                                     , true);

    m_afficheur->afficherDesChambres(  m_afficheur->ascenceurChOccupee()->idPremiereCh()
                                     , m_afficheur->ascenceurChOccupee()->chambres()
                                     , false);
}

PiloteChambreGraphicView::~PiloteChambreGraphicView()
{
    delete m_afficheur;
}
