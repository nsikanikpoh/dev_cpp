#include <iostream>
#include <vector>

using namespace std;

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c, int k)
{
    int e=100;
    int x=0;

    while(1)
    {
        e--;
        if(c[x]==1)
            e-=2;

        x+=k;
        if(x==c.size())
            x=0;

        else if(x>c.size())
            x=x % c.size();

        if(x==0)
            break;

    }
    return e;
}

int main()
{
    vector<int> v{0, 0, 1, 0, 0, 1, 1, 0};
    vector<int> b{1, 1, 1, 0, 1, 1, 0, 0, 0, 0};
    cout << jumpingOnClouds(v, 2) << endl;
    cout << jumpingOnClouds(b, 3) << endl;
    return 0;
}
