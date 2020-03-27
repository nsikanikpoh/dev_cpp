#include <iostream>
#include <string>

enum class Animal
{
    PIG,
    CHICKEN,
    GOAT,
    CAT,
    DOG,
    OSTRICH
};

std::string getAnimalName(Animal animal)
{
    switch(animal)
    {
    case Animal::PIG:
        return "Pig";
    case Animal::CHICKEN:
        return "Chicken";
    case Animal::GOAT:
        return "Goat";
    case Animal::CAT:
        return "Cat";
    case Animal::DOG:
        return "Dog";
    case Animal::OSTRICH:
        return "Ostrich";
    default:
        return "getAnimalName(): Animal does not exist";
    }
}

void printNumberOfLegs(Animal animal)
{
using namespace std;
 switch(animal)
    {
    case Animal::PIG:
    case Animal::GOAT:
    case Animal::CAT:
    case Animal::DOG:
        cout << "A " << getAnimalName(animal) << " has 4 legs\n";
        break;
    case Animal::CHICKEN:
    case Animal::OSTRICH:
         cout << "A " << getAnimalName(animal) << " has 2 legs\n";
         break;
    default:
        cout << "printNumberOfLegs(): Animal does not exist\n";
        break;
    }
}

int main()
{
    printNumberOfLegs(Animal::CAT);
    printNumberOfLegs(Animal::CHICKEN);
    //printNumberOfLegs("LION");
    return 0;
}

