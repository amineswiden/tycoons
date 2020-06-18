#include "admin.h"
#include <QDebug>
admin::admin()
{

}
admin::admin(int id,QString password){
this->id=id;
this->password=password;
}
bool admin::authentification(){
    QSqlQuery query;
    QString test_id,test_password;
    query.prepare("select * from administrateur where (id=:id) and(password=:password)");
    query.bindValue(":id",id);
    query.bindValue(":password",password);
    query.exec();
    while(query.next()){
        test_id=query.value(0).toString();
    test_password=query.value(1).toString();
    }
    return (((test_id!="")&&(test_password!="")));
}

