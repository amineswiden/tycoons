#ifndef CATEGORIES_H
#define CATEGORIES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Categories
{
public:
    Categories();
    Categories(int,QString);
    int getIdc ();
    QString getNom();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool  modifier() ;
    bool supprimer(int);
    QSqlQueryModel* recherche(QString e );
    QSqlQueryModel* trier();

private :
    QString nom ;
    int idc ;
};

#endif // CATEGORIES_H
