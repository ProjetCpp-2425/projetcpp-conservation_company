#include "mainwindow.h"
#include "qrcode.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QDebug>
#include <QVBoxLayout>  // Ajout pour le layout
#include "livraison.h"
#include <QPainter>
#include "arduino.h"
#include <QDebug>
#include <QSqlError>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(new QSqlQueryModel(this))
{
    ui->setupUi(this);

    if (arduino.connectToArduino()) {
        connect(arduino.serial, &QSerialPort::readyRead, this, &MainWindow::handleArduinoData);
    } else {
        qDebug() << "Impossible de connecter à l'Arduino.";
    }



    ui->tableView->setModel(livraison.afficher()); // Display all records on app start
    connect(ui->stat_2, &QPushButton::clicked, this, &MainWindow::afficherStatistiquesLivraisons);

    // Connect buttons to slots
    connect(ui->afficherliv, &QPushButton::clicked, this, &MainWindow::on_afficherLivraisonsButton_clicked);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::on_addButton_clicked);
    connect(ui->modifyButton, &QPushButton::clicked, this, &MainWindow::on_modifyButton_clicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::on_deleteButton_clicked);
    connect(ui->searchButton_2, &QPushButton::clicked, this, &MainWindow::on_searchButton_clicked);
    connect(ui->generatePdfButton_2, &QPushButton::clicked, this, &MainWindow::generatePdf);
    connect(ui->sortButton_2, &QPushButton::clicked, this, &MainWindow::on_sortButton_clicked);
    //connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::on_loginButton_clicked);
    connect(ui->signup, &QPushButton::clicked, this, [this]() {
        if (inscrireEmploye()) {
            changerDePageLogin();  // Si l'inscription réussit, changer de page
        }
    });
    ////
    connect(ui->Login, &QPushButton::clicked, this, &MainWindow::changerDePageLogin);
    connect(ui->loginButton, &QPushButton::clicked, this, [this]() {
        // Call the login function and navigate only if login is successful
        if (on_loginButton_clicked()) {
            changerDePageLivraison(); // Change page if login is successful
        }
    });
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::changerDePageLivraison()
{

    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::changerDepageSignup()
{

    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::changerDePageLogin()
{

    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_afficherLivraisonsButton_clicked()
{
    Livraison livraison; // Instance de la classe Livraison
    QSqlQueryModel *model = livraison.afficher();
    if (model) {
        ui->tableView->setModel(model); // Liaison du modèle au tableView
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible d'afficher les livraisons.");
    }
}

void MainWindow::on_addButton_clicked()
{
    QString numSuiv = ui->numSuivLineEdit->text();
    QDate dateArrive = ui->dateArriveEdit->date();
    QDate dateSortie = ui->dateSortieEdit->date();
    QString ADDRESS = ui->ADDRESSLineEdit->text();
    int idProduit = ui->idProduitLineEdit->text().toInt();

    livraison = Livraison(numSuiv, dateArrive, dateSortie, ADDRESS, idProduit );

    if (livraison.ajouter()) {
        QMessageBox::information(this, "Success", "Livraison added successfully.");
        ui->tableView->setModel(livraison.afficher()); // Refresh table
    } else {
        QMessageBox::warning(this, "Error", "Failed to add livraison.");
    }
}

void MainWindow::on_modifyButton_clicked()
{
    QString numSuiv = ui->numSuivLineEdit->text();
    QDate dateArrive = ui->dateArriveEdit->date();
    QDate dateSortie = ui->dateSortieEdit->date();
    QString ADDRESS = ui->ADDRESSLineEdit->text();
    int idProduit = ui->idProduitLineEdit->text().toInt();

    if (livraison.modifier(numSuiv, dateArrive, dateSortie, ADDRESS, idProduit)) {
        QMessageBox::information(this, "Success", "Livraison modified successfully.");
        ui->tableView->setModel(livraison.afficher()); // Refresh table
    } else {
        QMessageBox::warning(this, "Error", "Failed to modify livraison.");
    }
}

void MainWindow::on_deleteButton_clicked()
{
    QString numSuiv = ui->recherche_3->text();

    if (livraison.supprimer(numSuiv)) {
        QMessageBox::information(this, "Success", "Livraison deleted successfully.");
        ui->tableView->setModel(livraison.afficher()); // Refresh table
    } else {
        QMessageBox::warning(this, "Error", "Failed to delete livraison.");
    }
}
void MainWindow::on_searchButton_clicked() {
    QString keyword = ui->recherche_3->text(); // Assuming there is a search input field with this name
    ui->tableView->setModel(livraison.search(keyword)); // Update table view with search results
}

void MainWindow::generatePdf()
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

    // Define fonts
    QFont headerFont("Arial", 12, QFont::Bold);
    QFont contentFont("Arial", 10);

    // Use tableView for PDF export
    QTableView *tableView = ui->tableView;
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
    int rowHeight = 50;  // Keep the same as specified
    int x = leftMargin;
    int y = topMargin;

    int columnSpacing = 500; // Adjust column spacing for your content
    int rowSpacing = 300;    // Adjust row spacing for readability

    // **Draw the header row with a background color**
    painter.setBrush(QColor(200, 200, 255)); // Light blue background
    painter.setPen(Qt::NoPen);              // No border
    painter.drawRect(leftMargin, y - rowHeight + 10, model->columnCount() * columnSpacing, rowHeight); // Header background

    painter.setPen(Qt::black);              // Black text for headers
    painter.setFont(headerFont);

    x = leftMargin;
    for (int col = 0; col < model->columnCount(); ++col) {
        QString header = model->headerData(col, Qt::Horizontal).toString();
        painter.drawText(x, y, header);
        x += columnSpacing;
    }

    y += rowSpacing;
    x = leftMargin;

    // **Draw table content with alternating row colors**
    painter.setFont(contentFont);
    for (int row = 0; row < model->rowCount(); ++row) {
        // Alternate row colors
        if (row % 2 == 0) {
            painter.setBrush(QColor(240, 240, 240)); // Light gray for even rows
        } else {
            painter.setBrush(QColor(255, 255, 255)); // White for odd rows
        }

        painter.setPen(Qt::NoPen); // No border
        painter.drawRect(leftMargin, y - rowHeight + 10, model->columnCount() * columnSpacing, rowHeight); // Row background

        // Draw row content with separators
        painter.setPen(Qt::black); // Black text
        QString rowText;
        for (int col = 0; col < model->columnCount(); ++col) {
            QVariant data = model->data(model->index(row, col));
            if (col > 0) {
                rowText += " | "; // Add separator between columns
            }
            rowText += data.toString();
        }
        painter.drawText(x, y, rowText);
        y += rowSpacing;

        // Check for page overflow
        if (y > pdfWriter.height() - 50) {
            pdfWriter.newPage();
            y = topMargin;

            // Redraw the header on the new page
            painter.setBrush(QColor(200, 200, 255)); // Light blue background
            painter.setPen(Qt::NoPen);
            painter.drawRect(leftMargin, y - rowHeight + 10, model->columnCount() * columnSpacing, rowHeight); // Header background

            painter.setPen(Qt::black);
            x = leftMargin;
            for (int col = 0; col < model->columnCount(); ++col) {
                QString header = model->headerData(col, Qt::Horizontal).toString();
                painter.drawText(x, y, header);
                x += columnSpacing;
            }
            y += rowSpacing;
        }
    }

    painter.end();

    QMessageBox::information(this, "Success", "Data exported to PDF file successfully.");
}





void MainWindow::on_sortButton_clicked()
{
    // Utilise la fonction pour obtenir les données triées en ordre décroissant
    QSqlQueryModel *sortedModel = livraison.trierParDateSortie();
    if (sortedModel) {
        ui->tableView->setModel(sortedModel);  // Affiche les données triées dans tableView
        QMessageBox::information(this, "Tri effectué", "Les livraisons ont été triées par date de sortie (ordre décroissant).");
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible d'effectuer le tri.");
    }
}


#include "employe.h"
#include <QMessageBox>

                              ///// thabet feha hethi

bool MainWindow::on_loginButton_clicked() {
    QString idText = ui->usernameLineEdit->text();  // User-provided ID
    QString mdpText = ui->passwordLineEdit->text(); // User-provided password

    // Validate input fields
    if (idText.isEmpty() || mdpText.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        return false;
    }

    // Convert ID to integer
    bool ok;
    int idEmploye = idText.toInt(&ok);
    if (!ok || idEmploye <= 0) {
        QMessageBox::warning(this, "Erreur", "ID Employé invalide.");
        return false;
    }

    // Query the database for user credentials
    QSqlQuery query;
    query.prepare("SELECT MDP FROM Employe WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", idEmploye);

    if (query.exec() && query.next()) {
        QString mdp = query.value(0).toString(); // Fetch password from database

        // Check if password matches
        if (mdp == mdpText) {
            qDebug() << "Login successful for user ID:" << idEmploye;
            return true; // Login successful
        } else {
            QMessageBox::warning(this, "Erreur", "Mot de passe incorrect.");
            return false; // Incorrect password
        }
    } else {
        QMessageBox::warning(this, "Erreur", "ID Employé non trouvé.");
        return false; // User not found
    }
}

#include <QRandomGenerator>
bool MainWindow::inscrireEmploye() {
    QString nom = ui->nomi->text();
    QString prenom = ui->prenomi->text();
    QString poste = ui->postei->currentText();
    QString telephone = ui->telephonei->text();
    QString mdp = ui->mdpi->text();

    // Validation des champs vides
    if (nom.isEmpty() || prenom.isEmpty() || poste.isEmpty() || telephone.isEmpty() || mdp.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return false;
    }

    // Validation du numéro de téléphone
    if ((!telephone.startsWith("2") && !telephone.startsWith("3") &&
         !telephone.startsWith("5") && !telephone.startsWith("7") &&
         !telephone.startsWith("9")) || telephone.length() != 8) {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit être valide et contenir 8 chiffres.");
        return false;
    }

    // Validation du mot de passe
    QRegularExpression regex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d).{6,}$");
    if (!regex.match(mdp).hasMatch()) {
        QMessageBox::warning(this, "Erreur",
                             "Le mot de passe doit contenir au moins 6 caractères, "
                             "incluant une lettre majuscule, une lettre minuscule, et un chiffre.");
        return false;
    }

    // Création d'un objet Employe
    Employe employe;

    // Génération d'un ID unique (vous pouvez ajuster ce code selon vos besoins)
    int idUnique = employe.genererIdUnique();

    // Inscription de l'employé
    if (employe.inscrire(idUnique, nom, prenom, poste, telephone.toInt(), mdp)) {
        QMessageBox::information(this, "Succès", "Employé inscrit avec succès.");

        // Envoi d'un SMS de bienvenue
        QString message = QString("Bienvenue %1 %2 ! Votre ID employé est : %3.")
                              .arg(nom)
                              .arg(prenom)
                              .arg(idUnique);
        employe.sendSMS("+216" + telephone, message);

        // Réinitialisation des champs
        ui->nomi->clear();
        ui->prenomi->clear();
        ui->telephonei->clear();
        ui->mdpi->clear();
        ui->postei->setCurrentIndex(0);

        return true;
    } else {
        QMessageBox::critical(this, "Erreur", "L'inscription a échoué.");
        return false;
    }
}


void MainWindow::afficherStatistiquesLivraisons() {
    // Supprimer les anciens widgets du layout stat
    QLayout *layout = ui->stat->layout();
    if (layout) {
        // Utiliser une boucle propre pour vider les anciens widgets du layout
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
    }

    // Création d'un objet Livraison et récupération des statistiques
    Livraison livraison;
    QMap<QString, int> stats = livraison.statistiquesLivraisonsParMois();

    // Calcul du total pour les pourcentages
    int total = 0;
    for (int value : stats) {
        total += value;
    }

    // Création d'une série pour le graphique
    QPieSeries *series = new QPieSeries();
    QList<QColor> couleurs = { Qt::blue, Qt::red, Qt::green, Qt::yellow, Qt::cyan, Qt::magenta };
    int indexCouleur = 0;

    for (auto it = stats.begin(); it != stats.end(); ++it) {
        QPieSlice *slice = series->append(it.key(), it.value());
        double percentage = (double)it.value() / total * 100;
        slice->setLabel(QString("%1: %2%").arg(it.key()).arg(QString::number(percentage, 'f', 1)));
        slice->setLabelVisible(true);
        slice->setColor(couleurs[indexCouleur % couleurs.size()]);
        indexCouleur++;
    }

    // Création du graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des livraisons par mois");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Vérifier si le layout est déjà défini
    QVBoxLayout *statLayout = qobject_cast<QVBoxLayout *>(ui->stat->layout());
    if (!statLayout) {
        statLayout = new QVBoxLayout(ui->stat);
        ui->stat->setLayout(statLayout);
    }

    // Ajouter le graphique à l'interface utilisateur
    statLayout->addWidget(chartView);
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    if (index.isValid()) {
        QString id = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 0)).toString();
        QString nom = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 1)).toString();
        QString prenom = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 2)).toString();

        QString data = id + " " + nom + " " + prenom;
        qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(data.toUtf8().constData(), qrcodegen::QrCode::Ecc::MEDIUM);

        // Créer l'image du code QR
        int size = qr.getSize();
        QImage image(size, size, QImage::Format_RGB32);
        QRgb black = qRgb(0, 0, 0);
        QRgb white = qRgb(255, 255, 255);
        for (int y = 0; y < size; y++) {
            for (int x = 0; x < size; x++) {
                image.setPixel(x, y, qr.getModule(x, y) ? black : white);
            }
        }

        // Afficher l'image du code QR
        ui->qrLabel->setPixmap(QPixmap::fromImage(image.scaled(100, 100, Qt::KeepAspectRatio, Qt::FastTransformation)));
    }

}


