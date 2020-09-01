#ifndef BDAJUSTERHEURESYST_H
#define BDAJUSTERHEURESYST_H

#include "bdLib_global.h"

#include <QDialog>
#include <QDateTime>

namespace Ui {
    class BDAjusterHeureSyst;
}

class BDLIBSHARED_EXPORT BDAjusterHeureSyst : public QDialog {
    Q_OBJECT
public:
    BDAjusterHeureSyst(QWidget *parent = 0);
    BDAjusterHeureSyst(QDate date, QTime heure, QWidget *parent = 0);
    ~BDAjusterHeureSyst();

    QDateTime dateTimeSelectionnee()const;
protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDAjusterHeureSyst *ui;
};

#endif // BDAJUSTERHEURESYST_H
