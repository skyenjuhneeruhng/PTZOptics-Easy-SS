#ifndef ESSAPP_H
#define ESSAPP_H

#include <QApplication>
#include "mainwindow.h"
#include "appsettings.h"

class ESSApp : public QApplication
{
public:
    ESSApp(int argc, char *argv[]);
    void showUi();
private:
    MainWindow *mainWin;
    AppSettings *appSetting;
};

#endif // ESSAPP_H
