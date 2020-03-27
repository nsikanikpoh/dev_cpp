#include <iostream>

int factorial(int num)
{
    if(num <= 1)
     return 1;
    else
     return factorial(num-1)*num;
}

int main()
{
    std::cout << factorial(5)<< std::endl;
    std::cout << factorial(6)<< std::endl;
    return 0;
}
