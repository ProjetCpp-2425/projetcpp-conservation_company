#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"client.h"

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
    void user();

    void Login();

    void clients();
    void statistique();
    void chatbot();

private slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_modifier_clicked();




private:
    Ui::MainWindow *ui;
    client tmclient;
};
#endif // MAINWINDOW_H
