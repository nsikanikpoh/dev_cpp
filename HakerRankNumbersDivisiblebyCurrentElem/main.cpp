// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Utility function to print the
// elements of the array
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// Function to generate and print
// the required array
void generateArr(int A[], int n)
{
    int B[n];

    // For every element of the array
    for (int i = 0; i < n; i++) {

        // To store the count of elements
        // on the left that the current
        // element divides
        int cnt = 0;
        for (int j = 0; j < i; j++) {
            if (A[j] % A[i] == 0)
                cnt++;
        }
        B[i] = cnt;
    }

    // Print the generated array
    printArr(B, n);
}

// Driver code
int main()
{
    int A[] = { 3, 5, 1 };
    int n = sizeof(A) / sizeof(A[0]);

    generateArr(A, n);

    return 0;
}
