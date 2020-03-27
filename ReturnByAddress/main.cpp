#include <iostream>

int* allocateArray(int size)
{
    return new int[size];
}

int main()
{
    int *array = allocateArray(25);

    std::cout << *array;

    // do stuff with array

    delete[] array;
    return 0;
}
