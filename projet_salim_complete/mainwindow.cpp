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
#include <QRegularExpression>
#include "arduino.h"
#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QCalendarWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QTextCharFormat>
#include <QDate>
#include <QWidget>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
   , networkManager(new QNetworkAccessManager(this))

{
    ui->setupUi(this);
    int ret = A.connect_arduino(); // Attempt to connect to Arduino
    switch (ret) {
    case 0:
        qDebug() << "Arduino is available and connected to:" << A.getarduino_port_name();
        break;
    case 1:
        qDebug() << "Arduino is available but not connected to:" << A.getarduino_port_name();
        break;
    case -1:
        qDebug() << "Arduino is not available";
        break;
    }

    // Connect signal for data received to slot
    QObject::connect(A.getserial(), &QSerialPort::readyRead, this, &MainWindow::update_label);

    client tempClient;
    QTableView* tableView = ui->widget->findChild<QTableView*>("cc");

    if (tableView) {
        tableView->setModel(tempClient.afficher());
    } else {
        qDebug() << "tableView 'affclient' not found!";
    }


//ai
    connect(ui->pushButton_chatbot_query, &QPushButton::clicked, this, &MainWindow::on_pushButton_chatbot_query_clicked);


    connect(ui->pushButton_send_sms, &QPushButton::clicked, this, &MainWindow::on_pushButton_send_sms_clicked);


    connect(ui->pushButton_status, &QPushButton::clicked, this, &MainWindow::on_pushButton_status_clicked);




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
    ui->stackedWidget_2->addWidget(ui->arduino);


    connect(ui->pushButton_user, &QPushButton::clicked, this, &MainWindow::user);
    connect(ui->pushButton_20, &QPushButton::clicked, this, &MainWindow::Login);
    connect(ui->pushButton_11, &QPushButton::clicked, this, &MainWindow::user);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::stock);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::Livraison);




    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::clients);
    connect(ui->pushButon_statistic, &QPushButton::clicked, this, &MainWindow::statistique);
    connect(ui->pushButton_16, &QPushButton::clicked, this, &MainWindow::chatbot);
    connect(ui->pushArduino, &QPushButton::clicked, this, &MainWindow::arduino);








    ui->tableView->setModel(Etmp.afficher());
    connect(ui->add, &QPushButton::clicked, this, &::MainWindow::on_add_clicked);
    connect(ui->delete_2, &QPushButton::clicked, this, &::MainWindow::on_delete_2_clicked);
    connect(ui->updateButton, &QPushButton::clicked, this, &::MainWindow::on_updateButton_clicked);
    connect(ui->update2Button, &QPushButton::clicked, this, &::MainWindow::on_update2Button_clicked);
    connect(ui->comboBox_10, &QComboBox::currentTextChanged, this, &MainWindow::on_sortComboBox_changed);
    connect(ui->lineEdit_S, &QLineEdit::textChanged, this, &MainWindow::on_searchLineEdit_textChanged);
    connect(ui->Stats, &QPushButton::clicked, this, &MainWindow::on_statsButton_clicked);
    connect(ui->pushButton_13, &QPushButton::clicked, this, &MainWindow::on_pushButton_13_clicked);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::on_pushButton_7_clicked);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::on_pushButton_8_clicked);
    connect(ui->pushButton_10, &QPushButton::clicked, this, &MainWindow::on_pushButton_10_clicked);






























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


void MainWindow::arduino()
{
    ui->stackedWidget_2->setCurrentIndex(3);
}








void MainWindow::stock()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::Livraison()
{
    ui->stackedWidget->setCurrentIndex(2);
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

    QString input = ui->widget->findChild<QWidget*>("stackedWidget")
                        ->findChild<QWidget*>("widget_2")
                        ->findChild<QWidget*>("stackedWidget_2")
                        ->findChild<QWidget*>("frame_6")
                        ->findChild<QLineEdit*>("line_supp")->text();


    QSqlQuery query;
    query.prepare(
        "SELECT * FROM client "
        "WHERE code_client = :code_client OR nom LIKE :nom OR type LIKE :type"
        );

    bool isNumber;
    int code_client = input.toInt(&isNumber);
    if (isNumber) {
        query.bindValue(":code_client", code_client);
    } else {
        query.bindValue(":code_client", QVariant(QVariant::Int));
    }


    QString searchPattern = "%" + input + "%";
    query.bindValue(":nom", searchPattern);
    query.bindValue(":type", searchPattern);


    if (query.exec()) {
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(query);

        if (model->rowCount() > 0) {

            QTableView* tableView = ui->widget->findChild<QTableView*>("cc");
            if (tableView) {
                tableView->setModel(model);
            } else {
                qDebug() << "tableView 'cc' not found!";
            }
        } else {
            QMessageBox::information(this, "No Results", "No client found matching the given input.");
        }
    } else {
        QMessageBox::critical(this, "Search Error", "Failed to execute search query.");
    }
}




