#ifndef DOG_H
#define DOG_H
#include "Animal.h"

class Dog : public Animal 
{
    private:
        static int dogCount;

    public:
        Dog(string name, int age, int weight, string breed, string color, 
            string health, string sound);

        void introduction(ostream &out) const;

        static int getDogCount();
};

#endif