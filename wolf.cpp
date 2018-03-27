#include "wolf.h"
#include <iostream>
wolf::wolf()
{
    srand(time(NULL));
    x = rand() % 333;
    y = 22;
    zhuangtai = 0;
    ballstyle = rand() % 2;
    _x = -100;
}
void wolf::paint(QPainter *p)
{
    QImage ball[2];
    ball[0] = QImage(":/Picture/img/ball1.png");
    ball[1] = QImage(":/Picture/img/ball2.png");
    if (zhuangtai == 1)
    {
        p->drawImage(x, y, QImage(":/Picture/img/wolf.png"));
        p->drawImage(x, y - 10, ball[ballstyle]);
    }
    if (zhuangtai == 3)
    {
        p->drawImage(_x, y, QImage(":/Picture/img/testwolf.png"));
    }
    if (zhuangtai == 4)
    {
        p->drawImage(x, 500, QImage(":/Picture/img/testwolf.png"));
    }
}
void wolf::setzhuangtai(int index)
{
    zhuangtai = index;
    y = 22;
    ballstyle = rand() % 2;
    if (index == 3)
    {
        x = rand() % 333;
        _x = -100;
    }
    else if (index == 1)
    {
    }
    else if (index == 4)
    {
        y = 500;
    }
}
