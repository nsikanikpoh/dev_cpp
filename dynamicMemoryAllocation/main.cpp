#include <iostream>


int main()
{
    int *ptr1 = new int (5); // use direct initialization
    int *ptr2 = new int { 6 }; // use uniform initialization
    std::cout << ptr1 << '\t' << *ptr1 << '\n';
    std::cout << ptr2 << '\t' << *ptr2 << '\n';

    // assume ptr has previously been allocated with operator new
    delete ptr1; // return the memory pointed to by ptr to the operating system
    ptr1 = nullptr; // set ptr to be a null pointer (use nullptr instead of 0 in C++11)
    std::cout << ptr2 << '\t' << *ptr2 << '\n';

    int *value = new (std::nothrow) int; // ask for an integer's worth of memory
    if (!value) // handle case where new returned null
    {
        // Do error handling here
        std::cout << "Could not allocate memory";
    }

    int valuee = 5;
    int *ptre = new int; // allocate memory
    delete ptre; // return memory back to operating system
    ptre = &valuee; // reassign pointer to address of value

    return 0;
}
