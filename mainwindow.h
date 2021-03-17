#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <UVsim.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(UVSim * machine) : simulator(machine) { QMainWindow(nullptr); };
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void populateTable();

    UVSim * simulator = nullptr;

private slots:
    void on_tableWidget_cellActivated(int row, int column);

    void on_tableWidget_cellChanged(int row, int column);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
