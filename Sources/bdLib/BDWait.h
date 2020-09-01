#ifndef BDWAIT_H
#define BDWAIT_H

#include "bdLib_global.h"
#include <QDialog>
#include <QTimer>
#include <QCloseEvent>

namespace Ui {
    class BDWait;
}

class BDLIBSHARED_EXPORT BDWait : public QDialog {
    Q_OBJECT
public:
    BDWait(QWidget *parent = 0);
    ~BDWait();

    void wait(int msec);

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent * e);

private:
    Ui::BDWait *ui;
    bool m_fermer;

private slots:
    void stop();
};

#endif // BDWAIT_H
