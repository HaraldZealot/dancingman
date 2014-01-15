#include "manscreen.h"
#include <QPainter>

ManScreen::ManScreen(QWidget *parent) :
    QWidget(parent)
{
}

void ManScreen::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setBrush(QBrush(Qt::black));
    painter.setPen(Qt::NoPen);
    painter.drawRect(0, 0, width() - 1, height() - 1);
}
