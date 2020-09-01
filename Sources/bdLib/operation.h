#ifndef OPERATION_H
#define OPERATION_H

#include "bdLib_global.h"

#include <QObject>
#include <QProgressDialog>
#include <QTimer>
#include <QWidget>

class BDLIBSHARED_EXPORT Operation : public QObject
{
    Q_OBJECT
public:
    Operation(QObject * parent, int maximum);
    ~Operation();

    void setMinimum(int minimum);
    void show();
    void setParentWidget(QWidget *);

private:
    int steps;
    QProgressDialog * pd;

public slots:
    void perform();
    void setValue(int value);
    void setLibelle(QString lib);
    void setMaximum(int maximum);
};

#endif // OPERATION_H
