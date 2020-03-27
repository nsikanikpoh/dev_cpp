#include <iostream>
class Base
{
public:
    Base() {}
};

class Derived: public Base
{
public:
    Derived() {}
};

//Rule: Handlers for derived exception classes should be listed before those for base classes.
int main()
{
    try
    {
        throw Derived();
    }
    catch (Derived &derived)
    {
        std::cerr << "caught Derived";
    }
    catch (Base &base)
    {
        std::cerr << "caught Base";
    }

    return 0;
}
