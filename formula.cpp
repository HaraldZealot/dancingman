#include "formula.h"
#include <stack>
#include <exception>
#include <iostream>
#include <cassert>
#include <QStringList>
#include <QRegularExpression>
#include "terms.h"
#include <QDebug>

using namespace std;

class AccesToEmptyException: exception
{
    public:
        AccesToEmptyException() noexcept {}
    AccesToEmptyException(const AccesToEmptyException &original) noexcept:
        exception(original) {}
        AccesToEmptyException &operator= (const AccesToEmptyException &rhs) noexcept
        {
            this->operator =(rhs);
            return *this;
        }
        virtual ~AccesToEmptyException() {}
        virtual const char *what() const noexcept override {return "AccesToEmptyException";}
};

class TransnotationAdapter
{
    public:
        enum Role
        {
            operand, operation, opener, closer
        };

        TransnotationAdapter(shared_ptr<AbstractTerm> term, Role role, int priority, bool placible):
            mTerm(term),
            mRole(role),
            mPriority(priority),
            mPlacible(placible)
        {
        }
        //default copy ctor
        //default copy opAssign
        //default destructor

        Role role()const {return mRole;}
        int priority()const {return mPriority;}
        void putToContainer(vector<shared_ptr<AbstractTerm> > &container)const
        {
            if(mPlacible)
                container.push_back(mTerm);
        }

    private:
        shared_ptr<AbstractTerm> mTerm;
        Role mRole;
        int mPriority;
        bool mPlacible;
};

TransnotationAdapter makeDummy()
{
    return TransnotationAdapter(shared_ptr<AbstractTerm>(), TransnotationAdapter::operand, -1, false);
}

TransnotationAdapter makeValuelike(shared_ptr<AbstractTerm> term)
{
    return TransnotationAdapter(term, TransnotationAdapter::operand, -1, true);
}

TransnotationAdapter makeOperator(shared_ptr<AbstractTerm> term, int priority)
{
    return TransnotationAdapter(term, TransnotationAdapter::operation, priority, true);
}

TransnotationAdapter makeFunction(shared_ptr<AbstractTerm> term)
{
    return TransnotationAdapter(term, TransnotationAdapter::opener, 0, true);
}

TransnotationAdapter makeOpenBracket()
{
    return TransnotationAdapter(shared_ptr<AbstractTerm>(), TransnotationAdapter::opener, 0, false);
}

TransnotationAdapter makeCloseBracket()
{
    return TransnotationAdapter(shared_ptr<AbstractTerm>(), TransnotationAdapter::closer, 0, false);
}

TransnotationAdapter factory(const QString &token, double &t)
{
    if(QRegularExpression("^[0-9]+(\\.[0-9]+)?([eE][-+]?[0-9]+)?$").match(token).hasMatch())
    {
        return makeValuelike(make_shared<Literal>(token.toDouble()));
    }
    else if(QRegularExpression("^t$").match(token).hasMatch())
    {
        return makeValuelike(make_shared<Variable>(t));
    }
    else if(QRegularExpression("^\\($").match(token).hasMatch())
    {
        return makeOpenBracket();
    }
    else if(QRegularExpression("^\\)$").match(token).hasMatch())
    {
        return makeCloseBracket();
    }
    else if(QRegularExpression("^[+-*/^]$").match(token).hasMatch())
    {
        if(QRegularExpression("^\\+$").match(token).hasMatch())
            return makeOperator(make_shared<Plus>(), 1);
        else if(QRegularExpression("^\\-$").match(token).hasMatch())
            return makeOperator(make_shared<Minus>(), 1);
        else if(QRegularExpression("^\\*$").match(token).hasMatch())
            return makeOperator(make_shared<Multiply>(), 2);
        else if(QRegularExpression("^\\/$").match(token).hasMatch())
            return makeOperator(make_shared<Devide>(), 2);
        else if(QRegularExpression("^\\^$").match(token).hasMatch())
            return makeOperator(make_shared<Power>(), 3);
        else
            assert(false);
    }
    else if(QRegularExpression("^((sqrt|sin|cos|tg|ctg|arcsin|arccos|arctg|arcctg|exp|lg|ln|lb)\\W*\\()$").match(token).hasMatch())
    {
        if(QRegularExpression("^sin\\W*\\($").match(token).hasMatch())
        {
            return makeFunction(make_shared<Sin>());
        }
        else if(QRegularExpression("^exp\\W*\\($").match(token).hasMatch())
        {
            return makeFunction(make_shared<Exp>());
        }
        else if(QRegularExpression("^lg\\W*\\($").match(token).hasMatch())
        {
            return makeFunction(make_shared<Log10>());
        }
        else
            assert(false);
    }
    else
        assert(false);

    return makeDummy();
}

Formula::Formula():
    mT(0.0)
{
    postfixRecord.push_back(make_shared<Literal>(0.01));
    postfixRecord.push_back(make_shared<Variable>(mT));
    postfixRecord.push_back(make_shared<Multiply>());
    postfixRecord.push_back(make_shared<Exp>());
}

Formula::Formula(const QString &infixRecord):
    mT(0.0)
{
    QRegularExpression tokenPattern("([+-*/^]|((sqrt|sin|cos|tg|ctg|arcsin|arccos|arctg|arcctg|exp|lg|ln|lb)\\W*\\()|\\(|\\)|([0-9]+(\\.[0-9]+)?([eE][-+]?[0-9]+)?)|t)");
    QRegularExpressionMatchIterator it = tokenPattern.globalMatch(infixRecord);
    QStringList tokens;

    while(it.hasNext())
    {
        QRegularExpressionMatch match = it.next();
        QString token = match.captured(1);
        qDebug() << token;
        tokens << token;
    }

    qDebug() << tokens;
}

double Formula::map(double t)
{
    mT = t;
    /*stack<double> calcStack;
    double argumentStack[2] = {0.0, 0.0};
    double result = 0.0;

    try
    {
        for(auto it = postfixRecord.begin(), end = postfixRecord.end(); it != end; ++it)
        {
            int valency = (*it)->valency();

            for(auto j = 0; j < valency; ++j)
            {
                if(calcStack.empty())
                    throw AccesToEmptyException();

                argumentStack[j] = calcStack.top();
                calcStack.pop();
            }

            calcStack.push((*it)->calc(argumentStack, valency));
        }

        if(calcStack.empty())
            throw AccesToEmptyException();

        result = calcStack.top();
        calcStack.pop();
        assert(calcStack.empty());
    }
    catch(AccesToEmptyException &e)
    {
        cerr << e.what();
    }

    return result;*/
    return 0.0;
}
