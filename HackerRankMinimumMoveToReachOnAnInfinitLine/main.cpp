// CPP program to find minimum moves to
// reach target if we can move i steps in
// i-th move.
#include <iostream>
using namespace std;

int reachTarget(int target)
{
    // Handling negatives by symmetry
    target = abs(target);

    // Keep moving while sum is smaller or difference
    // is odd.
    int sum = 0, step = 0;
    while (sum < target || (sum - target) % 2 != 0) {
        step++;
        sum += step;
    }
    return step;
}

// Driver code
int main()
{
    int target = 5;
    cout << reachTarget(target);
    return 0;
}
