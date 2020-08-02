#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_set1_clicked();
    void on_pushButton_set2_clicked();
    void on_pushButton_set3_clicked();
    void on_pushButton_set4_clicked();

    void on_pushButton_refresh_clicked();

private:
    Ui::MainWindow *ui;
    void ShowipAndInterfaceName();
};

#endif // MAINWINDOW_H
