#include "employe.h"
#include <QSqlQuery>
#include <QVariant>

Employe::Employe()
{
    // Initialisation, si nécessaire
}

bool Employe::login(const QString &username, const QString &password)
{
    QSqlQuery query;

    // Préparez une requête pour vérifier les informations de connexion
    query.prepare("SELECT * FROM Employe WHERE ID_EMPLOYE = :username AND employe = :password");

    // Convertissez le champ "username" en entier pour l'ID_EMPLOYE
    bool isNumeric;
    int id = username.toInt(&isNumeric);

    if (!isNumeric) {
        return false; // Si l'ID n'est pas un entier, échec de la connexion
    }

    query.bindValue(":username", id);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {
        // Connexion réussie
        id_employe = query.value("ID_EMPLOYE").toInt();
        nom = query.value("MDP").toString();

        return true;
    }

    // Connexion échouée
    return false;
}

#include "employe.h"
#include <QRandomGenerator>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

// Incluez les bibliothèques nécessaires pour Twilio si vous utilisez une API HTTP
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QLabel>
#include <QMap>
#include <QStandardItemModel>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QAuthenticator>
#include <QEventLoop>


void Employe::sendSMS(const QString &telephone, const QString &message) {

    


    QUrl url("https://api.twilio.com/2010-04-01/Accounts/" + accountSID + "/Messages.json");


    QUrlQuery postData;
    postData.addQueryItem("To", telephone);
    postData.addQueryItem("From", fromPhoneNumber);
    postData.addQueryItem("Body", message);


    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");


    QByteArray auth = (accountSID + ":" + authToken).toUtf8().toBase64();
    request.setRawHeader("Authorization", "Basic " + auth);


    QNetworkAccessManager manager;
    QEventLoop loop;
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);

    QNetworkReply *reply = manager.post(request, postData.query().toUtf8());
    loop.exec();


    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "SMS envoyé avec succès à" << telephone;
    } else {
        qDebug() << "Erreur lors de l'envoi du SMS:" << reply->errorString();
    }
    reply->deleteLater();
}



bool Employe::inscrire(int ID_EMPLOYE, const QString& NOM, const QString& PRENOM,
                       const QString& POSTE, int TELEPHONE, const QString& MDP) {
    QSqlQuery query;

    // Préparation de la requête SQL pour insérer les données
    query.prepare("INSERT INTO Employe (ID_EMPLOYE, NOM, PRENOM, POSTE, TELEPHONE, MDP, presence) "
                  "VALUES (:ID_EMPLOYE, :NOM, :PRENOM, :POSTE, :TELEPHONE, :MDP, 'absent')");

    // Liaison des valeurs aux paramètres
    query.bindValue(":ID_EMPLOYE", ID_EMPLOYE);
    query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM", PRENOM);
    query.bindValue(":POSTE", POSTE);
    query.bindValue(":TELEPHONE", TELEPHONE); // TELEPHONE est un entier
    query.bindValue(":MDP", MDP);

    // Exécution de la requête et retour du résultat
    return query.exec();
}


int Employe::genererIdUnique() {
    int id;
    QSqlQuery query;

    do {

        id = QRandomGenerator::global()->bounded(1000, 10000);


        query.prepare("SELECT COUNT(*) FROM employes WHERE ID_EMPLOYE = :id");
        query.bindValue(":id", id);
        query.exec();
    } while (query.next() && query.value(0).toInt() > 0);

    return id;
}
