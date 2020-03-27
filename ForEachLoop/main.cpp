#include <iostream>
#include <vector>

int main()
{


    std::vector<int> fibonacci7 = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 }; // note use of std::vector here rather than a fixed array
    for (const auto &number : fibonacci7)
        std::cout << number << ' ';




    const int numStudents = 5;
    int scores[numStudents] = { 84, 92, 76, 81, 56 };
    int maxScore = 0; // keep track of our largest score
    for (const auto &score: scores) // iterate over array scores, assigning each value in turn to variable score
        if (score > maxScore)
            maxScore = score;

    std::cout << "The best score was " << maxScore << '\n';
    std::cout << '\n';


    int fibonacci[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
    for (int number : fibonacci) // iterate over array fibonacci
        std::cout << number << ' '; // we access the array element for this iteration through variable number
    std::cout << '\n';
    for (auto number : fibonacci) // type is auto, so number has its type deduced from the fibonacci array
        std::cout << number << ' ';
    std::cout << '\n';

    int array[5] = { 9, 7, 5, 3, 1 };
    for (auto &element: array) // The ampersand makes element a reference to the actual array element, preventing a copy from being made
        std::cout << element << ' ';

    std::cout << '\n';
    for (const auto &element: array) // element is a const reference to the currently iterated array element
        std::cout << element << ' ';



    return 0;
}
