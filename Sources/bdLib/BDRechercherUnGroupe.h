#ifndef BDRECHERCHERUNGROUPE_H
#define BDRECHERCHERUNGROUPE_H

#include "bdLib_global.h"

#include <QDialog>
#include <QPrintDialog>
#include <QPrinter>

#include "groupe.h"
#include "client.h"
#include "factureHotelGroupe.h"
#include "factureRestoGroupe.h"
#include "factureBarGroupe.h"
#include "DialogContact.h"
#include "BDWaiting.h"

namespace Ui {
    class BDRechercherUnGroupe;
}

class BDLIBSHARED_EXPORT BDRechercherUnGroupe : public QDialog {
    Q_OBJECT
public:
    BDRechercherUnGroupe(bool searchOnly, QWidget *parent = 0);
    ~BDRechercherUnGroupe();

    groupe groupeSelectionne()const{return m_groupeSelectionne;};

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDRechercherUnGroupe *ui;
    groupe m_groupeSelectionne;
    BDWaiting * m_bdWaiting;

    int currentIdGroupe();

private slots:
    void on_btn_imprimerBar_clicked();
    void updateEtatGroupeRech();
    void on_btn_contacts_clicked();
    void on_btn_imprimerResto_clicked();
    void on_btn_imprimerHotel_clicked();
    void on_btn_choisir_clicked();
    void on_btn_annuler_clicked();
    void chargerGroupes();
    void updateEtatBtnChoisir();
    void afficherGroupes();
};

#endif // BDRECHERCHERUNGROUPE_H
