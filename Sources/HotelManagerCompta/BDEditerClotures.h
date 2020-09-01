#ifndef BDEDITERCLOTURES_H
#define BDEDITERCLOTURES_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>

#include "clotureService.h"
#include "operationService.h"
#include "agent.h"
#include "modeDePayement.h"
#include "taux.h"
#include "PlanComptable.h"
#include "MesTables.h"
#include "configServiceCompta.h"
#include "BDExecuterNlleOperation.h"

namespace Ui {
    class BDEditerClotures;
}

class BDEditerClotures : public QDialog {
    Q_OBJECT
public:
    BDEditerClotures(BDD * db, const agent & ag, QWidget *parent = 0);
    ~BDEditerClotures();

    bool isModified();

protected:
    void changeEvent(QEvent *e);
    QSqlTableModel * m_modelClotures;
    QSqlRelationalTableModel * m_modelOperations;
    BDD * m_db;
    QStringList m_comptesStr;
    agent m_agent;
    float m_tauxTVA;
    float m_tauxTT;
    bool m_modified;

    void initialiserClotures();
    void initialiserOperations();
    void initialiserGroupeCritere();
    void initialiserComptes();

private:
    Ui::BDEditerClotures *ui;

private slots:
    void on_btn_operation_depouillee_clicked();
    void on_btn_faireUneOperation_clicked();
    void on_comboBoxRessource_currentIndexChanged(int index);
    void on_btn_depouiller_clicked();
    void updateEtatBtnDepouillerEntier(QModelIndex);
    void updateEtatBtnDepouillerOp(QModelIndex);
    void updateEtatGroupeDetails(QModelIndex);
    void updateEtatGroupeCritere(QModelIndex);
    void on_btn_depouilleEntier_clicked();
    void updateEtatGroupeVenteEtLocation(bool);
    void on_btn_fermer_clicked();
    void chargerClotures();
    void chargerOperations();
};

#endif // BDEDITERCLOTURES_H
