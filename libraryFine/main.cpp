#include <iostream>

using namespace std;

int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2)
{

    if (y1>y2)
        return 10000;
    else if (y2==y1 && m1>m2)
        return 500*(m1-m2);
    else if (y2==y1 && m2==m1 && d1>d2)
        return 15*(d1-d2);
    else
         return 0;
}

int main()
{
    cout << libraryFine(9,6,2015, 6,6,2015)<< endl;
    return 0;
}
