#include <iostream>
#include <iterator>
namespace Animals
{
enum Animals // The name of this enum could be omitted since it isn't used anywhere
{
    CHICKEN,
    DOG,
    CAT,
    ELEPHANT,
    DUCK,
    SNAKE,
    MAX_ANIMALS
};
}

namespace StudentNames
{
enum StudentNames
{
    KENNY, // 0
    KYLE, // 1
    STAN, // 2
    BUTTERS, // 3
    CARTMAN, // 4
    WENDY, // 5
    MAX_STUDENTS // 6
};
}

int main()
{


    int scores[] = { 84, 92, 76, 81, 56 };
    const int numStudents = std::size(scores); // requires C++17 and <iterator> header
//    const int numStudents = sizeof(scores) / sizeof(scores[0]); // use this instead if not C++17 capable
    int totalScore = 0;
    int maxElIndex{0};
    int maxScore = 0; // keep track of our largest score
// use a loop to calculate totalScore
    for (int student = 0; student < numStudents; ++student)
    {
        totalScore += scores[student];
        if (scores[student] > maxScore)
        {

            maxScore = scores[student];
            maxElIndex = student;
        }
    }

    double averageScore = static_cast<double>(totalScore) / numStudents;
    std::cout << "The best score was " << maxScore << '\n';
    std::cout << "The best score Index was " << maxElIndex << '\n';
    std::cout << "The average score is " << averageScore << '\n';



    int legs[Animals::MAX_ANIMALS] = { 2, 4, 4, 4, 2, 0 };

    std::cout << "An elephant has " << legs[Animals::ELEPHANT] << " legs.\n";

    int testScores[StudentNames::MAX_STUDENTS]; // allocate 6 integers
    testScores[StudentNames::STAN] = 76;
    std::cout << testScores[StudentNames::STAN] << '\n' ;

    int array[] = { 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << "The array has: " << std::size(array) << " elements\n";

    return 0;
}
