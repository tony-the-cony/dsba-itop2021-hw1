#include "windowInput.h"
#include "./ui_windowInput.h"

windowInput::windowInput(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::windowInput)
{
    ui->setupUi(this);
}


void windowInput::on_pushButton1_clicked()
{
    this->close();
    emit startWindow();
}

windowInput::~windowInput()
{
    delete ui;
}
