#include "windowOutput.h"
#include "./ui_windowOutput.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
#include <QFileInfo>
#include <QStringList>
#include <QPixmap>
#include <QAbstractTableModel>

windowOutput::windowOutput(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::windowOutput)
{
    ui->setupUi(this);
    csvModel = new QStandardItemModel(this);
    ui->tableView->setModel(csvModel);

}


void windowOutput::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Data Storage"), "", tr("CSV Files (*.csv)"));
    QFile file(fileName);
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File does not exist";
    } else {

        ui->pushButtonSortCountry->setDisabled(false);
        ui->pushButtonSortDate->setDisabled(false);
        QTextStream in(&file);
        QString line = in.readLine();
        while (!in.atEnd())
        {
            line = in.readLine();
            QList<QStandardItem *> standardItemsList;
            for (QString item : line.split(",")) {
                standardItemsList.append(new QStandardItem(item));
            }
            csvModel->insertRow(csvModel->rowCount(), standardItemsList);
        }
        file.close();
    }
}


void windowOutput::on_pushButtonSortCountry_clicked()
{
    ui->tableView->sortByColumn(6, Qt::AscendingOrder);
}

void windowOutput::on_pushButtonSortDate_clicked()
{
    ui->tableView->sortByColumn(5, Qt::AscendingOrder);
}


void windowOutput::on_pushButton3_clicked()
{
    this->close();
    emit startWindow();
}

windowOutput::~windowOutput()
{
    delete ui;
}
