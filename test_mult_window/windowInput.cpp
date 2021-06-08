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

            QString EXT = ui->lineEditExtroversion->text();
            QString AGR = ui->lineEditAgreableness->text();
            QString CSN = ui->lineEditConscientiousness->text();
            QString EST = ui->lineEditNeuroticism->text();
            QString OPN = ui->lineEditOpenness->text();
            QString dateload = ui->lineEditDate->text();
            QString country = ui->lineEditCountry->text();

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
                ui->lineEditExtroversion->setText("");
                ui->lineEditAgreableness->setText("");
                ui->lineEditConscientiousness->setText("");
                ui->lineEditNeuroticism->setText("");
                ui->lineEditOpenness->setText("");
                ui->lineEditDate->setText("");
                ui->lineEditCountry->setText("");
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
            }
            file.close();
        }
}


windowInput::~windowInput()
{
    delete ui;
}
