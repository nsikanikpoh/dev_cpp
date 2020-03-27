#include <iostream>
#include <random> // for std::mt19937
#include <ctime> // for std::time

int main()
{

/*
You’ll note that Mersenne Twister generates random 32-bit unsigned integers (not 15-bit integers like std::rand()),
giving a lot more range. There’s also a version (std::mt19937_64) for generating 64-bit unsigned integers.
	// Create a reusable random number generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution<> die{ 1, 6 };
*/
// Initialize our mersenne twister with a random seed based on the clock
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

	// Create a reusable random number generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution<> die{ 1, 6 };

	// Print a bunch of random numbers
	for (int count{ 1 }; count <= 48; ++count)
	{
		std::cout << die(mersenne) << '\t'; // generate a roll of the die here

		// If we've printed 6 numbers, start a new row
		if (count % 6 == 0)
			std::cout << '\n';
	}

	return 0;
}
