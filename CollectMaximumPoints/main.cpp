#include <iostream>
#include <algorithm>

using namespace std;

// M x N matrix
#define M 5
#define N 5

// Function to check if cell (i, j) is valid and safe to visit
bool isSafe(int mat[M][N], int i, int j)
{
    if (i < 0 || i >= M || j < 0 || j >= N || mat[i][j] == -1)
        return false;

    return true;
}

// Function to collect maximum number of ones starting from
// cell mat[i][j]
int findMaximum(int mat[M][N], int i, int j)
{
    // return if cell (i, j) is invalid or unsafe to visit
    if (!isSafe(mat, i, j))
        return 0;

    // if row is odd, we can go left or down
    if (i & 1)
        return mat[i][j] + max(findMaximum(mat, i, j - 1),
                            findMaximum(mat, i + 1, j));

    // if row is even, we can go right or down
    else
        return mat[i][j] + max(findMaximum(mat, i, j + 1),
                        findMaximum(mat, i + 1, j));
}

int main()
{
    int mat[M][N] =
    {
        {  1,  1, -1,  1,  1 },
        {  1,  0,  0, -1,  1 },
        {  1,  1,  1,  1, -1 },
        { -1, -1,  1,  1,  1 },
        {  1,  1, -1, -1,  1 }
    };
/*
 int mat[M][N] =
    {
        {  1,  1, 1,  1,  1 },
        {  0,  0,  0, -1,  1 },
        {  -1,  0,  0,  0, -1 },
        { -1, -1,  1,  1,  1 },
        {  1,  -1, -1, -1,  1 }
    };*/
    cout << "Maximum value collected is " << findMaximum(mat,0,0);

    return 0;
}
