#include "login.h"



login::login( QString nom, int password)
{

    this->password=password;
    this->nom=nom;
}

int  login::getmotdp(){ return password ; }

bool login::authent()
{
    QSqlQuery query;
    QString test_nom,test_password;
    query.prepare("select * from administrateur where (nom =:nom) and(password=:password)");
    query.bindValue(":nom",nom);
    query.bindValue(":password",password);
    query.exec();
    while(query.next()){
        test_nom=query.value(0).toString();
    test_password=query.value(1).toString();
    }
    return (((test_nom!="")&&(test_password!="")));
}
QString login::getnom() {return nom ;}

