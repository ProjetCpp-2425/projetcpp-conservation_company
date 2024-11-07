#ifndef LIVRAISON_H
#define LIVRAISON_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Livraison {
public:
    Livraison();

    Livraison(QString NUM_SUIV, QDate DATE_ARRIVE, QDate DATE_SORTIE, QString ADDRESS, QString ID_PRODUIT);

    bool ajouter();
    bool modifier(QString NUM_SUIV, QDate DATE_ARRIVE, QDate DATE_SORTIE, QString ADDRESS, QString ID_PRODUIT);
    bool supprimer(QString num_suiv);
    QSqlQueryModel *afficher();
    Livraison rechercher(QString num_suiv);

    // Getters
    QString getNumSuiv() const;
    QDate getDateArrive() const;
    QDate getDateSortie() const;
    QString getADDRESS() const;
    QString getIdProduit() const;

    // Setters
    void setNumSuiv(const QString &num_suiv);
    void setDateArrive(const QDate &date_arrive);
    void setDateSortie(const QDate &date_sortie);
    void setADDRESS(const QString &ADDRESS);
    void setIdProduit(const QString &id_produit);

private:
    QString NUM_SUIV;
    QDate DATE_ARRIVE;
    QDate DATE_SORTIE;
    QString ADDRESS;
    QString ID_PRODUIT;
};

#endif // LIVRAISON_H

