#include "match.h"
#include <QDebug>
match::match()
{
ctqui="";
dat="";
placement="";
type="";
etat="";
}
match::match(QString ctqui,QString dat,QString placement,QString  type , QString  etat)
{
  this->ctqui=ctqui;
  this->dat=dat;
  this->placement=placement;
  this->type=type;
  this->etat=etat;
}
QString match::get_ctqui(){return  ctqui;}
QString match::get_dat(){return dat;}
QString match::get_placement(){return placement;}
QString match::get_type(){return type;}

QString match::get_match()
{
    return etat;
}


bool match::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO match (ctqui, dat, placement , type , etat) "
                    "VALUES (:ctqui, :dat, :placement ,:type,:etat)");
query.bindValue(":ctqui", ctqui);
query.bindValue(":dat", dat);
query.bindValue(":placement", placement);
query.bindValue(":type", type);
query.bindValue(":etat", etat);

return    query.exec();
}

bool match::modifier()
{
    QSqlQuery query;

    query.prepare("UPDATE match SET  ctqui=:ctqui , dat=:dat , placement=:placement , type=:type , etat=:etat WHERE ctqui=:ctqui ");
    query.bindValue(":ctqui", ctqui);
    query.bindValue(":dat", dat);
    query.bindValue(":placement", placement);
    query.bindValue(":type", type);
    query.bindValue(":etat", etat);

    return    query.exec();
}

QSqlQueryModel * match::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from match");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ctqui"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("dat"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("placement"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("etat"));
    return model;
}

bool match::supprimer(QString ctqui)
{
QSqlQuery query;
//QString res= QString(ctqui);
query.prepare("Delete from match where ctqui = :ctqui ");
query.bindValue(":ctqui", ctqui);
return    query.exec();
}

int match::get_gagne()
{
    QSqlQuery query("SELECT COUNT (*) FROM MATCH WHERE etat = 'gagne' ");
    query.next();
    double nbmatch = query.value(0).toDouble();
    return nbmatch;

}

int match::get_perdu()
{

    QSqlQuery query("SELECT COUNT (*) FROM MATCH WHERE etat = 'perdu' ");
    query.next();
    double nbmatch = query.value(0).toDouble();
    return nbmatch;
}
QSqlQueryModel * match::rechercher(QString ctqui )
{
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM match WHERE ctqui =  '"+ctqui+"' ;");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ctqui"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("dat"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("placement"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("etat"));
        return model ;
}

QSqlQueryModel * match::trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM match ORDER BY dat ;");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ctqui"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("dat"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("placement"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("etat"));


    return model;
}
