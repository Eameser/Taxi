#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <order.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_orderButton_clicked();

    //void on_pushButton_3_clicked();

    //void on_pushButton_4_clicked();

    void on_pushButton_save_clicked();

    //void on_loadButton_clicked();

private:
    Ui::MainWindow *ui;
    std::vector <order*> order_vector;
    int counter = 0;
    QStringList rows;

};

#endif // MAINWINDOW_H
