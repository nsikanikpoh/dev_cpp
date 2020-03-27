#include <iostream>

class Base
{
protected:
	int m_value;

public:
	Base(int value)
		: m_value(value)
	{
	}
	virtual ~Base(){}

	virtual const char* getName() { return "Base"; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base(value)
	{
	}
	virtual ~Derived(){}

	virtual const char* getName() { return "Derived"; }
};

int main()
{
	Derived *d = new Derived(5);
	Base *b = d;
	std::cout << b->getName();
	delete b;

	return 0;
}
