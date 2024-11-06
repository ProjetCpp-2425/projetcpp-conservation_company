#include "client.h"
#include <QDebug>
client::client() : code_client(0), tel(0) {}

client::client(int code_client,QString nom,QString prenom,QString adresse,QString type,int tel,QString mail) {
    this->code_client=code_client;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->type=type;
    this->tel=tel;
    this->mail=mail;
}
bool client::ajouter(){
    QSqlQuery query;
    QString res = QString::number(code_client);
    query.prepare("insert into client (code_client , nom , prenom , adresse , type , tel , mail)" "values (:code_client, :nom, :prenom, :adresse, :type, :tel, :mail)");
    query.bindValue(":code_client" , res);
    query.bindValue(":nom" , nom);
    query.bindValue(":prenom" , prenom);
    query.bindValue(":adresse" , adresse);
    query.bindValue(":type" , type);
    QString rr = QString::number(tel);
    query.bindValue(":tel" , rr);
    query.bindValue(":mail" , mail);
    return query.exec();
}


bool client::supprimer(int code_client)
{
    QSqlQuery query;
    QString res=QString::number(code_client);
    query.prepare("delete from client where code_client =:code_client");
    query.bindValue(":code_client",res);
    return query.exec();


}





QSqlQueryModel * client::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from client");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("code_client"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("tel"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("mail"));

    return model;
}




bool client::modifier(int code_client, QString nom, QString prenom, QString adresse, QString type, int tel, QString mail)
{
    QSqlQuery query;


    query.prepare("UPDATE client SET nom = :nom, prenom = :prenom, adresse = :adresse, type = :type, tel = :tel, mail = :mail WHERE code_client = :code_client");


    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":type", type);
    query.bindValue(":tel", tel);
    query.bindValue(":mail", mail);
    query.bindValue(":code_client", code_client);


    return query.exec();

}




