#include <iostream>

// x is our number to test
// pow is a power of 2 (e.g. 128, 64, 32, etc...)
int printandDecrementBit(int x, int pow)
{
    // Test whether our x is greater than some power of 2 and print the bit
    if (x >= pow)
    {
        std::cout << "1";
        // If x is greater than our power of 2, subtract the power of 2
        return x - pow;
    }
    else
    {
        std::cout << "0";
        return x;
    }
}

int main()
{
    std::cout << "Enter an integer between 0 and 255: ";
    int x;
    std::cin >> x;

    x = printandDecrementBit(x, 128);
    x = printandDecrementBit(x, 64);
    x = printandDecrementBit(x, 32);
    x = printandDecrementBit(x, 16);

    std::cout << " ";

    x = printandDecrementBit(x, 8);
    x = printandDecrementBit(x, 4);
    x = printandDecrementBit(x, 2);
    x = printandDecrementBit(x, 1);

    return 0;
}
