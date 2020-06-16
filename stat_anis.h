#ifndef STAT_ANIS_H
#define STAT_ANIS_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QWidget>
#include "billet.h"
class stat_anis: public QWidget
{
    Q_OBJECT
public:
    explicit stat_anis(QWidget *parent = nullptr);
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
