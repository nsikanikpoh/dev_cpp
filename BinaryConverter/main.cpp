#include <iostream>

void printUBinary(unsigned int n)
{
	if (n > 1) // we only recurse if n > 1, so this is our termination case for n == 0
		printUBinary(n / 2);

	std::cout << n % 2;
}

int main()
{
	unsigned int x;
	std::cout << "Enter a integer: ";
	std::cin >> x;

	printUBinary(x);
	std::cout << "\n";
    std::cout << "********************\n";
	unsigned int y;
	std::cout << "Enter a integer: ";
	std::cin >> y;

	printUBinary(y);

	return 0;
}
