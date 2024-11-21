#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QUrlQuery>
#include <QByteArray>
#include <QHttpMultiPart>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QLayout>
#include <QtCharts/QPieSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QScatterSeries>
#include <QVBoxLayout>
#include <QPolygonF>
#include <QPointF>
#include <QVector>
#include <QGraphicsPolygonItem>
#include <QtCore/QTimer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
, networkManager(new QNetworkAccessManager(this))

{
    ui->setupUi(this);
    client tempClient;
    QTableView* tableView = ui->widget->findChild<QTableView*>("cc");

    if (tableView) {
        tableView->setModel(tempClient.afficher());
    } else {
        qDebug() << "tableView 'affclient' not found!";
    }


//ai

    connect(ui->pushButton_chatbot_query, &QPushButton::clicked, this, &MainWindow::on_pushButton_chatbot_query_clicked);
    connect(networkManager, &QNetworkAccessManager::finished, this, &MainWindow::handleChatbotReply);





  


connect(ui->pushButton_tri, &QPushButton::clicked, this, &MainWindow::tri);

connect(ui->pushButton_chercher, &QPushButton::clicked, this, &MainWindow::on_pushButton_chercher_clicked);

connect(ui->pushButton_pdf, &QPushButton::clicked, this, &MainWindow::on_pushButton_pdf_clicked);

    ui->stackedWidget->addWidget(ui->user);
    ui->stackedWidget->addWidget(ui->stock);
    ui->stackedWidget->addWidget(ui->Livraison);
    ui->stackedWidget->addWidget(ui->Login);
    ui->stackedWidget_2->addWidget(ui->clients);
    ui->stackedWidget_2->addWidget(ui->statistique);
    ui->stackedWidget_2->addWidget(ui->chatbot);
    ui->stackedWidget_2->addWidget(ui->Arduino);


    connect(ui->pushButton_user, &QPushButton::clicked, this, &MainWindow::user);
    connect(ui->pushButton_20, &QPushButton::clicked, this, &MainWindow::Login);
    connect(ui->pushButton_11, &QPushButton::clicked, this, &MainWindow::user);



    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::clients);
    connect(ui->pushButon_statistic, &QPushButton::clicked, this, &MainWindow::statistique);
    connect(ui->pushButton_16, &QPushButton::clicked, this, &MainWindow::chatbot);
    connect(ui->pushButton_24, &QPushButton::clicked, this, &MainWindow::Arduino);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::user()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::Login()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::clients()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}
void MainWindow::statistique()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::chatbot()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::Arduino()
{
    ui->stackedWidget_2->setCurrentIndex(3);
}



