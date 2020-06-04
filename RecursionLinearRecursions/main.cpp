#include <iostream>
#include <algorithm>

using namespace std;

int LinearSum(const int A[], int n)
{
    if(n == 1)
        return A[0];
    else
        return LinearSum(A, n-1) + A[n-1];
}

void ReverseArray(int A[], int i, int j)
{
    while(i<j)
    {
        if(A[i] < A[j])
            swap(A[i], A[j]);
        ++i;
        --j;
    }
}

int main()
{
    int arr[11] {1,3,5,6,8,23,8,6,34,9,6};
    ReverseArray(arr, 0, 10);
    cout << LinearSum(arr, 11) << endl;
    for(const auto &elem: arr)
        cout << elem << ", ";
    cout << endl;
    return 0;
}
