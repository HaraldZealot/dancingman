#include "manscreen.h"
#include <QPainter>
#include <QTime>
#include "sinusoida.h"
#include <QDebug>


ManScreen::ManScreen(QWidget *parent) :
    QWidget(parent),
    man(),
    headFormula(new Sinusoida(3.0)),
    bodyFormula(new Sinusoida(2.0))
{
    startTimer(20);
}

void ManScreen::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setBrush(QBrush(Qt::black));
    painter.setPen(Qt::NoPen);
    painter.drawRect(0, 0, width() - 1, height() - 1);
    painter.setTransform(QTransform(1, 0, 0, -1, width() / 2, height() / 2));
    man.drawSelf(painter);
}

void ManScreen::timerEvent(QTimerEvent *)
{
    QTime current = QTime::currentTime();
    double t = (current.minute() * 60000 + current.second() * 1000 + current.msec()) / 1000.0;
    qDebug() << t;
    man.setHeadAngle(headFormula->map(t));
    man.setBodyAngle(bodyFormula->map(t));
    update();
}
