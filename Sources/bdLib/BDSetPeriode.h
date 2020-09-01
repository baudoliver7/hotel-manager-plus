#ifndef BDSETPERIODE_H
#define BDSETPERIODE_H

#include "bdLib_global.h"

#include <QDialog>
#include <QDate>

#include "DialogCalendar.h"
#include "horloge.h"

namespace Ui {
    class BDSetPeriode;
}

class BDLIBSHARED_EXPORT BDSetPeriode : public QDialog {
    Q_OBJECT
public:
    BDSetPeriode(QDate debut, QDate fin, QWidget *parent = 0);
    ~BDSetPeriode();

    QDate dateDebut();
    QDate dateFin();

    bool isModified();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDSetPeriode *ui;
    QDate m_dateDebut;
    QDate m_dateFin;
    bool m_modified;

private slots:
    void setDateDebut();
    void setDateFin();
};

#endif // BDSETPERIODE_H
