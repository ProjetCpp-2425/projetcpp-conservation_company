#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "material.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void on_add_clicked();
    void on_delete_2_clicked();
    void on_updateButton_clicked();
    void on_update2Button_clicked();
    void on_sortComboBox_changed();
    void on_searchLineEdit_textChanged();
    void on_statsButton_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_10_clicked();




private:
    Ui::MainWindow *ui;
    Material Etmp;
};
#endif // MAINWINDOW_H
