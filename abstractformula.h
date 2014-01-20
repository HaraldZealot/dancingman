#ifndef ABSTRACTFORMULA_H
#define ABSTRACTFORMULA_H

class AbstractFormula
{
public:
    AbstractFormula();
    virtual ~AbstractFormula();
    virtual double operator()(double t)const=0;
};

#endif // ABSTRACTFORMULA_H
