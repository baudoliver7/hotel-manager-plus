#ifndef BDCHARGEMENT_H
#define BDCHARGEMENT_H

#include <QDialog>

namespace Ui {
    class BDChargement;
}

class BDChargement : public QDialog {
    Q_OBJECT
public:
    BDChargement(QWidget *parent = 0);
    ~BDChargement();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDChargement *ui;
};

#endif // BDCHARGEMENT_H
