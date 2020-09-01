#ifndef BDINFOSHOTELS_H
#define BDINFOSHOTELS_H

#include "bdLib_global.h"

#include <QDialog>
#include <QFileDialog>
#include <QPixmap>

#include "DialogContact.h"
#include "infosHotel.h"

namespace Ui {
    class BDInfosHotels;
}

class BDLIBSHARED_EXPORT BDInfosHotels : public QDialog {
    Q_OBJECT
public:
    BDInfosHotels(QWidget *parent = 0);
    ~BDInfosHotels();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDInfosHotels *ui;
    QPixmap m_pixmap;
    QString m_fileName;
    infosHotel * m_ih;

private slots:
    void on_btn_ok_clicked();
    void on_btn_insererLogo_clicked();
    void on_btn_contacts_clicked();
    void on_btn_annuler_clicked();
};

#endif // BDINFOSHOTELS_H
