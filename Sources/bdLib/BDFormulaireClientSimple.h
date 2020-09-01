#ifndef BDFORMULAIRECLIENTSIMPLE_H
#define BDFORMULAIRECLIENTSIMPLE_H

#include "bdLib_global.h"

#include <QDialog>

#include "client.h"
#include "profileClient.h"
#include "typeDeClient.h"
#include "pieceIdentiteClient.h"
#include "occupation.h"
#include "DialogContact.h"

namespace Ui {
    class BDFormulaireClientSimple;
}

class BDLIBSHARED_EXPORT BDFormulaireClientSimple : public QDialog {
    Q_OBJECT
public:
    BDFormulaireClientSimple(const client & cl, bool readOnly, QWidget *parent = 0);
    ~BDFormulaireClientSimple();

    client clientRenseigne()const{return m_client;};

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDFormulaireClientSimple *ui;
    client m_client;
    bool m_readOnly;

    void afficherClient(const client & cl);

private slots:
    void updateEtatBtnOK();
    void on_btn_calendrier_clicked();
    void on_btn_annuler_clicked();
    void on_btn_ok_clicked();
};

#endif // BDFORMULAIRECLIENTSIMPLE_H
