#include <iostream>

enum class ErrorCode
{
    SUCCESS = 0,
    NEGATIVE_NUMBER = -1
};

ErrorCode doSomething(int value)
{
    // if value is a negative number
    if (value < 0)
       // early return an error code
        return ErrorCode::NEGATIVE_NUMBER;

    // Do whatever here

    return ErrorCode::SUCCESS;
}

int main()
{
    std::cout << "Enter a positive number: ";
    int x;
    std::cin >> x;

    if (doSomething(x) == ErrorCode::NEGATIVE_NUMBER)
    {
        std::cout << "You entered a negative number!\n";
    }
    else
    {
        std::cout << "It worked!\n";
    }

    return 0;
}
