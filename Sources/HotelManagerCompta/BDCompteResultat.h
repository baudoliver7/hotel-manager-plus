#ifndef BDCOMPTERESULTAT_H
#define BDCOMPTERESULTAT_H

#include <QDialog>

namespace Ui {
    class BDCompteResultat;
}

class BDCompteResultat : public QDialog {
    Q_OBJECT
public:
    BDCompteResultat(QWidget *parent = 0);
    ~BDCompteResultat();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDCompteResultat *ui;
};

#endif // BDCOMPTERESULTAT_H
