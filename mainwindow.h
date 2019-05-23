#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShowEvent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void loadSettings();
    void initUi();
private slots:
    void onBrowseBtnClicked();
    void onStartBtnClicked();
    void onApplyBtnClicked();
    void onCancelBtnClicked();

protected:
    void showEvent(QShowEvent *ev);
};

#endif // MAINWINDOW_H
