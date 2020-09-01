#ifndef DIALOGCONTACT_H
#define DIALOGCONTACT_H

#include <QDialog>

namespace Ui {
    class DialogContact;
}

class DialogContact : public QDialog {
    Q_OBJECT
public:
    DialogContact(QString contact = QString(), QWidget *parent = 0);
    ~DialogContact();

    QString getContact();
    bool estVide();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DialogContact *ui;
    QString m_contactVide;

private slots:
    void on_btn_Annuler_clicked();
    void on_btn_OK_clicked();

private:
    void afficherContacts(QString contact);

public:
     QString contactVide();
     QString numeroCel();
     QString numeroTel();
     QString email();
     QString Bp();

public:
     static QString contacts(QString cel, QString tel, QString email, QString bp);
};

#endif // DIALOGCONTACT_H
