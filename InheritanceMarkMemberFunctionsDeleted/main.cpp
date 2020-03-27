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

	int getValue() { return m_value; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base(value)
	{
	}


	int getValue() = delete; // mark this function as inaccessible
};

int main()
{
	Derived derived(7);

	// We can still access the function deleted in the Derived class through the Base class
	std::cout << static_cast<Base>(derived).getValue();



	return 0;
}
