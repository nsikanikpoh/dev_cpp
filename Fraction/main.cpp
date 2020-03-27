#include <iostream>

struct Fraction
{
    int numerator;
    int denominator;
};

Fraction getFraction()
{
    Fraction temp;
    std::cout << "Enter a value for numerator: ";
    std::cin >> temp.numerator;
    std::cout << "Enter a value for denominator: ";
    std::cin >> temp.denominator;
    std::cout << "\n";
    return temp;
}

void multiply(Fraction f1, Fraction f2)
{
    // Don't forget the static cast, otherwise the compiler will do integer division!
    std::cout << static_cast<double>(f1.numerator) * f2.numerator /
        (f1.denominator * f2.denominator);
}

int main()
{
    // Allocate our first fraction
    Fraction f1{ getFraction() };
    Fraction f2{ getFraction() };

    multiply(f1, f2);

    return 0;
}
