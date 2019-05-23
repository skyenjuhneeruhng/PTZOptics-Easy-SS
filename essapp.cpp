#include "essapp.h"

ESSApp::ESSApp(int argc, char *argv[]):QApplication(argc, argv)
{
    mainWin = new MainWindow;
    appSetting = new AppSettings;
}
void ESSApp::showUi()
{
    mainWin->show();
}
