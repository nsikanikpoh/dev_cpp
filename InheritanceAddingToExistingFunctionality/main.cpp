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
    friend std::ostream& operator<< (std::ostream &out, const Base &b)
	{
		out << "In Base\n";
		out << b.m_value << '\n';
		return out;
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
        Base::identify(); // call Base::identify() first
        std::cout << "I am a Derived\n";
    }

    void print()
	{
		std::cout << "Derived ";
	}

	friend std::ostream& operator<< (std::ostream &out, const Derived &d)
	{
		out << "In Derived\n";
		// static_cast Derived to a Base object, so we call the right version of operator<<
		out << static_cast<Base>(d);
		return out;
	}
};
int main()
{
    Base base(5);
    base.identify();

    Derived derived(7);
    derived.identify();
    derived.print(); // calls derived::print(), which is public
    std::cout << derived;

    return 0;
}


