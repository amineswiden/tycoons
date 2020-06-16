#ifndef STAT_CHEDLI_H
#define STAT_CHEDLI_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QWidget>
#include <QVector>

#include "abonnements.h"
class stat_chedli : public QWidget
{
    Q_OBJECT
public:
    explicit stat_chedli(QWidget *parent = nullptr);
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
