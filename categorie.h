#ifndef categorie_H
#define categorie_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class categorie
{   private:
    int id;
    QString type;
    int nb_heures;
    int salaire;

    public:

    categorie();
    categorie(int,QString,int,int);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * trier();
    int get_id();
    QString get_type();
    int get_nb_heures();
    int get_salaire();
    double crit1();
    double crit2();
   // double crit3();
    //double crit4();
};

#endif // categorie_H
