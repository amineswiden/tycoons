#ifndef ABONNEMENTS_H
#define ABONNEMENTS_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class abonnements
{
    QString type;
    QDate DL;
    int id,prix;
public:
    abonnements();
    abonnements(int,int,QString,QDate);
    QString gettype();
    int getid();
    int getprix();
    QDate getDL();
    QSqlQueryModel * afficher();
     QSqlQueryModel * afficher_id();
      bool ajouter();
    bool supprimer(int);
    bool modifier();
    double stprix();
    double pprix();



};

#endif // ABONNEMENTS_H
