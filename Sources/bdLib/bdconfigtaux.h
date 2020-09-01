#ifndef BDCONFIGTAUX_H
#define BDCONFIGTAUX_H

#include "bdLib_global.h"

#include <QDialog>
#include <QSqlRecord>

#include "InfosSurBD.h"
#include "taux.h"
#include "MesTables.h"

namespace Ui {
    class BDConfigTaux;
}

class BDLIBSHARED_EXPORT BDConfigTaux : public QDialog {
    Q_OBJECT
public:
    BDConfigTaux(QWidget *parent = 0);
    ~BDConfigTaux();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDConfigTaux *ui;

    void afficherTaux();

private slots:
    void on_buttonBox_accepted();
};

#endif // BDCONFIGTAUX_H
