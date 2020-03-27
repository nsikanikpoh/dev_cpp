#include <iostream>

int main()
{
    int value = 7;
    int *ptr = &value;

    std::cout << ptr << '\n';
    std::cout << ptr+1 << '\n';
    std::cout << ptr+2 << '\n';
    std::cout << ptr+3 << '\n';


    int array[] = { 9, 7, 5, 3, 1 };

    std::cout << "Element 0 is at address: " << &array[0] << '\n';
    std::cout << "Element 1 is at address: " << &array[1] << '\n';
    std::cout << "Element 2 is at address: " << &array[2] << '\n';
    std::cout << "Element 3 is at address: " << &array[3] << '\n';

    std::cout << &array[1] << '\n'; // print memory address of array element 1
    std::cout << array+1 << '\n'; // print memory address of array pointer + 1
    std::cout << array << '\n'; // print memory address of array pointer + 1

    std::cout << array[1] << '\n'; // prints 7
    std::cout << *(array+1) << '\n'; // prints 7 (note the parenthesis required here)



    const int arrayLength = 7;
    char name[arrayLength] = "Mollie";
    int numVowels(0);
    for (char *ptr = name; ptr < name + arrayLength; ++ptr)
    {
        switch (*ptr)
        {
        case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
            ++numVowels;
        }
    }

    std::cout << name << " has " << numVowels << " vowels.\n";

    int nArray[5] { 9, 7, 5, 3, 1 };
    char cArray[] { "Hello!" };
    const char *namewe{ "Alex" };

    std::cout << nArray << '\n'; // nArray will decay to type int*
    std::cout << cArray << '\n'; // cArray will decay to type char*
    std::cout << namewe << '\n'; // name is already type char*


    char c{ 'Q' };
    std::cout << &c;


    return 0;
}
