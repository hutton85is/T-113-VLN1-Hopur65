#ifndef PIZZATOPPINGS_H
#define PIZZATOPPINGS_H


class PizzaToppings
{
    public:
        PizzaToppings();
        virtual ~PizzaToppings();

        friend ostream& operator <<(ostream& outs, PizzaToppings& p_toppings);

        int price;
        char toppings[32];

    protected:

    private:
};

#endif // PIZZATOPPINGS_H
