#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"client.h"
#include "arduino.h"

#include <QMainWindow>
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include "material.h"
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
    void stock();
    void Livraison();

    void Login();

    void clients();
    void statistique();
    void chatbot();
    void arduino();












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



















private slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_pdf_clicked();
    void on_pushButton_chercher_clicked();
    void tri();
    void on_pushButton_send_sms_clicked();
    void onSmsSent(QNetworkReply* reply);
     void on_pushButton_stat_clicked(); // Slot for showing statistics

    void on_pushButton_chatbot_query_clicked();  // For handling the query
    void handleChatbotReply(QNetworkReply* reply);  // Fo
    void update_label();  // This is the slot that updates the UI
    void on_pushButton_buzzer_clicked();
    void on_pushButton_tem_clicked();
    void on_pushButton_status_clicked();










private:
    Ui::MainWindow *ui;
    client tmclient;
    void sendSms(const QString& toPhoneNumber, const QString& message);    

    QNetworkAccessManager *networkManager; // For API requests
    QByteArray data;
    Arduino A;
    Material Etmp;

};
#endif // MAINWINDOW_H
