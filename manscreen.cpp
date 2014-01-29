#include "manscreen.h"
#include <QPainter>
#include <QTime>
#include "sinusoida.h"
#include "formula.h"
#include <QDebug>


ManScreen::ManScreen(QWidget *parent) :
    QWidget(parent),
    man(),
    headFormula(new Sinusoida(3.0)),
    bodyFormula(new Formula("(2.348   + -3e-5)  /\n(exp  (2.0*sqrt\t(0.5*t-0.1))*tg(4*t))"))
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
    //qDebug() << t;
    man.setHeadAngle(headFormula->map(t));
    man.setBodyAngle(bodyFormula->map(t));
    update();
}
