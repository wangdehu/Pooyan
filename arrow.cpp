#include "arrow.h"
#include <QPixmap>
#include <iostream>
#include <QWidget>

arrow::arrow(int y) : y(y)
{

    x = 490;

    zhuangtai = 0;
}
void arrow::paint(QPainter *p)
{

    if (zhuangtai == 1)
    {

        p->drawImage(x, y, QImage(":/Picture/img/arrow1.png"));
    }
    else if (zhuangtai == 2)
    {

        p->drawImage(x, y, QImage(":/Picture/img/arrow2.png"));
    }
}
