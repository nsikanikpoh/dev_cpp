#include <string>
#include <iostream>
class Animal
{
protected:
    std::string m_name;

public:
    Animal(std::string name)
        : m_name(name)
    {
    }
    std::string getName()
    {
        return m_name;
    }
    virtual const char* speak() = 0; // note that speak is now a pure virtual function
    //This means Animal is now an abstract base class, and can not be instantiated
};

const char* Animal::speak()  // even though it has a body
{
    return "buzz";
}

class Cat: public Animal
{
public:
    Cat(std::string name)
        : Animal(name)
    {
    }

    virtual const char* speak()
    {
        return "Meow";
    }
};

class Dog: public Animal
{
public:
    Dog(std::string name)
        : Animal(name)
    {
    }

    virtual const char* speak()
    {
        return "Woof";
    }
};

class Cow: public Animal
{
public:
    Cow(std::string name)
        : Animal(name)
    {
    }

    // We forgot to redefine speak
    virtual const char* speak()
    {
        return "Moo";
    }
};

class Dragonfly: public Animal
{

public:
    Dragonfly(std::string name)
        : Animal(name)
    {
    }

    virtual const char* speak() // this class is no longer abstract because we defined this function
    {
        return Animal::speak(); // use Animal's default implementation
    }
};

int main()
{
    Cow cow("Betsy");
    std::cout << cow.getName() << " says " << cow.speak() << '\n';

    Dragonfly dfly("Sally");
    std::cout << dfly.getName() << " says " << dfly.speak() << '\n';

    return 0;
}
