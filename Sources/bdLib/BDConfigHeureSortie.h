#ifndef BDCONFIGHEURESORTIE_H
#define BDCONFIGHEURESORTIE_H

#include "bdLib_global.h"

#include <QDialog>
#include "HeureLimite.h"

namespace Ui {
    class BDConfigHeureSortie;
}

class BDLIBSHARED_EXPORT BDConfigHeureSortie : public QDialog {
    Q_OBJECT
public:
    BDConfigHeureSortie(QWidget *parent = 0);
    ~BDConfigHeureSortie();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDConfigHeureSortie *ui;

    void afficherHeureLimite();

private slots:
    void on_buttonBox_accepted();
};

#endif // BDCONFIGHEURESORTIE_H
