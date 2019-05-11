#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "heatexchanger.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void CalcValues();
    void ResetValues();


private slots:
    void on_buttonCalculate_clicked();



    void on_buttonReset_clicked();

private:
    Ui::MainWindow *ui;
    HeatExchanger exchanger;
};
    #endif // MAINWINDOW_H