void MainWindow::tri() {
    // Récupérer le texte entré dans le QLineEdit
    QString input = ui->widget->findChild<QWidget*>("stackedWidget")
                        ->findChild<QWidget*>("widget_2")
                        ->findChild<QWidget*>("stackedWidget_2")
                        ->findChild<QWidget*>("frame_6")
                        ->findChild<QLineEdit*>("line_supp")->text();


    QString sortColumn;

    if (input.compare("type", Qt::CaseInsensitive) == 0) {
        sortColumn = "type";
    } else if (input.compare("nom", Qt::CaseInsensitive) == 0) {
        sortColumn = "nom";
    } else if (input.compare("code", Qt::CaseInsensitive) == 0) {
        sortColumn = "code_client";
    } else {

        QMessageBox::information(this, "Critère invalide", "Veuillez entrer 'code', 'nom' ou 'type' pour le tri.");
        return;
    }


    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    QString queryString = QString("SELECT * FROM client ORDER BY %1 ASC").arg(sortColumn);

    if (query.exec(queryString)) {

        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, tr("code_client"));
        model->setHeaderData(1, Qt::Horizontal, tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, tr("prenom"));
        model->setHeaderData(3, Qt::Horizontal, tr("adresse"));
        model->setHeaderData(4, Qt::Horizontal, tr("type"));
        model->setHeaderData(5, Qt::Horizontal, tr("tel"));


        ui->cc->setModel(model);
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible d'exécuter la requête pour le tri.");
    }
}




QString formatPhoneNumber(const QString& phoneNumber) {
    QString formattedNumber = phoneNumber.trimmed();
    if (!formattedNumber.startsWith("+")) {
        formattedNumber.prepend("+216"); // Change "+216" to your default country code if needed
    }
    return formattedNumber;
}




void MainWindow::on_pushButton_send_sms_clicked()
{
    // Access phone number from the UI
    QLineEdit* lineEditNumber = ui->widget->findChild<QWidget*>("stackedWidget")
                                    ->findChild<QWidget*>("widget_2")
                                    ->findChild<QWidget*>("stackedWidget_2")
                                    ->findChild<QWidget*>("frame_20")
                                    ->findChild<QLineEdit*>("lineEdit_number");

    if (!lineEditNumber) {
        qDebug() << "lineEdit_number not found!";
        return;
    }

    QString toPhoneNumber = formatPhoneNumber(lineEditNumber->text());
    qDebug() << "Formatted Phone Number: " << toPhoneNumber;

    // Access the message from QLineEdit located inside frame_20
    QLineEdit* lineEditMsg = ui->widget->findChild<QWidget*>("stackedWidget")
                                 ->findChild<QWidget*>("widget_2")
                                 ->findChild<QWidget*>("stackedWidget_2")
                                 ->findChild<QWidget*>("frame_20")
                                 ->findChild<QLineEdit*>("lineEdit_msg");

    if (!lineEditMsg) {
        qDebug() << "lineEdit_msg not found!";
        return;
    }

    QString message = lineEditMsg->text();

    // Check if phone number and message are not empty
    if (toPhoneNumber.isEmpty() || message.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter both a phone number and a message.");
        return;
    }

    // Call the sendSms function to send the SMS
    sendSms(toPhoneNumber, message);
}











