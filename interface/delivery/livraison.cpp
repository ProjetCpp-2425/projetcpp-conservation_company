#include "livraison.h"
#include <QSqlError>
#include <QDebug>

Livraison::Livraison() {
    NUM_SUIV = "";
    DATE_ARRIVE = QDate();
    DATE_SORTIE = QDate();
    ADDRESS = "";
    ID_PRODUIT =0;
}

Livraison::Livraison(QString NUM_SUIV, QDate DATE_ARRIVE, QDate DATE_SORTIE, QString ADDRESS, int ID_PRODUIT)
    : NUM_SUIV(NUM_SUIV), DATE_ARRIVE(DATE_ARRIVE), DATE_SORTIE(DATE_SORTIE), ADDRESS(ADDRESS) {this->ID_PRODUIT=ID_PRODUIT;}

// Getters
QString Livraison::getNumSuiv() const { return NUM_SUIV; }
QDate Livraison::getDateArrive() const { return DATE_ARRIVE; }
QDate Livraison::getDateSortie() const { return DATE_SORTIE; }
QString Livraison::getADDRESS() const { return ADDRESS; }
int Livraison::getIdProduit() const { return ID_PRODUIT; }

// Setters
void Livraison::setNumSuiv(const QString &num_suiv) { NUM_SUIV = num_suiv; }
void Livraison::setDateArrive(const QDate &date_arrive) { DATE_ARRIVE = date_arrive; }
void Livraison::setDateSortie(const QDate &date_sortie) { DATE_SORTIE = date_sortie; }
void Livraison::setADDRESS(const QString &ADDRESS) { this->ADDRESS = ADDRESS; }
void Livraison::setIdProduit(const int &id_produit) { ID_PRODUIT = id_produit; }

// Add a new Livraison
bool Livraison::ajouter() {
    if (NUM_SUIV.length() != 8) {
        qDebug() << "Erreur: NUM_SUIV doit contenir exactement 8 caractères.";
        return false;
    }

    QDate dateLimite(2024, 7, 11);

    if (DATE_SORTIE <= dateLimite) {
        qDebug() << "Erreur: DATE_SORTIE doit être après le 11/07/2024.";
        return false;
    }

    if (DATE_SORTIE >= DATE_ARRIVE) {
        qDebug() << "Erreur: DATE_SORTIE doit être antérieure à DATE_ARRIVE.";
        return false;
    }

    if (!ADDRESS.contains(',')) {
        qDebug() << "Erreur: L'adresse doit contenir au moins une virgule.";
        return false;
    }

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
bool Livraison::modifier(QString NUM_SUIV, QDate DATE_ARRIVE, QDate DATE_SORTIE, QString ADDRESS, int ID_PRODUIT) {
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

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression: " << query.lastError().text();
        return false;
    }

    if (query.numRowsAffected() == 0) {
        qDebug() << "Erreur: Aucune livraison trouvée avec le NUM_SUIV donné.";
        return false;
    }

    return true;
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
        this->ID_PRODUIT = query.value("ID_PRODUIT").toString().toInt();
        return *this;
    }

    return Livraison();
}
