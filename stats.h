#ifndef STATS_H
#define STATS_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QWidget>
#include <QString>

class stats : public QWidget
{
    Q_OBJECT
public:
    explicit stats(QWidget *parent = nullptr);
    void setData(QVector<double> value, QVector<QColor> colors ) ;
protected:
void paintEvent(QPaintEvent *);
private:
 QVector<double> qvValues;
 QVector<QColor>  qvColors;
public:
double total();

signals:

};

#endif // STATS_H
