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
#include <QSortFilterProxyModel>

windowOutput::windowOutput(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::windowOutput)
{
    ui->setupUi(this);
    csvModel = new QStandardItemModel(this);
    ui->tableView->setModel(csvModel);
    QSortFilterProxyModel *sortModel = new QSortFilterProxyModel(csvModel);
    sortModel->setSourceModel(csvModel);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->setModel(sortModel);
}

int listSum(QList<int> ust){
    int ans = 0;
    for (int i=0; i<ust.size(); i++){
        ans += ust[i];
    }
    return ans;
}

void windowOutput::on_actionOpen_triggered()
{
    int kostyl = 0;
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
        while (!in.atEnd()){
            kostyl += 1;
            line = in.readLine();
        }
        file.close();

    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
    } else {
        QTextStream in(&file);
        QString line = in.readLine();
        int kostyl1 = kostyl-50;
        for (int i=0; i<kostyl1; i++){
            in.readLine();
        }
        while (!in.atEnd()){
            kostyl1 += 1;
            if ((kostyl1<=kostyl)&(kostyl1>=kostyl-50)){
                line = in.readLine();
                QList<QStandardItem *> standardItemsList;
                for (QString item : line.split(",")) {
                    standardItemsList.append(new QStandardItem(item));
                }
                csvModel->insertRow(csvModel->rowCount(), standardItemsList);
            }
        }
        file.close();
    }



    QList<QStandardItem *> persList;
    for (int i=0; i<50; i++){
        QList<int> uniList = {};
        for (int j=0; j<=4; j++){
            uniList.append(csvModel->item(i, j)->text().toInt());
        }
        int temp = listSum(uniList);
        if (temp>=0 & temp<=5)
            persList.append(new QStandardItem("Истероид"));
        else if (temp>5 & temp<=10)
            persList.append(new QStandardItem("Эпилептоид"));
        else if (temp>10 & temp<=15)
            persList.append(new QStandardItem("Параноял"));
        else if (temp>15 & temp<=20)
            persList.append(new QStandardItem("Эмотив"));
        else if (temp>20 & temp<=25)
            persList.append(new QStandardItem("Шизоид"));
    }
    csvModel->insertColumn(7, persList);

    for (int i=0; i<50; i++){
        QString temp = csvModel->item(i, 7)->text();
        if (temp == "Истероид"){
            for (int j=0; j<=7; j++){
                const QModelIndex index = csvModel->index(i, j);
                csvModel->setData(index, QColor(255, 0, 0), Qt::BackgroundRole);
            }
        }
        if (temp == "Эпилептоид"){
            for (int j=0; j<=7; j++){
                const QModelIndex index = csvModel->index(i, j);
                csvModel->setData(index, QColor(0, 255, 255), Qt::BackgroundRole);
            }
        }
        if (temp == "Параноял"){
            for (int j=0; j<=7; j++){
                const QModelIndex index = csvModel->index(i, j);
                csvModel->setData(index, QColor(255, 0, 255), Qt::BackgroundRole);
            }
        }
        if (temp == "Эмотив"){
            for (int j=0; j<=7; j++){
                const QModelIndex index = csvModel->index(i, j);
                csvModel->setData(index, QColor(255, 255, 0), Qt::BackgroundRole);
            }
        }
        if (temp == "Шизоид"){
            for (int j=0; j<=7; j++){
                const QModelIndex index = csvModel->index(i, j);
                csvModel->setData(index, QColor(0, 0, 255), Qt::BackgroundRole);
            }
        }
    }
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
