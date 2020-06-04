#include <iostream>

using namespace std;

int func(int x, int y)
    {
        x = y;
        y = y+x;
        return x;
    }

int foo(int y)
{
    int x=0;
    return func(x, y);
}



int main()
{

    for(int i = 0; i<10; i++)
    {
        if(i%2 == 0)
            cout << foo(i) << ",  " ;

    }
cout << endl;

    return 0;
}
