#include "windowInput.h"
#include "./ui_windowInput.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
#include <QFileInfo>
#include <QStringList>
#include <QPixmap>
#include <QAbstractTableModel>
#include <QVariant>
#include <QMessageBox>
#include <QComboBox>
#include <QSet>
#include <QList>

void addItemsToComboBox(QComboBox *box){
    box->insertItem(0, "1");
    box->insertItem(1, "2");
    box->insertItem(2, "3");
    box->insertItem(3, "4");
    box->insertItem(4, "5");
}



windowInput::windowInput(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::windowInput)
{
    ui->setupUi(this);
    addItemsToComboBox(ui->comboBoxAgreableness);
    addItemsToComboBox(ui->comboBoxOpenness);
    addItemsToComboBox(ui->comboBoxNeuroticism);
    addItemsToComboBox(ui->comboBoxExtroversion);
    addItemsToComboBox(ui->comboBoxConsc);
}


void windowInput::on_pushButton1_clicked()
{
    this->close();
    emit startWindow();
}

bool isint(QString s)
{
    bool ok;
    s.toInt(&ok);
    return ok;
}

void windowInput::on_pushButtonAdd_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                tr("Open Data Storage"), "", tr("CSV Files (*.csv)"));
            QFile file(fileName);
            if ( !file.open(QIODevice::ReadWrite| QIODevice::Append)) {
                qDebug() << "File does not exist";
            } else {
                QTextStream out(&file);
            QString EXT = ui->comboBoxExtroversion->currentText();
            QString AGR = ui->comboBoxAgreableness->currentText();
            QString CSN = ui->comboBoxConsc->currentText();
            QString EST = ui->comboBoxNeuroticism->currentText();
            QString OPN = ui->comboBoxOpenness->currentText();
            QString dateload = ui->dateEdit->date().toString();
            QString country = ui->lineEdit->text();

            ui->LabelExtroversion->setStyleSheet("QLabel {color : black; }");
            ui->LabelAgreableness->setStyleSheet("QLabel {color : black; }");
            ui->LabelConscientiousness->setStyleSheet("QLabel {color : black; }");
            ui->LabelNeuroticism->setStyleSheet("QLabel {color : black; }");
            ui->LabelOpenness->setStyleSheet("QLabel {color : black; }");
            ui->LabelDate->setStyleSheet("QLabel {color : black; }");
            ui->LabelCountry->setStyleSheet("QLabel {color : black; }");

            if (isint(EXT) & isint(AGR) & isint(CSN) & isint(EST) & isint(OPN) & dateload!="" & country!="")
            {
                out << EXT << ','<< AGR << ','<< CSN << ','<< EST << ','<< OPN << ','<< dateload << ','<< country << '\n';
                ui->comboBoxExtroversion->setCurrentText("");
                ui->comboBoxAgreableness->setCurrentText("");
                ui->comboBoxConsc->setCurrentText("");
                ui->comboBoxNeuroticism->setCurrentText("");
                ui->comboBoxOpenness->setCurrentText("");
                ui->lineEdit->setText("");

                QMessageBox msgBox;
                msgBox.setText("Successfully added the response.");
                msgBox.exec();
            }
            else
            {
                if (!isint(EXT)){ui->LabelExtroversion->setStyleSheet("QLabel {color : red; }");}
                if (!isint(AGR)){ui->LabelAgreableness->setStyleSheet("QLabel {color : red; }");}
                if (!isint(CSN)){ui->LabelConscientiousness->setStyleSheet("QLabel {color : red; }");}
                if (!isint(EST)){ui->LabelNeuroticism->setStyleSheet("QLabel {color : red; }");}
                if (!isint(OPN)){ui->LabelOpenness->setStyleSheet("QLabel {color : red; }");}
                if (dateload==""){ui->LabelDate->setStyleSheet("QLabel {color : red; }");}
                if (country==""){ui->LabelCountry->setStyleSheet("QLabel {color : red; }");}

                QMessageBox msgBox2;
                msgBox2.setText("Some values are invalid. They are highlighted in red.");
                msgBox2.exec();
            }
            file.close();
        }
}


windowInput::~windowInput()
{
    delete ui;
}
