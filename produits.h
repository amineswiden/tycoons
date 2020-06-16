#ifndef PRODUITS_H
#define PRODUITS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QWidget>
class Produits
{
public:
    Produits();
    Produits(int,float,int,QString,QString,QString,int);
    QString get_des();
    QString get_pho();
    QString get_col();
    int get_code();
    int get_qte();
    float get_prix();
    bool ajouter();
    bool modifier();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel* recherche(QString e );
    QSqlQueryModel* trier();
    double critere1();
    double critere2();

private:
    QString des, pho ,col  ;
    int qte , code ,idp ;
    float prix;
};

#endif // PRODUITS_H