void MainWindow::on_pushButton_ajouter_clicked()
{

    int code_client = ui->widget->findChild<QWidget*>("stackedWidget")
                          ->findChild<QWidget*>("widget_2")
                          ->findChild<QWidget*>("stackedWidget_2")
                          ->findChild<QWidget*>("frame_4")
                          ->findChild<QLineEdit*>("id_2")->text().toInt();

    QString nom = ui->widget->findChild<QWidget*>("stackedWidget")
                      ->findChild<QWidget*>("widget_2")
                      ->findChild<QWidget*>("stackedWidget_2")
                      ->findChild<QWidget*>("frame_4")
                      ->findChild<QLineEdit*>("line_nom")->text();

    QString prenom = ui->widget->findChild<QWidget*>("stackedWidget")
                         ->findChild<QWidget*>("widget_2")
                         ->findChild<QWidget*>("stackedWidget_2")
                         ->findChild<QWidget*>("frame_4")
                         ->findChild<QLineEdit*>("line_prenom")->text();

    QString adresse = ui->widget->findChild<QWidget*>("stackedWidget")
                          ->findChild<QWidget*>("widget_2")
                          ->findChild<QWidget*>("stackedWidget_2")
                          ->findChild<QWidget*>("frame_4")
                          ->findChild<QLineEdit*>("line_add")->text();

    QString type = ui->widget->findChild<QWidget*>("stackedWidget")
                       ->findChild<QWidget*>("widget_2")
                       ->findChild<QWidget*>("stackedWidget_2")
                       ->findChild<QWidget*>("frame_4")
                       ->findChild<QLineEdit*>("line_type")->text();

    QString telStr = ui->widget->findChild<QWidget*>("stackedWidget")
                         ->findChild<QWidget*>("widget_2")
                         ->findChild<QWidget*>("stackedWidget_2")
                         ->findChild<QWidget*>("frame_4")
                         ->findChild<QLineEdit*>("line_tel")->text();

    QString email = ui->widget->findChild<QWidget*>("stackedWidget")
                        ->findChild<QWidget*>("widget_2")
                        ->findChild<QWidget*>("stackedWidget_2")
                        ->findChild<QWidget*>("frame_4")
                        ->findChild<QLineEdit*>("line_email")->text();


    if (nom.isEmpty() || prenom.isEmpty() || adresse.isEmpty() || type.isEmpty() || telStr.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields are required.");
        return;
    }


    QRegularExpression codePattern("^\\d{6}$");
    if (!codePattern.match(QString::number(code_client)).hasMatch()) {
        QMessageBox::warning(this, "Input Error", "Invalid ID. It must be a unique 6-digit number.");
        return;
    }


    QRegularExpression alphaPattern("^[A-Za-z]+$");
    if (nom.length() < 2 || !alphaPattern.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Input Error", "First name must be at least 2 characters and contain only letters.");
        return;
    }
    if (prenom.length() < 2 || !alphaPattern.match(prenom).hasMatch()) {
        QMessageBox::warning(this, "Input Error", "Last name must be at least 2 characters and contain only letters.");
        return;
    }


    if (type != "particulier" && type != "entreprise") {
        QMessageBox::warning(this, "Input Error", "Type must be either 'particulier' or 'entreprise'.");
        return;
    }


    QRegularExpression telPattern("^\\d{8,}$");
    if (!telPattern.match(telStr).hasMatch()) {
        QMessageBox::warning(this, "Input Error", "Invalid phone number. It must contain only digits and be at least 9 digits long.");
        return;
    }
    int tel = telStr.toInt();


    QRegularExpression emailPattern("^[\\w.-]+@[\\w.-]+\\.[a-z]{2,3}$");
    if (!emailPattern.match(email).hasMatch()) {
        QMessageBox::warning(this, "Input Error", "Invalid email format.");
        return;
    }


    client C(code_client, nom, prenom, adresse, type, tel, email);


    bool test = C.ajouter();

    if (test) {
        QTableView* tableView = ui->widget->findChild<QTableView*>("cc");
        tableView->setModel(C.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectue\nClick Cancel to exit."),
                                 QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Ajout non effectue.\nClick Cancel to exit."),
                              QMessageBox::Cancel);
    }
}



