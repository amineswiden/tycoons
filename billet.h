#ifndef BILLET_H
#define BILLET_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class billet
{public:
    billet();
    billet(QString,int,int);
    QString get_id();
    int get_nbticket();
    int get_prix();
    bool ajouter();
    bool modifier();
    QSqlQueryModel * afficher();
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * trier();
    bool supprimer(QString);
private:
    QString id;
    int nbticket,prix;
};


#endif // ETUDIANT_H
