#ifndef MANSCREEN_H
#define MANSCREEN_H

#include <QWidget>
#include "dancingman.h"

class ManScreen : public QWidget
{
    Q_OBJECT
public:
    explicit ManScreen(QWidget *parent = 0);

    QSize sizeHint() const override {return QSize(200,200);}

signals:

public slots:

protected:
   void paintEvent(QPaintEvent *) override;
private:
    DancingMan man;
};

#endif // MANSCREEN_H
