#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// N x N matrix
#define R 4
#define C 3

/*

 * Given a cost matrix having a cost at each cell. Find the minimum cost it
 * will take to reach cell (m, n) from top left corner cell (0, 0) if the only
 * allowed directions to move from a cell are right, down and diagonally down.

 */

int min(int x, int y, int z);

int minimumCostPathDP(int cost[R][C], int m, int n)
{
    int i, j;

    // Instead of following line, we can use int tc[m+1][n+1] or
    // dynamically allocate memory to save space. The following line is
    // used to keep the program simple and make it working on all compilers.
    int tc[R][C];

    tc[0][0] = cost[0][0];

    /* Initialize first column of total cost(tc) array */
    for (i = 1; i <= m; i++)
        tc[i][0] = tc[i-1][0] + cost[i][0];

    /* Initialize first row of tc array */
    for (j = 1; j <= n; j++)
        tc[0][j] = tc[0][j-1] + cost[0][j];

    /* Construct rest of the tc array */
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            tc[i][j] = min(tc[i-1][j-1],
                           tc[i-1][j],
                           tc[i][j-1]) + cost[i][j];

    return tc[m][n];
}

/* A utility function that returns minimum of 3 integers */
int min(int x, int y, int z)
{
    if (x < y)
        return (x < z)? x : z;
    else
        return (y < z)? y : z;
}


int main()
{
    int cost[R][C] = { { 3, 2, 8 }, { 1, 9, 7 }, { 0, 5, 2 }, {6, 4, 3} };

    cout << "The minimum cost is " << minimumCostPathDP(cost, 2, 2) << '\n';

    return 0;
}
