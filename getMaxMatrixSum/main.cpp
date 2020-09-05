#include <bits/stdc++.h>
using namespace std;
#define SIZE 10
int getMaxMatrixSum(int mat[SIZE][SIZE], int n){
   if (n == 1) {
      return mat[0][0];
   }
   int dp[n][n];
   int maxSum = INT_MIN, max;
   for (int j = 0; j < n; j++) {
      dp[n - 1][j] = mat[n - 1][j];
   }
   for (int i = n - 2; i >= 0; i--) {
      for (int j = 0; j < n; j++) {
         max = INT_MIN;
         if (((j - 1) >= 0) && (max < dp[i + 1][j - 1])) {
            max = dp[i + 1][j - 1];
         }
         if (((j + 1) < n) && (max < dp[i + 1][j + 1])) {
            max = dp[i + 1][j + 1];
         }
         dp[i][j] = mat[i][j] + max;
      }
   }
   for (int j = 0; j < n; j++) {
      if (maxSum < dp[0][j]) {
         maxSum = dp[0][j];
      }
   }
   return maxSum;
}
int main(){
   int mat[SIZE][SIZE] = {
      {5, 6, 1, 17},
      {-2, 10, 8, -1},
      {3, -7, -9, 4},
      {12, -4, 2, 2}
   };
   int n = 4;
   cout << "Maximum Sum = " << getMaxMatrixSum(mat, n) << endl;
   return 0;
}
