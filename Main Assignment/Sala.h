#ifndef SALA_H
#define SALA_H


class Sala
{
    public:
        Sala();
        virtual ~Sala();
        void enterCrust();
        void enterToppings();
        void enterPizzaSize();
        void enterMenu();
        void enterExtras();
        void enterLocation();



    private:
        Pizza p;
};

#endif // SALA_H
