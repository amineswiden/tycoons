#include "discipline.h"

discipline::discipline()
{
    id=0;
    type="";
    nb_titre=0;
}

discipline::discipline(int id, QString type, int nb_titre)
{
    this->id=id;
    this->type=type;
    this->nb_titre=nb_titre;
}

int discipline::get_id()
{
    return id;
}
QString discipline::get_type()
{
    return type;
}
int discipline::get_nb_titre()
{
    return nb_titre;
}
bool discipline::ajouter()
{
    QSqlQuery query ;
    QString res=QString ::number(id);
    QString res1=QString::number(nb_titre);

    query.prepare("INSERT INTO discipline (ID,TYPE,NB_TITRE)" "VALUES(:id,:type,:nb_titre)");
    query.bindValue(":id",res);
    query.bindValue(":type",type);
    query.bindValue(":nb_titre",res1);

    return query.exec();
}

QSqlQueryModel * discipline::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from discipline");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("type "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nb_titre"));


    return model;
}

bool discipline::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from discipline where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool discipline::modifier()
{
    QSqlQuery query ;
    QString res=QString ::number(id);
    QString res1=QString::number(nb_titre);

    query.prepare("UPDATE discipline SET  id=:id , type=:type , nb_titre=:nb_titre   WHERE id=:id ");
    query.bindValue(":id",res);
    query.bindValue(":type",type);
    query.bindValue(":nb_titre",res1);

    return query.exec();
}
QSqlQueryModel * discipline::rechercher(QString type )
{
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM DISCIPLINE WHERE TYPE =  '"+type+"' ;");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("nb_titre"));
        return model ;
}

QSqlQueryModel * discipline::trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM DISCIPLINE ORDER BY nb_titre ;");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nb_titre"));


    return model;
}
