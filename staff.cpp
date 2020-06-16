#include "staff.h"



staff::staff()
{
    CIN=0;
    nom="";
    prenom="";
    poste="";
    age=0;
    tel=0;

}
staff::staff(int cin ,QString n,QString p,QString post,int Age,int telph)
{
    CIN=cin;
    nom=n;
    prenom=p;
    poste=post;
    age=Age;
    tel=telph;
}
int staff::get_CIN()
{
    return CIN;
}
QString staff::get_nom()
{
    return nom;
}
QString staff::get_prenom()
{
    return prenom;
}
QString staff::get_poste()
{
    return poste;
}
int staff::get_age()
{
    return age;
}
int staff::get_tel()
{
    return tel;
}

bool staff::ajouter()
{
    QSqlQuery query ;
    QString res=QString ::number(CIN);
    QString res1=QString ::number(age);
    QString res2=QString ::number(tel);

    query.prepare("INSERT INTO staff (CIN,NOM,PRENOM,POSTE,AGE,TEL)" "VALUES(:CIN,:nom,:prenom,:poste,:age,:tel)");
    query.bindValue(":CIN",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom" ,prenom);
    query.bindValue(":poste" ,poste);
    query.bindValue(":age" ,res1);
    query.bindValue(":tel" ,res2);

    return query.exec();
}

QSqlQueryModel * staff::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from staff");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("poste"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("tel"));
    return model;
}

bool staff::supprimer(int cin)
{
QSqlQuery query;
QString res= QString::number(cin);
query.prepare("Delete from staff where CIN = :CIN ");
query.bindValue(":CIN", res);
return    query.exec();
}
bool staff::modifier()
{
    QSqlQuery query;
    QString res=QString ::number(CIN);
    QString res1=QString::number(age);
    QString res2=QString::number(tel);
    query.prepare("UPDATE staff SET  CIN=:CIN , nom=:nom , prenom=:prenom , poste=:poste , age=:age , tel=:tel  WHERE CIN=:CIN " );
    query.bindValue(":CIN",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom" ,prenom);
    query.bindValue(":poste" ,poste);
    query.bindValue(":age" ,res1);
    query.bindValue(":tel" ,res2);

          return query.exec();

}

QSqlQueryModel * staff::rechercher(QString nom )
{

    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM staff WHERE NOM =  '"+nom+"' ;");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("poste"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("tel"));

    return model ;
}
QSqlQueryModel * staff::trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM staff ORDER BY NOM ;");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("poste"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("tel"));

    return model;
}



