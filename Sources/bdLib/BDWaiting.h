#ifndef BDWAITING_H
#define BDWAITING_H

#include "bdLib_global.h"

#include <QDialog>

namespace Ui {
    class BDWaiting;
}

class BDLIBSHARED_EXPORT BDWaiting : public QDialog {
    Q_OBJECT
public:
    BDWaiting(QWidget *parent = 0);
    ~BDWaiting();

    void lancerTacheAExecuter();

signals:
    void excuterTache();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDWaiting *ui;
};

#endif // BDWAITING_H
