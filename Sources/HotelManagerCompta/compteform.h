#ifndef COMPTEFORM_H
#define COMPTEFORM_H

#include <QWidget>
#include <QSqlTableModel>

#include "DialogCalendar.h"
#include "horloge.h"
#include "operationsComptables.h"
#include "BDExecuterNlleOperation.h"

namespace Ui {
    class CompteForm;
}

class CompteForm : public QWidget {
    Q_OBJECT
public:
    CompteForm(BDD * db, int numCompte, QWidget *parent = 0);
    ~CompteForm();

    void supprimerOperationCourante();

signals:
    void currentRowIsValid(bool);
    void opened(bool);

public:
    int numeroOperationCourante()const;

public slots:
    void chargerOperations();

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *);

private:
    Ui::CompteForm *ui;
    QSqlTableModel * m_operationsMdodel;
    BDD * m_db;
    int m_numeroCompte;

private slots:
    void on_btn_afficherOp_clicked();
    void on_rb_periode2_toggled(bool checked);
    void on_rb_periode1_toggled(bool checked);
    void on_rb_periode2_clicked();
    void on_rb_periode1_clicked();
    void on_btn_fin_clicked();
    void on_btn_debut_clicked();
    void preparerEtLancerRowIsValid(QModelIndex);

private:
    void setPeriode2Enabled(bool enabled);
    void chargerOperations(QString debut, QString fin);
    void initialiserTableau();
};

#endif // COMPTEFORM_H
