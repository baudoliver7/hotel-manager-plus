#include "operation.h"

Operation::Operation(QObject *parent, int maximum)
    : QObject(parent), steps(0)
{
    pd = new QProgressDialog("Chargement...", QString(), 0, maximum);
    pd->setWindowTitle("Processus");
    pd->setWindowModality(Qt::WindowModal);
     //connect(pd, SIGNAL(canceled()), this, SLOT(cancel()));
}

Operation::~Operation()
{
    delete pd;
}

void Operation::perform()
{
    steps++;
    pd->setValue(steps);
     //... perform one percent of the operation
     if(steps == pd->maximum())
    {
         steps = 0;
         pd->setMinimum(steps);
         pd->reset();
    }

}

void Operation::setMaximum(int maximum)
{
    pd->setMaximum(maximum);
}

void Operation::setMinimum(int minimum)
{
    pd->setMinimum(minimum);
}

void Operation::show()
{
    pd->show();
}

void Operation::setParentWidget(QWidget * p)
{
    pd->setParent(p);
}

void Operation::setValue(int value)
{
    pd->setValue(value);
}

void Operation::setLibelle(QString lib)
{
    pd->setLabelText(lib);
}