void MainWindow::sendSms(const QString& toPhoneNumber, const QString& message)
{
    // Twilio credentials
    const QString accountSid = "AC1c953cd560cb86aceacf2542e9babdc4";
    const QString authToken = "bc7b4633e05c42340342b0787bfe028f";
    const QString fromPhoneNumber = "+14124192354";  // Replace with your Twilio number

    // API endpoint
    QUrl apiUrl("https://api.twilio.com/2010-04-01/Accounts/" + accountSid + "/Messages.json");

    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QNetworkRequest request(apiUrl);

    // Set up HTTP Basic Authentication
    QString authValue = "Basic " + QString(QByteArray(QString("%1:%2").arg(accountSid).arg(authToken).toUtf8()).toBase64());
    request.setRawHeader("Authorization", authValue.toUtf8());

    // Set up multipart data for the request
    QHttpMultiPart* multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    QHttpPart toPart;
    toPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"To\""));
    toPart.setBody(toPhoneNumber.toUtf8());

    QHttpPart fromPart;
    fromPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"From\""));
    fromPart.setBody(fromPhoneNumber.toUtf8());

    QHttpPart bodyPart;
    bodyPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"Body\""));
    bodyPart.setBody(message.toUtf8());

    // Append parts to the multipart
    multiPart->append(toPart);
    multiPart->append(fromPart);
    multiPart->append(bodyPart);

    // Send the request
    QNetworkReply* reply = manager->post(request, multiPart);
    multiPart->setParent(reply);  // Ensure multiPart is deleted with the reply

    connect(reply, &QNetworkReply::finished, [reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QMessageBox::information(nullptr, "Success", "SMS sent successfully!");
        } else {
            QByteArray responseData = reply->readAll();
            QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
            QString errorMessage = jsonResponse["message"].toString();

            qDebug() << "Error sending SMS:" << reply->errorString();
            qDebug() << "Twilio response:" << jsonResponse;
            QMessageBox::warning(nullptr, "Error", "Failed to send SMS: " + errorMessage);
        }
        reply->deleteLater();
    });
}

void MainWindow::onSmsSent(QNetworkReply* reply)
{
    // Check if the SMS was sent successfully
    if (reply->error() == QNetworkReply::NoError) {
        QMessageBox::information(this, "Success", "SMS sent successfully!");
    } else {
        // Handle error and show the response from the Twilio API
        QString error = reply->errorString();
        qDebug() << "Error sending SMS: " << error;
        QMessageBox::warning(this, "Error", "Failed to send SMS: " + error);
    }

    // Clean up after the reply
    reply->deleteLater();
}









