#ifndef BDDETAILSRESTOGROUPE_H
#define BDDETAILSRESTOGROUPE_H

#include <QDialog>

namespace Ui {
    class BDDetailsRestoGroupe;
}

class BDDetailsRestoGroupe : public QDialog {
    Q_OBJECT
public:
    BDDetailsRestoGroupe(QWidget *parent = 0);
    ~BDDetailsRestoGroupe();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDDetailsRestoGroupe *ui;
};

#endif // BDDETAILSRESTOGROUPE_H