void MainWindow::on_pushButton_supprimer_clicked()
{
    int code_client = ui->widget->findChild<QWidget*>("stackedWidget")
    ->findChild<QWidget*>("widget_2")
        ->findChild<QWidget*>("stackedWidget_2")
        ->findChild<QWidget*>("frame_6")
        ->findChild<QLineEdit*>("line_supp")->text().toInt();

    bool test = tmclient.supprimer(code_client);
    if (test)
    {
        QTableView* tableView = ui->widget->findChild<QTableView*>("cc");
        tableView->setModel(tmclient.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("suppressipn effectueé\n"
                                             "click cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("suppression non affectueé\n"
                                          "click cancel to exit."),QMessageBox::Cancel);
}









void MainWindow::on_pushButton_modifier_clicked()
{
    int code_client = ui->widget->findChild<QWidget*>("stackedWidget")
    ->findChild<QWidget*>("widget_2")
        ->findChild<QWidget*>("stackedWidget_2")
        ->findChild<QWidget*>("frame_22")
        ->findChild<QLineEdit*>("id_4")->text().toInt();

    QSqlQuery query;
    query.prepare("SELECT nom, prenom, adresse, type, tel, mail FROM client WHERE code_client = :code_client");
    query.bindValue(":code_client", code_client);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Erreur", "Client introuvable !");
        return;
    }
     QRegularExpression alphaPattern("^[A-Za-z]+$");

    QString nom = ui->widget->findChild<QWidget*>("stackedWidget")
                      ->findChild<QWidget*>("widget_2")
                      ->findChild<QWidget*>("stackedWidget_2")
                      ->findChild<QWidget*>("frame_22")
                      ->findChild<QLineEdit*>("line_nom_2")->text();
    if (nom.isEmpty()) nom = query.value("nom").toString();
    else {
        if (nom.length() < 2) {
            QMessageBox::warning(this, "Erreur de saisie", "Le nom doit comporter au moins 2 caractères.");
            return;
        }
        QRegularExpression alphaPattern("^[A-Za-z]+$");
        if (!alphaPattern.match(nom).hasMatch()) {
            QMessageBox::warning(this, "Erreur de saisie", "Le nom ne doit contenir que des lettres.");
            return;
        }
    }

    QString prenom = ui->widget->findChild<QWidget*>("stackedWidget")
                         ->findChild<QWidget*>("widget_2")
                         ->findChild<QWidget*>("stackedWidget_2")
                         ->findChild<QWidget*>("frame_22")
                         ->findChild<QLineEdit*>("line_prenom_2")->text();
    if (prenom.isEmpty()) prenom = query.value("prenom").toString();
    else {
        if (prenom.length() < 2) {
            QMessageBox::warning(this, "Erreur de saisie", "Le prénom doit comporter au moins 2 caractères.");
            return;
        }
        if (!alphaPattern.match(prenom).hasMatch()) {
            QMessageBox::warning(this, "Erreur de saisie", "Le prénom ne doit contenir que des lettres.");
            return;
        }
    }

    QString adresse = ui->widget->findChild<QWidget*>("stackedWidget")
                          ->findChild<QWidget*>("widget_2")
                          ->findChild<QWidget*>("stackedWidget_2")
                          ->findChild<QWidget*>("frame_22")
                          ->findChild<QLineEdit*>("line_add_2")->text();
    if (adresse.isEmpty()) adresse = query.value("adresse").toString();

    QString type = ui->widget->findChild<QWidget*>("stackedWidget")
                       ->findChild<QWidget*>("widget_2")
                       ->findChild<QWidget*>("stackedWidget_2")
                       ->findChild<QWidget*>("frame_22")
                       ->findChild<QLineEdit*>("line_type_2")->text();
    if (type.isEmpty()) type = query.value("type").toString();
    else if (type != "particulier" && type != "entreprise") {
        QMessageBox::warning(this, "Erreur de saisie", "Le type doit être soit 'particulier' soit 'entreprise'.");
        return;
    }

    QString telStr = ui->widget->findChild<QWidget*>("stackedWidget")
                         ->findChild<QWidget*>("widget_2")
                         ->findChild<QWidget*>("stackedWidget_2")
                         ->findChild<QWidget*>("frame_22")
                         ->findChild<QLineEdit*>("line_tel_2")->text();
    int tel = telStr.isEmpty() ? query.value("tel").toInt() : telStr.toInt();
    if (!telStr.isEmpty()) {
        QRegularExpression telPattern("^\\d{8,}$");
        if (!telPattern.match(telStr).hasMatch()) {
            QMessageBox::warning(this, "Erreur de saisie", "Numéro de téléphone invalide. Il doit contenir uniquement des chiffres et au moins 9 chiffres.");
            return;
        }
    }

    QString email = ui->widget->findChild<QWidget*>("stackedWidget")
                        ->findChild<QWidget*>("widget_2")
                        ->findChild<QWidget*>("stackedWidget_2")
                        ->findChild<QWidget*>("frame_22")
                        ->findChild<QLineEdit*>("line_email_2")->text();
    if (email.isEmpty()) email = query.value("mail").toString();
    else {
        QRegularExpression emailPattern("^[\\w.-]+@[\\w.-]+\\.[a-z]{2,3}$");
        if (!emailPattern.match(email).hasMatch()) {
            QMessageBox::warning(this, "Erreur de saisie", "Format d'email invalide.");
            return;
        }
    }

    client c(code_client, nom, prenom, adresse, type, tel, email);

    if (c.modifier(code_client, nom, prenom, adresse, type, tel, email)) {
        QMessageBox::information(this, "Succès", "Client modifié avec succès.");
        QTableView* tableView = ui->widget->findChild<QTableView*>("cc");
        tableView->setModel(c.afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du client.");
    }
}





void MainWindow::on_pushButton_pdf_clicked()
{

    QString defaultPath = "C:/Users/Admin/Desktop/Gestion_Client/ClientReport.pdf";


    QString pdfFilePath = QFileDialog::getSaveFileName(this, "Save as PDF", defaultPath, "PDF Files (*.pdf)");

    if (pdfFilePath.isEmpty()) {
        QMessageBox::warning(this, "Warning", "No file selected!");
        return;
    }


    if (!pdfFilePath.endsWith(".pdf"))
        pdfFilePath += ".pdf";

    QPdfWriter pdfWriter(pdfFilePath);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(300);

    QPainter painter(&pdfWriter);
    if (!painter.isActive()) {
        QMessageBox::critical(this, "Error", "Failed to initialize QPainter.");
        return;
    }


    QFont headerFont("Arial", 12, QFont::Bold);
    QFont contentFont("Arial", 10);


    QTableView *tableView = ui->widget->findChild<QTableView *>("cc");
    if (!tableView) {
        QMessageBox::critical(this, "Error", "TableView not found!");
        return;
    }

    QAbstractItemModel *model = tableView->model();
    if (!model) {
        QMessageBox::critical(this, "Error", "Model not found!");
        return;
    }


    int leftMargin = 50;
    int topMargin = 50;
    int rowHeight = 50;
    int x = leftMargin;
    int y = topMargin;


    int columnSpacing =300;
    int rowSpacing = 150;


    painter.setFont(headerFont);
    for (int col = 0; col < model->columnCount(); ++col) {
        QString header = model->headerData(col, Qt::Horizontal).toString();
        painter.drawText(x, y, header);
        x += columnSpacing;
    }


    y += rowSpacing;
    x = leftMargin;


    painter.setFont(contentFont);
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QVariant data = model->data(model->index(row, col));
            painter.drawText(x, y, data.toString());
            x += columnSpacing;
        }
        y += rowSpacing;
        x = leftMargin;


        if (y > pdfWriter.height() - 50) {
            pdfWriter.newPage();
            y = topMargin;
        }
    }

    painter.end();

    QMessageBox::information(this, "Success", "Data exported to PDF file successfully.");
}


