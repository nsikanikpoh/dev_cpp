#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>


using namespace std;

// create a map to store solutions of subproblems
unordered_map<string, int> lookup;

bool isSafeRD(vector<vector<int>> &mat, int m, int n, int i, int j)
{
    if (i < 0 || i >= m || j < 0 || j >= n || mat[i][j] == -1)
        return false;

    return true;
}


int collectRiders(vector<vector<int>> &mat, int m, int n, int i, int j, int x, int y, bool &path_exist )
{

    if (!isSafeRD(mat, m, n, i, j))
        return 0;
    if(i==x && j==y)
        path_exist = true;

    string key = to_string(i) + "|" + to_string(j);


    if (lookup.find(key) == lookup.end())
    {
        int riders;
        if (i & 1 )
            riders = max(collectRiders(mat, m, n, i, j - 1, x, y, path_exist),
                         collectRiders(mat, m, n, i + 1, j, x, y, path_exist));

        else
            riders = max(collectRiders(mat, m, n, i, j + 1, x, y, path_exist),

                         collectRiders(mat, m, n, i + 1, j, x, y, path_exist));
        lookup[key] = mat[i][j] + riders;
    }

    return lookup[key];
}


int collectMax(vector<vector<int>> &mat)
{

    int m = mat.size();
    int n = mat[0].size();
    if(mat[m-1][n-1] == -1)
        return 0;
    bool path_exist{false};
    int total_riders = collectRiders(mat, m, n, 0, 0, m-1, n-1, path_exist);
    return (path_exist == true) ? total_riders : 0;
}

int main()
{
    vector<vector<int>> mat
    {
        {  0, 1, -1 },
        {  1,  0, -1 },
        {  1,  1,  1 }
    };

    cout << collectMax(mat) << endl;

    return 0;
}
