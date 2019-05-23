#ifndef ESSAPP_H
#define ESSAPP_H

#include <QApplication>
#include <QMenu>
#include <QAction>
#include <QSystemTrayIcon>
#include "mainwindow.h"
#include "appsettings.h"

class ESSApp : public QApplication
{
    Q_OBJECT
public:
    ESSApp(int argc, char *argv[]);
    ~ESSApp();
    void showUi();
    void hideUi();
    void quitApp();
    AppSettings *getAppSetting();
private:
    MainWindow *mainWin;
    AppSettings *appSetting;

private:
    void sysTrayInit();
    QSystemTrayIcon *appTrayIcon;
    QAction *actionToggle;
    QAction *actionShowWindow;
    QAction *actionExit;
    QMenu *trayMenu;
private slots:
    void onShowHide();
    void onStartStop();
    void onExit();
};
inline ESSApp *App() {return static_cast<ESSApp*>(qApp);}
#endif // ESSAPP_H
