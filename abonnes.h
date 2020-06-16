#ifndef ABONNES_H
#define ABONNES_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class abonnes
{
    QString nom,prenom,email,adresse;
    int cin,numtel;
      QDate dn;

public:
    abonnes();
    abonnes(int,QString,QString,int,QString,QString,QDate);
    QString getnom();
    QString getprenom();
    QString getemail();
      QString getadresse();
      QDate getdn();

    int getcin();
    int getnumtel();
    bool ajouter();
    QSqlQueryModel * afficher();
     QSqlQueryModel * afficher_cin();
    bool supprimer(int);
    bool modifier();



};


#endif // ABONNES_H
