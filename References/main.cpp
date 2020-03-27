#include <iostream>

// ref is a reference to the argument passed in, not a copy
void changeN(int &ref)
{
    ref = 6;
}

struct Something
{
    int value1;
    float value2;
};

struct Other
{
    Something something;
    int otherValue;
};


void printIt(const int &x)
{
    std::cout << x;
}

int main()
{
    int a = 1;
    printIt(a); // non-const l-value

    const int b = 2;
    printIt(b); // const l-value

    printIt(3); // literal r-value

    printIt(2+b); // expression r-value

int value{ 5 };
int *const ptr{ &value };
int &ref{ value };
//*ptr and ref evaluate identically. As a result, the following two statements produce the same effect:

*ptr = 5;
ref = 5;



    Other other;

    int &ref{ other.something.value1 };
// ref can now be used in place of other.something.value1
//The following two statements are thus identical:

    other.something.value1 = 5;
    ref = 5;

    int n{ 5 };

    std::cout << n << '\n';

    changeN(n); // note that this argument does not need to be a reference

    std::cout << n << '\n';
    int value{ 5 }; // normal integer
    int &ref{ value }; // reference to variable value

    value = 6; // value is now 6
    ref = 7; // value is now 7

    std::cout << value << '\n'; // prints 7
    ++ref;
    std::cout << value << '\n'; // prints 8
    std::cout << ref << '\n'; // prints 8
    std::cout << &value << '\n'; // prints 8
    std::cout << &ref << '\n'; // prints 8


    return 0;
}
