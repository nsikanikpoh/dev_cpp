
// CPP program to Find the minimum number of moves required to
// reach the destination by the king in a chess board
#include <bits/stdc++.h>
using namespace std;

// function to Find the minimum number of moves required to
// reach the destination by the king in a chess board
void MinSteps(int SourceX, int SourceY, int DestX, int DestY)
{
    // minimum number of steps
    cout << max(abs(SourceX - DestX), abs(SourceY - DestY)) << endl;

    // while the king is not in the same row or column
    // as the destination
    while ((SourceX != DestX) || (SourceY != DestY)) {

        // Go up
        if (SourceX < DestX) {
            cout << 'U';
            SourceX++;
        }

        // Go down
        if (SourceX > DestX) {
            cout << 'D';
            SourceX--;
        }

        // Go left
        if (SourceY > DestY) {
            cout << 'L';
            SourceY--;
        }

        // Go right
        if (SourceY < DestY) {
            cout << 'R';
            SourceY++;
        }

        cout << endl;
    }
}

// Driver code
int main()
{
    int sourceX = 4, sourceY = 4;
    int destinationX = 7, destinationY = 0;

    MinSteps(sourceX, sourceY, destinationX, destinationY);

    return 0;
}
