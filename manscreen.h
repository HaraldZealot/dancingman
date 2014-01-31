#ifndef MANSCREEN_H
#define MANSCREEN_H

#include <QWidget>
#include <QTime>
#include "dancingman.h"
#include "abstractformula.h"

class ManScreen : public QWidget
{
        Q_OBJECT
    public:
        explicit ManScreen(QWidget *parent = 0);

        QSize sizeHint() const override {return QSize(200, 200);}

    signals:

    public slots:
        void setHeadFormula(const QString &formula);

    protected:
        void paintEvent(QPaintEvent *) override;
        void timerEvent(QTimerEvent *) override;
    private:
        QTime originTime;
        DancingMan man;
        AbstractFormula *headFormula, *bodyFormula;
};

#endif // MANSCREEN_H
