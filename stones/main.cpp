#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> stones(int n, int a, int b)
{
    set<int> s;
    n--;
    for(int i=0; i<=n; i++)
        s.insert( i*a + (n-i)*b );
    return vector<int>(s.begin(),s.end());
}

int main()
{
    auto res1 = stones(3,1,2);
    for(int &i: res1)
        cout << i << endl;
    auto res11 = stones(4,10,100);
    for(int &i: res11)
     cout << i << endl;
    return 0;
}
