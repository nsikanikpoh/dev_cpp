#include <iostream>
#include <array>
#include <chrono> // for std::chrono functions
#include <algorithm> // for std::sort

const int g_arrayElements = 10000;

class Timer
{
private:
	// Type aliases to make accessing nested type easier
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

void sortArray(std::array<int, g_arrayElements> &array)
{

	// Step through each element of the array
	// (except the last one, which will already be sorted by the time we get there)
	for (long unsigned int  startIndex = 0; startIndex < g_arrayElements - 1; ++startIndex)
	{
		// smallestIndex is the index of the smallest element we’ve encountered this iteration
		// Start by assuming the smallest element is the first element of this iteration
		long unsigned int  smallestIndex = startIndex;

		// Then look for a smaller element in the rest of the array
		for (long unsigned int  currentIndex = startIndex + 1; currentIndex < g_arrayElements; ++currentIndex)
		{
			// If we've found an element that is smaller than our previously found smallest
			if (array[currentIndex] < array[smallestIndex])
				// then keep track of it
				smallestIndex = currentIndex;
		}

		// smallestIndex is now the smallest element in the remaining array
		// swap our start element with our smallest element (this sorts it into the correct place)
		std::swap(array[startIndex], array[smallestIndex]);
	}
}

int main()
{
	std::array<int, g_arrayElements> array;
	for (long unsigned int  i = 0; i < g_arrayElements; ++i)
		array[i] = g_arrayElements - i;

	Timer t;

	std::sort(array.begin(), array.end());

	std::cout << "Time taken: " << t.elapsed() << " seconds\n";

	return 0;
}
