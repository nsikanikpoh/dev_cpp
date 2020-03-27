#include <iostream>

void foo(int *&ptr) // pass pointer by reference
{
	ptr = nullptr; // this changes the actual ptr argument passed in, not a copy
}

int main()
{
	int x = 5;
	int *ptr = &x;
	std::cout << "ptr is: " << (ptr ? "non-null" : "null") << '\n'; // prints non-null
	foo(ptr);
	std::cout << "ptr is: " << (ptr ? "non-null" : "null") << '\n'; // prints null

	return 0;
}
