#ifndef BDCARDEX_H
#define BDCARDEX_H

#include "bdLib_global.h"

#include <QDialog>
#include <QSqlTableModel>

#include "BDFormulaireClientSimple.h"
#include "MesTables.h"
#include "BDWaiting.h"

#define ID 0
#define FACTURE 1
#define CHAMBRE 2
#define DATEARRIVEE 3
#define DATEDEPART 4
#define DUREE 5
#define MONTANTTOTAL 6
#define MONTANTPAYE 7
#define MONTANTRESTANT 8
#define MATRICULEAGENT 9

namespace Ui {
    class BDCardex;
}

class BDLIBSHARED_EXPORT BDCardex : public QDialog {
    Q_OBJECT
public:
    BDCardex(QWidget *parent = 0);
    ~BDCardex();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDCardex *ui;
    client m_clientSelectionne;
    QSqlTableModel * m_model;
    BDWaiting * m_bdWaiting;
    occupation m_occupSelectionnee;
    bool m_affichage;

    void afficherElement(int row, int column, const QString &value);
    void initialiserTableauLocations();

private slots:    
    void on_btn_modifier_clicked();
    void chargerLocations();
    void afficherLocations();
    void chargerClientsRecherches();
    void chargerAutresInfos();
    void on_btn_fermer_clicked();
    void on_btn_ajouter_clicked();
    void initialiserTableau();

    void selectionnerLocation(QModelIndex);
    void selectionnerClient(QModelIndex);

    void updateEtatAutresInfos(bool enabled);
    void updateEtatBtnModifier(QModelIndex);
};

#endif // BDCARDEX_H
