#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <windowOutput.h>
#include <windowInput.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton2_clicked();
    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    windowOutput *sWindow;
    windowInput *tWindow;
};
#endif // MAINWINDOW_H
