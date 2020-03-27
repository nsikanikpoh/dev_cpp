#include <iostream>

int main()
{
    // Declare a 10x10 array
    const int numRows = 10;
    const int numCols = 10;
    int product[numRows][numCols] = { 0 };

    // Calculate a multiplication table
    for (int row = 1; row < numRows; ++row)
        for (int col = 1; col < numCols; ++col)
            product[row][col] = row * col;

    // Print the table
    for (int row = 1; row < numRows; ++row)
    {
        for (int col = 1; col < numCols; ++col)
            std::cout << product[row][col] << "\t";

        std::cout << '\n';
    }

    return 0;
}
