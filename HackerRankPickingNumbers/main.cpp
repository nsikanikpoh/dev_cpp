#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pickingNumbers(vector<int> a) {

     int z=0;
    int freq[100]={0};
    for(int i=0;i<a.size();i++)
        freq[a[i]]++;

    for(int i=2;i<100;i++)
        z=max(z,freq[i]+freq[i-1]);
    return z;
}


int main()
{
    vector<int> arr = {4,6,5,3,3,1};
   int integer_count = pickingNumbers(arr);

    cout << "Integer Count: " << integer_count << endl;
    return 0;
}
