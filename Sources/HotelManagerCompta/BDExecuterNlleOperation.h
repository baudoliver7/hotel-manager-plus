#ifndef BDEXECUTERNLLEOPERATION_H
#define BDEXECUTERNLLEOPERATION_H

#include <QDialog>
#include <QModelIndex>

#include "BDEditerUnMvt.h"
#include "MesTables.h"
#include "DialogCalendar.h"
#include "bdd.h"

namespace Ui {
    class BDExecuterNlleOperation;
}

class BDExecuterNlleOperation : public QDialog {
    Q_OBJECT
public:
    BDExecuterNlleOperation(BDD * db, QString matriculeAgent, QWidget *parent = 0, bool afficher = false, int numOp = 0);
    ~BDExecuterNlleOperation();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDExecuterNlleOperation *ui;
    BDD * m_db;
    QString m_matricule;

private slots:
    void on_btn_calendrier_clicked();
    void on_rb_enDiffere_clicked();
    void on_rb_enLive_clicked();
    void on_btn_executer_clicked();
    void on_btn_editer_clicked();
    void on_btn_supprimerMvt_clicked();
    void on_btn_mvtDebiteur_clicked();
    void on_btn_mvtCrediteur_clicked();
    void on_btn_annuler_clicked();
    void updateEtatBtnSuprEtEditer();

private:
    void newEditerUnMvt(bool debiteur, QString title);
    void modifierUnMvt(int row);
    void initialiserTableau();
    void afficherUnElt(int row, int col, QString value);
    void afficherUneLigne(int row, int numCpt, QString libelle, int montant, bool debiter);
    void ajouterUneLigne(int numCpt, QString libelle, int montant, bool debiter);
    void supprimerUneLigne(int row);
    int numCpt(int row);
    bool debiteur(int row);
    int montant(int row);
    QString libelle(int row);
    QString libelleComplet(int row);
    void afficher(int numOp);
};

#endif // BDEXECUTERNLLEOPERATION_H
