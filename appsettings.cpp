#include "appsettings.h"
#include <QStandardPaths>
#include <QDir>
#include <QCoreApplication>
AppSettings::AppSettings()
{
    settings = new QSettings(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/settings.ini" , QSettings::IniFormat);
}
void AppSettings::setAppPath(QString appPath)
{
    settings->setValue("app_path" , appPath);
}
void AppSettings::setIdleTime(unsigned int idleTime)
{
    settings->setValue("idle_time" , idleTime);
}
void AppSettings::setRunAsAdmin(bool admin)
{
    settings->setValue("run_as_admin" , admin);
#ifdef _WIN32
    QString subKey = "Software\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\Layers";
    QString valueName = getApplicationDir();
    QString valueData = "~ RUNASADMIN";
    if(admin)
    {
        if(RegSetKeyValueA(HKEY_CURRENT_USER, subKey.toStdString().c_str(), valueName.toStdString().c_str(), REG_SZ, valueData.toStdString().c_str(), valueData.length()) == ERROR_SUCCESS)
        {
            //TODO
        }
    }
    else
    {
        if(RegDeleteKeyValueA(HKEY_CURRENT_USER, subKey.toStdString().c_str(), valueName.toStdString().c_str()) == ERROR_SUCCESS)
        {
            //TODO
        }
    }

#endif
}
void AppSettings::setRunOnStartup(bool startup)
{
    settings->setValue("run_on_startup" , startup);
#ifdef _WIN32
    QString subKey = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
    QString valueName = QString(APP_NAME);
    QString valueData = getApplicationDir();
    if(startup)
    {
        if(RegSetKeyValueA(HKEY_CURRENT_USER, subKey.toStdString().c_str(), valueName.toStdString().c_str(), REG_SZ, valueData.toStdString().c_str(), valueData.length()) == ERROR_SUCCESS)
        {
            //TODO
        }
    }
    else
    {
        if(RegDeleteKeyValueA(HKEY_CURRENT_USER, subKey.toStdString().c_str(), valueName.toStdString().c_str()) == ERROR_SUCCESS)
        {
            //TODO
        }
    }
#endif
}
void AppSettings::setTurnOnLaunch(bool launch)
{
    settings->setValue("turn_on_launch" , launch);
}

QString AppSettings::getAppPath()
{
    return settings->value("app_path" , "Choose an application.").toString();
}
unsigned int AppSettings::getIdleTime()
{
    return settings->value("idle_time" , 5).toUInt();
}
bool AppSettings::getRunAsAdmin()
{
    return settings->value("run_as_admin" , false).toBool();
}
bool AppSettings::getRunOnStartup()
{
    return settings->value("run_on_startup" , false).toBool();
}
bool AppSettings::getTurnOnLaunch()
{
    return settings->value("turn_on_launch" , false).toBool();
}
QString AppSettings::getApplicationDir()
{
    return QDir::toNativeSeparators(QCoreApplication::applicationFilePath());
}
