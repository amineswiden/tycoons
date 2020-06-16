#include "categories.h"

Categories::Categories()
{
idc=0;
nom="";
}

Categories::Categories(int idc , QString nom)
{

    this->idc=idc;
    this->nom=nom;
}

int  Categories::getIdc(){ return idc ; }
QString Categories::getNom() {return nom ;}

bool Categories::ajouter()
{
      QSqlQuery query ;
      QString res=QString ::number(idc);
      query.prepare("INSERT INTO categories (idc,nom) " " VALUES (:idc,:nom)");
      query.bindValue(":idc",res);
      query.bindValue(":nom",nom);
      return query.exec();
}
QSqlQueryModel * Categories::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from categories");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("idc"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
return model;
}
bool Categories::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from categories  where IDC = :idc ");
query.bindValue(":idc", res);
return    query.exec();
}

bool Categories::modifier()
{
    QSqlQuery query ;
    QString res=QString ::number(idc);

    query.prepare("UPDATE categories SET  idc=:idc , nom=:nom  WHERE idc=:idc " );
    query.bindValue(":idc",res);
    query.bindValue(":nom",nom);

          return query.exec();

}

QSqlQueryModel * Categories:: recherche( QString e )
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM categories WHERE nom='"+e+"' ;");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idc"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    return model;
}

QSqlQueryModel * Categories:: trier ()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM categories ORDER BY idc ;");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idc"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    return model ;
}
