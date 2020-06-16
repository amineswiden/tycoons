#include "joueur.h"



joueur::joueur()
{
    CIN=0;
    nom="";
    prenom="";
    numero_maillot=0;
    poste="";
    salaire=0;
    age=0;
    cap_att=0;
    cap_def=0;

}
joueur::joueur(int cin ,QString n,QString p,int num,QString post,float sal,int Age,int cp_att,int cp_def)
{
    CIN=cin;
    nom=n;
    prenom=p;
    numero_maillot=num;
    poste=post;
    salaire=sal;
    age=Age;
    cap_att=cp_att;
    cap_def=cp_def;
}
int joueur::get_CIN()
{
    return CIN;
}
QString joueur::get_nom()
{
    return nom;
}
QString joueur::get_prenom()
{
    return prenom;
}
int joueur::get_num_maillot()
{
    return numero_maillot;
}
QString joueur::get_poste()
{
    return poste;
}
float joueur::get_salaire()
{
    return salaire;
}
int joueur::get_age()
{
    return age;
}
int joueur::get_cap_att()
{
    return cap_att;
}
int joueur::get_cap_def()
{
    return cap_def;
}
QByteArray joueur::get_photo()
{
    return photo;
}
bool joueur::ajouter()
{
    QSqlQuery query ;
    QString res=QString ::number(CIN);
    QString res1=QString::number(numero_maillot);
    QString res2=QString::number(salaire);
    QString res3=QString ::number(age);
    QString res4=QString::number(cap_att);
    QString res5=QString::number(cap_def);
    query.prepare("INSERT INTO joueur (CIN,NOM,PRENOM,NUMERO_MAILLOT,POSTE,SALAIRE,AGE,CAP_ATT,CAP_DEF)" "VALUES(:CIN,:nom,:prenom,:numero_maillot,:poste,:salaire,:age,:cap_att,:cap_def)");
    query.bindValue(":CIN",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom" ,prenom);
    query.bindValue(":numero_maillot" ,res1);
    query.bindValue(":poste" ,poste);
    query.bindValue(":salaire" ,res2);
    query.bindValue(":age" ,res3);
    query.bindValue(":cap_att" ,res4);
    query.bindValue(":cap_def" ,res5);
    return query.exec();
}

QSqlQueryModel * joueur::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from joueur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero maillot"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("poste"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("age"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("capacite attaque"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("capacite defensive"));
    return model;
}

bool joueur::supprimer(int cin)
{
QSqlQuery query;
QString res= QString::number(cin);
query.prepare("Delete from joueur where CIN = :CIN ");
query.bindValue(":CIN", res);
return    query.exec();
}
bool joueur::modifier()
{
    QSqlQuery query;
    QString res=QString ::number(CIN);
    QString res1=QString::number(numero_maillot);
    QString res2=QString::number(salaire);
    QString res3=QString::number(age);
    QString res4=QString::number(cap_att);
    QString res5=QString::number(cap_def);
    query.prepare("UPDATE joueur SET  CIN=:CIN , nom=:nom , prenom=:prenom ,  numero_maillot=:numero_maillot , poste=:poste , salaire=:salaire , age=:age , cap_att=:cap_att , cap_def=:cap_def  WHERE CIN=:CIN " );
    query.bindValue(":CIN",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom" ,prenom);
    query.bindValue(":numero_maillot" ,res1);
    query.bindValue(":poste" ,poste);
    query.bindValue(":salaire" ,res2);
    query.bindValue(":age" ,res3);
    query.bindValue(":cap_att" ,res4);
    query.bindValue(":cap_def" ,res5);

          return query.exec();

}

QSqlQueryModel * joueur::rechercher(QString nom )
{

    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM JOUEUR WHERE NOM =  '"+nom+"' ;");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero_maillot"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("poste"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("age"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("capacite attaque"));
        model->setHeaderData(8, Qt::Horizontal, QObject::tr("capacite defensive"));

    return model ;
}
QSqlQueryModel * joueur::trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM JOUEUR ORDER BY SALAIRE ;");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero_maillot"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("poste"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("capacite attaque"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("capacite defensive"));

    return model;
}

double joueur::total_att()
{
    QSqlQuery query("SELECT COUNT (*) FROM JOUEUR WHERE CAP_ATT>=50 ");
    query.next();
    double nbjoueur = query.value(0).toDouble();
    return nbjoueur;

}

double joueur::total_def()
{
    QSqlQuery query("SELECT COUNT (*) FROM JOUEUR WHERE CAP_att<50 ");
    query.next();
    double nbjoueur = query.value(0).toDouble();
    return nbjoueur;
}
