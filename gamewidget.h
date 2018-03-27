#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H
#include <iostream>
#include <QPen>
#include <QWidget>
#include <QIcon>
#include <QPalette>
#include <QBrush>
#include <QPixmap>
#include <QPushButton>
#include <QMessageBox>
#include <QPaintEvent>
#include <QPainter>
#include <QLabel>
#include <QTimer>
#include <QTime>
#include <ctime>
#include <QButtonGroup>
#include <QKeyEvent>
#include <QStyle>
#include <wolf.h>
#include <arrow.h>
#include <QVector>
#include <QMediaPlayer>
class Gamewidget : public QWidget
{
  Q_OBJECT
public:
  explicit Gamewidget(QWidget *parent = 0);
  void paintEvent(QPaintEvent *);
  void keyPressEvent(QKeyEvent *e);
    ~Gamewidget();
  void sousousou();

private:
  int num;
  int next;
  bool one;
  bool button;
  QPushButton *startPush;
  QLabel *pigmum;
  QLabel *testwolf;
  long h;
  QPainter *p;
  QVector<wolf> wolves;
  arrow *a1, *a2;
  int different;
  QMediaPlayer *player;
  int score;
  int diednum;
  QTimer *timer;
signals:

public slots:
  void timeToShow();
  void startgame();
};

#endif // GAMEWIDGET_H
