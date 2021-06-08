#ifndef WINDOWOUTPUT_H
#define WINDOWOUTPUT_H

#include <QWidget>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class windowOutput; }
QT_END_NAMESPACE

class windowOutput : public QWidget
{
    Q_OBJECT

public:
    explicit windowOutput(QWidget *parent = nullptr);
    ~windowOutput();

private slots:
    void on_pushButton3_clicked();
    void on_actionOpen_triggered();

signals:
    void startWindow();

private:
    Ui::windowOutput *ui;
    QStandardItemModel *csvModel;
};



#endif // WINDOWOUTPUT_H
