#ifndef BDINFOSCONNECTION_H
#define BDINFOSCONNECTION_H

#include "bdLib_global.h"

#include <QDialog>

#define IDALIAS    0
#define IDSERVER   1
#define IDBDNAME   2
#define IDUSER     3
#define IDPASSWORD 4
#define IDPORT     5

namespace Ui {
    class BDInfosConnection;
}

class BDLIBSHARED_EXPORT BDInfosConnection : public QDialog {
    Q_OBJECT
public:
    BDInfosConnection(QStringList dsn, QWidget *parent = 0);
    ~BDInfosConnection();

    QString databaseName()const;
    QString serveur()const;
    QString user()const;
    QString password()const;
    int port()const;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDInfosConnection *ui;
};

#endif // BDINFOSCONNECTION_H
