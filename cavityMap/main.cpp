#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <iterator>
using namespace std;

vector<string> cavityMap(vector<string> grid)
{

   for(int i = 1; i < grid.size()-1; i++)
    {

        for(int j = 1; j < grid.size()-1; j++)
        {
            if((grid[i][j] > grid[i][j-1]) && (grid[i][j] > grid[i-1][j]) &&
                    (grid[i][j] > grid[i+1][j]) && (grid[i][j] > grid[i][j+1]))
                grid[i][j] = 'X';
        }
    }
    return grid;
}

int main()
{
    vector<string> a
    {
        "1112",
        "1912",
        "1892",
        "1234"
    };

    vector<string> res  = cavityMap(a);
    for(string &s: res)
        cout << s << endl;

    return 0;
}