void MainWindow::on_pushButton_stat_clicked() {
    // Query the database to get counts for each client type
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

    // Create the pie chart for stat
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

    // Line chart for stat_2
    QLineSeries *lineSeries = new QLineSeries();
    lineSeries->append(0, countParticulier); // Data point for "Particulier"
    lineSeries->append(1, countEntreprise); // Data point for "Entreprise"
    QChart *lineChart = new QChart();
    lineChart->addSeries(lineSeries);
    lineChart->setTitle("Client Type Comparison (Curve)");
    lineChart->createDefaultAxes();
    lineChart->legend()->setVisible(true);
    lineChart->legend()->setAlignment(Qt::AlignBottom);

    // Set the color of the "Entreprise" line to purple
    lineSeries->setColor(QColor(128, 0, 128)); // Purple

    QChartView *lineChartView = new QChartView(lineChart);
    lineChartView->setRenderHint(QPainter::Antialiasing);
    if (!ui->stat_2->layout()) {
        QVBoxLayout *layout = new QVBoxLayout(ui->stat_2);
        ui->stat_2->setLayout(layout);
    }
    ui->stat_2->layout()->addWidget(lineChartView);

    // Bar chart for stat_3
    QBarSet *setParticulier = new QBarSet("Particulier");
    *setParticulier << countParticulier;
    QBarSet *setEntreprise = new QBarSet("Entreprise");
    *setEntreprise << countEntreprise;
    QBarSeries *barSeries = new QBarSeries();
    barSeries->append(setParticulier);
    barSeries->append(setEntreprise);

    // Set colors for the bars
    setParticulier->setColor(Qt::blue);  // Particulier - Green
    setEntreprise->setColor(QColor(128, 0, 128));  // Entreprise - Purple (using QColor)

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

    // Create the sinusoidal curve chart for stat_4
    QLineSeries *sinusoidalSeries = new QLineSeries();
    int amplitude = 50;  // Amplitude of the sinusoidal curve
    int frequency = 2;   // Frequency of the sinusoidal curve
    int phaseShift = 0;  // Phase shift for the sinusoidal curve

    // Generate sinusoidal data points
    for (int x = 0; x < 360; x++) {
        // Sinusoidal formula: y = amplitude * sin(frequency * x + phaseShift)
        double y = amplitude * sin(frequency * qDegreesToRadians(x) + phaseShift);
        sinusoidalSeries->append(x, y);
    }

    QChart *sinusoidalChart = new QChart();
    sinusoidalChart->addSeries(sinusoidalSeries);
    sinusoidalChart->createDefaultAxes();
    sinusoidalChart->setTitle("Sinusoidal Curve for Client Type Distribution");

    QChartView *sinusoidalChartView = new QChartView(sinusoidalChart);
    sinusoidalChartView->setRenderHint(QPainter::Antialiasing);

    // Add the sinusoidal curve chart to stat_4
    if (!ui->stat_4->layout()) {
        QVBoxLayout *layout = new QVBoxLayout(ui->stat_4);
        ui->stat_4->setLayout(layout);
    }
    ui->stat_4->layout()->addWidget(sinusoidalChartView);

    // Switch to the statistics page
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

QString tempBuffer = "";

void MainWindow::update_label() {
    QByteArray data = A.read_from_arduino();

    if (!data.isEmpty()) {
        qDebug() << "Raw data received: " << data;


        QString dataStr = QString::fromUtf8(data);
        qDebug() << "Received string: " << dataStr;


        dataStr = dataStr.trimmed();


        if (dataStr.isEmpty() || dataStr == "\r\n" || dataStr == "\n") {
            qDebug() << "Waiting for valid data...";
            return;
        }


        QRegularExpression regex("^([0-9]{1,2})\\.[0-9]{1,2}$");
        QRegularExpressionMatch match = regex.match(dataStr);

        if (match.hasMatch()) {

            bool ok;
            float temperature = dataStr.toFloat(&ok);

            if (ok && temperature > 0 && temperature < 100) {

                ui->label_temperature->setText(QString("Temperature: %1 °C").arg(temperature));
                qDebug() << "Temperature displayed: " << temperature;


                tempBuffer.clear();
            } else {
                qDebug() << "Invalid temperature value: " << temperature;
            }
        } else {
            qDebug() << "Invalid data format. Waiting for valid data...";
        }
    } else {
        qDebug() << "No data received from Arduino.";
    }
}


void MainWindow::on_pushButton_buzzer_clicked() {
    qDebug() << "Buzzer button clicked.";
    if (A.getserial()->isWritable()) {
        A.write_to_arduino("BUZZER_ON\n");
        qDebug() << "BUZZER_ON command sent to Arduino.";
    } else {
        qDebug() << "Failed to write to Arduino.";
    }
}







void MainWindow::on_pushButton_tem_clicked()
{

    int code_client = ui->id99->text().toInt();


    if (code_client <= 0) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid Client ID.");
        return;
    }

    // Get the temperature from the label
    QString temperature = ui->label_temperature->text();


    QRegularExpression regex(R"(\b\d{1,2}\.\d{1,2}\b)");
    QRegularExpressionMatch match = regex.match(temperature);

    if (!match.hasMatch()) {
        QMessageBox::warning(this, "Input Error", "Temperature value is invalid or not set.");
        return;
    }

    QString tempValue = match.captured(0);


    QSqlQuery query;
    query.prepare("UPDATE client SET tem = :tem WHERE code_client = :code_client");
    query.bindValue(":tem", tempValue);
    query.bindValue(":code_client", code_client);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Temperature updated successfully!");
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to update temperature. Error: " + query.lastError().text());
    }
}


void MainWindow::on_pushButton_status_clicked() {
    // Récupérer les clients avec température >= 20°C
    QSqlQuery query;
    query.prepare("SELECT code_client, nom, tem FROM client WHERE tem >= 20");
    if (query.exec()) {
        QString clientList;
        while (query.next()) {
            int code_client = query.value(0).toInt();
            QString clientName = query.value(1).toString();
            float clientTemp = query.value(2).toFloat();

            clientList.append(QString("Client: %1, Temp: %2°C\n").arg(clientName).arg(clientTemp));
        }

        // Afficher la notification
        if (!clientList.isEmpty()) {
            QMessageBox::information(this, "Clients avec Température >= 20°C", clientList);
        } else {
            QMessageBox::information(this, "Aucun Client", "Aucun client n'a une température >= 20°C.");
        }
    } else {
        QMessageBox::critical(this, "Database Error", "Erreur lors de la récupération des clients: " + query.lastError().text());
    }
}

































