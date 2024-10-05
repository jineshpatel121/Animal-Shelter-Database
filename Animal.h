#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
using namespace std;

class Animal 
{
    private:
        static int animalCount;
        string type;
        string name;
        int age;
        int weight;
        string breed;
        string color;
        string health;
        string sound;

    public:
        Animal(string type, string name, int age, int weight, string breed, 
            string color, string health, string sound);

        string getType() const;
        string getName() const;
        int getAge() const;
        int getWeight() const;
        string getBreed() const;
        string getColor() const;
        string getHealth() const;
        string getSound() const;

        void introduction(ostream &out) const;

        static Animal baseAnimal();
        static int getAnimalCount();
};

#endif