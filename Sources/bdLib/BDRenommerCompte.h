#ifndef BDRENOMMERCOMPTE_H
#define BDRENOMMERCOMPTE_H

#include "bdLib_global.h"

#include <QDialog>

#include "PlanComptable.h"

namespace Ui {
    class BDRenommerCompte;
}

class BDLIBSHARED_EXPORT BDRenommerCompte : public QDialog {
    Q_OBJECT
public:
    BDRenommerCompte(const planComptable & p, QWidget *parent = 0);
    ~BDRenommerCompte();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDRenommerCompte *ui;
    planComptable m_p;

private slots:
    void updateEtatBtnOK();
    void on_btn_ok_clicked();
    void on_btn_annuler_clicked();
};

#endif // BDRENOMMERCOMPTE_H
