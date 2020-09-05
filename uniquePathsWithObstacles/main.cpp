#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& grid)
{

    int m = grid.size();
    if(m==0)
        return 0;
    int n = grid[0].size();

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==0 && j ==0)
            {
                grid[i][j] = grid[i][j] == 0?1:0;
            }
            else if(i==0)
            {
                grid[i][j] = grid[i][j] == 0?grid[i][j-1]:0;
            }
            else if(j==0)
            {
                grid[i][j] = grid[i][j] == 0?grid[i-1][j]:0;
            }
            else
            {
                grid[i][j] = grid[i][j] == 0?grid[i][j-1] + grid[i-1][j] :0;
            }
        }
    }
    return grid[m-1][n-1];
}

int main()
{
    vector<vector<int>> vec
    {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    cout << uniquePathsWithObstacles(vec) << endl;
    return 0;
}
