#include "Animal.h"

#include <iostream>
using namespace std;

int Animal::animalCount = 0;

// Constructor
Animal::Animal(string type, string name, int age, int weight, string breed, 
               string color, string health, string sound)
                : type(type), name(name), age(age), weight(weight), breed(breed), 
                color(color), health(health), sound(sound) 
{
    ++animalCount;
    //debug: cout << "ANIMAL #:" << animalCount << endl;
}

// Getter Functions 
string Animal::getType() const { return type; }
string Animal::getName() const { return name; }
int Animal::getAge() const { return age; }
int Animal::getWeight() const { return weight; }
string Animal::getBreed() const { return breed; }
string Animal::getColor() const { return color; }
string Animal::getHealth() const { return health; }
string Animal::getSound() const { return sound; }

// The animals' "speech"
void Animal::introduction(ostream &out) const 
{
    out << "Hi, I'm " << name << ", I'm a " << type << " and I'm " << age << " years old."
        << " My weight is: " << weight << " lbs. I'm a " << breed << " and I am " << color
        << ". The status of my health is: " << health << " and I " << sound << endl;
}

// Defualt values if trait is unknown
Animal Animal::baseAnimal() 
{
    return Animal("UNKNOWN", "UNKNOWN", 0, 0, "UNKNOWN", "UNKNOWN", "UNKNOWN", "UNKNOWN");
}

int Animal::getAnimalCount() 
{
    return animalCount;
}
