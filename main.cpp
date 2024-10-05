/* 
    Animal Shelter
    By: Jinesh Patel
    Created: 04/20

    Purpose: The program creates a database of dogs, cats, and every animal(including dogs and cats) using a main Animal 
    class and two subclasses, Dog and Cat. The program needs a file containg the various traits of an animal and then 
    reads the file and sorts the animals into three vectors. Then reports the number of animals in the database.
    Addtionly it creates an introdtuction sentence that states all the traits of the animal. If a trait is not given,
    the repscetive felid in the introduction is replaced by "UNKNOWN" or "O"(if a numerical trait). The program reports
    to the console and an output file simultaneously.

    Changelog: 
        - Created parent class Animal - 04/19
        - Re-organized Animal class to add private members - 04/19
        - Made constructors for Dog and Cat subclasses - 04/19
        - Created introduction and counter functions for all class - 04/19
        - Created method to break each line down into chracters - 04/19
        - Filled vectors with trait values - 04/19
        - Re-orginzed Animal class to add a default case -04/20
        - Created method to use default case when trait is not given -04/20
        - Created function to display statics using the counter function in the classes - 04/20
        - Made functions to output introductions - 04/20
    
    Notes/Special Features:
     - Fault tolerance when dealing with files opening
     - Used get functions to return privated meber values 
     - Broke down each file ine into characters to search for commas
     - Created each trait value character by character
     - Used counter and switch-case to assign each value to the correct trait felid
     - Emptied string containg vectors after every proccess
     - stored the numerical traits(age & weight) as strings then converted to int beofre adding to vector
     - Used ostream to simultaneously report to the console and file
     - Created a function to report each type of intro using the intro function from the respective class
     - Cleared dynmaiclly alocatted memory

*/

#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

// Prototypes
void setAttributes (ifstream &inFile, vector<Animal*> &animals, vector<Dog*> &dogs, vector<Cat*> &cats);
void showTotals (ostream &out);
void showAnimalIntro (ostream &out, vector<Animal*> &animals);
void showCatIntro (ostream &out, vector <Cat*> &cats);
void showDogIntro (ostream &out, vector <Dog*> &dogs);

int main()
{
    vector <Animal*> animals;
    vector <Dog*> dogs;
    vector <Cat*> cats;

    ifstream inFile;
    
    inFile.open("operationKindness.csv");

    if (inFile)
    {
        // Fill the vectors
        setAttributes(inFile,animals,dogs,cats);
        //debug: cout << "Vectors FILLED";

        bool open ;
        string fileName;
        do
        {   
            // Get name of output file
            cout << "Enter name of file to report to: ";
            getline(cin,fileName);

            ofstream outFile(fileName);

            if (outFile)
            {
                open = true;

                // Report 1
                showTotals(cout);
                showTotals(outFile);
                // Report 2
                showAnimalIntro(cout,animals);
                showAnimalIntro(outFile,animals);
                //Report 3
                showCatIntro(cout,cats);
                showCatIntro(outFile,cats);
                // Report 4
                showDogIntro(cout,dogs);
                showDogIntro(outFile,dogs);
            }
            else
            {
                open = false;
                cout << "ERROR! Report file can't open" << endl;
            }

            outFile.close();

        } while(!open);

    }
    else
    {
        cout << "ERROR! Input file can't open" << endl;
    }
    
    inFile.close();

    //debug: cout << "END, deleting started";
    // Delete the dymanic memory 
    for (int i = 0; i < animals.size(); ++i)
    {
        delete animals.at(i);
    }

    return 0;
}

