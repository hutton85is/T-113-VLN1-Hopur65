#ifndef PIZZALOCATIONS_H
#define PIZZALOCATIONS_H


class PizzaLocations
{
    public:
        PizzaLocations();
        virtual ~PizzaLocations();

        friend ostream& operator <<(ostream& outs, PizzaLocations& p_locations);

        int price;
        bool pick_up;

    protected:

    private:
};

#endif // PIZZALOCATIONS_H
