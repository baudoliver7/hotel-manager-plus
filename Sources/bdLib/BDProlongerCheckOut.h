#ifndef BDPROLONGERCHECKOUT_H
#define BDPROLONGERCHECKOUT_H

#include "bdLib_global.h"

#include <QDialog>

namespace Ui {
    class BDProlongerCheckOut;
}

class BDLIBSHARED_EXPORT BDProlongerCheckOut : public QDialog {
    Q_OBJECT
public:
    BDProlongerCheckOut(QWidget *parent = 0);
    ~BDProlongerCheckOut();

    int nbDeJoursAAjouter()const;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDProlongerCheckOut *ui;

private slots:
    void on_spinBox_valueChanged(int );
    void on_btn_ok_clicked();
    void on_btn_annuler_clicked();
};

#endif // BDPROLONGERCHECKOUT_H
