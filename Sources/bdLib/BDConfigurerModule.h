#ifndef BDCONFIGURERMODULE_H
#define BDCONFIGURERMODULE_H

#include "bdLib_global.h"

#include <QDialog>
#include <QFile>

namespace Ui {
    class BDConfigurerModule;
}

class BDLIBSHARED_EXPORT BDConfigurerModule : public QDialog {
    Q_OBJECT
public:
    BDConfigurerModule(QWidget *parent = 0);
    ~BDConfigurerModule();

    bool modified()const{return m_modified;};
    bool barEstChoisi()const;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDConfigurerModule *ui;
    bool m_modified;

private slots:
    void on_btn_annuler_clicked();
    void on_btn_ok_clicked();
    void setModified();
};

#endif // BDCONFIGURERMODULE_H
