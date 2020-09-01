#ifndef BDACTIVATIONPRODUCT_H
#define BDACTIVATIONPRODUCT_H

#include <QDialog>

namespace Ui {
    class BDActivationProduct;
}

class BDActivationProduct : public QDialog {
    Q_OBJECT
public:
    BDActivationProduct(QWidget *parent = 0);
    ~BDActivationProduct();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDActivationProduct *ui;
};

#endif // BDACTIVATIONPRODUCT_H
