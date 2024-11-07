/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QWidget *widget_2;
    QFrame *frame;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_5;
    QTextEdit *textEdit_6;
    QTextEdit *textEdit_7;
    QTextEdit *textEdit_8;
    QTextEdit *textEdit_9;
    QLineEdit *numSuivLineEdit;
    QLineEdit *ADDRESSLineEdit;
    QLineEdit *idProduitLineEdit;
    QComboBox *comboBox;
    QDateEdit *dateArriveEdit;
    QDateEdit *dateSortieEdit;
    QFrame *frame_2;
    QTextEdit *textEdit_10;
    QTextEdit *textEdit_12;
    QTextEdit *textEdit_15;
    QTextEdit *textEdit_16;
    QTextEdit *textEdit_17;
    QTextEdit *textEdit_18;
    QTextEdit *textEdit_19;
    QTextEdit *textEdit_20;
    QTextEdit *textEdit_21;
    QLabel *label;
    QTableView *tableView;
    QPushButton *deleteButton;
    QPushButton *addButton;
    QPushButton *modifyButton;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *searchButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1322, 891);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, -10, 1531, 931));
        widget->setStyleSheet(QString::fromUtf8("\n"
"border-radius:30px;\n"
"background-color: rgb(50, 171, 135);"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(10, 160, 101, 31));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255));\n"
"color:Black;\n"
"border-radius:10px;\n"
"font-size:15px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../Downloads/group.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 10, 101, 61));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(110, 20, 1391, 891));
        widget_2->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(225, 225, 225);\n"
