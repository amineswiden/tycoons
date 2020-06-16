#include "abonnes.h"



abonnes::abonnes()
{
cin=0;
numtel=0;
}
abonnes::abonnes(int a,QString d,QString e,int b,QString f,QString g,QDate v)
{
cin=a;

nom=d;
prenom=e;
numtel=b;
email=f;
adresse=g;
dn=v;



}
int abonnes::getcin(){

    return cin;
}
QString abonnes::getnom(){

    return nom;
}
QString abonnes::getprenom(){

    return prenom;
}
int abonnes::getnumtel(){

    return numtel;
}
QString abonnes::getemail(){

    return email;
}
QString abonnes::getadresse(){

    return adresse;
}
QDate abonnes::getdn(){

    return dn;
}



bool abonnes::ajouter(){

    QSqlQuery query;
     QString res=QString ::number(cin);
     QString res1=QString::number(numtel);
    query.prepare("insert into abonnes (CIN,NOM,PRENOM,NUMTEL,EMAIL,ADRESSE,DN)" "VALUES(:cin,:nom,:prenom,:numtel,:email,:adresse,:dn);");

   query.bindValue(":cin",res);

   query.bindValue(":nom",nom);

   query.bindValue(":prenom",prenom);

   query.bindValue(":numtel",res1);

   query.bindValue(":email",email);

   query.bindValue(":adresse",adresse);

   query.bindValue(":dn",dn);


   return query.exec();
}
QSqlQueryModel * abonnes::afficher(){

    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from abonnes;");
   return model;



}
bool abonnes::supprimer(int a){

    QSqlQuery query;
    query.prepare("delete from abonnes where cin = ?");
    query.addBindValue(a);


   return query.exec();

}
bool abonnes::modifier(){


    QSqlQuery query;
    QString res=QString ::number(cin);
    QString res1=QString::number(numtel);
    query.prepare("UPDATE abonnes SET  cin=:cin , nom=:nom , prenom=:prenom ,  numtel=:numtel , email=:email , adresse=:adresse , dn=:dn   WHERE cin=:cin " );

    query.bindValue(":cin",res);

    query.bindValue(":nom",nom);

    query.bindValue(":prenom",prenom);

    query.bindValue(":numtel",res1);

    query.bindValue(":email",email);

    query.bindValue(":adresse",adresse);

    query.bindValue(":dn",dn);





   return query.exec();

}
QSqlQueryModel * abonnes::afficher_cin(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select cin from mescrud;" );

    return  model;

}


