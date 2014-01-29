#ifndef ABSTRACTFORMULA_H
#define ABSTRACTFORMULA_H

/// hierarchy-item type of class
class AbstractFormula
{
    public:
        virtual ~AbstractFormula(){}

        virtual double map(double t) = 0;

    protected:
        AbstractFormula(){}

    private:
        AbstractFormula(const AbstractFormula &);
        AbstractFormula &operator=(const AbstractFormula &);
};

#endif // ABSTRACTFORMULA_H
