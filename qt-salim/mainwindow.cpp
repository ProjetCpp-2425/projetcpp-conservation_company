#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "material.h"

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
{
    ui->setupUi(this);
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
/*void MainWindow::on_add_clicked()
{
    //proxyModel->sort(6, Qt::DescendingOrder);


        QString id = ui->lineEdit_6->text().trimmed();
        QString recy = ui->comboBox_4->currentText();
        QString type = ui->comboBox_3->currentText();
        QString stockstr = ui->lineEdit_3->text().trimmed();
        QDate date = ui->dateEdit->date();
        QString coststr = ui->lineEdit_5->text().trimmed();

        int cost = coststr.toInt();
        int stock = stockstr.toInt();


        //Controle de saisie
//(QString material_id, int recyclability, int material_type, int quantity_in_stock, QDate purchase_date, QString unit_cost)
    Material M(id, recy, type, stock, date, cost);
    bool test = M.add();
    if (test) {
        ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(this, "Success", "Material added successfully.");
    } else {
        QMessageBox::critical(this, "Failed", "Error");
    }
}
*/
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
/*void MainWindow::on_pushButton_13_clicked() {
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
    painter.setFont(QFont("Arial", 18, QFont::Bold));
    painter.drawText(0, 0, pdfWriter.width(), 50, Qt::AlignCenter, "Material Table Export");

    // Prepare the table data
    QSqlQuery query("SELECT * FROM PRODUIT");
    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to fetch table data.");
        return;
    }

    // Draw the table headers
    painter.setFont(QFont("Arial", 12, QFont::Bold));
    int x = 50;
    int y = 100;
    int rowHeight = 30;
    int columnWidth = pdfWriter.width() / 6;

    QStringList headers = {"Material ID", "Recyclability", "Material Type", "Quantity in Stock", "Purchase Date", "Unit Cost"};
    for (const QString &header : headers) {
        painter.drawText(x, y, columnWidth, rowHeight, Qt::AlignLeft, header);
        x += columnWidth;
    }

    y += rowHeight; // Move to the next row
    x = 50; // Reset x for table rows

    // Draw the table rows
    painter.setFont(QFont("Arial", 10));
    while (query.next()) {
        for (int i = 0; i < headers.size(); ++i) {
            QString value = query.value(i).toString();
            painter.drawText(x, y, columnWidth, rowHeight, Qt::AlignLeft, value);
            x += columnWidth;
        }
        y += rowHeight; // Move to the next row
        x = 50; // Reset x for next row
        if (y > pdfWriter.height() - 100) { // Check if the page is full
            pdfWriter.newPage();
            y = 50; // Reset y for the new page
        }
    }

    painter.end();

    QMessageBox::information(this, "Success", "Table exported to PDF successfully!");
}*/


/*void MainWindow::on_pushButton_13_clicked() {
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
    painter.setFont(QFont("Arial", 18, QFont::Bold));
    painter.drawText(0, 0, pdfWriter.width(), 50, Qt::AlignCenter, "Exported Table Data");

    // Fetch data from the table view
    QAbstractItemModel *model = ui->tableView->model();
    if (!model) {
        QMessageBox::critical(this, "Error", "Failed to fetch table view data.");
        return;
    }

    // Draw the table headers
    painter.setFont(QFont("Arial", 12, QFont::Bold));
    int x = 50;
    int y = 100;
    int rowHeight = 30;
    int columnWidth = pdfWriter.width() / model->columnCount();

    // Print the headers
    for (int column = 0; column < model->columnCount(); ++column) {
        QString header = model->headerData(column, Qt::Horizontal).toString();
        painter.drawText(x, y, columnWidth, rowHeight, Qt::AlignLeft, header);
        x += columnWidth;
    }

    y += rowHeight; // Move to the next row
    x = 50; // Reset x for table rows

    // Print the table data
    painter.setFont(QFont("Arial", 10));
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int column = 0; column < model->columnCount(); ++column) {
            QString value = model->data(model->index(row, column)).toString();
            painter.drawText(x, y, columnWidth, rowHeight, Qt::AlignLeft, value);
            x += columnWidth;
        }
        y += rowHeight; // Move to the next row
        x = 50; // Reset x for next row
        if (y > pdfWriter.height() - 100) { // Check if the page is full
            pdfWriter.newPage();
            y = 50; // Reset y for the new page
        }
    }

    painter.end();

    QMessageBox::information(this, "Success", "Table exported to PDF successfully!");
}
*/
//---------------------------------------------------------------------pdf
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



/*void MainWindow::on_pushButton_8_clicked() {
    // Create a QWidget to hold the calendar
    QDialog *calendarDialog = new QDialog(this);
    calendarDialog->setWindowTitle("Purchase Date Calendar");
    calendarDialog->resize(500, 400);

    // Create the calendar widget
    QCalendarWidget *calendar = new QCalendarWidget(calendarDialog);

    // Prepare formats for recyclable and non-recyclable dates
    QTextCharFormat recyclableFormat;
    recyclableFormat.setBackground(Qt::green);
    recyclableFormat.setForeground(Qt::white);

    QTextCharFormat nonRecyclableFormat;
    nonRecyclableFormat.setBackground(Qt::red);
    nonRecyclableFormat.setForeground(Qt::white);

    // Query the database for purchase dates and recyclability
    QSqlQuery query;
    if (!query.exec("SELECT PURCHASE_DATE, RECYCLABILITY FROM PRODUIT")) {
        QMessageBox::critical(this, "Database Error", "Failed to fetch purchase dates: " + query.lastError().text());
        return;
    }

    // Loop through the results and highlight dates
    while (query.next()) {
        QDate purchaseDate = query.value(0).toDate();  // Get the purchase date
        QString recyclability = query.value(1).toString().toLower();  // Get the recyclability status

        // Apply the appropriate format
        if (recyclability == "recyclable") {
            calendar->setDateTextFormat(purchaseDate, recyclableFormat);
        } else if (recyclability == "non-recyclable") {
            calendar->setDateTextFormat(purchaseDate, nonRecyclableFormat);
        }
    }

    // Create a Close Button
    QPushButton *closeButton = new QPushButton("Close", calendarDialog);
    connect(closeButton, &QPushButton::clicked, calendarDialog, &QDialog::accept);

    // Layout for the calendar and close button
    QVBoxLayout *layout = new QVBoxLayout(calendarDialog);
    layout->addWidget(calendar);
    layout->addWidget(closeButton);

    // Show the dialog
    calendarDialog->exec();
}


#include <QCalendarWidget>
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTextCharFormat>
#include <QDate>

void MainWindow::on_pushButton_8_clicked() {
    // Create the calendar widget and add it to the main interface
    QCalendarWidget *calendar = new QCalendarWidget(this);
    calendar->setGeometry(50, 100, 500, 400); // Adjust position and size for a better fit
    calendar->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader); // Remove vertical headers for a cleaner look
    calendar->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames); // Show abbreviated day names

    // Apply custom styles to the calendar
    calendar->setStyleSheet("QCalendarWidget {"
                             "    background-color: #ffffff;"  // Clean white background
                             "    color: #000;"                // Black text
                             "    border: 1px solid #0078d7;"  // Blue border
                             "    border-radius: 10px;"        // Rounded edges
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

    // Prepare the format for purchase dates (all green)
    QTextCharFormat purchaseDateFormat;
    purchaseDateFormat.setBackground(Qt::green);
    purchaseDateFormat.setForeground(Qt::white);
    purchaseDateFormat.setFontWeight(QFont::Bold);

    // Query the database for purchase dates
    QSqlQuery query;
    if (!query.exec("SELECT PURCHASE_DATE FROM PRODUIT")) {
        QMessageBox::critical(this, "Database Error", "Failed to fetch purchase dates: " + query.lastError().text());
        return;
    }

    // Loop through the results and highlight dates
    while (query.next()) {
        QString purchaseDateStr = query.value(0).toString();  // Get the purchase date as string
        QDate purchaseDate = QDate::fromString(purchaseDateStr, "yyyy-MM-dd"); // Ensure correct format

        // Apply the green format for valid dates
        if (purchaseDate.isValid()) {
            calendar->setDateTextFormat(purchaseDate, purchaseDateFormat);
        }
    }

    // Show the calendar in the main interface
    calendar->show();
}
#include <QCalendarWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTextCharFormat>
#include <QDate>
#include <QWidget>

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

    // Prepare the format for purchase dates (green)
    QTextCharFormat purchaseDateFormat;
    purchaseDateFormat.setBackground(Qt::green);
    purchaseDateFormat.setForeground(Qt::white);
    purchaseDateFormat.setFontWeight(QFont::Bold);

    // Query the database for purchase dates
    QSqlQuery query;
    if (!query.exec("SELECT PURCHASE_DATE FROM PRODUIT")) {
        QMessageBox::critical(this, "Database Error", "Failed to fetch purchase dates: " + query.lastError().text());
        return;
    }

    // Loop through the results and highlight dates
    while (query.next()) {
        QString purchaseDateStr = query.value(0).toString();  // Get the purchase date as a string
        QDate purchaseDate = QDate::fromString(purchaseDateStr, "dd/MM/yyyy"); // Ensure correct format

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
#include <QCalendarWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTextCharFormat>
#include <QDate>
#include <QWidget>

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

    // Prepare the format for purchase dates (green)
    QTextCharFormat purchaseDateFormat;
    purchaseDateFormat.setBackground(Qt::green);
    purchaseDateFormat.setForeground(Qt::white);
    purchaseDateFormat.setFontWeight(QFont::Bold);

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
}*/

//---------------------------------------------------------------calendar

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



