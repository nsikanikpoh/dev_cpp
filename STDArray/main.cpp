#include <iostream>
#include <array>
#include <algorithm> // for std::sort

void printLength(const std::array<double, 5> &myArray)
{
    std::cout << "length: " << myArray.size() << '\n';
}

int main()
{
    std::array<double, 5> myArray3 { 9.0, 7.2, 5.4, 3.6, 1.8 };

    printLength(myArray3);

    std::array<int, 5> myArray { 7, 3, 1, 9, 5 };
    myArray.at(1) = 6;
    myArray[2] = 8;
    std::sort(myArray.begin(), myArray.end()); // sort the array forwards
//    std::sort(myArray.rbegin(), myArray.rend()); // sort the array backwards

    for (const auto &element : myArray)
        std::cout << element << ' ';
    std::cout << '\n';

    using index_t = std::array<int, 5>::size_type;

    for (index_t i{ 0 }; i < myArray.size(); ++i)
        std::cout << myArray[i] << ' ';

    return 0;
}
