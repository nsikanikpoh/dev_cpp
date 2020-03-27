#include <iostream>

void print(int x)
{
    std::cout << "print(int): " << x << '\n';
}

void print(int *x)
{
    if (!x)
        std::cout << "print(int*): null\n";
    else
        std::cout << "print(int*): " << *x << '\n';
}

int main()
{
    int *x { nullptr };
    print(x); // calls print(int*)

    print(nullptr); // calls print(int*) as desired


    double *ptr { nullptr }; // note: ptr is still an integer pointer, just set to a null value

// pointers convert to boolean false if they are null, and boolean true if they are non-null
    if (ptr)
        std::cout << "ptr is pointing to a double value.";
    else
        std::cout << "ptr is a null pointer.";

    return 0;
}
