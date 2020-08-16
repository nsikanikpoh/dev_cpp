// C++ program to find length of a jump
// to reach end avoiding all obstacles
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int avoidObstacles(unordered_set<int> obs)
{

    // set jump distance to 1
    int jump_dist = 1;

    // flag to check if current jump distance
    // hits an obstacle
    bool obstacle_hit = true;

    while(obstacle_hit)
    {

        obstacle_hit = false;
        jump_dist += 1;

        // checking if jumping with current length
        // hits an obstacle
        for (auto i:obs)
        {
            if (i % jump_dist == 0)
            {

                // if obstacle is hit repeat process
                // after increasing jump distance
                obstacle_hit = true;
                break;
            }
            }
        }

    return jump_dist;
}

// Driver Code
int main()
{
    unordered_set<int> a = {5, 3, 6, 7, 9};
    int b = avoidObstacles(a);
    cout << b;
}

// This code is contributed by mohit kumar 29
