// C++ implementation of the approach
#include <bits/stdc++.h>
#define n 3
using namespace std;

// 2d array to store
// states of dp
int dp[n][n];

// Array to determine whether
// a state has been solved before
int v[n][n];

// Function to return the minimum steps required
int minSteps(int i, int j, int arr[][n])
{

    // Base cases
    if (i == n - 1 and j == n - 1)
        return 0;

    if (i > n - 1 || j > n - 1)
        return 9999999;

    // If a state has been solved before
    // it won't be evaluated again
    if (v[i][j])
        return dp[i][j];

    v[i][j] = 1;
    dp[i][j] = 9999999;

    // Recurrence relation
    for (int k = max(0, arr[i][j] + j - n + 1);
         k <= min(n - i - 1, arr[i][j]); k++) {
        dp[i][j] = min(dp[i][j], minSteps(i + k, j + arr[i][j] - k, arr));
    }

    dp[i][j]++;

    return dp[i][j];
}

// Driver code
int main()
{
    int arr[n][n] = { { 4, 1, 2 },
                      { 1, 1, 1 },
                      { 2, 1, 1 } };

    int ans = minSteps(0, 0, arr);
    if (ans >= 9999999)
        cout << -1;
    else
        cout << ans;

    return 0;
}
