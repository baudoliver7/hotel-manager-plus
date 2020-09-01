#ifndef BDCONFIGCOMPTARECEPT_H
#define BDCONFIGCOMPTARECEPT_H

#include <QDialog>

namespace Ui {
    class BDConfigComptaRecept;
}

class BDConfigComptaRecept : public QDialog {
    Q_OBJECT
public:
    BDConfigComptaRecept(QWidget *parent = 0);
    ~BDConfigComptaRecept();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDConfigComptaRecept *ui;
};

#endif // BDCONFIGCOMPTARECEPT_H
