#include <iostream>
#include <vector>

class Base
{
protected:
    int m_value{};

public:
    Base(int value)
        : m_value{ value }
    {
    }

    virtual const char* getName() const
    {
        return "Base";
    }
    int getValue() const
    {
        return m_value;
    }
};

class Derived: public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }

    virtual const char* getName() const
    {
        return "Derived";
    }
};


void printName(const Base &base) // note: base now passed by reference
{
    std::cout << "I am a " << base.getName() << '\n';
}

int main()
{
    Derived derived{ 5 };
    Base base{ derived }; // what happens here?
    std::cout << "base is a " << base.getName() << " and has value " << base.getValue() << '\n';
    Derived de{ 5 };
    printName(de); // oops, didn't realize this was pass by value on the calling end


    std::vector<Base*> v{};

    Base b{ 5 }; // b and d can't be anonymous objects
    Derived d{ 6 };

    v.push_back(&b); // add a Base object to our vector
    v.push_back(&d); // add a Derived object to our vector

    // Print out all of the elements in our vector
    for (const auto* element : v)
        std::cout << "I am a " << element->getName() << " with value " << element->getValue() << '\n';
    return 0;
}
