#include "Cat.h"
#include <iostream>
using namespace std;

int Cat::catCount = 0;

Cat::Cat(string name, int age, int weight, string breed, string color, 
         string health, string sound)
        : Animal("Cat", name, age, weight, breed, color, health, sound) 
{
    ++catCount;
    // debug: cout << "CAT #: " << catCount << endl;
}

void Cat::introduction(ostream &out) const 
{
    Animal::introduction(out);
}

int Cat::getCatCount() 
{
    return catCount;
}
