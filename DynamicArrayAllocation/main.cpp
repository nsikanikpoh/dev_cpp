#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter a positive integer: ";
    int length;
    std::cin >> length;

    int *array = new int[length]; // use array new.  Note that length does not need to be constant!

    std::cout << "I just allocated an array of integers of length " << length << '\n';

    array[0] = 5; // set element 0 to value 5

    delete[] array; // use array delete to deallocate array

    int *dynamicArray2 = new int[3] {1, 2, 3};

    char *arrayc = new char[14];
    std::string *starr = new std::string[12] {"sly", "keleb", "joyous"};
    std::cout << "int array: " << dynamicArray2 << '\n';
    std::cout << "char array: " << arrayc << '\n';
    std::cout << "string array: " << *starr << '\n';

    // we don't need to set array to nullptr/0 here because it's going to go out of scope immediately after this anyway

    return 0;
}