void MainWindow::on_pushButton_chercher_clicked()
{

    QString searchInput = ui->widget->findChild<QWidget*>("stackedWidget")
                              ->findChild<QWidget*>("widget_2")
                              ->findChild<QWidget*>("stackedWidget_2")
                              ->findChild<QWidget*>("frame_6")
                              ->findChild<QLineEdit*>("line_supp")->text();


    if (searchInput.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a search query.");
        return;
    }

    QSqlQuery query;
    QString queryStr;


    bool isNumeric;
    int code_client = searchInput.toInt(&isNumeric);

    if (isNumeric) {

        queryStr = "SELECT * FROM client WHERE code_client = :code_client";
        query.prepare(queryStr);
        query.bindValue(":code_client", code_client);
    } else {

        queryStr = R"(
            SELECT * FROM client
            WHERE LOWER(nom) LIKE LOWER(:search)
            OR LOWER(type) LIKE LOWER(:search)
        )";
        query.prepare(queryStr);
        query.bindValue(":search", "%" + searchInput + "%");
    }


    qDebug() << "Executing query:" << queryStr;

    if (query.exec()) {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery(query);

        // Check if results exist
        if (model->rowCount() > 0) {
            QTableView* tableView = ui->widget->findChild<QTableView*>("cc");
            if (tableView) {
                tableView->setModel(model);
            } else {
                qDebug() << "tableView 'cc' not found!";
            }
        } else {
            QMessageBox::information(this, "No Results", "No client found matching the search query.");
        }
    } else {

        QMessageBox::critical(this, "Search Error", "Failed to execute search query: " );
    }
}





void MainWindow::tri() {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM client ORDER BY code_client ASC");

    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, tr("code_client"));
        model->setHeaderData(1, Qt::Horizontal, tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, tr("prenom"));
        model->setHeaderData(3, Qt::Horizontal, tr("adresse"));
        model->setHeaderData(4, Qt::Horizontal, tr("type"));
        model->setHeaderData(5, Qt::Horizontal, tr("tel"));


        ui->cc->setModel(model);
    }


}






//////////////////////////////////







