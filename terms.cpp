#include "terms.h"
#include <cassert>
#include <cmath>

using namespace std;

Plus::Plus()
{

}

double Plus::calc(const double *operands, int valency) const
{
    assert(valency == mValency);
    return operands[1] + operands[0];
}

double Minus::calc(const double *operands, int valency) const
{
    assert(valency == mValency);
    return operands[1] - operands[0];
}

double Multiply::calc(const double *operands, int valency) const
{
    assert(valency == mValency);
    return operands[1] * operands[0];
}

double Devide::calc(const double *operands, int valency) const
{
    assert(valency == mValency);
    return operands[1] / operands[0];
}

double Power::calc(const double *operands, int valency) const
{
    assert(valency == mValency);
    return pow(operands[1], operands[0]);
}

double Exp::calc(const double *operands, int valency) const
{
    assert(valency == mValency);
    return exp(operands[0]);
}

double Log10::calc(const double *operands, int valency) const
{
    assert(valency == mValency);
    return log10(operands[0]);
}

double Sin::calc(const double *operands, int valency) const
{
    assert(valency == mValency);
    return sin(operands[0]);
}
