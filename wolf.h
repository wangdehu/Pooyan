#ifndef WOLF_H
#define WOLF_H
#include <QPainter>
#include <QGraphicsItem>
#include <QPixmap>
#include <iostream>
#include <QWidget>

class wolf
{
public:
  void setzhuangtai(int index);
  int getzhuangtai() { return zhuangtai; }
  int getY() { return y; }
  int getX() { return x; }
  void setY(int i) { y = i; }
  void paint(QPainter *);
  int get_X() { return _x; }
  void set_X(int index) { _x = index; }
  void setX(int index) { x = index; }

  wolf();

private:
  int x, y;
  int ballstyle;
  long zhuangtai;
  int _x;
};

#endif // WOLF_H
