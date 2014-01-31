#include "manscreen.h"
#include <QPainter>
#include "sinusoida.h"
#include "formula.h"
#include <QDebug>
#include <utility>


ManScreen::ManScreen(QWidget *parent) :
    QWidget(parent),
    man(),
    headFormula(new Sinusoida(3.0)),
    bodyFormula(new Formula("sin(4*t)"))
{
    originTime = QTime::currentTime();
    startTimer(20);
}

void ManScreen::setHeadFormula(const QString &formula)
{
    try
    {
        AbstractFormula *temp = new Formula(formula);
        std::swap(headFormula, temp);
        delete temp;
    }
    catch(...)
    {
    }
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
    double t = originTime.msecsTo(QTime::currentTime()) / 1000.0;
    //double t = (current.minute() * 60000 + current.second() * 1000 + current.msec()) / 1000.0;
    //qDebug() << t;
    man.setHeadAngle(headFormula->map(t));
    man.setBodyAngle(bodyFormula->map(t));
    update();
}
