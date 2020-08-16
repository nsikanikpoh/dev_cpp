#include <iostream>
#include <string>
#include <vector>
#include <numeric>

const int mod = 1000000007;

using namespace std;

// Complete the substrings function below.
long substrings(string s) {
    long n = s.length();
    long sod[n];
    sod[0] = s[0]-'0';
    long res = sod[0];
    for(long i=1; i<n; i++)
    {
        sod[i] = ((i+1) * (s[i]-'0') + 10 * sod[i-1])%mod;
        res = (res+sod[i])%mod;
    }
    return res;
}

int main()
{
    cout << substrings("123") << endl;
    cout << substrings("16") << endl;
    cout << substrings("42") << endl;
    return 0;
}
