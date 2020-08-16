#include <iostream>
#include <vector>
using namespace std;

#define M 3
#define N 3

// Function to check if (i, j) is valid matrix coordinate
bool isvalid(int i, int j)
{
    return (i >= 0 && i < M && j >= 0 && j < N);
}

// Function to print the route taken
void printPath(vector<int> const &path, int last)
{
    for (int i : path)
        cout << i << " - ";
    cout << last << endl;
}

void findPaths(int mat[][N], vector<int> &path, int i, int j)
{
    // if we have reached the last cell, print the route
    if (i == M - 1 && j == N - 1)
    {
        printPath(path, mat[i][j]);
        return;
    }

    // include current cell in path
    path.push_back(mat[i][j]);

    // move right
    if (isvalid(i, j + 1))
        findPaths(mat, path, i, j + 1);

    // move down
    if (isvalid(i + 1, j))
        findPaths(mat, path, i + 1, j);

    // remove current cell from the path
    path.pop_back();
}

// Returns count of possible paths to reach cell at row
// number m and column number n from the topmost leftmost
// cell (cell at 1, 1)
int numberOfPaths(int m, int n)
{
    // If either given row number is first or given column
    // number is first
    if (m == 1 || n == 1)
        return 1;

    // If diagonal movements are allowed then the last
    // addition is required.
    return numberOfPaths(m - 1, n) + numberOfPaths(m, n - 1);
    // + numberOfPaths(m-1, n-1);
}

int main()
{
    int mat[M][N] =
    {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    vector<int> path;


    // start from (0, 0) cell
    int x = 0, y = 0;

    findPaths(mat, path, x, y);
    cout << numberOfPaths(3, 3) << '\n';

    return 0;
}
