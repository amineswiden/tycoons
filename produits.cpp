#include "produits.h"
#include <QDebug>
#include "connection.h"


Produits::Produits()
{
code=0;
prix=0;
qte=0;
des="";
pho="";
col="";
idp=0;
}
Produits::Produits(int code,float prix ,int qte,QString des ,QString pho ,QString col,int idp )
{
    this->code=code;
    this->prix=prix;
    this->qte=qte;
    this->des = des ;
    this->pho= pho;
    this->col=col ;
    this->idp=idp;
}

QString Produits:: get_des() {return des;}
QString Produits::get_pho() {return pho ;}
QString Produits::get_col() {return col ;}
int Produits::get_code() {return code ;}
int Produits::get_qte() {return qte ;}
float Produits::get_prix(){return prix ;}

bool Produits ::ajouter()
{
    QSqlQuery query ;
    QString res=QString ::number(code);
    QString res1=QString::number(idp);
    QString res2=QString::number(qte);
    QString res3=QString::number(prix);
    query.prepare("INSERT INTO produits (code,prix,qte,des,pho,col,idp)" "VALUES(:code,:prix,:qte,:des,:pho,:col,:idp)");
    query.bindValue(":code",res);
    query.bindValue(":prix",res3);
    query.bindValue(":qte" ,res2);
    query.bindValue(":des" ,des);
    query.bindValue(":pho" ,pho);
    query.bindValue(":col" ,col);
    query.bindValue(":idp" ,res1);
    return query.exec();
}

QSqlQueryModel * Produits::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from produits");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prix"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantité"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Designation"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Photo"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Couleur"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("IDP"));
return model;
}

bool Produits::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from produits where CODE = :code ");
query.bindValue(":code", res);
return    query.exec();
}

bool Produits::modifier()
{
    QSqlQuery query ;
    QString res=QString ::number(code);
    QString res1=QString::number(idp);
    QString res2=QString::number(qte);
    QString res3=QString::number(prix);

    query.prepare("UPDATE produits SET  code=:code , prix=:prix , qte=:qte , des=:des, pho=:pho , col=:col , idp=:idp  WHERE code=:code " );
    query.bindValue(":code",res);
    query.bindValue(":prix",res3);
    query.bindValue(":qte" ,res2);
    query.bindValue(":des" ,des);
    query.bindValue(":pho" ,pho);
    query.bindValue(":col" ,col);
    query.bindValue(":idp" ,res1);


          return query.exec();

}

QSqlQueryModel * Produits:: recherche( QString e )
{
    //int code=e.toInt();
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM produits WHERE des='"+e+"' ;");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantité"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Designation"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Photo"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Couleur"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("IDP"));
    return model ;
}

QSqlQueryModel * Produits:: trier ()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM produits ORDER BY qte ;");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantité"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Designation"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Photo"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Couleur"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("IDP"));
    return model ;
}

double Produits::critere1()
{
    QSqlQuery query("SELECT COUNT (*) FROM produits WHERE prix > 10");
           query.next();
           double nbprod = query.value(0).toDouble();
           return nbprod;
}

double Produits::critere2()
{
    QSqlQuery query("SELECT COUNT (*) FROM produits WHERE prix <= 10");
           query.next();
           double nbprod1 = query.value(0).toDouble();
           return nbprod1;
}
