#include <bits/stdc++.h>

using namespace std;



// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c) {
    int jumps = 0;
    if(c.size() == 0)
        return jumps;
    for( int i=0 ; i<c.size()-1 ; i++)
    {
        if(c[i]==1)
            continue;

        else if(c[i+1]==0 && c[i+2]==0)
            i=i+1;
        jumps++;
    }
    return jumps;

}

int main()
{
 vector<int> arr{0, 0, 1, 0, 0, 1, 0};
    int result = jumpingOnClouds(arr);
    cout << "result: " << result << '\n';
    return 0;
}
