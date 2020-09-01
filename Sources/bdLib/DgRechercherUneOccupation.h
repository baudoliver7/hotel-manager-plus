#ifndef DGRECHERCHERUNEOCCUPATION_H
#define DGRECHERCHERUNEOCCUPATION_H

#include "bdLib_global.h"

#include <QDialog>
#include <QString>
#include <QStringList>
#include <QTableWidgetItem>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>

#include "InfosSurBD.h"
#include "Client.h"
#include "occupation.h"
#include "recevoirOccup.h"
#include "horloge.h"
#include "MesTables.h"
#include "agent.h"
#include "configServiceCompta.h"
#include "BDRestituerAuClient.h"
#include "HeureLimite.h"
#include "typeDeChambre.h"
#include "DialogCalendar.h"
#include "recuHotel.h"
#include "infosHotel.h"
#include "taux.h"

#define NUMERO_RESERV 0
#define CHAMBRE 1
#define DATE_ENTREE 2
#define OCCUPANT 3
#define DUREE_EN_JOURS 4
#define DATE_SORTIE 5
#define PRIXTOTAL 6
#define MONTANTVERSE 7
#define MONTANTRESTANT 8

namespace Ui {
    class DgRechercherUneOccupation;
}

class BDLIBSHARED_EXPORT DgRechercherUneOccupation : public QDialog {
    Q_OBJECT
public:
    DgRechercherUneOccupation(agent * ag, QWidget *parent = 0);
    ~DgRechercherUneOccupation();

    inline int nbOccupArretee()const{return m_nbOccupArretee;};

signals:
    void chambreEtatModifie();
    void bdModifie();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DgRechercherUneOccupation *ui;
    int m_nbOccupArretee;
    agent * m_recepteur;
    QList<typeDeChambre> m_typesDeChambreDispo;
    QStringList m_typesDeChambreStrDispo;

    void initialiserTypeDeChambre();
    void initialiserTable();
    void afficherElement(int row, int column, const QString & value);
    void liberer();
    int currentNumOp();

private slots:
    void on_spinBoxMontantSup_valueChanged(int );
    void on_btn_imprimerRecu_clicked();
    void on_btn_enregistrerFraisSup_clicked();
    void on_btn_enregistrerResto_clicked();
    void on_btn_enregistrer_clicked();
    void afficherFraisSupplementaire(QModelIndex);
    void afficherMontantReglementLoc(QModelIndex);
    void afficherMontantReglementResto(QModelIndex);
    void afficherMontantReglementFraisSup(QModelIndex);
    void updateEtatBtnEnregistrer();
    void updateEtatBtnEnregistrerFraisSup();
    void updateEtatBtnEnregistrerResto();
    void updatePeriode();
    void on_btn_fin_clicked();
    void on_btn_debut_clicked();
    void on_btn_supprimer_clicked();
    void updateEtatBtnLiberer(QModelIndex);
    void rafraichirTable();
    void on_btn_annuler_clicked();
    void on_btn_liberer_clicked();
};

#endif // DGRECHERCHERUNEOCCUPATION_H
