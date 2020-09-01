#ifndef BDDETAILSCLOTURE_H
#define BDDETAILSCLOTURE_H

#include "bdLib_global.h"
#include <QDialog>
#include <QSqlRelationalTableModel>

#include "operationService.h"
#include "modeDePayement.h"
#include "clotureService.h"

namespace Ui {
    class BDDetailsCloture;
}

class BDLIBSHARED_EXPORT BDDetailsCloture : public QDialog {
    Q_OBJECT
public:
    BDDetailsCloture(int idCloture, QWidget *parent = 0);
    ~BDDetailsCloture();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDDetailsCloture *ui;
    QSqlRelationalTableModel * m_modelActivites;
    int m_idCloture;

private slots:
    void on_btn_fermer_clicked();
    void chargerActivites();
    void initialiserTableauActivites();
};

#endif // BDDETAILSCLOTURE_H
