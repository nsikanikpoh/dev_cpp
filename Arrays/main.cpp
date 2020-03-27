#include <iostream>

struct Rectangle
{
    int length;
    int width;
};

enum StudentNames
{
    KENNY, // 0
    KYLE, // 1
    STAN, // 2
    BUTTERS, // 3
    CARTMAN, // 4
    MAX_STUDENTS // 5
};

int main()
{

    int testScores[MAX_STUDENTS]; // allocate 5 integers
    testScores[STAN] = 76;

    std::cout << testScores[STAN] << '\n';

    int array[5] { 7, 4, 5 }; // only initialize first 3 elements

    std::cout << array << '\n';
    std::cout << array[0] << '\n';

    std::cout << array[1] << '\n';
    std::cout << array[2] << '\n';
    std::cout << array[3] << '\n';
    std::cout << array[4] << '\n';


    Rectangle rects[5]; // declare an array of 5 Rectangle
    rects[0].length = 24;
    std::cout << rects[0].length << '\n';
    double array1[3]; // allocate 3 doubles
    array1[0] = 2.0;
    array1[1] = 3.0;
    array1[2] = 4.3;

    std::cout << "The average is " << (array1[0] + array1[1] + array1[2]) / 3 << "\n";

    return 0;
}
