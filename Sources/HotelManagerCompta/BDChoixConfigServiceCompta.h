#ifndef BDCHOIXCONFIGSERVICECOMPTA_H
#define BDCHOIXCONFIGSERVICECOMPTA_H

#include <QDialog>

#include "PlanComptable.h"

namespace Ui {
    class BDChoixConfigServiceCompta;
}

class BDChoixConfigServiceCompta : public QDialog {
    Q_OBJECT
public:
    BDChoixConfigServiceCompta(int compteAssocie, QWidget *parent = 0);
    ~BDChoixConfigServiceCompta();

    int compteAssocie();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDChoixConfigServiceCompta *ui;
    QList<int> m_numCpts;

private slots:
    void on_btn_ok_clicked();
    void on_btn_annuler_clicked();
    void chargerComptes();
};

#endif // BDCHOIXCONFIGSERVICECOMPTA_H
