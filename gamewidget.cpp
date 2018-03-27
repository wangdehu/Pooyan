#include "gamewidget.h"

Gamewidget::Gamewidget(QWidget *parent) : QWidget(parent), h(119), different(2), num(0), next(0), button(false), one(false)
{

    score = 0;
    diednum = 0;
    player = new QMediaPlayer;
    player->setVolume(100);

    this->setFocus();
    this->setAutoFillBackground(true);
    this->setFixedSize(640, 595);
    wolves.clear();
    for (int i = 0; i < 20; ++i)
    {
        wolves.push_back(wolf());
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeToShow()));
    timer->start(60);

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/Picture/img/background2.jpg").scaled(this->size())));
    this->setPalette(palette);

    pigmum = new QLabel(this);
    pigmum->setPixmap(QPixmap(":/Picture/img/pigmum.png").scaled(80, 80));
    pigmum->move(490, h);

    testwolf = new QLabel(this);
    testwolf->setPixmap(QPixmap(":/Picture/img/testwolf.png").scaled(60, 60));
    testwolf->move(333, 22);

    a1 = new arrow(h);
    a2 = new arrow(h);

    startPush = new QPushButton(this);
    startPush->setIconSize(QSize(920, 45));
    startPush->setGeometry(520, 30, 90, 45);
    startPush->setIcon(QIcon(":/Picture/img/Start.png"));
    startPush->setFlat(1);
    connect(startPush, SIGNAL(clicked(bool)), this, SLOT(startgame()));
}
Gamewidget::~Gamewidget(){
    delete player;
    delete timer;
    delete pigmum;
    delete testwolf;
    delete a1;
    delete a2;
    delete startPush;

}
void Gamewidget::timeToShow()
{

    if (a1->getzhuangtai() == 1)
    {
        a1->setX(a1->getX() - 3);
    }
    if (a1->getX() < 0 || a1->getY() > 590)
    {
        a1->setzhuangtai(0);
        a1->setX(490);
    }
    if (a2->getzhuangtai() == 1)
    {
        a2->setX(a2->getX() - 3);
    }
    if (a2->getX() < 0 || a2->getY() > 590)
    {
        a2->setzhuangtai(0);
        a2->setX(490);
    }
    if (a1->getzhuangtai() == 2)
    {
        a1->setY(a1->getY() + 6);
    }
    if (a2->getzhuangtai() == 2)
    {
        a2->setY(a2->getY() + 6);
    }

    num = 0;
    for (int i = 0; i < 20; ++i)
    {
        if (wolves[i].getzhuangtai() == 1)
        {
            num++;
            wolves[i].setY(wolves[i].getY() + 2);
            if (wolves[i].getY() > 500)
            {
                wolves[i].setzhuangtai(4);
                score -= 50;
                diednum++;
                continue;
            }
            if (abs(wolves[i].getY() - 20 - a1->getY()) < 20 && a1->getzhuangtai() == 1 && (a1->getX() - wolves[i].getX()) < 10)
            {
                a1->setzhuangtai(2);
                wolves[i].setzhuangtai(2);
                QString absDir = "C:\\Users\\Wrzz\\Documents\\c++workplace\\wdh_last\\mp3\\py.mp3";
                player->setMedia(QUrl::fromLocalFile(absDir));
                player->play();
                score += 100;
                diednum++;
                continue;
            }
            else if (abs(wolves[i].getY() - a2->getY()) < 20 && a2->getzhuangtai() == 1 && (a2->getX() - wolves[i].getX()) < 10)
            {
                a2->setzhuangtai(2);
                wolves[i].setzhuangtai(2);
                QString absDir = "C:\\Users\\Wrzz\\Documents\\c++workplace\\wdh_last\\mp3\\py.mp3";
                player->setMedia(QUrl::fromLocalFile(absDir));
                player->play();
                score += 100;
                diednum++;
                continue;
            }
        }
        if (wolves[i].getzhuangtai() == 3)
        {
            num++;
            if (wolves[i].get_X() < wolves[i].getX())
            {
                wolves[i].set_X(wolves[i].get_X() + 2);
            }
            else
            {
                wolves[i].setzhuangtai(1);
            }
        }
        if (wolves[i].getzhuangtai() == 4)
        {

            if (wolves[i].getX() < 700)
            {
                wolves[i].setX(wolves[i].getX() + 2);
            }
        }
    }

    if (button && num < different && next < 20)
    {
        wolves[next++].setzhuangtai(3);
        num++;
    }
    if (diednum == 20)
    {
        QMessageBox::information(this, "Your Score is :", QString::number(score));

        diednum = 0;
        this->close();
        delete this;
    }
    update();
}
void Gamewidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    QPen pen(Qt::red, 2, Qt::SolidLine);
    p.setPen(pen);

    pigmum->move(490, h);
    QPoint fir(540, 119), sec(540, h);
    p.drawLine(fir, sec);

    for (int i = 19; i >= 0; i--)
    {
        if (wolves[i].getzhuangtai() == 1 || wolves[i].getzhuangtai() == 3 || wolves[i].getzhuangtai() == 4)
        {
            wolves[i].paint(&p);
        }
    }

    a1->paint(&p);
    a2->paint(&p);
    p.setFont(QFont("宋体", 20));
    p.drawText(20, 20, QString("score==") + QString::number(score));
}
void Gamewidget::keyPressEvent(QKeyEvent *e)
{
    switch (e->key())
    {
    case Qt::Key_Up:
        if (h >= 119)
            h -= 10;
        update();
        break;
    case Qt::Key_W:
        if (h >= 119)
            h -= 10;
        update();
        break;
    case Qt::Key_Down:
        if (h <= 430)
            h += 10;
        update();
        break;
    case Qt::Key_S:
        if (h <= 430)
            h += 10;
        update();
        break;
    case Qt::Key_J:
        sousousou();
        break;
    case Qt::Key_4:
        different++;
        break;
    default:
        break;
    }
}
void Gamewidget::startgame()
{
    if (one)
        return;
    button = true;
    score = 0;
    wolves[0].setzhuangtai(3);
    wolves[1].setzhuangtai(3);
    num = 2;
    next = 2;
    one = 1;
    diednum = 0;
    different = 2;
}
void Gamewidget::sousousou()
{
    if (a1->getzhuangtai() == 0)
    {
        a1->setY(h + 30);
        a1->setzhuangtai(1);
        QString absDir = "C:\\Users\\Wrzz\\Documents\\c++workplace\\wdh_last\\mp3\\shot.mp3";
        player->setMedia(QUrl::fromLocalFile(absDir));
        player->play();
    }
    else if (a2->getzhuangtai() == 0)
    {
        a2->setY(h + 30);
        a2->setzhuangtai(1);
        QString absDir = "C:\\Users\\Wrzz\\Documents\\c++workplace\\wdh_last\\mp3\\shot.mp3";
        player->setMedia(QUrl::fromLocalFile(absDir));
        player->play();
    }
}
