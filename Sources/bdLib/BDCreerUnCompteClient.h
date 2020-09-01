#ifndef BDCREERUNCOMPTECLIENT_H
#define BDCREERUNCOMPTECLIENT_H

#include "bdLib_global.h"

#include <QDialog>
#include "compteClient.h"
#include "client.h"
#include "operationCompteClient.h"
#include "agent.h"
#include "modeDePayement.h"
#include "bdd.h"

#include "BDIdentifierClientHotelSimple.h"

namespace Ui {
    class BDCreerUnCompteClient;
}

class BDLIBSHARED_EXPORT BDCreerUnCompteClient : public QDialog {
    Q_OBJECT
public:
    BDCreerUnCompteClient(BDD * db, const agent & ag, QWidget *parent = 0);
    ~BDCreerUnCompteClient();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDCreerUnCompteClient *ui;
    client m_client;
    agent m_agent;
    BDD * m_db;

private slots:
    void chargerModeDePayement();
    void on_spinBoxSolde_valueChanged(int );
    void chargerComptesExistants();
    void on_lineEditLibelle_textChanged(QString );
    void updateEtatBtnCreer();
    void on_btn_client_clicked();
    void on_btn_annuler_clicked();
    void on_btn_creer_clicked();
};

#endif // BDCREERUNCOMPTECLIENT_H