//-------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_add_clicked()
{
    QString id = ui->lineEdit_6->text().trimmed();
    QString recy = ui->comboBox_4->currentText();
    QString type = ui->comboBox_3->currentText();
    QString stockstr = ui->lineEdit_3->text().trimmed();
    QDate date = ui->dateEdit->date();
    QString coststr = ui->lineEdit_5->text().trimmed();

    // Validation: Check if Material ID has 12 characters
    if (id.length() != 12) {
        QMessageBox::warning(this, "Input Error", "Material ID must be exactly 12 characters long.");
        return;
    }

    // Validation: Ensure Quantity in Stock is a valid positive number
    bool stockIsNumber;
    int stock = stockstr.toInt(&stockIsNumber);
    if (!stockIsNumber || stock < 0) {
        QMessageBox::warning(this, "Input Error", "Quantity in Stock must be a positive number (0 or more).");
        return;
    }

    // Validation: Ensure Unit Cost is a valid positive number
    bool costIsNumber;
    int cost = coststr.toInt(&costIsNumber);
    if (!costIsNumber || cost < 0) {
        QMessageBox::warning(this, "Input Error", "Unit Cost must be a positive number (0 or more).");
        return;
    }

    // If all validations pass, proceed to add the material
    Material M(id, recy, type, stock, date, cost);
    bool test = M.add();
    if (test) {
        ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(this, "Success", "Material added successfully.");
    } else {
        QMessageBox::critical(this, "Failed", "Error adding material.");
    }
}


/*void MainWindow::on_delete_2_clicked()
{

    QString id = ui->lineEdit_6->text().trimmed();
    bool test = Etmp.supprimer(id);
    if (test) {
        ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("Success"),
                                 QObject::tr("Record deleted successfully."));
    } else {
        // Display an error message if deletion fails
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Failed to delete the record. Please check your data"));
    }
}*/
void MainWindow::on_delete_2_clicked() {
    // Get the ID from the input field
    QString id = ui->lineEdit_2->text().trimmed();

    // Validate if the ID is empty
    if (id.isEmpty()) {
        QMessageBox::warning(this, QObject::tr("Input Error"),
                             QObject::tr("Please enter a valid Material ID to delete."));
        return; // Exit the function if no ID is provided
    }

    // Attempt to delete the record
    bool test = Etmp.supprimer(id);
    if (test) {
        // Refresh the table view after successful deletion
        ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(this, QObject::tr("Success"),
                                 QObject::tr("Material deleted successfully."));
    } else {
        // Display an error message if deletion fails
        QMessageBox::critical(this, QObject::tr("Error"),
                              QObject::tr("Failed to delete the Material. Please check if the Material ID exists."));
    }
}



void MainWindow::on_updateButton_clicked() {
    QString id = ui->lineEdit_6->text().trimmed(); // Get the material ID to retrieve

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Selection Error", "Please enter a valid Material ID to retrieve.");
        return;
    }

    Material M;

    // Fetch data for the given Material ID
    if (M.fetchData(id)) {
        // Fill the form fields with the retrieved data
        ui->comboBox_4->setCurrentText(M.getRecyclability());
        ui->comboBox_3->setCurrentText(M.getMaterialType());
        ui->lineEdit_3->setText(QString::number(M.getQuantityInStock()));
        ui->lineEdit_5->setText(QString::number(M.getUnitCost()));
        ui->dateEdit->setDate(M.getPurchaseDate());
    } else {
        QMessageBox::warning(this, "Retrieve Error", "No material found with the given ID.");
    }
}


