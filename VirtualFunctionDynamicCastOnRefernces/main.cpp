#include <iostream>
#include <string>

class Base
{
protected:
	int m_value;

public:
	Base(int value)
		: m_value(value)
	{
	}

	virtual ~Base() {}
};

class Derived : public Base
{
protected:
	std::string m_name;

public:
	Derived(int value, std::string name)
		: Base(value), m_name(name)
	{
	}

	const std::string& getName() { return m_name; }
};

//Because C++ does not have a “null reference”, dynamic_cast can’t return a null reference
// upon failure. Instead, if the dynamic_cast of a reference fails, an exception of
//type std::bad_cast is thrown. We talk about exceptions later in this tutorial.

int main()
{
	Derived apple(1, "Apple"); // create an apple
	Base &b = apple; // set base reference to object
	Derived &d = dynamic_cast<Derived&>(b); // dynamic cast using a reference instead of a pointer

	std::cout << "The name of the Derived is: " << d.getName() << '\n'; // we can access Derived::getName through d

	return 0;
}
