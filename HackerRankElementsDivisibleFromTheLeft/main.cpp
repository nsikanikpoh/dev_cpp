// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the maximum count
// of required elements
int findMax(int arr[], int n)
{

    // divisible[i] will store true
    // if arr[i] is divisible by
    // any element on its right
    bool divisible[n] = { false };

    // To store the maximum required count
    int res = 0;

    // For every element of the array
    for (int i = n - 1; i > 0; i--) {

        // If the current element is
        // divisible by any element
        // on its right
        if (divisible[i])
            continue;

        // Find the count of element
        // on the left which are divisible
        // by the current element
        int cnt = 0;
        for (int j = 0; j < i; j++) {

            // If arr[j] is divisible then
            // set divisible[j] to true
            if ((arr[j] % arr[i]) == 0) {
                divisible[j] = true;
                cnt++;
            }
        }

        // Update the maximum required count
        res = max(res, cnt);
    }

    return res;
}

// Driver code
int main()
{
    int arr[] = { 8, 1, 28, 4, 2, 6, 7 };
    int n = sizeof(arr) / sizeof(int);

    cout << findMax(arr, n);

    return 0;
}