void MainWindow::on_update2Button_clicked() {
    QString id = ui->lineEdit_6->text().trimmed(); // Material ID to update

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a Material ID to update.");
        return;
    }

    // Retrieve updated values from the form
    QString recyclability = ui->comboBox_4->currentText(); // Recyclability as QString
    QString materialType = ui->comboBox_3->currentText();  // Material Type as QString
    int stock = ui->lineEdit_3->text().toInt();            // Quantity in Stock as int
    int cost = ui->lineEdit_5->text().toInt();       // Unit Cost as QString
    QDate purchaseDate = ui->dateEdit->date();             // Purchase Date as QDate


    // Create a Material object with updated values
    Material M(id, recyclability, materialType, stock, purchaseDate, cost);

    // Attempt to update the material in the database
    if (M.update(id)) {
        ui->tableView->setModel(Etmp.afficher()); // Refresh the table view
        QMessageBox::information(this, "Success", "Material updated successfully.");
    } else {
        QMessageBox::critical(this, "Error", "Failed to update the material. Please check your input.");
    }
}
//---------------------------------------------------------------sort
void MainWindow::on_sortComboBox_changed() {
    QString column = ui->comboBox_10->currentText();

    // Map the column name to the corresponding database field
    QString dbColumn;
    if (column == "Material_ID") {
        dbColumn = "MATERIAL_ID";
    } else if (column == "Recyclability") {
        dbColumn = "RECYCLABILITY";
    } else if (column == "Material Type") {
        dbColumn = "MATERIAL_TYPE";
    } else if (column == "Quantity in Stock") {
        dbColumn = "QUANTITY_IN_STOCK";
    } else if (column == "Unit Cost") {
        dbColumn = "UNIT_COST";
    } else if (column == "Purchase Date") {
        dbColumn = "PURCHASE_DATE";
    } else {
        return; // Invalid selection
    }

    // Use the Material object's sortBy method to sort the table
    QSqlQueryModel *sortedModel = Etmp.sortBy(dbColumn, true); // true for ascending
    if (sortedModel) {
        ui->tableView->setModel(sortedModel); // Update the table view with the sorted model
    } else {
        QMessageBox::warning(this, "Sorting Error", "Failed to sort the table. Please try again.");
    }
}
//-------------------------------------------------------------chercher
void MainWindow::on_searchLineEdit_textChanged() {
    QString id = ui->lineEdit_S->text().trimmed();

    // If the search field is empty, show all transactions
    if (id.isEmpty()) {
        ui->tableView->setModel(Etmp.afficher());
        return;
    }

    // Otherwise, search for the specific ID
    QSqlQueryModel *searchModel = Etmp.search(id);

    if (searchModel) {
        ui->tableView->setModel(searchModel);
    } else {
        QMessageBox::warning(this, "Search Error", "No results found for the provided ID.");
    }
}
//-----------------------------------------------------------------Stats
void MainWindow::on_statsButton_clicked() {
    QSqlQuery query;
    QMap<QString, int> materialQuantities; // Map to store material type and its total quantity

    // Query to fetch material type and their total quantity in stock
    if (query.exec("SELECT MATERIAL_TYPE, SUM(QUANTITY_IN_STOCK) AS TOTAL_QUANTITY FROM PRODUIT GROUP BY MATERIAL_TYPE")) {
        while (query.next()) {
            QString materialType = query.value(0).toString();
            int totalQuantity = query.value(1).toInt();
            materialQuantities[materialType] = totalQuantity;
        }
    } else {
        qDebug() << "Error fetching statistics:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to fetch statistics. Please try again.");
        return;
    }

    // Check if there is any data to display
    if (materialQuantities.isEmpty()) {
        QMessageBox::information(this, "Statistics", "No data available to display statistics.");
        return;
    }

    // Create bar sets for the chart
    QBarSet *set = new QBarSet("Material Types");
    QStringList categories; // Store material types for the X-axis labels

    for (auto it = materialQuantities.begin(); it != materialQuantities.end(); ++it) {
        *set << it.value();               // Add total quantity to the bar set
        categories << it.key();           // Add material type to categories
    }

    QBarSeries *series = new QBarSeries();
    series->append(set);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistics: Quantity in Stock by Material Type");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Configure X-axis with material types
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Configure Y-axis for quantities
    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Quantity in Stock");
    axisY->setLabelFormat("%i");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Create the chart view
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Create a new QWidget to display the chart
    QWidget *chartWidget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(chartWidget);
    layout->addWidget(chartView);
    chartWidget->setWindowTitle("Material Statistics");
    chartWidget->resize(800, 600);
    chartWidget->show();

    // Close the chart widget when it's no longer needed
    connect(chartWidget, &QWidget::destroyed, [=]() {
        chartWidget->deleteLater();
    });
}



