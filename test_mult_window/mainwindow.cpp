#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sWindow = new windowOutput();
    // connected to the slot start the main window on the button in the second window
    connect(sWindow, &windowOutput::startWindow, this, &MainWindow::show);

    tWindow = new windowInput();
    // connected to the slot start the main window on the button in the second window
    connect(tWindow, &windowInput::startWindow, this, &MainWindow::show);
}

void MainWindow::on_pushButton_clicked()
{
    tWindow->show();  // Show the second window
    this->close();
}

void MainWindow::on_pushButton2_clicked()
{
    sWindow->show();  // Show the third window
    this->close();
}


MainWindow::~MainWindow()
{
    delete ui;
}

