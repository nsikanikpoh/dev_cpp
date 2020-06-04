#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// N x N matrix
#define N 5

// DP function to calculate the minimum cost to reach the destination city n
// from the source city 0
int findMinCost(int cost[][N])
{
    // lookup[i] stores the minimum cost to reach city i from city 0
    int lookup[N];

    // Initialize lookup[] with the direct ticket price from the source city
    for (int i = 0; i < N; i++)
        lookup[i] = cost[0][i];


    // repeat loop till lookup[] is filled with all minimum values
    bool is_filled = false;
    while (!is_filled)
    {
        is_filled = true;

        // fill lookup[] in bottom-up manner
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (lookup[i] > lookup[j] + cost[j][i]) {
                    lookup[i] = lookup[j] + cost[j][i];
                    is_filled = false;    // mark lookup[] as NOT filled
                }
            }
        }
    }

    // return the minimum cost to reach city N-1 from city 0
    return lookup[N-1];
}

int main()
{
    int cost[N][N] =
    {
        { 0, 30, 25, 10, 110 },
        { 20, 0, 15, 80, 80 },
        { 30, 15, 0, 70, 90 },
        { 10, 50, 10, 0, 100 },
        { 40, 50, 5, 10, 0 }
    };

    cout << "The minimum cost is " << findMinCost(cost) << "$";

    return 0;
}
