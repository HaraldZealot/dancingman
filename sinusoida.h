#ifndef SINUSOIDA_H
#define SINUSOIDA_H

#include "abstractformula.h"
#include <cmath>

class Sinusoida : public AbstractFormula
{
public:
    Sinusoida(double omega);
    virtual ~Sinusoida();
    virtual double operator ()(double t)const override{return std::sin(mOmega * t);}
private:
    double mOmega;
};

#endif // SINUSOIDA_H
