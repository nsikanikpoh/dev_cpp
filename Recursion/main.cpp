#include <iostream>

using namespace std;

int recursiveFactorial(int n)// recursive factorial function
{
    if (n == 0)
        return 1;// basis case
    else
        return n * recursiveFactorial(n-1);// recursive case
}

int main()
{
    cout << recursiveFactorial(7) << endl;
    cout << recursiveFactorial(6) << endl;
    cout << recursiveFactorial(5) << endl;
    cout << recursiveFactorial(4) << endl;
    return 0;
}
