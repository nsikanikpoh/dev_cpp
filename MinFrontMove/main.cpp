// C++ program to find minimum number of move-to-front
// moves to arrange items in sorted order.
#include <bits/stdc++.h>
using namespace std;

// Calculate minimum number of moves to arrange array
// in increasing order.
int minMoves(int arr[], int n)
{
    // Since we traverse array from end, extected item
    // is initially  n
    int expectedItem = n;

    // Taverse array from end
    for (int i=n-1; i >= 0; i--)
    {
        // If current item is at its correct position,
        // decrement the expectedItem (which also means
        // decrement in minimum number of moves)
        if (arr[i] == expectedItem)
            expectedItem--;
    }

    return expectedItem;
}

// Driver Program
int main()
{
    int arr[] = {4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << minMoves(arr, n);
    return 0;
}
