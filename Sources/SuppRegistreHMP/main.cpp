#include <QSettings>

#define PARAMSCONNECTION "Param�tres de connection"
#define APPNAME "HMP's product win32"
#define PRODUCTNAME "HMP"

int main(int argc, char *argv[])
{
    QSettings settings(APPNAME, PRODUCTNAME);

    /* R�cup�ration des param�tres de connection */
    settings.setValue(PARAMSCONNECTION, QString());

    return 0;
}
