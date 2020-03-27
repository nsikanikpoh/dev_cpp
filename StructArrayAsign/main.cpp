#include <iostream>
#include <string>
#include <algorithm>

struct Student
{
 int grade;
 std::string name;
};


// Function to sort our students.
// Since students is a pointer to an array and doesn't know its length, we need to pass in the length explicitly
void sortNames(Student *students, int length)
{
	// Step through each element of the array
	for (int startIndex = 0; startIndex < length; ++startIndex)
	{
		// largestIndex is the index of the largest element we've encountered so far.
		int largestIndex = startIndex;

		// Look for largest element in the remaining array (starting at startIndex+1)
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			// If the current element is larger than our previously found smallest
			if (students[currentIndex].grade > students[largestIndex].grade)
				// This is the new largest number for this iteration
				largestIndex = currentIndex;
		}

		// Swap our start element with our largest element
		std::swap(students[startIndex], students[largestIndex]);
	}
}


int main()
{
    std::cout << "How many student to enter grades for? : \n";
    int length;
    std::cin >> length;

    Student *studentArray = new Student[length];

    for(int index = 0; index<length; ++index)
    {
     std::cout << "Enter student name:  \n";
     std::cin >> studentArray[index].name;

     std::cout << "Enter student grade:  \n";
     std::cin >> studentArray[index].grade;
    }

    // Sort the names
	sortNames(studentArray, length);

    for(int index = 0; index<length; ++index)
     std::cout << studentArray[index].name << " got a grade of " << studentArray[index].grade << '\n';
    return 0;
}
