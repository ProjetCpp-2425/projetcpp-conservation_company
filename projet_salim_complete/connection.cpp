#include "connection.h"

connection::connection() {}

bool connection::createconnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("conservation_company");
    db.setUserName("projetcpp2a34");
    db.setPassword("mp2a34");

    if (db.open()) test=true;

    return test;

}

void connection::closeConnection(){db.close();}
