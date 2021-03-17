#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAbstractItemModel>
#include <QTableView>
#include <QTableWidget>
#include <iostream>
#include <QDebug>

    const int MEM_DATA_COLUMN = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



   //for (int i = 0; i < 2; i++)
   //    ui->tableWidget->insertColumn(i);
   //
   //for (int i = 0; i < 100; i++)
   //    ui->tableWidget->insertRow(i);
   //
   //ui->tableWidget->setVerticalHeaderLabels(row_labels);
   //
   //auto header = ui->tableWidget->horizontalHeader();
   //header->setFrameStyle(QFrame::Box | QFrame::Plain);
   //header->setLineWidth(1);
   //ui->tableWidget->setHorizontalHeader(header);
}

void MainWindow::populateTable()
{
    QStringList row_labels;

    auto row_list = ui->tableWidget->selectedItems();
    for (int i = 0; i < 100; i++)
    {
        try{

        QTableWidgetItem * item_ptr = nullptr;
        //auto item_string = QString(simulator->mainMemory[i].readWord());
        auto item_string = QString::number(simulator->mainMemory[i].readWord());

        while (item_string.length() < 4)
        {
            item_string.prepend('0');
        }

        item_ptr = new QTableWidgetItem(item_string);


        ui->tableWidget->setItem(i, MEM_DATA_COLUMN, item_ptr);
        row_labels << QString("%1").arg(i);
         }
        catch(exception e)
        {
            qDebug() << e.what() << '\n';
        }

    }
    ui->tableWidget->setVerticalHeaderLabels(row_labels);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    static int debug = 0;
    if (column == MEM_DATA_COLUMN)
    {
        int new_num = ui->tableWidget->item(row, column)->text().toInt();

        simulator->mainMemory[row].writeWord(new_num);

        QString new_text = QString::number(simulator->mainMemory[row].readWord());

        if (new_text.at(0) == '-')
        {
            while (new_text.length() < 5)
            {
               new_text.insert(1, '0');
            }
        }
        else
        {
            while (new_text.length() < 4)
            {
                new_text.prepend('0');
            }
                new_text.prepend('+');
        }

        debug++;
        ui->tableWidget->item(row, column)->setText(new_text);
        qDebug() << simulator->mainMemory[row].readWord();

    }
}

void MainWindow::on_tableWidget_cellActivated(int row, int column)
{

}
