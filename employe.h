#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class Employe
{
public:
    Employe();

    // Fonction pour la connexion (authentification)
    bool login(const QString &username, const QString &password);
    bool inscrire(int ID_EMPLOYE, const QString& NOM, const QString& PRENOM,
                           const QString& POSTE, int TELEPHONE, const QString& MDP);
    void sendSMS(const QString &telephone, const QString &message);
    int genererIdUnique();
private:
    int id_employe;         // ID de l'employé (entier)
    QString mdp;            // Mot de passe
    QString nom;            // Nom
    QString prenom;         // Prénom
    int telephone;          // Numéro de téléphone (entier)
    QString poste;          // Poste de l'employé
};

#endif // EMPLOYE_H
