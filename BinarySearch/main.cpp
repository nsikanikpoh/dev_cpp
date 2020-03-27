#include <iostream>
#include <cassert>
// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is found, -1 otherwise
int binarySearch(int *array, int target, int min, int max)
{
    assert(array);

    while (min <= max)
    {
        // implement this iteratively
        int midpoint{ min + ((max-min) / 2) }; // this way of calculating midpoint avoids overflow

        if (array[midpoint] > target)
        {
            // if array[midpoint] > target, then we know the number must be in the lower half of the array
            // we can use midpoint - 1 as the upper index, since we don't need to retest the midpoint next iteration
            max = midpoint - 1;
        }
        else if (array[midpoint] < target)
        {
            // if array[midpoint] < target, then we know the number must be in the upper half of the array
            // we can use midpoint + 1 as the lower index, since we don't need to retest the midpoint next iteration
            min = midpoint + 1;
        }
        else
            return midpoint;
    }


    return -1;

}


// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is found, -1 otherwise
int binarySearchRecurssive(int *array, int target, int min, int max)
{
        assert(array); // make sure array exists

	// implement this recursively

	if (min > max)
		return -1;

	int midpoint{ min + ((max-min) / 2) }; // this way of calculating midpoint avoids overflow

	if (array[midpoint] > target)
	{
		return binarySearch(array, target, min, midpoint - 1);
	}
	else if (array[midpoint] < target)
	{
		return binarySearch(array, target, midpoint + 1, max);
	}
	else
		return midpoint;
}



int main()
{
     int array[] { 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

    // We're going to test a bunch of values to see if they produce the expected results
    int numTestValues{ 9 };
    // Here are the test values
     int testValues[9] { 0, 3, 12, 13, 22, 26, 43, 44, 49 };
    // And here are the expected results for each value
    int expectedValues[9] { -1, 0, 3, -1, -1, 8, -1, 13, -1 };

    // Loop through all of the test values
    for (int count{ 0 }; count < numTestValues; ++count)
    {
        // See if our test value is in the array
        int index{ binarySearchRecurssive(array, testValues[count], 0, 14) };
        // If it matches our expected value, then great!
        if (index == expectedValues[count])
            std::cout << "test value " << testValues[count] << " passed!\n";
        else // otherwise, our binarySearch() function must be broken
            std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
    }

    return 0;
}
