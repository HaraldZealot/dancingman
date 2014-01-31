#include "formulavalidator.h"
#include <QRegularExpression>
#include <QDebug>

FormulaValidator::FormulaValidator(QObject *parent) :
    QObject(parent)
{
    //connect(this, SIGNAL(QLineEdit::textChanged(QString)), this, SLOT(setText(QString)));
}

void FormulaValidator::reciveText(const QString &text)
{
    qDebug() << text;

    if(QRegularExpression("^(([-+*/^]|((sqrt|sin|cos|tg|ctg|arcsin|arccos|arctg|arcctg|exp|lg|ln|lb)\\W*\\()|\\(|\\)|([0-9]+(\\.[0-9]+)?([eE][-+]?[0-9]+)?)|t)\\W*)+$").match(text).hasMatch())
    {
        qDebug()<<"correct tokens";
    }
      //  emit newValidFormula(text);
}
