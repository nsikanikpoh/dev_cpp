#include <iostream>
#include "constants.h"
// returns true if x and y are equal, false otherwise
bool isEqual(int x, int y)
{
    return (x == y); // operator== returns true if x equals y, and false otherwise
}

bool isPrime(int x)
{
    if (x == 2) // if user entered 2, the number is prime
        return true;
    else if (x == 3) // if user entered 3, the number is prime
        return true;
    else if (x == 5) // if user entered 5, the number is prime
        return true;
    else if (x == 7) // if user entered 7, the number is prime
        return true;
    return false; // if the user did not enter 2, 3, 5, 7, the number must not be prime
}

int main()
{

 std::cout << "Enter a radius: ";
    int radius{};
    std::cin >> radius;

    double circumference { 2 * radius * constants::pi };
    std::cout << "The circumference is: " << circumference;


const double gravity { 9.8 }; // preferred use of const before type

constexpr double gravityx { 9.84 }; // ok, the value of 9.8 can be resolved at compile-time
std::cout << gravity << '\n';
std::cout << gravityx << '\n';

 int xa { 12 };
    std::cout << xa << '\n'; // decimal (by default)
    std::cout << std::hex << xa << '\n'; // hexadecimal
    std::cout << xa << '\n'; // now hexadecimal
    std::cout << std::oct << xa << '\n'; // octal
    std::cout << std::dec << xa << '\n'; // return to decimal
    std::cout << xa << '\n'; // decimal



    int c{ 012 }; // 0 before the number means this is octal
    std::cout << c << '\n';
    int q{ 0xF }; // 0x before the number means this is hexadecimal
    std::cout << q << '\n';

    char ch{ 'a' };
    std::cout << ch << '\n';
    std::cout << static_cast<int>(ch) << '\n';
    std::cout << ch << '\n';


    std::cout << "Input a keyboard character: ";

    char chr{};
    std::cin >> chr;
    std::cout << chr << " has ASCII code " << static_cast<int>(chr) << '\n';

    // Note: The following cin doesn't ask the user for input, it grabs queued input!
    std::cin >> chr; // ch = 'b', "cd" is left queued.
    std::cout << chr << " has ASCII code " << static_cast<int>(chr) << '\n';

    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y {};
    std::cin >> y;

    std::cout << std::boolalpha; // print bools as true or false

    if (isEqual(x, y))
        std::cout << x << " and " << y << " are equal\n";
    else
        std::cout << x << " and " << y << " are not equal\n";


    if (4) // nonsensical, but for the sake of example...
        std::cout << "hi";
    else
        std::cout << "bye";

    std::cout << "Enter an integer: ";
    int w {};
    std::cin >> w;

    if (isPrime(w))
        std::cout << w << " is a prime number\n";
    else
        std::cout << w<< " is not a prime number\n";

    char ch1{ 'a' }; // (preferred)
    std::cout << ch1; // cout prints a character

    char ch2{ 98 }; // code point for 'b' (not preferred)
    std::cout << ch2; // cout prints a character


    return 0;
}
