#ifndef MATCH_H
#define MATCH_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class match
{public:
    match();
    match(QString,QString,QString,QString,QString);
    QString get_ctqui();
    QString get_dat();
    QString get_placement();
    QString get_type();
    QString get_match();
    QString get_etat();
    bool ajouter();
    bool modifier();
    QSqlQueryModel * afficher();
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * trier();
    bool supprimer(QString);
    int get_gagne();
    int get_perdu();
private:
    QString ctqui,dat,placement,type,etat;
};


#endif // ETUDIANT_H
