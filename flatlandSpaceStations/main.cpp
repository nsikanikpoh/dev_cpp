#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int flatlandSpaceStations(int n, vector<int> c)
{
    int max1=0;
    for(int i=0; i<n; i++)
    {
        int min2=100000;
        for(int j=0; j<c.size(); j++)
        {
            min2=min(min2,abs(i-c[j]));
        }
        max1 = max(max1,min2);
    }
    return max1;
}

int main()
{
    vector<int> c{0,4};

    cout << flatlandSpaceStations(5, c) << endl;
    return 0;
}
