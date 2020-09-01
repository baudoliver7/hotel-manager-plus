#ifndef BDCONFIGURERMENURESTO_H
#define BDCONFIGURERMENURESTO_H

#include "bdLib_global.h"

#include <QDialog>

#include <QSqlTableModel>

#include "menuResto.h"
#include "categorieMenu.h"
#include "BDNvelleCategorieMenu.h"

namespace Ui {
    class BDConfigurerMenuResto;
}

class BDLIBSHARED_EXPORT BDConfigurerMenuResto : public QDialog {
    Q_OBJECT
public:
    BDConfigurerMenuResto(QWidget *parent = 0);
    ~BDConfigurerMenuResto();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDConfigurerMenuResto *ui;
    QSqlTableModel * m_model;
    QSqlTableModel * m_modelCategorie;

    void initialiserTable();
    void initialiserCategorie();

    int currentCategorie();

private slots:
    void on_comboBoxCategorie_currentIndexChanged(int index);
    void on_btn_nvelleCategorie_clicked();
    void on_btn_fermer_clicked();
    void updateEtatBtnSupprimer(QModelIndex);
    void on_btn_supprimer_clicked();
    void on_btn_ajouter_clicked();
    void chargerMenus();
    void chargerCategorie();
    void on_spinBoxPrixUnitaire_valueChanged(int );
    void on_lineEditLibelle_textChanged(QString );
};

#endif // BDCONFIGURERMENURESTO_H
