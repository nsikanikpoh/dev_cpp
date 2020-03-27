#include <iostream>

// returns the value nBase ^ nExp
int pow(int base, int exponent)
{
    int total = 1;

    for (int count=0; count < exponent; ++count)
        total *= base;

    return total;
}

int main()
{

    std::cout << pow(2,5) << std::endl;


    for (int count = 9; count >= 0; count -= 2)
        std::cout << count << " ";
    std::cout  << "\n";

    for (int iii=0, jjj=9; iii < 10; ++iii, --jjj)
        std::cout << iii << " " << jjj << '\n';

    for (char c = 'a'; c <= 'e'; ++c) // outer loop on letters
	{
		std::cout << c; // print our letter first

		for (int i = 0; i < 3; ++i) // inner loop on all numbers
			std::cout << i;

		std::cout << '\n';
	}

    return 0;
}
