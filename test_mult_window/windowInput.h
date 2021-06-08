#ifndef WINDOWINPUT_H
#define WINDOWINPUT_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class windowInput; }
QT_END_NAMESPACE

class windowInput : public QWidget
{
    Q_OBJECT

public:
    explicit windowInput(QWidget *parent = nullptr);
    ~windowInput();

private slots:
    void on_pushButton1_clicked();
    void on_pushButtonAdd_clicked();

signals:
    void startWindow();

private:
    Ui::windowInput *ui;
};


#endif // WINDOWINPUT_H
