#include <iostream>
class Base
{
public:
    Base() {}
    virtual void print() { std::cout << "Base"; }
};

class Derived: public Base
{
public:
    Derived() {}
    virtual void print() { std::cout << "Derived"; }
};


//When rethrowing the same exception, use the throw keyword by itself.
int main()
{
    try
    {
        try
        {
            throw Derived();
        }
        catch (Base& b)
        {
            std::cout << "Caught Base b, which is actually a ";
            b.print();
            std::cout << "\n";
            throw; // note: We're now rethrowing the object here
        }
    }
    catch (Base& b)
    {
        std::cout << "Caught Base b, which is actually a ";
        b.print();
        std::cout << "\n";
    }

    return 0;
}
