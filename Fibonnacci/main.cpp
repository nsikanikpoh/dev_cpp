#include <iostream>
#include <vector>

using index_t = std::vector<int>::size_type;
// h/t to potterman28wxcv for a variant of this code
int fibonacci(index_t count)
{
	// We'll use a static std::vector to cache calculated results
	static std::vector<int> results{ 0, 1 };

	// If we've already seen this count, then use the cache'd result
	if (count < results.size())
		return results[count];
	else
	{
		// Otherwise calculate the new result and add it
		results.push_back(fibonacci(count - 1) + fibonacci(count - 2));
		return results[count];
	}
}

// And a main program to display the first 13 Fibonacci numbers
int main()
{
	for (index_t count = 0; count < 13; ++count)
		std::cout << fibonacci(count) << " ";

	return 0;
}
