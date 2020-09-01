#ifndef BDCONFIGURERTABLERESTO_H
#define BDCONFIGURERTABLERESTO_H

#include "bdLib_global.h"

#include <QDialog>
#include <QSqlTableModel>

#include "tableResto.h"

namespace Ui {
    class BDConfigurerTableResto;
}

class BDLIBSHARED_EXPORT BDConfigurerTableResto : public QDialog {
    Q_OBJECT
public:
    BDConfigurerTableResto(bool estBar, QWidget *parent = 0);
    ~BDConfigurerTableResto();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDConfigurerTableResto *ui;
    QSqlTableModel * m_model;
    bool m_modified;
    bool m_estBar;

    void initialiserTable();

private slots:
    void on_btn_supprimer_clicked();
    void on_btn_ajouter_clicked();
    void on_btn_appliquer_clicked();
    void on_tableView_doubleClicked(QModelIndex index);
    void updateEtatBtnSupprimer(QModelIndex);
    void chargerTables();
    void on_lineEditLibelle_textChanged(QString );
    void on_btn_fermer_clicked();
};

#endif // BDCONFIGURERTABLERESTO_H
