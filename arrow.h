#ifndef ARROW_H
#define ARROW_H
#include <QPainter>
class arrow
{
public:
  void setzhuangtai(int index) { zhuangtai = index; }
  int getzhuangtai() { return zhuangtai; }
  int getY() { return y; }
  int getX() { return x; }
  void setY(int i) { y = i; }
  void setX(int i) { x = i; }
  void paint(QPainter *);

  arrow(int y);

private:
  int x, y;
  long zhuangtai;
  int speed;
};

#endif // ARROW_H
