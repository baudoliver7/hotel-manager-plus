#ifndef BDNVELLECATEGORIEMENU_H
#define BDNVELLECATEGORIEMENU_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
    class BDNvelleCategorieMenu;
}

class BDNvelleCategorieMenu : public QDialog {
    Q_OBJECT
public:
    BDNvelleCategorieMenu(QWidget *parent = 0);
    ~BDNvelleCategorieMenu();

    QString libelle()const;
    bool plat()const;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDNvelleCategorieMenu *ui;

private slots:
    void on_btn_annuler_clicked();
    void on_btn_ok_clicked();
};

#endif // BDNVELLECATEGORIEMENU_H
