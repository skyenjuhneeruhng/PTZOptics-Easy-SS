#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QSettings>
#include <qt_windows.h>
#define APP_NAME "EasyScreenSaver"

class AppSettings
{
public:
    AppSettings();
    void setAppPath(QString appPath);
    void setIdleTime(unsigned int idleTime);
    void setRunAsAdmin(bool admin);
    void setRunOnStartup(bool startup);
    void setTurnOnLaunch(bool launch);

    QString getAppPath();
    unsigned int getIdleTime();
    bool getRunAsAdmin();
    bool getRunOnStartup();
    bool getTurnOnLaunch();
private:
    QSettings *settings;
    QString getApplicationDir();
};

#endif // APPSETTINGS_H
