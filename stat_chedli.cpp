#include "stat_chedli.h"
#include <QPainter>
stat_chedli::stat_chedli(QWidget *parent) : QWidget(parent)
{

}

double stat_chedli::total()
{
   // QString maRequete = "SELECT COUNT (*) FROM abonnements";
       QSqlQuery query("SELECT COUNT (*) FROM abonnements");
       query.next();
       double nbprix = query.value(0).toDouble();
       return nbprix;

}



void stat_chedli::setData(QVector<double> value, QVector<QColor> color)
{
    qvValue=value;
    qvColor=color;
    repaint();
    update();
}

void stat_chedli::paintEvent(QPaintEvent *)

{
    QPainter painter(this);
    QPen pen;
    QRectF size;
    pen.setColor(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
    if (this->height() > this->width())
   {

        size =QRectF(10,10,this->width()-10,this->width()-10);
    }
    else
    {
        size =QRectF(10,10,this->height()-10,this->height()-10);
    }
    double sum=total(); double startAng =0.0;
    double angle, endAng, percent ;
    for(int i=0; i<qvValue.size(); i++)
    {
        percent= qvValue[i] / sum;
        angle = percent * 360.0;
        endAng = startAng + angle;
        painter.setBrush(qvColor[i]);
        painter.drawPie(size,startAng*16,angle*16);
        startAng=endAng;
    }

}


