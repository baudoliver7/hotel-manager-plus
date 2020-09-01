#ifndef BDCONFIGCOMPTASERVICE_H
#define BDCONFIGCOMPTASERVICE_H

#include <QDialog>

#include "serviceEntreprise.h"
#include "configServiceCompta.h"
#include "BDChoixConfigServiceCompta.h"

namespace Ui {
    class BDConfigComptaService;
}

class BDConfigComptaService : public QDialog {
    Q_OBJECT
public:
    BDConfigComptaService(QWidget *parent = 0);
    ~BDConfigComptaService();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDConfigComptaService *ui;
    QSqlTableModel * m_confiServiceCompte;
    QList<int> m_idSes;

    void initialiserTableau();

private slots:
    void on_btn_editer_clicked();
    void on_comboBoxServices_currentIndexChanged(int index);
    void on_btn_fermer_clicked();
    void chargerServices();
    void chargerConfigServiceCompta();
    void updateEtatBtnEditer(QModelIndex);
};

#endif // BDCONFIGCOMPTASERVICE_H
