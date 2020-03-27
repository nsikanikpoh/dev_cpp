#include <iostream>
#include <vector>
#include <functional> // for std::reference_wrapper

class Base
{
protected:
    int m_value{};

public:
    Base(int value)
        : m_value{ value }
    {
    }

    virtual const char* getName() const
    {
        return "Base";
    }
    int getValue() const
    {
        return m_value;
    }
};

class Derived: public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }

    virtual const char* getName() const
    {
        return "Derived";
    }
};

int main()
{
	std::vector<std::reference_wrapper<Base> > v{}; // our vector is a vector of std::reference_wrapper wrapped Base (not Base&)
	Base b{ 5 }; // b and d can't be anonymous objects
	Derived d{ 6 };
	v.push_back(b); // add a Base object to our vector
	v.push_back(d); // add a Derived object to our vector

	// Print out all of the elements in our vector
	for (const auto& element : v)
		std::cout << "I am a " << element.get().getName() << " with value " << element.get().getValue() << "\n"; // we use .get() to get our element from the wrapper


	return 0;

}