void MainWindow::on_pushButton_13_clicked() {
    // Ask the user to select a file name and location for the PDF
    QString fileName = QFileDialog::getSaveFileName(this, "Export Table to PDF", "", "*.pdf");
    if (fileName.isEmpty()) {
        return; // User canceled the dialog
    }

    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive)) {
        fileName += ".pdf"; // Ensure the file has a .pdf extension
    }

    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(300); // High-quality resolution
    QPainter painter(&pdfWriter);

    // Title of the PDF
    painter.setFont(QFont("Arial", 16, QFont::Bold));
    QRect titleRect(0, 0, pdfWriter.width(), 50);
    painter.drawText(titleRect, Qt::AlignCenter, "Exported Table Data");

    // Fetch data from the table view
    QAbstractItemModel *model = ui->tableView->model();
    if (!model) {
        QMessageBox::critical(this, "Error", "Failed to fetch data from tableView2.");
        return;
    }

    // Set initial positions and dimensions
    int x = 50;                // Left margin
    int y = 100;               // Top margin
    int rowHeight = 50;        // Height of each row
    int totalWidth = pdfWriter.width() - 100; // Total width available for the table
    QVector<int> columnWidths = {totalWidth / 6, totalWidth / 6, totalWidth / 6, totalWidth / 6, totalWidth / 6, totalWidth / 6};

    // Draw the table headers
    painter.setFont(QFont("Arial", 12, QFont::Bold));
    QVector<QString> headers = {"Material ID", "Recyclability", "Material Type", "Quantity in Stock", "Purchase Date", "Unit Cost"};
    for (int column = 0; column < headers.size(); ++column) {
        painter.drawText(x, y, columnWidths[column], rowHeight, Qt::AlignCenter, headers[column]);
        x += columnWidths[column];
    }

    y += rowHeight; // Move to the next row
    x = 50; // Reset x for table rows

    // Draw the table rows
    painter.setFont(QFont("Arial", 10));
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int column = 0; column < model->columnCount(); ++column) {
            QString value = model->data(model->index(row, column)).toString();

            // Format the "Purchase Date" column (assuming column 4 is the date)
            if (column == 4) {
                QDateTime date = QDateTime::fromString(value, Qt::ISODate);
                value = date.toString("dd/MM/yyyy");
            }

            // Align data in the cells
            painter.drawText(x, y, columnWidths[column], rowHeight, Qt::AlignCenter, value);
            x += columnWidths[column];
        }
        y += rowHeight; // Move to the next row
        x = 50; // Reset x for next row

        // Check if the page is full
        if (y > pdfWriter.height() - 100) {
            pdfWriter.newPage();
            y = 100; // Reset y for the new page
        }
    }

    painter.end();

    QMessageBox::information(this, "Success", "Table exported to PDF successfully!");
}
//------------------------------------------------------------------mail
void MainWindow::on_pushButton_7_clicked() {
    // Define the email details
    QString recipient = "example@example.com"; // Replace with the recipient's email address
    QString subject = "Hello from RUBICON!"; // The email subject
    QString body = "Dear User,\n\nThis is an email sent from the RUBICON application.\n\nBest regards,\nThe RUBICON Team"; // The email body

    // Encode the email details into a mailto link
    QString mailto = QString("mailto:%1?subject=%2&body=%3")
                         .arg(recipient)
                         .arg(subject)
                         .arg(body);

    // Open the default email client
    QDesktopServices::openUrl(QUrl(mailto));
}




