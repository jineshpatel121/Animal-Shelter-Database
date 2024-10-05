#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal 
{
    private:
        static int catCount;

    public:
        Cat(string name, int age, int weight, string breed, string color, 
            string health, string sound);

        void introduction(ostream &out) const;

        static int getCatCount();
};

#endif