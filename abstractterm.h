#ifndef ABSTRACTTERM_H
#define ABSTRACTTERM_H

/// hierarchy-item type of class
class AbstractTerm
{
    public:
        virtual ~AbstractTerm() {}

        int valency()const = 0;
        double calc(const double operands, int valency)const = 0;

    protected:
        AbstractTerm() {}

    private:
        AbstractTerm(const AbstractTerm &);
        AbstractTerm &operator=(const AbstractTerm &);
};

#endif // ABSTRACTTERM_H
