#include "mainwindow.h"
#include "essapp.h"

int main(int argc, char *argv[])
{
    //for 4k monitor hdpi scaling
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setDesktopSettingsAware(true);


    ESSApp a(argc, argv);
    a.setQuitOnLastWindowClosed(false);
    a.showUi();

    return a.exec();
}
