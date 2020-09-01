#ifndef BDRESTITUERAUCLIENT_H
#define BDRESTITUERAUCLIENT_H

#include <QDialog>

namespace Ui {
    class BDRestituerAuClient;
}

class BDRestituerAuClient : public QDialog {
    Q_OBJECT
public:
    BDRestituerAuClient(int somme, bool avance, QWidget *parent = 0);
    ~BDRestituerAuClient();

    int sommeARestituer();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDRestituerAuClient *ui;

private slots:
    void on_spinBoxSommeARestituer_valueChanged(int );
    void on_btn_annuler_clicked();
    void on_btn_ok_clicked();
};

#endif // BDRESTITUERAUCLIENT_H
