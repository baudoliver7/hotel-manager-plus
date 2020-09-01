#ifndef BDFACTURERUNGROUPE_H
#define BDFACTURERUNGROUPE_H

#include "bdLib_global.h"

#include <QDialog>
#include <QPrintDialog>
#include <QPrinter>

#include "agent.h"
#include "BDRechercherUnGroupe.h"
#include "BDFormulaireClientSimple.h"
#include "groupeLiaison.h"
#include "client.h"
#include "repasCompletResto.h"
#include "modeDePayement.h"
#include "MesTables.h"
#include "factureRestoGroupe.h"
#include "factureBarGroupe.h"

namespace Ui {
    class BDFacturerUnGroupe;
}

class BDLIBSHARED_EXPORT BDFacturerUnGroupe : public QDialog {
    Q_OBJECT
public:
    BDFacturerUnGroupe(QSqlDatabase * db, const agent & ag, QWidget *parent = 0);
    ~BDFacturerUnGroupe();

    inline QList<occupation> occupationsModifiees(){return m_occupations;};

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDFacturerUnGroupe *ui;
    agent m_agent;
    groupe m_groupe;
    client m_client;
    QList<occupation> m_occupations;
    QSqlDatabase * m_db;

    void afficherGroupe(const groupe & gr);
    void initialiser();
    bool enregistrerRestitution();
    bool enregistrerReglement();

private slots:
    void on_btn_detailsBar_clicked();
    void setLimitesSommeAPayer();
    void on_btn_detailsResto_clicked();
    void on_btn_payerTout_clicked();
    void on_spinBoxMontantAVerser_valueChanged(int );
    void on_btn_ok_clicked();
    void on_btn_annuler_clicked();
    void on_lineEditFraisDeRestauration_textChanged(QString );
    void chargerModeDePayement();
    void on_btn_details_clicked();
    void on_btn_groupe_clicked();
};

#endif // BDFACTURERUNGROUPE_H
