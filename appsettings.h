#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QSettings>

class AppSettings
{
public:
    AppSettings();
private:
    QSettings *settings;
};

#endif // APPSETTINGS_H
