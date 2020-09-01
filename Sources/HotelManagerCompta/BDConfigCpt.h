#ifndef BDCONFIGCPT_H
#define BDCONFIGCPT_H

#include <QDialog>
#include <QStringList>
#include "PlanComptable.h"
#include "operationsComptables.h"
#include "configServiceCompta.h"

namespace Ui {
    class BDConfigCpt;
}

class BDConfigCpt : public QDialog {
    Q_OBJECT
public:
    BDConfigCpt(QWidget *parent = 0);
    ~BDConfigCpt();

    inline bool modified(){return m_modifie;};

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDConfigCpt *ui;
    QString m_libellesEnCours;
    QList<int> m_numerosCptEnCours;
    bool m_modifie;

private slots:
    void on_btn_supprimer_clicked();
    void on_btn_creer_clicked();
    void on_comboBoxNbChiffre_currentIndexChanged(QString );
    void on_comboBoxClasse_currentIndexChanged(QString );
    void on_rb_cpt_a_creer_clicked();
    void on_rb_cpt_existant_clicked();
    void on_btn_fermer_clicked();

private:
    void chargerMesComptes(bool utilises);
};

#endif // BDCONFIGCPT_H
