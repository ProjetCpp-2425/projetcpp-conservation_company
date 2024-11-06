#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    client tempClient;
    QTableView* tableView = ui->widget->findChild<QTableView*>("cc");

    if (tableView) {
        tableView->setModel(tempClient.afficher());
    } else {
        qDebug() << "tableView 'affclient' not found!";
    }



    ui->stackedWidget->addWidget(ui->user);
    ui->stackedWidget->addWidget(ui->stock);
    ui->stackedWidget->addWidget(ui->Livraison);
    ui->stackedWidget->addWidget(ui->Login);
    ui->stackedWidget_2->addWidget(ui->clients);
    ui->stackedWidget_2->addWidget(ui->statistique);
    ui->stackedWidget_2->addWidget(ui->chatbot);


    connect(ui->pushButton_user, &QPushButton::clicked, this, &MainWindow::user);
    connect(ui->pushButton_20, &QPushButton::clicked, this, &MainWindow::Login);
    connect(ui->pushButton_11, &QPushButton::clicked, this, &MainWindow::user);



    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::clients);
    connect(ui->pushButton_13, &QPushButton::clicked, this, &MainWindow::statistique);
    connect(ui->pushButton_16, &QPushButton::clicked, this, &MainWindow::chatbot);
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


    QRegularExpression telPattern("^\\d{9,}$");
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
        QRegularExpression telPattern("^\\d{9,}$");
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






