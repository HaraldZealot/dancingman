#ifndef MANSCREEN_H
#define MANSCREEN_H

#include <QWidget>

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

};

#endif // MANSCREEN_H
