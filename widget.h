#ifndef WIDGET_H
#define WIDGET_H
#include <QMediaPlayer>
#include <QWidget>
#include <QWidget>
#include <QIcon>
#include <QPalette>
#include <QBrush>
#include <QPixmap>
#include <QPushButton>
#include <QMessageBox>
#include <QAbstractAnimation>
#include <QKeyEvent>
#include <gamewidget.h>
#include <QLabel>
#include <QPropertyAnimation>
#include <QPainter>
#include <QColor>
#include <QMouseEvent>
#include <QTime>
#include <QSequentialAnimationGroup>
#include <iostream>
#include <QKeyEvent>
#include "gamewidget.h"
#include <QSound>
class Widget : public QWidget
{
  Q_OBJECT

public:
  Widget(QWidget *parent = 0);
  ~Widget();
  Gamewidget *gamewindow;
  void paintEvent(QPaintEvent *);
  void keyPressEvent(QKeyEvent *e);
  void startAnimation();
  void startPush();
  QMediaPlayer *player;
private slots:
  void onCurrentAnimationChanged(QAbstractAnimation *current);

private:
  long choose;
  QLabel *bird_13;
  QLabel *bird_16;
  QLabel *bird_15;
  QLabel *bird_11;
  QLabel *bird_12;
  QLabel *bird_14;
};

#endif // WIDGET_H
