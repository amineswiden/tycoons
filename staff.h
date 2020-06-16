#ifndef staff_H
#define staff_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class staff
{private:
    int CIN;
    QString nom;
    QString prenom;
    QString poste;
    int age;
    int tel;




public:
    staff();
    staff(int,QString,QString,QString,int,int);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * trier();
    int get_CIN();
    QString get_nom();
    QString get_prenom();
    QString get_poste();
    int get_age();
    int get_tel();

};

#endif // staff_H
