#ifndef FORMULA_H
#define FORMULA_H


#include <memory>
#include <vector>
#include <QString>
#include "abstractformula.h"
#include "abstractterm.h"

class Formula : public AbstractFormula
{
public:
    Formula();
    Formula(const QString &infixRecord);
    virtual ~Formula(){}

    virtual double map(double t)override;

private:
    Formula(const Formula &);
    Formula &operator=(const Formula &);

    typedef std::vector<std::shared_ptr<AbstractTerm> > container_t;
    container_t postfixRecord;
    double mT; // time argument
};

#endif // FORMULA_H
