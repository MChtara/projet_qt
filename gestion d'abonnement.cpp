#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("MIMI");
db.setUserName("yass");//inserer nom de l'utilisateur
db.setPassword("yass");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