void MainWindow::on_pushButton_8_clicked() {
    // Create a QWidget to contain the calendar and close button
    QWidget *calendarWidget = new QWidget(this);
    calendarWidget->setWindowTitle("Purchase Dates Calendar");
    calendarWidget->setGeometry(50, 100, 500, 450); // Adjust position and size
    calendarWidget->setStyleSheet("background-color: #ffffff; border: 1px solid #0078d7; border-radius: 10px;");

    // Create the calendar widget
    QCalendarWidget *calendar = new QCalendarWidget(calendarWidget);
    calendar->setGeometry(10, 10, 480, 380); // Position the calendar within the widget
    calendar->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader); // Remove vertical headers
    calendar->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames); // Use abbreviated day names
    calendar->setStyleSheet("QCalendarWidget {"
                            "    color: #000;"                // Black text
                            "}"
                            "QCalendarWidget QToolButton {"
                            "    background-color: #0078d7;"  // Blue for navigation buttons
                            "    color: #fff;"                // White text
                            "    border-radius: 5px;"         // Rounded button edges
                            "    padding: 5px;"               // Padding for better button design
                            "    font-size: 14px;"            // Font size
                            "    font-weight: bold;"          // Bold text
                            "}"
                            "QCalendarWidget QToolButton::hover {"
                            "    background-color: #005bb5;"  // Darker blue on hover
                            "}"
                            "QCalendarWidget QAbstractItemView:enabled {"
                            "    font-size: 12px;"            // Adjust font size
                            "    color: #000;"                // Default black text for days
                            "}"
                            "QCalendarWidget QAbstractItemView::item:selected {"
                            "    background-color: #ffcc00;"  // Highlight selected day
                            "    color: #000;"                // Black text for selected day
                            "}");

    // Prepare the format for purchase dates (green, resembling the "20")
    QTextCharFormat purchaseDateFormat;
    purchaseDateFormat.setBackground(QColor("#32CD32")); // Green color similar to the orange highlight
    purchaseDateFormat.setForeground(Qt::black);         // Black text
    purchaseDateFormat.setFontWeight(QFont::Bold);       // Bold text

    // Query the database for purchase dates
    QSqlQuery query;
    if (!query.exec("SELECT PURCHASE_DATE FROM PRODUIT")) {
        QMessageBox::critical(this, "Database Error", "Failed to fetch purchase dates: " + query.lastError().text());
        return;
    }

    // Loop through the results and highlight dates
    while (query.next()) {
        QString purchaseDateStr = query.value(0).toString();  // Get the purchase date as a string
        QDate purchaseDate = QDate::fromString(purchaseDateStr, "yyyy-MM-dd"); // Parse using the correct format

        // If parsing fails, try alternative formats
        if (!purchaseDate.isValid()) {
            purchaseDate = QDate::fromString(purchaseDateStr, "dd/MM/yyyy");
        }

        // Apply the green format for valid dates
        if (purchaseDate.isValid()) {
            calendar->setDateTextFormat(purchaseDate, purchaseDateFormat);
        }
    }

    // Create a close button for the widget
    QPushButton *closeButton = new QPushButton("Close", calendarWidget);
    closeButton->setGeometry(200, 400, 100, 30); // Position the button at the bottom of the widget
    closeButton->setStyleSheet("background-color: #0078d7; color: #fff; border-radius: 5px; font-size: 12px;");
    connect(closeButton, &QPushButton::clicked, calendarWidget, &QWidget::close);

    // Show the widget
    calendarWidget->show();
}
//---------------------------------------------notifications
void MainWindow::on_pushButton_10_clicked() {
    // Query the database for materials with stock < 100
    QSqlQuery query;
    if (!query.exec("SELECT MATERIAL_ID, MATERIAL_TYPE, QUANTITY_IN_STOCK FROM PRODUIT WHERE QUANTITY_IN_STOCK < 100")) {
        QMessageBox::critical(this, "Database Error", "Failed to fetch low-stock materials: " + query.lastError().text());
        return;
    }

    // Prepare the message content
    QString message = "The following materials have low stock (< 100):\n\n";
    bool hasLowStock = false;

    while (query.next()) {
        hasLowStock = true; // At least one item with low stock exists
        QString materialId = query.value(0).toString();
        QString materialType = query.value(1).toString();
        int quantity = query.value(2).toInt();
        message += QString("ID: %1 | Type: %2 | Stock: %3\n")
                       .arg(materialId)
                       .arg(materialType)
                       .arg(quantity);
    }

    // Show notification based on the result
    if (hasLowStock) {
        QMessageBox::warning(this, "Low Stock Alert", message);
    } else {
        QMessageBox::information(this, "Stock Levels", "All materials have sufficient stock.");
    }
}







































































