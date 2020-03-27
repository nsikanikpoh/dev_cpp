// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the count of equal
// elements to the right - count of equal
// elements to the left for each of the element
void right_left(int a[], int n)
{

    // Maps to store the frequency and same
    // elements to the left of an element
    unordered_map<int, int> total, left;

    // Count the frequency of each element
    for (int i = 0; i < n; i++)
        total[a[i]]++;

    for (int i = 0; i < n; i++) {

        // Print the answer for each element
        cout << (total[a[i]] - 1 - (2 * left[a[i]])) << " ";

        // Increment it's left frequency
        left[a[i]]++;
    }
}

// Driver code
int main()
{
    int a[] = { 1, 2, 3, 2, 1 };
    int n = sizeof(a) / sizeof(a[0]);

    right_left(a, n);

    return 0;
}
