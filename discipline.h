#ifndef DISCIPLINE_H
#define DISCIPLINE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class discipline
{   private:
    int id;
    QString type;
    int nb_titre;

    public:

    discipline();
    discipline(int,QString,int);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * trier();
    int get_id();
    QString get_type();
    int get_nb_titre();

};

#endif // DISCIPLINE_H
