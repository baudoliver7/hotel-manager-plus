#ifndef BDAUTRESSORTIES_H
#define BDAUTRESSORTIES_H

#include "bdLib_global.h"

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
    class BDAutresSorties;
}

class BDLIBSHARED_EXPORT BDAutresSorties : public QDialog {
    Q_OBJECT
public:
    BDAutresSorties(QWidget *parent = 0);
    ~BDAutresSorties();

    QString description()const;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDAutresSorties *ui;

private slots:
    void on_lineEditDescription_textChanged(QString );
    void on_buttonBox_accepted();
};

#endif // BDAUTRESSORTIES_H
