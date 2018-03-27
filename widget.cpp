#include "widget.h"
#include <QCoreApplication>
#include <QSound>

Widget::Widget(QWidget *parent)
    : QWidget(parent), choose(0)
{

    QString absDir = "C:\\Users\\Wrzz\\Documents\\c++workplace\\wdh_last\\mp3\\bk0.mp3";
    player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile(absDir));
    player->setVolume(100);
    player->play();

    //this->resize(640, 595);
    this->setFixedSize(640, 595);
    this->setWindowTitle("wdh");
    this->setWindowIcon(QIcon(":/Picture/img/icon.jpg"));
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/Picture/img/background.jpg")));
    this->setStyleSheet("background-image:url(qrc::/Picture/img/icon.jpg)");
    this->setPalette(palette);
    startAnimation();
}
void Widget::keyPressEvent(QKeyEvent *e)
{
    switch (e->key())
    {
    case Qt::Key_Up:
        choose = 1;

        update();
        break;
    case Qt::Key_W:
        choose = 1;
        update();
        break;
    case Qt::Key_Down:
        choose = 2;
        update();
        break;
    case Qt::Key_S:
        choose = 2;
        update();
        break;
    case Qt::Key_Return:

        startPush();

        break;
    default:
        break;
    }
}
Widget::~Widget()
{
    delete player;
    delete bird_13,bird_15,bird_16, bird_11,bird_12,bird_14;

}
void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    QPen pen(Qt::red, 2, Qt::SolidLine);
    p.setPen(pen);
    QPoint p1(50, 50), p2(500, 300);

    if (choose == 1)
    {
        bird_15->move(159, 280);
    }
    else if (choose == 2)
    {
        bird_15->move(159, 356);
    }
}

void Widget::startAnimation()
{
    QPixmap birdimg = QPixmap(":/Picture/img/wolf0.png").scaled(60, 60);

    bird_11 = new QLabel(this);
    bird_11->setPixmap(birdimg);
    QPropertyAnimation *anim11 = new QPropertyAnimation(bird_11, "pos");
    anim11->setDuration(5000);
    anim11->setStartValue(QPoint(700, 416));
    anim11->setEndValue(QPoint(-400, 416));
    anim11->start();

    QPixmap birdimg2 = QPixmap(":/Picture/img/pooyan_pink0.png").scaled(60, 60);
   bird_12 = new QLabel(this);
    bird_12->setPixmap(birdimg2);
    QPropertyAnimation *anim12 = new QPropertyAnimation(bird_12, "pos");
    anim12->setDuration(5000);
    anim12->setStartValue(QPoint(800, 416));
    anim12->setEndValue(QPoint(-300, 416));
    anim12->start();

    QPixmap birdimg3 = QPixmap(":/Picture/img/ball1.png").scaled(60, 60);
    bird_13 = new QLabel(this);
    bird_13->setPixmap(birdimg3);
    QPropertyAnimation *anim13 = new QPropertyAnimation(bird_13, "pos");
    anim13->setDuration(3300);
    anim13->setStartValue(QPoint(900, 416));
    anim13->setEndValue(QPoint(159, 416));
    //    anim13->start();
    //

    QPixmap birdimg5 = QPixmap(":/Picture/img/ball1.png").scaled(60, 60);
    bird_15 = new QLabel(this);
    bird_15->setPixmap(birdimg5);
    bird_15->move(-100, -100);
    QPropertyAnimation *anim15 = new QPropertyAnimation(bird_15, "pos");
    anim15->setDuration(1700);
    anim15->setStartValue(QPoint(159, 416));
    anim15->setEndValue(QPoint(159, 280));

    bird_16 = new QLabel(this);
    QPropertyAnimation *anim16 = new QPropertyAnimation(bird_16, "pos");
    anim16->setDuration(10);
    anim16->setStartValue(QPoint(0, 0));
    anim16->setEndValue(QPoint(0, 0));
    QSequentialAnimationGroup *group = new QSequentialAnimationGroup;

    group->addAnimation(anim13);

    group->addAnimation(anim15);
    group->addAnimation(anim16);
    group->start();

    QPixmap birdimg4 = QPixmap(":/Picture/img/pooyan_blue1.png").scaled(60, 60);
    bird_14 = new QLabel(this);
    bird_14->setPixmap(birdimg4);
    QPropertyAnimation *anim14 = new QPropertyAnimation(bird_14, "pos");
    anim14->setDuration(5000);
    anim14->setStartValue(QPoint(1000, 416));
    anim14->setEndValue(QPoint(-100, 416));
    anim14->start();
    connect(group, SIGNAL(currentAnimationChanged(QAbstractAnimation *)),
            this, SLOT(onCurrentAnimationChanged(QAbstractAnimation *)));
}
void Widget::onCurrentAnimationChanged(QAbstractAnimation *current)
{
    QPropertyAnimation *pAnimation = dynamic_cast<QPropertyAnimation *>(current);
    if (pAnimation == NULL)
        return;
    QLabel *pLabel = dynamic_cast<QLabel *>(pAnimation->targetObject());

    if (pLabel == bird_15)
    {
        bird_13->move(-100, -100);
    }
    if (pLabel == bird_16)
    {
        bird_15->move(-100, -100);
        choose = 1;

        update();
    }
}
void Widget::startPush()
{

    gamewindow = new Gamewidget(this);
    //player->stop();
    gamewindow->show();
}
