#include <iostream>
#include <algorithm>

using namespace std;
const int N {4};


// Converts A[][] to its transpose
void transpose(int A[][N])
{
    for (int i = 0; i < N; i++)
        for (int j = i+1; j < N; j++)
            swap(A[i][j], A[j][i]);
}

int main()
{

    int arr[][N] = { { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 }};

    transpose(arr);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arr[i][j]<< " " ;

        }
        cout  << endl;
    }


    return 0;
}
