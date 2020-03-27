#include <iostream>

int sumTo(int num)
{
    int sum {0};
    for(int counter = 1; counter <= num; ++counter)
      sum += counter;
    return sum;
}

int main()
{
    for(int num = 2; num <= 20; num+=2)
        std::cout << num << '\n';

    std::cout << sumTo(5) << '\n';

    return 0;
}
