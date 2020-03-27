#include <iostream>
#include <cmath> // for sqrt()

void printSqrt(double value)
{
    if (value >= 0.0)
        std::cout << "The square root of " << value << " is " << sqrt(value) << "\n";
    else
        std::cout << "Error: " << value << " is negative\n";
}

int main()
{
    std::cout << "Enter a number: ";
    int x;
    std::cin >> x;

    if (x >= 10)
    {
        if (x <= 20)
            std::cout << x << "is between 10 and 20\n";
    }
    else // attached to outer if statement
        std::cout << x << "is less than 10\n";

    return 0;
}
