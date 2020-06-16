#ifndef STATISTIQUE_H
#define STATISTIQUE_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QWidget>
#include "staff.h"
class statistique : public QWidget
{
    Q_OBJECT
public:
    explicit statistique(QWidget *parent = nullptr);
    double total();

    void setData(QVector<double> value, QVector<QColor> color);
protected:
     void paintEvent(QPaintEvent *);
private:
     QVector<double> qvValue;
     QVector<QColor> qvColor;
signals:

};

#endif // STATISTIQUE_H