"border-radius:30px;"));
        frame = new QFrame(widget_2);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(940, 30, 431, 381));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(50, 171, 135);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        textEdit_3 = new QTextEdit(frame);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(10, 10, 141, 61));
        textEdit_4 = new QTextEdit(frame);
        textEdit_4->setObjectName("textEdit_4");
        textEdit_4->setGeometry(QRect(0, 210, 161, 61));
        textEdit_5 = new QTextEdit(frame);
        textEdit_5->setObjectName("textEdit_5");
        textEdit_5->setGeometry(QRect(0, 100, 171, 31));
        textEdit_6 = new QTextEdit(frame);
        textEdit_6->setObjectName("textEdit_6");
        textEdit_6->setGeometry(QRect(0, 160, 171, 31));
        textEdit_7 = new QTextEdit(frame);
        textEdit_7->setObjectName("textEdit_7");
        textEdit_7->setGeometry(QRect(0, 60, 151, 41));
        textEdit_8 = new QTextEdit(frame);
        textEdit_8->setObjectName("textEdit_8");
        textEdit_8->setGeometry(QRect(0, 280, 171, 41));
        textEdit_9 = new QTextEdit(frame);
        textEdit_9->setObjectName("textEdit_9");
        textEdit_9->setGeometry(QRect(0, 380, 71, 31));
        numSuivLineEdit = new QLineEdit(frame);
        numSuivLineEdit->setObjectName("numSuivLineEdit");
        numSuivLineEdit->setGeometry(QRect(160, 60, 181, 31));
        numSuivLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:10px;"));
        ADDRESSLineEdit = new QLineEdit(frame);
        ADDRESSLineEdit->setObjectName("ADDRESSLineEdit");
        ADDRESSLineEdit->setGeometry(QRect(160, 280, 181, 31));
        ADDRESSLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:10px;"));
        idProduitLineEdit = new QLineEdit(frame);
        idProduitLineEdit->setObjectName("idProduitLineEdit");
        idProduitLineEdit->setGeometry(QRect(150, 210, 181, 31));
        idProduitLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:10px;"));
        comboBox = new QComboBox(frame);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(90, 420, 82, 28));
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        dateArriveEdit = new QDateEdit(frame);
        dateArriveEdit->setObjectName("dateArriveEdit");
        dateArriveEdit->setGeometry(QRect(160, 160, 110, 29));
        dateSortieEdit = new QDateEdit(frame);
        dateSortieEdit->setObjectName("dateSortieEdit");
        dateSortieEdit->setGeometry(QRect(160, 110, 110, 29));
        frame_2 = new QFrame(widget_2);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(940, 420, 431, 451));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.0717489, y2:0.125, stop:0 rgba(0, 170, 127, 108), stop:1 rgba(255, 255, 255, 255));"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        textEdit_10 = new QTextEdit(frame_2);
        textEdit_10->setObjectName("textEdit_10");
        textEdit_10->setGeometry(QRect(10, 10, 191, 51));
        textEdit_10->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));"));
        textEdit_12 = new QTextEdit(frame_2);
        textEdit_12->setObjectName("textEdit_12");
        textEdit_12->setGeometry(QRect(10, 410, 41, 31));
        textEdit_12->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));"));
        textEdit_15 = new QTextEdit(frame_2);
        textEdit_15->setObjectName("textEdit_15");
        textEdit_15->setGeometry(QRect(10, 70, 41, 31));
        textEdit_15->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));"));
        textEdit_16 = new QTextEdit(frame_2);
        textEdit_16->setObjectName("textEdit_16");
        textEdit_16->setGeometry(QRect(10, 130, 41, 31));
        textEdit_16->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));"));
        textEdit_17 = new QTextEdit(frame_2);
        textEdit_17->setObjectName("textEdit_17");
        textEdit_17->setGeometry(QRect(10, 190, 41, 31));
        textEdit_17->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));"));
        textEdit_18 = new QTextEdit(frame_2);
        textEdit_18->setObjectName("textEdit_18");
        textEdit_18->setGeometry(QRect(10, 260, 41, 31));
        textEdit_18->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));"));
        textEdit_19 = new QTextEdit(frame_2);
        textEdit_19->setObjectName("textEdit_19");
        textEdit_19->setGeometry(QRect(10, 330, 61, 61));
        textEdit_19->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));"));
        textEdit_20 = new QTextEdit(frame_2);
        textEdit_20->setObjectName("textEdit_20");
        textEdit_20->setGeometry(QRect(530, 450, 41, 31));
        textEdit_20->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:black;"));
        textEdit_21 = new QTextEdit(frame_2);
        textEdit_21->setObjectName("textEdit_21");
        textEdit_21->setGeometry(QRect(440, 450, 41, 31));
        textEdit_21->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:black;"));
        label = new QLabel(frame_2);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 10, 41, 21));
        label->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));"));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/statistical-graphic.png")));
        label->setScaledContents(true);
        tableView = new QTableView(widget_2);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(80, 430, 651, 261));
        tableView->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 170, 127);"));
        deleteButton = new QPushButton(widget_2);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(310, 150, 221, 61));
        deleteButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 170, 127);"));
        addButton = new QPushButton(widget_2);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(310, 250, 221, 61));
        addButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 170, 127);"));
        modifyButton = new QPushButton(widget_2);
        modifyButton->setObjectName("modifyButton");
        modifyButton->setGeometry(QRect(70, 150, 211, 61));
        modifyButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 170, 127);"));
        pushButton_6 = new QPushButton(widget_2);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(580, 150, 171, 61));
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 170, 127);"));
        pushButton_7 = new QPushButton(widget_2);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(580, 250, 171, 61));
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 170, 127);"));
        searchButton = new QPushButton(widget_2);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(70, 70, 681, 51));
        searchButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:10px;"));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 820, 83, 29));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::SystemShutdown")));
        pushButton_2->setIcon(icon1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1322, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Delivery service", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:700; color:#000000;\">Dashboard</span></p></body></html>", nullptr));
        textEdit_3->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700; color:#000000;\">add delivery</span></p></body></html>", nullptr));
        textEdit_4->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700;\">package</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt; font-weight:700;\"><br /></p></body></html>", nullptr));
        textEdit_5->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">dateSortie</p></body></html>", nullptr));
        textEdit_6->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">dateArrive</p></body></html>", nullptr));
        textEdit_7->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700; color:#ffffff;\">Tracking number</span></p></body></html>", nullptr));
        textEdit_8->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Address</span></p></body></html>", nullptr));
        textEdit_9->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Type</span></p></body></html>", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Particulier", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Entreprise", nullptr));

        textEdit_10->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700; color:#0affca;\">Monthly Delivery Statistics</span></p></body></html>", nullptr));
        textEdit_12->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">100</span></p></body></html>", nullptr));
        textEdit_15->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">350</span></p></body></html>", nullptr));
        textEdit_16->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">300</span></p></body></html>", nullptr));
        textEdit_17->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">250</span></p></body></html>", nullptr));
        textEdit_18->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">200</span></p></body></html>", nullptr));
        textEdit_19->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">150</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:700;\"><br /></p></body></html>", nullptr));
        textEdit_20->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">Mon</span></p></body></html>", nullptr));
        textEdit_21->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">Sun</span></p></body></html>", nullptr));
        label->setText(QString());
        deleteButton->setText(QCoreApplication::translate("MainWindow", "delete delivery ", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "add button ", nullptr));
        modifyButton->setText(QCoreApplication::translate("MainWindow", "modify delivery", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "sort by date ", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "E-mail", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "search", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
