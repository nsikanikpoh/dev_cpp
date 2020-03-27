#include <algorithm> // for std::sort
#include <iostream>

int main()
{
	const int length = 5;
	int array[length] = { 30, 50, 20, 10, 40 };

	std::sort(std::begin(array), std::end(array));

	for (int i=0; i < length; ++i) // better to use std::size or std::ssize here if your compiler supports them
		std::cout << array[i] << ' ';

	return 0;
}
