#ifndef BDNOMDUSERVEUR_H
#define BDNOMDUSERVEUR_H

#include "bdLib_global.h"

#include <QDialog>

namespace Ui {
    class BDNomDuServeur;
}

class BDLIBSHARED_EXPORT BDNomDuServeur : public QDialog {
    Q_OBJECT
public:
    BDNomDuServeur(QWidget *parent = 0);
    ~BDNomDuServeur();

    QString nomDuServeur()const;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDNomDuServeur *ui;
};

#endif // BDNOMDUSERVEUR_H
