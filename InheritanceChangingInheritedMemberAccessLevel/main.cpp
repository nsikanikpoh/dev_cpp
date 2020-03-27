#include <iostream>

class Base
{
private:
    int m_value;

public:
    Base(int value)
        : m_value(value)
    {
    }

protected:
    void printValue() { std::cout << m_value; }
};


class Derived: public Base
{
public:
    Derived(int value)
        : Base(value)
    {
    }

    // Base::printValue was inherited as protected, so the public has no access
    // But we're changing it to public via a using declaration
    using Base::printValue; // note: no parenthesis here
};


int main()
{
    Derived derived(7);

    // printValue is public in Derived, so this is okay
    derived.printValue(); // prints 7
    return 0;
}
