#include "livraison.h"
#include <QSqlError>
#include <QDebug>

Livraison::Livraison() {
    NUM_SUIV = "";
    DATE_ARRIVE = QDate();
    DATE_SORTIE = QDate();
    ADDRESS = "";
    ID_PRODUIT = "";
}

Livraison::Livraison(QString NUM_SUIV, QDate DATE_ARRIVE, QDate DATE_SORTIE, QString ADDRESS, QString ID_PRODUIT)
    : NUM_SUIV(NUM_SUIV), DATE_ARRIVE(DATE_ARRIVE), DATE_SORTIE(DATE_SORTIE), ADDRESS(ADDRESS), ID_PRODUIT(ID_PRODUIT) {}

// Getters
QString Livraison::getNumSuiv() const { return NUM_SUIV; }
QDate Livraison::getDateArrive() const { return DATE_ARRIVE; }
QDate Livraison::getDateSortie() const { return DATE_SORTIE; }
QString Livraison::getADDRESS() const { return ADDRESS; }
QString Livraison::getIdProduit() const { return ID_PRODUIT; }

// Setters
void Livraison::setNumSuiv(const QString &num_suiv) { NUM_SUIV = num_suiv; }
void Livraison::setDateArrive(const QDate &date_arrive) { DATE_ARRIVE = date_arrive; }
void Livraison::setDateSortie(const QDate &date_sortie) { DATE_SORTIE = date_sortie; }
void Livraison::setADDRESS(const QString &ADDRESS) { this->ADDRESS = ADDRESS; }
void Livraison::setIdProduit(const QString &id_produit) { ID_PRODUIT = id_produit; }

// Add a new Livraison
bool Livraison::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO LIVRAISON (NUM_SUIV, DATE_ARRIVE, DATE_SORTIE, ADDRESS, ID_PRODUIT) "
                  "VALUES (:NUM_SUIV, :DATE_ARRIVE, :DATE_SORTIE, :ADDRESS, :ID_PRODUIT)");
    query.bindValue(":NUM_SUIV", NUM_SUIV);
    query.bindValue(":DATE_ARRIVE", DATE_ARRIVE);
    query.bindValue(":DATE_SORTIE", DATE_SORTIE);
    query.bindValue(":ADDRESS", ADDRESS);
    query.bindValue(":ID_PRODUIT", ID_PRODUIT);

    return query.exec();
}

// Modify an existing Livraison
bool Livraison::modifier(QString NUM_SUIV, QDate DATE_ARRIVE, QDate DATE_SORTIE, QString ADDRESS, QString ID_PRODUIT) {
    QSqlQuery query;
    query.prepare("UPDATE LIVRAISON SET DATE_ARRIVE = :DATE_ARRIVE, DATE_SORTIE = :DATE_SORTIE, "
                  "ADDRESS = :ADDRESS, ID_PRODUIT = :ID_PRODUIT WHERE NUM_SUIV = :NUM_SUIV");
    query.bindValue(":NUM_SUIV", NUM_SUIV);
    query.bindValue(":DATE_ARRIVE", DATE_ARRIVE);
    query.bindValue(":DATE_SORTIE", DATE_SORTIE);
    query.bindValue(":ADDRESS", ADDRESS);
    query.bindValue(":ID_PRODUIT", ID_PRODUIT);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification de la livraison:" << query.lastError().text();
        return false;
    }

    return true;
}

// Delete a Livraison
bool Livraison::supprimer(QString num_suiv) {
    QSqlQuery query;
    query.prepare("DELETE FROM Livraison WHERE NUM_SUIV = :NUM_SUIV");
    query.bindValue(":NUM_SUIV", num_suiv);

    return query.exec();
}

// Display all Livraisons
QSqlQueryModel *Livraison::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Livraison");
    return model;
}

// Search for a Livraison by NUM_SUIV
Livraison Livraison::rechercher(QString num_suiv) {
    QSqlQuery query;
    query.prepare("SELECT * FROM LIVRAISON WHERE NUM_SUIV = :NUM_SUIV");
    query.bindValue(":NUM_SUIV", num_suiv);

    if (query.exec() && query.next()) {
        this->NUM_SUIV = query.value("NUM_SUIV").toString();
        this->DATE_ARRIVE = query.value("DATE_ARRIVE").toDate();
        this->DATE_SORTIE = query.value("DATE_SORTIE").toDate();
        this->ADDRESS = query.value("ADDRESS").toString();
        this->ID_PRODUIT = query.value("ID_PRODUIT").toString();
        return *this;
    }

    return Livraison();
}
