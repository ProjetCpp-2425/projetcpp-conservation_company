#ifndef MATERIAL_H
#define MATERIAL_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class Material {
private:
    QString material_id;       // VARCHAR2(12)
    QString recyclability;         // NUMBER
    QString material_type;         // NUMBER
    int quantity_in_stock;     // NUMBER
    QDate purchase_date;     // DATE
    int unit_cost;         // CHAR(1)

public:
    // Constructors
    Material() {}
    Material(QString material_id, QString recyclability, QString material_type, int quantity_in_stock, QDate purchase_date, int unit_cost);
    ~Material() {}

    // Getters and Setters
    QString getMaterialId() const;
    void setMaterialId(const QString &id);

    QString getRecyclability() const;
    void setRecyclability(QString recyclability);

    QString getMaterialType() const;
    void setMaterialType(QString material_type);

    int getQuantityInStock() const;
    void setQuantityInStock(int quantity_in_stock);

    QDate getPurchaseDate() const;
    void setPurchaseDate(const QDate &date);

    int getUnitCost() const;
    void setUnitCost(const int &cost);

    // CRUD Operations
    bool ajouter();                          // Create
    bool supprimer(QString id);
    QSqlQueryModel * afficher();
    bool update();                       // Update
    bool remove(QString id);             // Delete
    bool fetchData(QString id);
    bool update(QString id);

    // Additional Functionalities
    //QSqlQueryModel* search(QString keyword);          // Search
    //QSqlQueryModel* sortBy(QString column, bool asc); // Sort
    QSqlQueryModel* generateStatistics();             // Statistics
    QSqlQueryModel* sortBy(QString column, bool asc);
    QSqlQueryModel* search(QString id);


    bool add();
};

#endif // MATERIAL_H
