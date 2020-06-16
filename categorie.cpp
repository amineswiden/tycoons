#include "categorie.h"

categorie::categorie()
{
    id=0;
    type="";
    nb_heures=0;
    salaire=0;
}

categorie::categorie(int id, QString type, int nb_heures,int salaire)
{
    this->id=id;
    this->type=type;
    this->nb_heures=nb_heures;
    this->salaire=salaire;
}

int categorie::get_id()
{
    return id;
}
QString categorie::get_type()
{
    return type;
}
int categorie::get_nb_heures()
{
    return nb_heures;
}
bool categorie::ajouter()
{
    QSqlQuery query ;
    QString res=QString ::number(id);
    QString res1=QString::number(nb_heures);
    QString res2=QString::number(salaire);

    query.prepare("INSERT INTO categorie (ID,TYPE,NB_HEURES,SALAIRE)" "VALUES(:id,:type,:nb_heures,:salaire)");
    query.bindValue(":id",res);
    query.bindValue(":type",type);
    query.bindValue(":nb_heures",res1);
    query.bindValue(":salaire",res2);

    return query.exec();
}

QSqlQueryModel * categorie::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from categorie");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("type "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nb_heures"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("salaire"));



    return model;
}

bool categorie::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from categorie where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool categorie::modifier()
{
    QSqlQuery query ;
    QString res=QString ::number(id);
    QString res1=QString::number(nb_heures);
    QString res2=QString::number(salaire);

    query.prepare("UPDATE categorie SET  id=:id , type=:type , nb_heures=:nb_heures , salaire=:salaire   WHERE id=:id ");
    query.bindValue(":id",res);
    query.bindValue(":type",type);
    query.bindValue(":nb_heures",res1);
    query.bindValue(":salaire",res2);

    return query.exec();
}
QSqlQueryModel * categorie::rechercher(QString type )
{
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM categorie WHERE TYPE =  '"+type+"' ;");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("nb_heures"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("salaire"));
        return model ;
}

QSqlQueryModel * categorie::trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM categorie ORDER BY salaire ;");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nb_heures"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("salaire"));


    return model;
}

double categorie::crit1()
{
    QSqlQuery query("SELECT COUNT (*) FROM categorie WHERE SALAIRE>=50 ");
    query.next();
    double c = query.value(0).toDouble();
    return c;

}

double categorie::crit2()
{
    QSqlQuery query("SELECT COUNT (*) FROM categorie WHERE SALAIRE<50  ");
    query.next();
    double c = query.value(0).toDouble();
    return c;
}
/*double categorie::crit3()
{
    QSqlQuery query("SELECT COUNT (*) FROM CATEGORIE WHERE SALAIRE>=50  ");
    query.next();
    double c = query.value(0).toDouble();
    return c;
}
double categorie::crit4()
{
    QSqlQuery query("SELECT COUNT (*) FROM CATEGORIE WHERE SALAIRE<50 ");
    query.next();
    double c = query.value(0).toDouble();
    return c;
}
*/
