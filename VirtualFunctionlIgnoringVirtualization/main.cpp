#include <iostream>

class Base
{
public:
    virtual const char* getName() { return "Base"; }
};

class Derived: public Base
{
public:
    virtual const char* getName() { return "Derived"; }
};

int main()
{
    Derived derived;
    Base &base { derived };
    // Calls Base::GetName() instead of the virtualized Derived::GetName()
    std::cout << base.Base::getName() << '\n';

    return 0;
}