void MainWindow::on_pushButton_stat_clicked() {

    QSqlQuery query;
    int countParticulier = 0, countEntreprise = 0;

    query.exec("SELECT type, COUNT(*) FROM client GROUP BY type");
    while (query.next()) {
        QString type = query.value(0).toString();
        int count = query.value(1).toInt();
        if (type == "particulier") {
            countParticulier = count;
        } else if (type == "entreprise") {
            countEntreprise = count;
        }
    }


    QPieSeries *pieSeries = new QPieSeries();
    pieSeries->append("Particulier", countParticulier);
    pieSeries->append("Entreprise", countEntreprise);

    QChart *pieChart = new QChart();
    pieChart->addSeries(pieSeries);
    pieChart->setTitle("Client Type Distribution");
    pieChart->legend()->setVisible(true);
    pieChart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *pieChartView = new QChartView(pieChart);
    pieChartView->setRenderHint(QPainter::Antialiasing);
    if (!ui->stat->layout()) {
        QVBoxLayout *layout = new QVBoxLayout(ui->stat);
        ui->stat->setLayout(layout);
    }
    ui->stat->layout()->addWidget(pieChartView);


    QLineSeries *lineSeries = new QLineSeries();
    lineSeries->append(0, countParticulier);
    lineSeries->append(1, countEntreprise);
    QChart *lineChart = new QChart();
    lineChart->addSeries(lineSeries);
    lineChart->setTitle("Client Type Comparison (Curve)");
    lineChart->createDefaultAxes();
    lineChart->legend()->setVisible(true);
    lineChart->legend()->setAlignment(Qt::AlignBottom);


    lineSeries->setColor(QColor(128, 0, 128));

    QChartView *lineChartView = new QChartView(lineChart);
    lineChartView->setRenderHint(QPainter::Antialiasing);
    if (!ui->stat_2->layout()) {
        QVBoxLayout *layout = new QVBoxLayout(ui->stat_2);
        ui->stat_2->setLayout(layout);
    }
    ui->stat_2->layout()->addWidget(lineChartView);


    QBarSet *setParticulier = new QBarSet("Particulier");
    *setParticulier << countParticulier;
    QBarSet *setEntreprise = new QBarSet("Entreprise");
    *setEntreprise << countEntreprise;
    QBarSeries *barSeries = new QBarSeries();
    barSeries->append(setParticulier);
    barSeries->append(setEntreprise);


    setParticulier->setColor(Qt::blue);
    setEntreprise->setColor(QColor(128, 0, 128));

    QChart *barChart = new QChart();
    barChart->addSeries(barSeries);
    barChart->setTitle("Client Type Distribution (Bar Chart)");
    barChart->legend()->setVisible(true);
    barChart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *barChartView = new QChartView(barChart);
    barChartView->setRenderHint(QPainter::Antialiasing);
    if (!ui->stat_3->layout()) {
        QVBoxLayout *layout = new QVBoxLayout(ui->stat_3);
        ui->stat_3->setLayout(layout);
    }
    ui->stat_3->layout()->addWidget(barChartView);


    QLineSeries *sinusoidalSeries = new QLineSeries();
    int amplitude = 50;
    int frequency = 2;
    int phaseShift = 0;


    for (int x = 0; x < 360; x++) {

        double y = amplitude * sin(frequency * qDegreesToRadians(x) + phaseShift);
        sinusoidalSeries->append(x, y);
    }

    QChart *sinusoidalChart = new QChart();
    sinusoidalChart->addSeries(sinusoidalSeries);
    sinusoidalChart->createDefaultAxes();
    sinusoidalChart->setTitle("Sinusoidal Curve for Client Type Distribution");

    QChartView *sinusoidalChartView = new QChartView(sinusoidalChart);
    sinusoidalChartView->setRenderHint(QPainter::Antialiasing);


    if (!ui->stat_4->layout()) {
        QVBoxLayout *layout = new QVBoxLayout(ui->stat_4);
        ui->stat_4->setLayout(layout);
    }
    ui->stat_4->layout()->addWidget(sinusoidalChartView);


    ui->stackedWidget_2->setCurrentIndex(1);
}





void MainWindow::on_pushButton_chatbot_query_clicked()
{
    QString query = ui->lineEdit_chatbot_query->text();

    if (query.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a query.");
        return;
    }

    QJsonObject json;
    json["model"] = "mistral";

    QJsonObject message;
    message["role"] = "user";
    message["content"] = query;

    QJsonArray messages;
    messages.append(message);

    json["messages"] = messages;

    QJsonDocument doc(json);

    QUrl url("http://localhost:11434/v1/chat/completions");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Prevent multiple connections
    disconnect(networkManager, &QNetworkAccessManager::finished, this, &MainWindow::handleChatbotReply);
    connect(networkManager, &QNetworkAccessManager::finished, this, &MainWindow::handleChatbotReply);

    networkManager->post(request, doc.toJson());
}

void MainWindow::handleChatbotReply(QNetworkReply* reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        QString errorMsg = reply->errorString();
        QMessageBox::critical(this, "Error", "Failed to communicate with Ollama server: " + errorMsg);
        reply->deleteLater();
        return;
    }

    QByteArray responseData = reply->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);

    if (jsonResponse.isObject()) {
        QJsonObject responseObject = jsonResponse.object();

        if (responseObject.contains("choices") && responseObject["choices"].isArray()) {
            QJsonArray choicesArray = responseObject["choices"].toArray();
            if (!choicesArray.isEmpty() && choicesArray[0].isObject()) {
                QJsonObject firstChoice = choicesArray[0].toObject();
                if (firstChoice.contains("message") && firstChoice["message"].isObject()) {
                    QJsonObject messageObject = firstChoice["message"].toObject();
                    if (messageObject.contains("content") && messageObject["content"].isString()) {
                        QString chatbotResponse = messageObject["content"].toString();
                        ui->textEdit_chatbot_response->setText(chatbotResponse);
                        reply->deleteLater();
                        return;
                    }
                }
            }
        }
    }

    ui->textEdit_chatbot_response->setText("No valid response from chatbot.");
    reply->deleteLater();
}






