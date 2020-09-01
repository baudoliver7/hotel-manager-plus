#ifndef BDREGLERFACTURE_H
#define BDREGLERFACTURE_H

#include "bdLib_global.h"

#include "repasCompletResto.h"
#include "agent.h"
#include "client.h"
#include "operationService.h"
#include "modeDePayement.h"
#include "recuInitial.h"
#include "BDIdentifierClientResto.h"
#include "compteClient.h"
#include "bdd.h"

#include <QDialog>

namespace Ui {
    class BDReglerFacture;
}

class BDLIBSHARED_EXPORT BDReglerFacture : public QDialog {
    Q_OBJECT
public:
    BDReglerFacture(BDD * db, const agent & ag, QWidget *parent = 0);
    ~BDReglerFacture();

    inline bool modified()const{return m_modified;};

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDReglerFacture *ui;
    agent * m_agent;
    client * m_client;
    BDD * m_db;
    repasCompletResto m_rcr;
    bool m_modified;
    QList<compteClient> m_comptesClient;

    QString currentFacture();

private slots:
    void on_comboBoxCompteClient_currentIndexChanged(int index);
    void on_comboBoxModeDePayement_currentIndexChanged(int index);
    void updateEtatBtnRegler(int);
    void on_btn_regler_clicked();
    void on_btn_identifier_clicked();
    void on_btn_fermer_clicked();
    void chargerFactures();
    void chargerModeDePayement();
    void afficherReglement(QModelIndex);
};

#endif // BDREGLERFACTURE_H
