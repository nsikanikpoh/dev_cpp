#include <iostream>

// parameter ptr contains a copy of the array's address
void changeArray(int *ptr)
{
    *ptr = 5; // so changing an array element changes the _actual_ array
}

int main()
{
    int array[] = { 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << "Element 0 has value: " << array[0] << '\n';

    changeArray(array);

    std::cout << "Element 0 has value: " << array[0] << '\n';

// dereferencing an array returns the first element (element 0)
    std::cout << *array << '\n'; // will print 9!

    char name[] = "Jason"; // C-style string (also an array)
    std::cout << *name << '\n'; // will print 'J'

    // print address of the array's first element
    std::cout << "Element 0 has address: " << &array[0] << '\n';

    // print the value of the pointer the array decays to
    std::cout << "The array decays to a pointer holding address: " << array << '\n';


    return 0;
}
