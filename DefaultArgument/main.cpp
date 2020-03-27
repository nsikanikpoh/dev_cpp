#include <iostream>
#include "addition.h"

void printValues(int x, int y)
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}

int main()
{
    printValues(5);

    return 0;
}
