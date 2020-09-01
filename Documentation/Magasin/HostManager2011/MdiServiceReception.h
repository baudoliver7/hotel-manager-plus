#ifndef MDISERVICERECEPTION_H
#define MDISERVICERECEPTION_H

#include <QWidget>
#include <QCloseEvent>
#include <QResizeEvent>
#include <QMessageBox>
#include <QDateTime>
#include <QLineEdit>
#include <QFile>
#include <QTextStream>

#include "MesTables.h"
#include "PiloteChambreGraphicView.h"
#include "recepteur.h"
#include "initialdechambre.h"
#include "DialogContact.h"
#include "tarif.h"
#include "Client.h"
#include "Chambre.h"
#include "occupation.h"
#include "recevoir.h"
#include "DialogCalendar.h"
#include "reservation.h"
#include "CompagnonFidele.h"

#define OCCUPER_UNE_CHAMBRE 0
#define RESEVER_UNE_CHAMBRE 1

#define ID 0
#define NOM 1
#define SEXE 2
#define CEL 3
#define TYPE_ACTUEL 4
#define TYPE_CONSEILLE 5

#define TAB_MSG 0
#define TAB_SUGG 2

namespace Ui {
    class MdiServiceReception;
}

class MdiServiceReception : public QWidget {
    Q_OBJECT
public:
    MdiServiceReception(const recepteur * r, QWidget *parent = 0);
    ~MdiServiceReception();

    bool seDeconnecter();
    inline void setFermer(bool fermer){m_fermer = fermer;};
    inline CompagnonFidele * compagnonFidele(){return m_CompagnonFidele;};

public slots:
    void remplirOccuperUneChambre(client cl);
    void remplirOccuperUneChambre(reservation rv);
    void remplirReserverUneChambre(client cl);

signals:
    void closed();
    void bdModifiee();

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *e);
    void resizeEvent(QResizeEvent *);
    void showEvent(QShowEvent *);

private:
    Ui::MdiServiceReception *ui;
    recepteur * m_recepteur;
    PiloteChambreGraphicView * m_piloteChambreGV;
    CompagnonFidele * m_CompagnonFidele;
    ListeDeChambres<Chambre *> m_chambres;
    QGraphicsScene * m_scene;
    QGraphicsScene * m_sceneCpgFidele;
    bool m_fermer;
    QString m_typeDeChambreActif;
    bool m_demandeSuggProvOccup;
    client * m_clientEnCours;

    void souhaiterBienvenue();
    void afficherDateDeConnection();
    void afficherNumeroClient();
    void afficherNumeroReservation();
    void afficherPrixTotal();
    void initialiserTabWidgetEnregistrement();
    void initialiserTabOccuperUneChambre();
    void initialiserTabReserverUneChambre();
    void initialiserChambreGV();
    void initialiserCompagnonFidele();
    bool tabOccuperActif();
    void enregistrerOccupationEnCours();
    void enregistrerReservationEnCours();
    void chargerTypesDeChambre();
    void chargerTypesClient();
    void chargerPrixDeChambre();
    void ouvrirBoiteAContacts(QLineEdit * lineEdit);
    void ouvrirCalendrier();
    bool estUnHomme_occup();
    bool estUnHomme_reserv();
    void afficherTabOccuperUneChambre();
    void afficherTabReserverUneChambre();
    ListeDeChambres<Chambre *> chambres(QString type);

    void ajouterUneSuggestion(client cl);
    void ajouterUnEltSuggestion(int row, int column, QString valeur);
    QString typeConseille(client cl);
    void afficherSuggestions(QString nom, QString prenoms);

private slots:
    void updateBtnCharge(QModelIndex );
    void on_btn_charger_clicked();
    void on_lineEditPrenomReserv_textChanged(QString );
    void on_lineEditNomReserv_textChanged(QString );
    void on_lineEditPrenomOcc_textChanged(QString );
    void on_lineEditNomOcc_textChanged(QString );
    void on_btn_effacer_clicked();
    void actualiserFenetre();
    void afficherLesChambres();
    void rafraichir();
    void on_spinBoxNbJoursReserv_valueChanged(int );
    void on_comboBoxDureeJoursReserv_currentIndexChanged(int index);
    void on_btn_contactReserv_clicked();
    void on_btn_calendrier_clicked();
    void on_btn_initialiser_clicked();
    void on_spinBoxNbJoursOcc_valueChanged(int );
    void on_comboBoxTypeClient_currentIndexChanged(QString );
    void on_comboBoxTypeCh_currentIndexChanged(QString );
    void on_btn_contactOcc_clicked();
    void on_comboBoxDureeOcc_currentIndexChanged(int index);
    void on_btn_enregistrer_clicked();

    void chargerIdentifiantsChDispo_occup();
    void chargerIdentifiantsChDispo_reserv();
    void actualiserEtatBtnEnregistrer();

    static void arrangerParOrdreCroissant(QStringList & l);
};

#endif // MDISERVICERECEPTION_H
