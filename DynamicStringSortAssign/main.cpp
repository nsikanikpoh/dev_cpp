#include <iostream>
#include <string>
#include <utility> // for std::swap, if you're not C++11 compatible, #include <algorithm> instead

void sortArray(std::string *array, int length)
{
	// Step through each element of the array
	// (except the last, because by the time we get there, the array will be sorted)
	for (int startIndex = 0; startIndex < length-1; ++startIndex)
	{
		// smallestIndex is the index of the smallest element we've encountered so far.
		int smallestIndex = startIndex;

		// Look for smallest element remaining in the array (starting at startIndex+1)
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			// If the current element is smaller than our previously found smallest
			if (array[currentIndex] < array[smallestIndex])
				// This is the new smallest number for this iteration
				smallestIndex = currentIndex;
		}

		// Swap our start element with our smallest element
		std::swap(array[startIndex], array[smallestIndex]);
	}
}

int main()
{
	std::cout << "How many names would you like to enter? ";
	int length;
	std::cin >> length;

	// Allocate an array to hold the names
	std::string *names = new std::string[length];

	// Ask user to enter all the names
	for (int i = 0; i < length; ++i)
	{
		std::cout << "Enter name #" << i + 1 << ": ";
		std::cin >> names[i];
	}

	// Sort the array
	sortArray(names, length);

	std::cout << "\nHere is your sorted list:\n";
	// Print the sorted array
	for (int i = 0; i < length; ++i)
		std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';

	delete[] names; // don't forget to use array delete
	// we don't need to set names to nullptr/0 here because it's going to go out of scope immediately after this anyway

	return 0;
}
