#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int M1[8][10]; // matrix with 8 rows and 10 columns

    const int N_DAYS = 7;
    const int N_HOURS = 24;
    int schedule[N_DAYS][N_HOURS];


      int n{8};
      int m{9};

    //Dynamic Allocation
    int** M = new int*[n]; // allocate an array of row pointers
    for (int i = 0; i < n; i++)
        M[i] = new int[m]; // allocate the i-th row


   //Dynamic Deallocation
    for (int i = 0; i < n; i++)
        delete[ ] M[i]; // delete the i-th row
    delete[ ] M; // delete the array of row pointers


    //STL vector alocation
    vector< vector<int> > array(n, vector<int>(m));
     cout << array[i][j] << endl;

    cout << "Hello world!" << endl;
    return 0;
}
