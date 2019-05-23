#include "mainwindow.h"
#include "essapp.h"

int main(int argc, char *argv[])
{
    ESSApp a(argc, argv);
    a.showUi();

    return a.exec();
}
