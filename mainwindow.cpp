#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "essapp.h"
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUi();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::initUi()
{
    connect(ui->browseBtn , SIGNAL(clicked(bool)) , this , SLOT(onBrowseBtnClicked()));
    connect(ui->startBtn , SIGNAL(clicked(bool)) , this , SLOT(onStartBtnClicked()));
    connect(ui->applyBtn , SIGNAL(clicked(bool)) , this , SLOT(onApplyBtnClicked()));
    connect(ui->cancelBtn , SIGNAL(clicked(bool)) , this , SLOT(onCancelBtnClicked()));
}

void MainWindow::onBrowseBtnClicked()
{
    QString appPath = QFileDialog::getOpenFileName(this , "Choose an application" , "./");
    if(appPath != "")
        ui->appPathEdit->setText(appPath);
}
void MainWindow::onStartBtnClicked()
{

}
void MainWindow::onApplyBtnClicked()
{
    App()->getAppSetting()->setAppPath(ui->appPathEdit->text());
    App()->getAppSetting()->setIdleTime(ui->idleTimeEdit->text().toUInt());
    App()->getAppSetting()->setRunAsAdmin(ui->runAsAdminCheck->isChecked());
    App()->getAppSetting()->setRunOnStartup(ui->runOnWindowStartupCheck->isChecked());
    App()->getAppSetting()->setTurnOnLaunch(ui->turnOnUponLaunchCheck->isChecked());
}
void MainWindow::onCancelBtnClicked()
{
    close();
}
void MainWindow::loadSettings()
{
    ui->appPathEdit->setText(App()->getAppSetting()->getAppPath());
    ui->idleTimeEdit->setText(QString::number(App()->getAppSetting()->getIdleTime()));
    ui->runAsAdminCheck->setChecked(App()->getAppSetting()->getRunAsAdmin());
    ui->runOnWindowStartupCheck->setChecked(App()->getAppSetting()->getRunOnStartup());
    ui->turnOnUponLaunchCheck->setChecked(App()->getAppSetting()->getTurnOnLaunch());
}
void MainWindow::showEvent(QShowEvent *ev)
{
    loadSettings();
    ev->accept();
}
