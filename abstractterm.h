#ifndef ABSTRACTTERM_H
#define ABSTRACTTERM_H

/// hierarchy-item type of class
class AbstractTerm
{
    public:
        virtual ~AbstractTerm() {}

        virtual int valency()const = 0;
        virtual double calc(const double *operands, int valency)const = 0;
        virtual bool isCompileTimeEvaluable()const {return false;}

    protected:
        AbstractTerm() {}

    private:
        AbstractTerm(const AbstractTerm &);
        AbstractTerm &operator=(const AbstractTerm &);
};

#endif // ABSTRACTTERM_H
