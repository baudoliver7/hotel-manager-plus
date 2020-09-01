#include <QSettings>

#define PARAMSCONNECTION "Paramètres de connection"
#define APPNAME "HMP's product win32"
#define PRODUCTNAME "HMP"

int main(int argc, char *argv[])
{
    QSettings settings(APPNAME, PRODUCTNAME);

    /* Récupération des paramètres de connection */
    settings.setValue(PARAMSCONNECTION, QString());

    return 0;
}
