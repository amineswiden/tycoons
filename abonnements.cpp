#include "abonnements.h"


abonnements::abonnements()
{
id=0;

}
abonnements::abonnements(int d,int p  ,QString t, QDate l)
{
id=d;
prix=p;
type=t;
DL=l;
}

 QString abonnements::gettype()
{

    return type;
}
int abonnements::getid()
{

    return id;
}
int abonnements::getprix()
{

    return prix;
}
QDate abonnements::getDL(){

return DL;
}

bool abonnements::ajouter(){

    QSqlQuery query;
       QString res2=QString ::number(id);
        QString res3=QString::number(prix);
    query.prepare("insert into abonnements     (ID,PRIX,TYPE,DL)" "VALUES(:id,:prix,:type,:DL);");
    query.bindValue(":id",res2);
    query.bindValue(":prix",res3);
  query.bindValue(":type",type);
  query.bindValue(":DL",DL);


   return query.exec();
}
QSqlQueryModel * abonnements::afficher(){

    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from abonnements;");
   return model;



}
bool abonnements::supprimer(int d){

    QSqlQuery query;
    query.prepare("delete from abonnements where id = ?");
    query.addBindValue(d);


   return query.exec();

}
bool abonnements::modifier(){


    QSqlQuery query;
    QString res2=QString ::number(id);
    QString res3=QString::number(prix);

    query.prepare("UPDATE abonnements SET  id=:id , prix=:prix , type=:type ,  DL=:DL   WHERE id=:id " );
    query.bindValue(":id",res2);
    query.bindValue(":prix",res3);
    query.bindValue(":type",type);
    query.bindValue(":DL",DL);






   return query.exec();
}

QSqlQueryModel * abonnements::afficher_id(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select id from abonnements;" );

    return  model;

}
double abonnements::stprix()

{

    QSqlQuery query("SELECT COUNT (*) FROM abonnements WHERE prix>=50 ");

    query.next();

    double nbprix = query.value(0).toDouble();

    return nbprix;



}
double abonnements::pprix()

{

    QSqlQuery query("SELECT COUNT (*) FROM abonnements WHERE prix<50 ");

    query.next();

    double nbprix = query.value(0).toDouble();

    return nbprix;

}


