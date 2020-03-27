// C++ code to count of elements such that
// difference between the sum of left and right
// sub-arrays are equal to a multiple of k

#include <bits/stdc++.h>
using namespace std;

// Functions to find the no of elements
int noOfElement(int a[], int n, int k)
{
    // Creating a prefix array
    int prefix[n];

    // Starting element of prefix array
    // will be the first element
    // of given array
    prefix[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    // Creating a suffix array;
    int suffix[n];
    // Last element of suffix array will
    // be the last element of given array
    suffix[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + a[i];
    }

    // Checking difference of left and right half
    // is divisible by k or not.
    int cnt = 0;
    for (int i = 1; i < n - 1; i++) {
        if ((prefix[i] - suffix[i]) % k == 0
            || (suffix[i] - prefix[i]) % k == 0) {
            cnt = cnt + 1;
        }
    }

    return cnt;
}

// Driver code
int main()
{
    int a[] = { 1, 2, 3, 3, 1, 1 };
    int k = 4;
    int n = sizeof(a) / sizeof(a[0]);
    cout << noOfElement(a, n, k);
    return 0;
}
