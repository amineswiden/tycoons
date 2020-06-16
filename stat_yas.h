#ifndef STAT_YAS_H
#define STAT_YAS_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QWidget>
#include "staff.h"
class stat_yas : public QWidget
{
    Q_OBJECT
public:
    explicit stat_yas(QWidget *parent = nullptr);
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
