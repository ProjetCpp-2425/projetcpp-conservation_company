#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"client.h"

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
    void Arduino();

private slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_pdf_clicked();
    void on_pushButton_chercher_clicked();
    void tri();
    void on_pushButton_send_sms_clicked();
    void onSmsSent(QNetworkReply* reply);
     void on_pushButton_stat_clicked(); 

    // Chatbot-related slots
     void on_pushButton_chatbot_query_clicked();  
     void handleChatbotReply(QNetworkReply* reply);  











private:
    Ui::MainWindow *ui;
    client tmclient;
    void sendSms(const QString& toPhoneNumber, const QString& message);


    QNetworkAccessManager *networkManager; 


};
#endif 
