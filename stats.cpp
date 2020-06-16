#include "stats.h"
#include <QPainter>


stats::stats(QWidget *parent) : QWidget(parent)
{

}

void stats::setData(QVector<double> value, QVector<QColor> colors)
{
    qvValues=value;
    qvColors=colors;
    repaint();
    update();

}

double stats::total()
{
    QSqlQuery query("SELECT COUNT (*) FROM produits ");
           query.next();
           double nbprod = query.value(0).toDouble();
           return nbprod;
}




void stats::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QPen pen;
    QRectF size ;
    pen.setColor(Qt::black);
    pen.setWidth(5);
    painter.setPen(pen);
    if (this->height() > this->width())
    {
        size=QRectF(10,10,this->width()-10,this->width()-10);
    }
    else
    {
         size=QRectF(10,10,this->height()-10,this->height()-10);
    }

   double sum=total();
   double startAng=0.0;
   double angle, endAng,percent ;


   for(int i=0;i<qvValues.size();i++)
    {
        percent = qvValues[i] / sum ;
        angle= percent * 360.0 ;
        endAng= startAng + angle;
        painter.setBrush(qvColors[i]);
        painter.drawPie(size,startAng*16,angle*16);
        startAng=endAng;
    }



}


