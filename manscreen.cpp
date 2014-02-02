#include "manscreen.h"
#include <QPainter>
#include "sinusoida.h"
#include "formula.h"
#include <QDebug>
#include <utility>


ManScreen::ManScreen(QWidget *parent) :
    QWidget(parent),
    man(),
    headFormula(new Formula("sin(3*t)")),
    bodyFormula(new Formula("cos(3*t)")),
    leftHandFormula(new Formula("sin(3*t)")),
    rightHandFormula(new Formula("cos(3*t)")),
    leftLegFormula(new Formula("sin(3*t)")),
    rightLegFormula(new Formula("cos(3*t)"))
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

void ManScreen::setBodyFormula(const QString &formula)
{
    try
    {
        AbstractFormula *temp = new Formula(formula);
        std::swap(bodyFormula, temp);
        delete temp;
    }
    catch(...)
    {
    }
}

void ManScreen::setLeftHandFormula(const QString &formula)
{
    try
    {
        AbstractFormula *temp = new Formula(formula);
        std::swap(leftHandFormula, temp);
        delete temp;
    }
    catch(...)
    {
    }
}

void ManScreen::setRightHandFormula(const QString &formula)
{
    try
    {
        AbstractFormula *temp = new Formula(formula);
        std::swap(rightHandFormula, temp);
        delete temp;
    }
    catch(...)
    {
    }
}

void ManScreen::setLeftLegFormula(const QString &formula)
{
    try
    {
        AbstractFormula *temp = new Formula(formula);
        std::swap(leftLegFormula, temp);
        delete temp;
    }
    catch(...)
    {
    }
}

void ManScreen::setRightLegFormula(const QString &formula)
{
    try
    {
        AbstractFormula *temp = new Formula(formula);
        std::swap(rightLegFormula, temp);
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
    man.setHeadAngle(headFormula->map(t));
    man.setBodyAngle(bodyFormula->map(t));
    man.setLeftHandAngle(leftHandFormula->map(t));
    man.setRightHandAngle(rightHandFormula->map(t));
    man.setLeftLegTangent(leftLegFormula->map(t));
    man.setRightLegTangent(rightLegFormula->map(t));
    update();
}
