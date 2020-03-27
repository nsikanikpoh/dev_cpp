// C++ program to check if a string can be converted to
// a string that has repeated substrings of length k.
#include<bits/stdc++.h>
using namespace std;

// Returns true if str can be coverted to a string
// with k repeated substrings after replacing k
// characters.
bool checkString(string str, long k)
{
    // Length of string must be a multiple of k
    int n = str.length();
    if (n%k != 0)
        return false;

    // Map to store strings of length k and their counts
    unordered_map<string, int> mp;
    for (int i=0; i<n; i+=k)
        mp[str.substr(i, k)]++;

    // If string is already a repition of k substrings,
    // return true.
    if (mp.size() == 1)
        return true;

    // If number of distinct substrings is not 2, then
    // not possible to replace a string.
    if (mp.size() != 2)
        return false;

    // One of the two distinct must appear exactly once.
    // Either the first entry appears once, or it appears
    // n/k-1 times to make other substring appear once.
    if ((mp.begin()->second == (n/k - 1)) ||
                    mp.begin()->second == 1)
       return true;

    return false;
}

// Driver code
int main()
{
    checkString("abababcd", 2)? cout << "Yes" :
                                cout << "No";
    return 0;
}
