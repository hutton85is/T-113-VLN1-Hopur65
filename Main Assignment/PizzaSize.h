#ifndef PIZZASIZE_H
#define PIZZASIZE_H


class PizzaSize
{
    public:
        PizzaSize();
        virtual ~PizzaSize();

        friend ostream& operator <<(ostream& outs, PizzaSize& p_size);

        int price;
        char p_size[32];

    protected:

    private:
};

#endif // PIZZASIZE_H
