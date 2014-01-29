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

    private:
        Literal(const Literal &);
        Literal &operator=(const Literal &);

        double mValue;
        static const int mValency = 0;
};

class Plus: public AbstractTerm
{
    public:
        Plus();
        virtual ~Plus() {}

        virtual int valency() const override {return mValency;}
        virtual double calc(const double *operands, int valency) const override;

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

    private:
        Power(const Power &);
        Power &operator=(const Power &);

        static const int mValency = 2;
};

class Exp: public AbstractTerm
{
    public:
        Exp(): AbstractTerm() {}
        virtual ~Exp() {}

        virtual int valency() const override {return mValency;}
        virtual double calc(const double *operands, int valency) const override;

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

    private:
        Sin(const Sin &);
        Sin &operator=(const Sin &);

        static const int mValency = 1;
};

#endif // TERMS_H
