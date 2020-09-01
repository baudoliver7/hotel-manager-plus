#ifndef BDEDITERUNMVT_H
#define BDEDITERUNMVT_H

#include <QDialog>

#include "PlanComptable.h"

namespace Ui {
    class BDEditerUnMvt;
}

class BDEditerUnMvt : public QDialog {
    Q_OBJECT
public:
    BDEditerUnMvt(bool debiteur, bool editer, QWidget *parent = 0, QString libelleComplet = 0, int montant = 0);
    ~BDEditerUnMvt();

    int numCpt();
    int montant();
    bool debiteur();
    QString libelle();
    bool modified();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDEditerUnMvt *ui;
    bool m_debiteur;
    bool m_editer;
    bool m_modified;
    QStringList m_libellesComplets;

private slots:
    void on_comboBoxLibelleCpt_currentIndexChanged(QString );
    void on_btn_ok_clicked();
    void on_btn_annuler_clicked();
    void on_spinBoxMontant_valueChanged(QString );
    void chargerMesComptes();
    void updateEtatsBtn();
};

#endif // BDEDITERUNMVT_H
