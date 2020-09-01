#ifndef BDDEBITERUNCOMPTECLIENT_H
#define BDDEBITERUNCOMPTECLIENT_H

#include "bdLib_global.h"

#include <QDialog>

#include "BDIdentifierClientHotelSimple.h"
#include "agent.h"
#include "modeDePayement.h"
#include "client.h"
#include "MesTables.h"
#include "bdd.h"

#define NUM 0
#define LIBELLE 1
#define SOLDE 2

namespace Ui {
    class BDDebiterUnCompteClient;
}

class BDLIBSHARED_EXPORT BDDebiterUnCompteClient : public QDialog {
    Q_OBJECT
public:
    BDDebiterUnCompteClient(BDD * db, const agent & ag, QWidget *parent = 0);
    ~BDDebiterUnCompteClient();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDDebiterUnCompteClient *ui;
    agent m_agent;
    client m_client;
    BDD * m_db;

    int currentIdCompteClient();
    int currentSolde();
    QString currentLibelle();
    void initialiserGroupeDebiter();

private slots:
    void setLimitesMontantVerse();
    void updateLibelleBtnDebiter();
    void updateEtatBtnDebiter(int montant);
    void on_btn_debiter_clicked();
    void on_btn_fermer_clicked();
    void updateEtatGroupeDebiterCompte(QModelIndex);
    void chargerComptesExistants();
    void chargerModeDePayement();
    void on_btn_identifier_clicked();
};

#endif // BDDEBITERUNCOMPTECLIENT_H
