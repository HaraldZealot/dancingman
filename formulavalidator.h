#ifndef FORMULAVALIDATOR_H
#define FORMULAVALIDATOR_H

#include <QObject>
#include <QString>

class FormulaValidator : public QObject
{
        Q_OBJECT
    public:
        explicit FormulaValidator(QObject *parent = 0);

    signals:
        void newValidFormula(const QString &);

    public slots:
        void reciveText(const QString &text);

};

#endif // FORMULAVALIDATOR_H