void MainWindow::handleArduinoData() {
    QString id = arduino.readData();  // Read data received from Arduino
    qDebug() << "ID reçu de l'Arduino:" << id;

    if (!id.isEmpty()) {
        ui->usernameLineEdit->setText(id);  // Display the ID in the UI

        QSqlQuery query;
        query.prepare("SELECT MDP, NOM, PRENOM FROM Employe WHERE ID_EMPLOYE = :id");
        query.bindValue(":id", id);

        if (!query.exec()) {
            qDebug() << "Erreur lors de l'exécution de la requête SELECT:" << query.lastError().text();
        } else if (query.next()) {
            QString mdp = query.value("MDP").toString();
            QString nom = query.value("NOM").toString();
            QString prenom = query.value("PRENOM").toString();

            qDebug() << "Employé trouvé:" << nom << prenom << "MDP:" << mdp;

            // Update the UI with employee data
            ui->passwordLineEdit->setText(mdp);

            // Update employee presence in the database
            QSqlQuery updateQuery;
            updateQuery.prepare("UPDATE Employe SET presence = 'present' WHERE ID_EMPLOYE = :id");
            updateQuery.bindValue(":id", id);
            if (!updateQuery.exec()) {
                qDebug() << "Erreur lors de la mise à jour de la présence:" << updateQuery.lastError().text();
            } else {
                qDebug() << "Présence mise à jour pour l'ID:" << id;
            }

            // Send the message starting with "Bienvenue"
            QString message = QString("Bienvenue %1 %2").arg(nom).arg(prenom);
            arduino.sendData(message);
            qDebug() << "Message envoyé à l'Arduino:" << message;

        } else {
            // If the employee is not found
            qDebug() << "Employé non trouvé pour l'ID:" << id;
            arduino.sendData("Employe non trouve");
        }
    } else {
        qDebug() << "Aucun ID reçu de l'Arduino.";
    }
}