void setAttributes (ifstream &inFile, vector<Animal*> &animals, vector<Dog*> &dogs, vector<Cat*> &cats)
{
    string line;
    char ch;

    // Call to replace missing traits 
    Animal base = Animal::baseAnimal();

    //Skip the first line
    getline(inFile,line);

    while (getline(inFile,line))
    {
        string type, name, ageStr, weightStr, breed, color, health, sound;
        int age, weight;

        // # of traits filled
        int attributeCount = 0;
        // String to track which trait to fill
        string curTrait;

        // Break each line down into chars
        for (int i = 0; i < line.length(); i++)
        {
            ch = line.at(i);

            if (ch == ',')
            {
                // debug: cout << "TRAIT found";
                if (!curTrait.empty())
                {
                    switch (attributeCount)
                    {
                        // debug: cout << "TRAIT #: " << attributeCount << endl;
                        // Assign trait values when its given 
                        case 0: type = curTrait;
                            break;
                        case 1: name = curTrait;
                            break;
                        case 2: ageStr = curTrait;
                            break;
                        case 3: weightStr = curTrait;
                            break;
                        case 4: breed = curTrait;
                            break;
                        case 5: color = curTrait;
                            break;
                        case 6: health = curTrait;
                            break;
                    }
                }
                else
                {
                    // debug: cout << "UNKNOWN,trait";
                    // If trait is unknown replace with defualt case 
                    switch (attributeCount)
                    {
                        case 0: type = base.getType();
                            break;
                        case 1: name = base.getName();
                            break;
                        case 2: ageStr = base.getAge();
                            break;
                        case 3: weightStr = base.getWeight();
                            break;
                        case 4: breed = base.getBreed();
                            break;
                        case 5: color = base.getColor();
                            break;
                        case 6: health = base.getHealth();
                            break;
                    }

                }
                // Empty the string after procccesing
                curTrait.clear();
                attributeCount++;
            }
            else
            {
                // Build char by char
                curTrait = curTrait + ch;
                // debug: cout << "BUILDING other char";
            }

        }
        // Fill sound trait outside switch since always last trait
        if (curTrait.empty())
        {
            sound = base.getSound();
        }
        else
        {
            sound = curTrait;
        }

        // Convert the age/weight strings to char arrays into intergers
        if (!ageStr.empty())
        {
            age = atoi(ageStr.c_str());
            // debug: cout << "AGE, converted";
        }
        if (!weightStr.empty())
        {
            weight = atoi(weightStr.c_str());
            // debug: cout << "WEIGHT,converted";
        }

        // Construct vectors
        if (type == "dog")
        {
            Dog *dog = new Dog(name, age, weight, breed, color, health, sound);
            dogs.push_back (dog);

            animals.push_back (dog);
            // debug: cout << "DOG,added";
        }
        else if (type == "cat")
        {
            Cat *cat = new Cat(name, age, weight, breed, color, health, sound);
            cats.push_back (cat);

            animals.push_back (cat);
            // debug: cout << "CAT,added";
        }
        else
        {
            animals.push_back (new Animal(type, name, age, weight, breed, color, health, sound));
            // debug: cout << "OTHER,added";
        }
         
    }
    
}
void showTotals (ostream &out)
{
    out << "******* Report 1: *******" << endl;
    // Account for first line/ earlier zero-indexing
    out <<"\nTotal Animals Created: " << (Animal::getAnimalCount()) - 1 << endl;

    out << "Number of Cats: " << Cat::getCatCount() << endl;
    out << "Number of Dogs: " << Dog::getDogCount() << endl;
    out << endl;
}
void showAnimalIntro (ostream &out, vector<Animal*> &animals)
{
    out << "******* Report 2: All Animals *******\n" << endl;

    for (int i = 0; i < animals.size(); ++i)
    {
        animals.at(i)->introduction(out);
    }
    out << endl;
}
void showCatIntro (ostream &out, vector <Cat*> &cats)
{
    out << "******* Report 3: Cats *******\n" << endl;
    for (int i = 0; i < cats.size(); ++i)
    {
        cats.at(i)->introduction(out);
    }
    out << endl;
}
void showDogIntro (ostream &out, vector <Dog*> &dogs)
{
    out << "******* Report 4: Dogs *******\n" << endl;
    for (int i = 0; i < dogs.size(); ++i)
    {
        dogs.at(i)->introduction(out);
    }
}
