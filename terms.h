#ifndef TERMS_H
#define TERMS_H

#include "abstractterm.h"
#include <QtGlobal>

class Variable: public AbstractTerm
{
    public:
        Variable(double &t): mT(t) {}
        virtual ~Variable() {}

        virtual int valency()const override {return mValency;}
        virtual double calc(const double *operands, int valency) const override {Q_UNUSED(operands); Q_UNUSED(valency); return mT;}
        virtual QString toString()const {return QString("t");}

    private:
        Variable(const Variable &);
        Variable &operator=(const Variable &);

        double &mT;
        static const int mValency = 0;
};

class Literal: public AbstractTerm
{
    public:
        Literal(double value): mValue(value) {}
        virtual ~Literal() {}

        virtual int valency()const override {return mValency;}
        virtual double calc(const double *operands, int valency) const override {Q_UNUSED(operands); Q_UNUSED(valency); return mValue;}
        virtual bool isCompileTimeEvaluable()const override {return true;}
        virtual QString toString()const {return QString("%1").arg(mValue);}

    private:
        Literal(const Literal &);
        Literal &operator=(const Literal &);

        double mValue;
        static const int mValency = 0;
};

class UnaryMinus: public AbstractTerm
{
    public:
        UnaryMinus(): AbstractTerm() {}
        virtual ~ UnaryMinus() {}

        virtual int valency() const override {return mValency;}
        virtual double calc(const double *operands, int valency) const override;
        virtual QString toString()const {return QString("_");}

    private:
        UnaryMinus(const  UnaryMinus &);
        UnaryMinus &operator=(const  UnaryMinus &);

        static const int mValency = 1;
};


class Plus: public AbstractTerm
{
    public:
        Plus(): AbstractTerm() {}
        virtual ~Plus() {}

        virtual int valency() const override {return mValency;}
        virtual double calc(const double *operands, int valency) const override;
        virtual QString toString()const override {return QString("+");}

    private:
        Plus(const Plus &);
        Plus &operator=(const Plus &);

        static const int mValency = 2;
};

class Minus: public AbstractTerm
{
    public:
        Minus(): AbstractTerm() {}
        virtual ~Minus() {}

        virtual int valency() const override {return mValency;}
        virtual double calc(const double *operands, int valency) const override;
        virtual QString toString()const override {return QString("-");}

    private:
        Minus(const Minus &);
        Minus &operator=(const Minus &);

        static const int mValency = 2;
};

class Multiply: public AbstractTerm
{
    public:
        Multiply(): AbstractTerm() {}
        virtual ~Multiply() {}

        virtual int valency() const override {return mValency;}
        virtual double calc(const double *operands, int valency) const override;
        virtual QString toString()const override {return QString("*");}

    private:
        Multiply(const Multiply &);
        Multiply &operator=(const Multiply &);

        static const int mValency = 2;
};

class Devide: public AbstractTerm
{
    public:
        Devide(): AbstractTerm() {}
        virtual ~Devide() {}

        virtual int valency() const override {return mValency;}
        virtual double calc(const double *operands, int valency) const override;
        virtual QString toString()const override {return QString("/");}

    private:
        Devide(const Devide &);
        Devide &operator=(const Devide &);

        static const int mValency = 2;
};

class Power: public AbstractTerm
{
    public:
        Power(): AbstractTerm() {}
        virtual ~Power() {}

        virtual int valency() const override {return mValency;}
        virtual double calc(const double *operands, int valency) const override;
        virtual QString toString()const override {return QString("^");}

    private:
        Power(const Power &);
        Power &operator=(const Power &);

        static const int mValency = 2;
};

class Sqrt: public AbstractTerm
{
    public:
        Sqrt(): AbstractTerm() {}
        virtual ~Sqrt() {}

        virtual int valency() const override {return mValency;}
        virtual double calc(const double *operands, int valency) const override;
        virtual QString toString()const override {return QString("sqrt");}

    private:
        Sqrt(const Sqrt &);
        Sqrt &operator=(const Sqrt &);

        static const int mValency = 1;
};

class Exp: public AbstractTerm
{
    public:
        Exp(): AbstractTerm() {}
        virtual ~Exp() {}

        virtual int valency() const override {return mValency;}
        virtual double calc(const double *operands, int valency) const override;
        virtual QString toString()const override {return QString("exp");}

    private:
        Exp(const Exp &);
        Exp &operator=(const Exp &);

        static const int mValency = 1;
};

class Log10: public AbstractTerm
{
    public:
        Log10(): AbstractTerm() {}
        virtual ~Log10() {}

        virtual int valency() const override {return mValency;}
        virtual double calc(const double *operands, int valency) const override;
        virtual QString toString()const override {return QString("log10");}

    private:
        Log10(const Log10 &);
        Log10 &operator=(const Log10 &);

        static const int mValency = 1;
};

class Sin: public AbstractTerm
{
    public:
        Sin(): AbstractTerm() {}
        virtual ~Sin() {}

        virtual int valency() const override {return mValency;}
        virtual double calc(const double *operands, int valency) const override;
        virtual QString toString()const override {return QString("sin");}

    private:
        Sin(const Sin &);
        Sin &operator=(const Sin &);

        static const int mValency = 1;
};

class Cos: public AbstractTerm
{
    public:
        Cos(): AbstractTerm() {}
        virtual ~Cos() {}

        virtual int valency() const override {return mValency;}
        virtual double calc(const double *operands, int valency) const override;
        virtual QString toString()const override {return QString("cos");}

    private:
        Cos(const Cos &);
        Cos &operator=(const Cos &);

        static const int mValency = 1;
};

class Tan: public AbstractTerm
{
    public:
        Tan(): AbstractTerm() {}
        virtual ~Tan() {}

        virtual int valency() const override {return mValency;}
        virtual double calc(const double *operands, int valency) const override;
        virtual QString toString()const override {return QString("tan");}

    private:
        Tan(const Tan &);
        Tan &operator=(const Tan &);

        static const int mValency = 1;
};

class Cotan: public AbstractTerm
{
    public:
        Cotan(): AbstractTerm() {}
        virtual ~Cotan() {}

        virtual int valency() const override {return mValency;}
        virtual double calc(const double *operands, int valency) const override;
        virtual QString toString()const override {return QString("cotan");}

    private:
        Cotan(const Cotan &);
        Cotan &operator=(const Cotan &);

        static const int mValency = 1;
};

class Asin: public AbstractTerm
{
    public:
        Asin(): AbstractTerm() {}
        virtual ~Asin() {}

        virtual int valency() const override {return mValency;}
        virtual double calc(const double *operands, int valency) const override;
        virtual QString toString()const override {return QString("asin");}

    private:
        Asin(const Asin &);
        Asin &operator=(const Asin &);

        static const int mValency = 1;
};


#endif // TERMS_H
