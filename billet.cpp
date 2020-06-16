#include "billet.h"
#include <QDebug>
billet::billet()
{
id="";
nbticket=0;
prix=0;

}
billet::billet(QString id,int nbticket,int prix)
{
  this->id=id;
  this->nbticket=nbticket;
  this->prix=prix;
}
QString billet::get_id(){return  id;}
int billet::get_nbticket(){return nbticket;}
int billet::get_prix(){return prix;}

bool billet::ajouter()
{
QSqlQuery query;
QString res= QString(id);
query.prepare("INSERT INTO billet (id, nbticket, prix) "
                    "VALUES (:id, :nbticket, :prix )");
query.bindValue(":id", res);
query.bindValue(":nbticket", nbticket);
query.bindValue(":prix", prix);

return    query.exec();
}

bool billet::modifier()
{
    QSqlQuery query;
    QString res= QString::number(nbticket);
    QString res1= QString::number(prix);
    query.prepare("UPDATE billet SET  id=:id , nbticket=:nbticket , prix=:prix WHERE id=:id  ");
    query.bindValue(":id", id);
    query.bindValue(":nbticket", res);
    query.bindValue(":prix", res1);

    return    query.exec();
}

QSqlQueryModel * billet::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from billet");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbticket "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
    return model;
}

bool billet::supprimer(QString id)
{
QSqlQuery query;

query.prepare("Delete from billet where id = :id ");
query.bindValue(":id", id);
return    query.exec();
}

QSqlQueryModel * billet::rechercher(QString id )
{
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM billet WHERE id =  '"+id+"' ;");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbticket"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
        return model ;
}

QSqlQueryModel * billet::trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM billet ORDER BY nbticket ;");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbticket"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));


    return model;
}
