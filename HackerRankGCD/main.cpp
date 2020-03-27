#include <iostream>

//Chinese Remainder Theorem
int computeGcd(int n, int m)
{
    if(m == 0)
        return n;
    int result;
    result = n%m;
    computeGcd(m, result);
}


int main()
{
    std::cout << computeGcd(80844, 25320) << '\n';
    return 0;
}
