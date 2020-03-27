#include <iostream>

void countDown(int count)
{
    std::cout << "push " << count << '\n';

    if (count > 1) // termination condition
        countDown(count-1);

    std::cout << "pop " << count << '\n';
}

// return the sum of all the integers between 1 (inclusive) and sumto (inclusive)
// returns 0 for negative numbers
int sumTo(int sumto)
{
    if (sumto <= 0)
        return 0; // base case (termination condition) when user passed in an unexpected parameter (0 or negative)
    else if (sumto == 1)
        return 1; // normal base case (termination condition)
    else
        return sumTo(sumto - 1) + sumto; // recursive function call
}

int main()
{
    countDown(5);
    std::cout << sumTo(5) << '\n';
    return 0;
}
