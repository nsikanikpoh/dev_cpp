#include <iostream>
#include <cstring>
using namespace std;

// M x N matrix
#define M 10
#define N 10

// check if it is possible to go to position (x, y) from
// current position. The function returns false if the cell
// has value 0 or it is already visited.
bool isSafe(int mat[M][N], int visited[M][N], int x, int y)
{
    if (mat[x][y] == 0 || visited[x][y])
        return false;

    return true;
}

// if not a valid position, return false
bool isValid(int x, int y)
{
    if (x < M && y < N && x >= 0 && y >= 0)
        return true;

    return false;
}

// Find Longest Possible Route in a Matrix mat from source cell (0, 0) to
// destination cell (x, y)
// max_dist is passed by reference and stores length of longest path from
// source to destination found so far dist maintains length of path from
// source cell to current cell (i, j)
void findLongestPath(int mat[M][N], int visited[M][N], int i, int j,
                int x, int y, int& max_dist, int dist)
{
    // destination not possible from current cell
    if (mat[i][j] == 0)
        return;

    // if destination is found, update max_dist
    if (i == x && j == y)
    {
        max_dist = max(dist, max_dist);
        return;
    }

    // set (i, j) cell as visited
    visited[i][j] = 1;

    // go to bottom cell
    if (isValid(i + 1, j) && isSafe(mat, visited, i + 1, j))
        findLongestPath(mat, visited, i + 1, j, x, y, max_dist, dist + 1);

    // go to right cell
    if (isValid(i, j + 1) && isSafe(mat, visited, i, j + 1))
        findLongestPath(mat, visited, i, j + 1, x, y, max_dist, dist + 1);

    // go to top cell
    if (isValid(i - 1, j) && isSafe(mat, visited, i - 1, j))
        findLongestPath(mat, visited, i - 1, j, x, y, max_dist, dist + 1);

    // go to left cell
    if (isValid(i, j - 1) && isSafe(mat, visited, i, j - 1))
        findLongestPath(mat, visited, i, j - 1, x, y, max_dist, dist + 1);

    // Backtrack - Remove (i, j) from visited matrix
  //  visited[i][j] = 0;
}

int main()
{
    // input matrix
    int mat[M][N] =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
        { 1, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
        { 1, 1, 0, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }
    };

    // construct a matrix to keep track of visited cells
    int visited[M][N];
    memset(visited, 0, sizeof visited);

    int max_dist = 0;

    // (0,0) are the source cell and (5, 7) are the destination cell coordinates
    findLongestPath(mat, visited, 0, 0, 5, 7, max_dist, 0);

    cout << "Maximum length path is " << max_dist << endl;

     for(int i=0; i < M; i++)
    {
        for(int j=0; j < N; j++)
        {
            cout << visited[i][j] << " , ";
        }
        cout << '\n';
    }

    return 0;
}
