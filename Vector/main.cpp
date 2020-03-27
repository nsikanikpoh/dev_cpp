#include <vector>
#include <iostream>

int main()
{
    std::vector<int> array { 0, 1, 2 };
    array[0] = 3; // no bounds checking
    array.at(1) = 5; // does bounds checking
    array.resize(5); // set size to 5

    std::cout << "The length is: " << array.size() << '\n';

    for (auto const &element: array)
        std::cout << element << ' ';
    std::cout << '\n';

    array.resize(3); // set length to 3

    std::cout << "The length is: " << array.size() << '\n';

    for (auto const &element: array)
        std::cout << element << ' ';

    std::vector<bool> array5 { true, false, false, true, true };
    std::cout << "The length is: " << array.size() << '\n';

    for (auto const &element: array5)
        std::cout << element << ' ';

    return 0;
}
