// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;


int calcSum(vector<vector<int>> &mat, int i1, int j1, int i2, int j2)
{
	if (i1 == i2 && j1 == j2) {
		return mat[i1][j1];
	}
	return mat[i1][j1] + mat[i2][j2];
}


int collectRiders(vector<vector<int>> &mat, int i1, int j1, int i2, int n,
                        vector<vector<vector<int>>> &lookup, bool &path_exist)
{

	// Column number of second path
	int j2 = i1 + j1 - i2;

	if (i1 >= n || i2 >= n || j1 >= n || j2 >= n || mat[i1][j1] == -1 || mat[i2][j2] == -1) {
		return 0;
	}
	if(i1 == j1 && j1 == n-1)
        path_exist = true;


	if (lookup[i1][j1][i2] != -1) {
		return lookup[i1][j1][i2];
	}
	int riders = INT_MIN;


  riders = max(riders, collectRiders(mat, i1 + 1, j1, i2 + 1, n, lookup, path_exist) + calcSum(mat, i1, j1, i2, j2));
  riders = max(riders, collectRiders(mat, i1, j1 + 1, i2, n, lookup, path_exist) + calcSum(mat, i1, j1, i2, j2));
  riders = max(riders, collectRiders(mat, i1, j1 + 1, i2 + 1, n, lookup, path_exist) + calcSum(mat, i1, j1, i2, j2));
  riders = max(riders, collectRiders(mat, i1 + 1, j1, i2, n, lookup, path_exist) + calcSum(mat, i1, j1, i2, j2));

  // Saving result to the DP matrix for current state
  lookup[i1][j1][i2] = riders;

  return riders;
}

int collectMax(vector<vector<int>> &mat)
{


    int n = mat.size();
    if(mat[n-1][n-1] == -1)
        return 0;
    bool path_exist{false};
    vector<vector<vector<int>>> lookup;
    lookup.resize(n+1, std::vector< std::vector<int> >(n+1, std::vector<int>(n+1, -1)) );
    int total_riders = collectRiders(mat, 0, 0, 0, n, lookup, path_exist);
    return (path_exist == true) ? total_riders : 0;
}

// Driver code
int main()
{
	vector<vector<int>> mat
    {
        {  0, 1, -1 },
        {  1,  0, -1 },
        {  1,  -1,  1 }
    };

    cout << collectMax(mat) << endl;

	return 0;
}
