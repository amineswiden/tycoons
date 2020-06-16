#ifndef LOGIN_H
#define LOGIN_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class login
{
public:
    login(QString,int);
    QString getnom();
    int getmotdp();
    bool authent();
private :
    QString nom ;
    int password ;
};

#endif // LOGIN_H
