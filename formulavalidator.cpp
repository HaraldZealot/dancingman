#include "formulavalidator.h"
#include <QRegularExpression>
#include <QDebug>
#include <stack>
#include <cassert>

FormulaValidator::FormulaValidator(QObject *parent) :
    QObject(parent)
{
    //connect(this, SIGNAL(QLineEdit::textChanged(QString)), this, SLOT(setText(QString)));
}

bool isBracketValid(const QString &text);
bool hasNoEmptyBracket(const QString &text);
bool isSequenceValid(const QString &text);

void FormulaValidator::reciveText(const QString &text)
{
    qDebug() << text;

    if(QRegularExpression("^(([-+*/^]|((sqrt|sin|cos|tg|ctg|arcsin|arccos|arctg|arcctg|exp|lg|ln|lb)\\W*\\()|\\(|\\)|([0-9]+(\\.[0-9]+)?([eE][-+]?[0-9]+)?)|t)\\W*)+$").match(text).hasMatch()
            && isBracketValid(text) && hasNoEmptyBracket(text) && isSequenceValid(text))
    {
        emit newValidFormula(text);
    }
}

bool isComplimentarBracket(const QChar &a, const QChar &b)
{
    return (a == QChar('(') && b == QChar(')')) || (a == QChar('{') && b == QChar('}')) || (a == QChar('[') && b == QChar(']'));
}

bool isBracketValid(const QString &text)
{
    std::stack<QChar> stack;

    for(auto it = text.cbegin(), end = text.cend(); it != end; ++it)
    {
        if(*it == QChar('(') || *it == QChar('{') || *it == QChar('['))
            stack.push(*it);

        if(*it == QChar(')') || *it == QChar('}') || *it == QChar(']'))
        {
            if(stack.empty())
                return false;

            if(isComplimentarBracket(stack.top(), *it))
                stack.pop();
            else
                return false;
        }
    }

    return stack.empty();
}

bool hasNoEmptyBracket(const QString &text)
{
    return !QRegularExpression("\\(\\W*\\)").match(text).hasMatch();
}

enum State {opener, operand, minus, operation, closer, stop};

State toState(const QString &token)
{
    if(QRegularExpression("^((sqrt|sin|cos|tg|ctg|arcsin|arccos|arctg|arcctg|exp|lg|ln|lb)\\W*\\(|\\()$").match(token).hasMatch())
        return State::opener;
    else if(QRegularExpression("^([0-9]+(\\.[0-9]+)?([eE][-+]?[0-9]+)?)|t$").match(token).hasMatch())
        return State::operand;
    else if(QRegularExpression("^-$").match(token).hasMatch())
        return State::minus;
    else if(QRegularExpression("^[/*^+]$").match(token).hasMatch())
        return State::operation;
    else if(QRegularExpression("^\\)$").match(token).hasMatch())
        return State::closer;

    assert(false);
    return State::opener;
}


bool isSequenceValid(const QString &text)
{
    QRegularExpression tokenPattern("([-+*/^]|((sqrt|sin|cos|tg|ctg|arcsin|arccos|arctg|arcctg|exp|lg|ln|lb)\\W*\\()|\\(|\\)|([0-9]+(\\.[0-9]+)?([eE][-+]?[0-9]+)?)|t)");
    QRegularExpressionMatchIterator it = tokenPattern.globalMatch(text);
    bool automatonGraph[6][6] = {{1, 1, 1, 0, 1, 0}, {0, 0, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 0}, {1, 1, 1, 0, 0, 0}, {0, 0, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0}};
    State state = opener;

    while(it.hasNext())
    {
        QRegularExpressionMatch match = it.next();
        QString token = match.captured(1);
        qDebug() << token << " " << toState(token);

        if(!automatonGraph[state][toState(token)])
            return false;

        state = toState(token);
    }

    if(!automatonGraph[state][State::stop])
        return false;

    return true;
}
