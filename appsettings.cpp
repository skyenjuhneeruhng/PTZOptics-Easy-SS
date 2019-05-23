#include "appsettings.h"
#include <QStandardPaths>
AppSettings::AppSettings()
{
    settings = new QSettings(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/settings.ini" , QSettings::IniFormat);
}
