#include "essapp.h"

ESSApp::ESSApp(int argc, char *argv[]):QApplication(argc, argv)
{

    appSetting = new AppSettings;
    mainWin = new MainWindow;
    sysTrayInit();
    //if turn on upon lauch start
    //TODO
}
ESSApp::~ESSApp()
{

}
void ESSApp::showUi()
{
    mainWin->show();
}
void ESSApp::hideUi()
{
    mainWin->close();
}
void ESSApp::quitApp()
{
    quit();
}
AppSettings *ESSApp::getAppSetting()
{
    return this->appSetting;
}
void ESSApp::sysTrayInit()
{
    appTrayIcon = new QSystemTrayIcon(QIcon(":/assets/trayicon.png") , this);

    actionToggle = new QAction("Start" , appTrayIcon);
    connect(actionToggle , SIGNAL(triggered()) , this , SLOT(onStartStop()));
    actionShowWindow = new QAction("Show/Hide" , appTrayIcon);
    connect(actionShowWindow , SIGNAL(triggered()) , this , SLOT(onShowHide()));
    actionExit = new QAction("Exit" , appTrayIcon);
    connect(actionExit , SIGNAL(triggered()) , this , SLOT(onExit()));

    trayMenu = new QMenu();
    trayMenu->addAction(actionShowWindow);
    trayMenu->addAction(actionToggle);
    trayMenu->addAction(actionExit);

    appTrayIcon->setContextMenu(trayMenu);
    appTrayIcon->show();
}
void ESSApp::onShowHide()
{
    if(mainWin->isVisible())
        hideUi();
    else
        showUi();
}
void ESSApp::onStartStop()
{
    //TODO
}
void ESSApp::onExit()
{
    quitApp();
}
