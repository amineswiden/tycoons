#ifndef JOUEUR_H
#define JOUEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class joueur
{private:
    int CIN;
    QString nom;
    QString prenom;
    int numero_maillot;
    QString poste;
    float salaire;
    int age;
    int cap_att;
    int cap_def;
    QByteArray photo;



public:
    joueur();
    joueur(int,QString,QString,int,QString,float,int,int,int);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * trier();
    double total_att();
    double total_def();
    int get_CIN();
    QString get_nom();
    QString get_prenom();
    int get_num_maillot();
    QString get_poste();
    float get_salaire();
    int get_age();
    int get_cap_att();
    int get_cap_def();
    QByteArray get_photo();
};

#endif // JOUEUR_H
