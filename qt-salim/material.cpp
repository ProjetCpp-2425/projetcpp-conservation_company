#include "material.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQueryModel>

// Getter and Setter for material_id
QString Material::getMaterialId() const {
    return material_id;
}

void Material::setMaterialId(const QString &id) {
    material_id = id;
}

// Getter and Setter for recyclability
QString Material::getRecyclability() const {
    return recyclability;
}

void Material::setRecyclability(QString recyclability) {
    this->recyclability = recyclability;
}

// Getter and Setter for material_type
QString Material::getMaterialType() const {
    return material_type;
}

void Material::setMaterialType(QString material_type) {
    this->material_type = material_type;
}

// Getter and Setter for quantity_in_stock
int Material::getQuantityInStock() const {
    return quantity_in_stock;
}

void Material::setQuantityInStock(int quantity) {
    quantity_in_stock = quantity;
}

// Getter and Setter for purchase_date
QDate Material::getPurchaseDate() const {
    return purchase_date;
}

void Material::setPurchaseDate(const QDate &date) {
    purchase_date = date;
}

// Getter and Setter for unit_cost
int Material::getUnitCost() const {
    return unit_cost;
}

void Material::setUnitCost(const int &cost) {
    unit_cost = cost;
}
#include "material.h"

// Constructor with parameters
Material::Material(QString material_id, QString recyclability, QString material_type, int quantity_in_stock, QDate purchase_date, int unit_cost)
    : material_id(material_id), recyclability(recyclability), material_type(material_type), quantity_in_stock(quantity_in_stock),
      purchase_date(purchase_date), unit_cost(unit_cost) {}
//--------------------------------------------------------------------add
bool Material::add() {
    QSqlQuery query;

    // Prepare the SQL query
    query.prepare("INSERT INTO PRODUIT (MATERIAL_ID, RECYCLABILITY, MATERIAL_TYPE, QUANTITY_IN_STOCK, PURCHASE_DATE, UNIT_COST) "
                  "VALUES (:material_id, :recyclability, :material_type, :quantity_in_stock, :purchase_date, :unit_cost)");

    // Bind values to placeholders
    query.bindValue(":material_id", material_id);
    query.bindValue(":recyclability", recyclability);
    query.bindValue(":material_type", material_type);
    query.bindValue(":quantity_in_stock", quantity_in_stock);
    query.bindValue(":unit_cost", unit_cost);
    query.bindValue(":purchase_date", purchase_date);


    // Execute the query and return the result
    return query.exec();
}
//--------------------------------------------------------------supprimer
bool Material::supprimer(QString id) {
    QSqlQuery query;
    QString res =QString (id);

    query.prepare("DELETE FROM PRODUIT WHERE MATERIAL_ID = :MATERIAL_ID");
    query.bindValue(":MATERIAL_ID", res);


    query.exec();
}
//--------------------------------------------------------------afficher
QSqlQueryModel * Material::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from PRODUIT INFO");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATERIAL_ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("RECYCLABILITY"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MATERIAL_TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITY_IN_STOCK"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PURCHASE_DATE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("UNIT_COST"));
    return model;
}

bool Material::fetchData(QString id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM PRODUIT WHERE MATERIAL_ID = :MATERIAL_ID");
    query.bindValue(":MATERIAL_ID", id);

    if (!query.exec()) {
        qDebug() << "Error fetching record:" << query.lastError().text();
        return false;
    }

    if (query.next()) {  // Check if a record is found
        // Assuming your class has member variables for each column
        material_id = query.value("MATERIAL_ID").toString();
        recyclability = query.value("RECYCLABILITY").toString();
        material_type = query.value("MATERIAL_TYPE").toString();
        quantity_in_stock = query.value("QUANTITY_IN_STOCK").toInt();
        purchase_date = query.value("PURCHASE_DATE").toDate();
        unit_cost = query.value("UNIT_COST").toInt();

        return true;  // Record found
    } else {
        return false;  // No record found
    }
}

bool Material::update(QString id) {
    QSqlQuery query;

    // Prepare the SQL statement for updating a record
    query.prepare("UPDATE PRODUIT SET RECYCLABILITY = :RECYCLABILITY, "
                  "MATERIAL_TYPE = :MATERIAL_TYPE, "
                  "QUANTITY_IN_STOCK = :QUANTITY_IN_STOCK, "
                  "PURCHASE_DATE = TO_DATE(:PURCHASE_DATE, 'YYYY-MM-DD'), "
                  "UNIT_COST = :UNIT_COST "
                  "WHERE MATERIAL_ID = :MATERIAL_ID");

    // Bind values to the placeholders
    query.bindValue(":RECYCLABILITY", recyclability);
    query.bindValue(":MATERIAL_TYPE", material_type);
    query.bindValue(":QUANTITY_IN_STOCK", quantity_in_stock);
    query.bindValue(":PURCHASE_DATE", purchase_date.toString("yyyy-MM-dd"));
    query.bindValue(":UNIT_COST", unit_cost);
    query.bindValue(":MATERIAL_ID", id);

    if (!query.exec()) {
        qDebug() << "Update failed:" << query.lastError().text();
        return false;
    }

    return true; // Return true if the update was successful
}
//--------------------------------------------------------------sort
QSqlQueryModel* Material::sortBy(QString column, bool asc) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QString sortOrder = asc ? "ASC" : "DESC";
    QString query = QString("SELECT * FROM PRODUIT ORDER BY %1 %2").arg(column, sortOrder);

    model->setQuery(query);

    if (model->lastError().isValid()) {
        qDebug() << "Sorting error: " << model->lastError().text();
        delete model;
        return nullptr;
    }

    return model;
}
//--------------------------------------------------------------chercher
QSqlQueryModel* Material::search(QString id) {
    QSqlQueryModel *model = new QSqlQueryModel();

    // Prepare the query to search by Material_ID
    QString query = "SELECT * FROM PRODUIT WHERE MATERIAL_ID LIKE :id";
    QSqlQuery sqlQuery;
    sqlQuery.prepare(query);
    sqlQuery.bindValue(":id", "%" + id + "%"); // Allows partial matches

    sqlQuery.exec();
    model->setQuery(sqlQuery);

    // Check for errors
    if (model->lastError().isValid()) {
        qDebug() << "Search error:" << model->lastError().text();
        delete model;
        return nullptr;
    }

    return model;
}


