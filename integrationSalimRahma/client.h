#include<QString>
#define CLIENT_H
#include<QSqlQuery>
#include <QSqlQueryModel>
class client
{
    QString nom,prenom, adresse, type,mail;
    int code_client,tel;
public:
    client();
    client(int,QString,QString,QString,QString,int,QString);


    int getcode_client(){return code_client;}
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}

    QString getAdresse(){return adresse;}
    QString getType(){return type;}
    int getTel(){return tel;}
    QString getMail(){return mail;}

    void setCode_client(int code_client){this->code_client=code_client;}
    void setNom(QString n){nom=n;}
    void setPrenom(QString pr){prenom=pr;}
    void setAdresse(QString ad){adresse=ad;}
    void setType(QString pa){type=pa;}
    void setTel(int tel){this->tel=tel;}
    void setMail(QString email){mail=email;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    //bool modifier(int code_client, QString nom, QString prenom, int cin, QString adresse, QString pays, int tel, QString mail);
    bool modifier(int code_client, QString nom, QString prenom, QString adresse, QString type, int tel, QString mail);
    bool exists(int);


};


