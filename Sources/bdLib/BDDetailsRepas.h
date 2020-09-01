#ifndef BDDETAILSREPAS_H
#define BDDETAILSREPAS_H

#include "bdLib_global.h"

#include <QDialog>
#include <QPrintDialog>
#include <QPrinter>

#include "consoResto.h"
#include "menuResto.h"
#include "repasCompletResto.h"
#include "factureRestoIndividu.h"

#define MENU 0
#define PRIXUNITAIRE 1
#define _QUANTITE 2
#define PRIXTOTAL 3

namespace Ui {
    class BDDetailsRepas;
}

class BDLIBSHARED_EXPORT BDDetailsRepas : public QDialog {
    Q_OBJECT
public:
    BDDetailsRepas(int idRepasCResto, QWidget *parent = 0);
    ~BDDetailsRepas();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDDetailsRepas *ui;
    int m_idRepasCResto;

    void rafraichirTable();
    void afficherElement(int row, int column, const QString &value);
    void initialiserTableau();

private slots:
    void on_btn_imprimerFacture_clicked();
    void on_btn_fermer_clicked();
};

#endif // BDDETAILSREPAS_H
