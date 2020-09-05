#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Complete the fairRations function below.
int fairRations(vector<int> B) {
    int total=0;
    for(int i=0 ; i<B.size()-1 ; i++)
    {
        if(B[i]%2 == 1)
        {
            B[i]++ ;
            B[i+1]++ ;
            total += 2 ;
        }
    }
    if(B[B.size() - 1]%2 != 0)
        return -1 ;
    return total ;
}


int main()
{
    vector<int> b{2,3,4,5,6};
    //vector<int> b{1,2};
    cout << fairRations(b) << endl;
    return 0;
}

