#include "windowOutput.h"
#include "./ui_windowOutput.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
#include <QFileInfo>
#include <QStringList>
#include <QPixmap>


windowOutput::windowOutput(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::windowOutput)
{
    ui->setupUi(this);
    // Create a data model for the mapping table from a CSV file
    csvModel = new QStandardItemModel(this);
    ui->tableView->setModel(csvModel);
}


void windowOutput::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Data Storage"), "", tr("CSV Files (*.csv)"));
    // Open the file from the resources. Instead of the file
    // Need to specify the path to your desired file
    QFile file(fileName);
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
    } else {
        // Create a thread to retrieve data from a file
        QTextStream in(&file);
        //Reads the data up to the end of file
        while (!in.atEnd())
        {
            QString line = in.readLine();
            // Adding to the model in line with the elements
            QList<QStandardItem *> standardItemsList;
            // consider that the line separated by semicolons into columns
            for (QString item : line.split(",")) {
                standardItemsList.append(new QStandardItem(item));
            }
            csvModel->insertRow(csvModel->rowCount(), standardItemsList);
        }
        file.close();
    }
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
