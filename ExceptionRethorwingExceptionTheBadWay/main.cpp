#include <iostream>


int getIntValueFromDatabase(Database *d, std::string table, std::string key)
{
    assert(d);

    try
    {
        return d->getIntValue(table, key); // throws int exception on failure
    }
    catch (int exception)
    {
        // Write an error to some global logfile
        g_log.logError("doSomethingImportant failed");

        throw exception;
    }
}



int getIntValueFromDatabase(Database *d, std::string table, std::string key)
{
    assert(d);

    try
    {
        return d->getIntValue(table, key); // throws Derived exception on failure
    }
    catch (Base &exception)
    {
        // Write an error to some global logfile
        g_log.logError("doSomethingImportant failed");

        throw exception; // Danger: this throws a Base object, not a Derived object
    }
}


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
            throw b; // the Derived object gets sliced here
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



using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
