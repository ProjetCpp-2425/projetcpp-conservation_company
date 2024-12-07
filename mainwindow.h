#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "livraison.h"
#include <QSqlQueryModel>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QCategoryAxis>
#include <QVBoxLayout>

#include <QMap>
#include <QWidget>
#include "arduino.h"
#include <QSerialPort>

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
    void on_addButton_clicked();
    void on_modifyButton_clicked();
    void on_deleteButton_clicked();
    void on_searchButton_clicked();
    void generatePdf();
    void on_sortButton_clicked(); // Bouton pour trier par date de sortie
    bool on_loginButton_clicked();
    bool inscrireEmploye();
    void changerDePageLivraison();
    void changerDepageSignup();
    void changerDePageLogin();
    void on_afficherLivraisonsButton_clicked();


    void afficherStatistiquesLivraisons();

   void handleArduinoData();


    void on_tableView_clicked(const QModelIndex &index);


private:
    Ui::MainWindow *ui;
    Livraison livraison;
    QSqlQueryModel *model;
    Arduino arduino;
};

#endif // MAINWINDOW_H
