#include <iostream>
#include <string_view>
#include <string>

class Animal
{
protected:
    std::string m_name;

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(const std::string &name)
        : m_name{ name }
    {
    }

public:
    const std::string& getName() const
    {
        return m_name;
    }
    std::string_view speak() const
    {
        return "???";
    }
};

class Cat: public Animal
{
public:
    Cat(const std::string &name)
        : Animal{ name }
    {
    }

    std::string_view speak() const
    {
        return "Meow";
    }
};

class Dog: public Animal
{
public:
    Dog(const std::string &name)
        : Animal{ name }
    {
    }

    std::string_view speak() const
    {
        return "Woof";
    }
};

int main()
{
    Cat cat{ "Fred" };
    std::cout << "cat is named " << cat.getName() << ", and it says " << cat.speak() << '\n';

    Dog dog{ "Garbo" };
    std::cout << "dog is named " << dog.getName() << ", and it says " << dog.speak() << '\n';

    Animal *pAnimal{ &cat };
    std::cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';

    pAnimal = &dog;
    std::cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';


    Cat fred{ "Fred" };
    Cat misty{ "Misty" };
    Cat zeke{ "Zeke" };

    Dog garbo{ "Garbo" };
    Dog pooky{ "Pooky" };
    Dog truffle{ "Truffle" };

    // Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
    Animal *animals[] { &fred, &garbo, &misty, &pooky, &truffle, &zeke };
    for (const auto animal : animals)
        std::cout << animal->getName() << " says " << animal->speak() << '\n';

    return 0;
}
