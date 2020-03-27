#include <iostream>

struct Something
{
    int nX, nY, nZ;
};


int main()
{

    char *chPtr; // chars are 1 byte
    int *iPtr; // ints are usually 4 bytes

    Something *somethingPtr; // Something is probably 12 bytes

    std::cout << sizeof(chPtr) << '\n'; // prints 4
    std::cout << sizeof(iPtr) << '\n'; // prints 4
    std::cout << sizeof(somethingPtr) << '\n'; // prints 4


    int x = 5;
    std::cout << x << '\n'; // print the value of variable x
    std::cout << &x << '\n'; // print the memory address of variable x
    std::cout << *(&x) << '\n'; /// print the value at the memory address of variable x (parenthesis not required, but make it easier to read)

    int *ptr = &x; // initialize ptr with address of variable v


    std::cout << ptr << '\n'; // print the address that ptr is holding

    std::cout << typeid(&x).name();

    int value = 5;
    std::cout << &value << '\n';  // prints address of value
    std::cout << value << '\n';  // prints contents of value

    int *ptr2 = &value; // ptr points to value
    std::cout << ptr2 << '\n';  // prints address held in ptr, which is &value
    std::cout << *ptr2 << '\n'; // dereference ptr (get the value that ptr is pointing to)


    int value1 = 5;
    int value2 = 7;

    int *ptr3;

    ptr3 = &value1; // ptr points to value1
    std::cout << *ptr3 << '\n';  // prints 5

    ptr3 = &value2; // ptr now points to value2
    std::cout << *ptr3 << '\n';  // prints 7

    int value3 = 5;
    int *ptr4 = &value3; // ptr points to value

    *ptr4 = 7; // *ptr is the same as value, which is assigned 7
    std::cout << value3 << '\n';   // prints 7


    return 0;
}
