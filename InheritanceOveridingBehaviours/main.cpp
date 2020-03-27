#include <iostream>

class Base
{
private:
    void print()
    {
        std::cout << "Base";
    }
protected:
    int m_value;

public:
    Base(int value)
        : m_value(value)
    {
    }

    void identify()
    {
        std::cout << "I am a Base\n";
    }

};

class Derived: public Base
{
public:
    Derived(int value)
        : Base(value)
    {
    }
    int getValue()
    {
        return m_value;
    }

    // Here's our modified function
    void identify()
    {
        std::cout << "I am a Derived\n";
    }

    void print()
	{
		std::cout << "Derived ";
	}
};
int main()
{
    Base base(5);
    base.identify();

    Derived derived(7);
    derived.identify();
    derived.print(); // calls derived::print(), which is public

    return 0;
}


