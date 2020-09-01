#ifndef BDFACTURERCLIENT_H
#define BDFACTURERCLIENT_H

#include "bdLib_global.h"

#include <QDialog>

#include "modeDePayement.h"
#include "client.h"
#include "occupation.h"
#include "agent.h"
#include "reservation.h"
#include "repasCompletResto.h"
#include "prixChambreTTC.h"
#include "chambreReservee.h"
#include "compteClient.h"
#include "MesTables.h"
#include "bdd.h"

namespace Ui {
    class BDFacturerClient;
}

class BDLIBSHARED_EXPORT BDFacturerClient : public QDialog {
    Q_OBJECT
public:
    BDFacturerClient(BDD * db, const agent & ag, int idClient, int idActivite, bool occuper, bool groupe, QWidget *parent = 0);
    ~BDFacturerClient();

    int coutTotalLocation()const;
    int resteLocation()const;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDFacturerClient *ui;
    BDD * m_db;
    client m_client;
    agent m_agent;
    occupation m_occupation;
    reservation m_reservation;
    bool m_occuper;
    QList<QSqlRecord> m_recordsResto, m_recordsBar;
    int m_prixUnitaireNorm;
    QList<compteClient> m_comptesDuClient;

private slots:
    void setLimitesSommeAPayer();
    void on_btn_maximum_SV_clicked();
    void on_spinBoxVersement_valueChanged(int );
    void on_comboBoxCompteClient_currentIndexChanged(int index);
    void chargerComptesDuClient();
    void on_comboBoxModeDePayement_currentIndexChanged(int index);
    void on_spinBoxFraisPenaliteRetard_valueChanged(int );
    void on_lineEditFraisResto_textChanged(QString );
    void on_spinBoxTarif_valueChanged(int );
    void on_btn_appliquerTarifNorm_clicked();
    void on_btn_annuler_clicked();
    void on_btn_ok_clicked();
    void chargerModeDePayement();
    bool enregistrerFacturationOccup();
    bool enregistrerFacturactionReserv();
    bool enregistrerRestitutionOccup();
    bool enregistrerRestitutionReserv();
    bool enregistrerReglementOccup();
    bool enregistrerReglementReserv();
};

#endif // BDFACTURERCLIENT_H
