#include <functional>
#include <iostream>

int foo()
{
    return 5;
}

int goo()
{
    return 6;
}

int main()
{
    std::function<int()> fcnPtr = foo; // declare function pointer that returns an int and takes no parameters
    fcnPtr = goo; // fcnPtr now points to function goo
    std::cout << fcnPtr() << '\n'; // call the function just like normal

    auto fcnPtrg = goo;
	std::cout << fcnPtrg();

    return 0;
}
