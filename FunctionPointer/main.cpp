#include <iostream>

int foo() // code starts at memory address 0x002717f0
{
    return 5;
}

int goo()
{
    return 6;
}

int main()
{
    int (*fcnPtr)() = foo; // fcnPtr points to function foo
    fcnPtr = goo; // fcnPtr now points to function goo


  //  To make a const function pointer, the const goes after the asterisk:
//int (*const fcnPtr)();

std::cout << reinterpret_cast<void*>(fcnPtr) << '\n';
  std::cout << reinterpret_cast<void*>(foo); // Tell C++ to interpret function foo as a void pointer

    return 0;
}
