#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(new QSqlQueryModel(this))
{
    ui->setupUi(this);
    ui->tableView->setModel(livraison.afficher()); // Display all records on app start

    // Connect buttons to slots
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::on_addButton_clicked);
    connect(ui->modifyButton, &QPushButton::clicked, this, &MainWindow::on_modifyButton_clicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::on_deleteButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    QString numSuiv = ui->numSuivLineEdit->text();
    QDate dateArrive = ui->dateArriveEdit->date();
    QDate dateSortie = ui->dateSortieEdit->date();
    QString ADDRESS = ui->ADDRESSLineEdit->text();
    QString idProduit = ui->idProduitLineEdit->text();

    livraison = Livraison(numSuiv, dateArrive, dateSortie, ADDRESS, idProduit);

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
    QString idProduit = ui->idProduitLineEdit->text();

    if (livraison.modifier(numSuiv, dateArrive, dateSortie, ADDRESS, idProduit)) {
        QMessageBox::information(this, "Success", "Livraison modified successfully.");
        ui->tableView->setModel(livraison.afficher()); // Refresh table
    } else {
        QMessageBox::warning(this, "Error", "Failed to modify livraison.");
    }
}

void MainWindow::on_deleteButton_clicked()
{
    QString numSuiv = ui->numSuivLineEdit->text();

    if (livraison.supprimer(numSuiv)) {
        QMessageBox::information(this, "Success", "Livraison deleted successfully.");
        ui->tableView->setModel(livraison.afficher()); // Refresh table
    } else {
        QMessageBox::warning(this, "Error", "Failed to delete livraison.");
    }
}


