#include "Dog.h"
#include <iostream>
using namespace std;

int Dog::dogCount = 0;

Dog::Dog(string name, int age, int weight, string breed, string color, 
         string health, string sound)
    : Animal("Dog", name, age, weight, breed, color, health, sound) 
{
    ++dogCount;
    //debug: cout << "DOG #: " << dogCount << endl;
}

void Dog::introduction(ostream &out) const 
{
    Animal::introduction(out);
}

int Dog::getDogCount() 
{
    return dogCount;
}
