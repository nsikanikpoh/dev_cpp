#include <iostream>
using namespace std;

// Size of given matrix is M x N
#define M 5
#define N 5

// Below arrays details all 8 possible movements
int row[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int col[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

// check whether cell (x, y) is valid or not
bool isValid(int x, int y)
{
    return (x >= 0 && x < M && y >= 0 && y < N);
}

// Find length of longest path in the matrix mat[][] with consecutive characters
// The path should continue from the previous character
// Here (i, j) denotes the coordinates of the current cell
int findMaxLength(char mat[][N], int x, int y, char previous)
{
    // base case: return length 0 if current cell (x, y) is invalid or
    // current character is not consecutive to the previous character
    if (!isValid(x, y) || previous + 1 != mat[x][y])
        return 0;

    // stores the length of longest path
    int max_length = 0;

    // recur for all 8 adjacent cells from current cell
    for (int k = 0; k < 8; k++)
    {
        // visit position (x + row[k], y + col[k]) and find the
        // maximum length from that path
        int len = findMaxLength(mat, x + row[k], y + col[k], mat[x][y]);

        // update the length of longest path if required
        max_length = max(max_length, 1 + len);
    }

    return max_length;
}

// Find length of longest path in the matrix with consecutive characters
int findMaxLength(char mat[][N], char ch)
{
    // stores the length of longest path
    int max_length = 0;

    // traverse the matrix
    for (int x = 0; x < M; x++)
    {
        for (int y = 0; y < N; y++)
        {
            // start from the current cell if its value matches with
            // the given character
            if (mat[x][y] == ch)
            {
                // recur for all 8 adjacent cells from current cell
                for (int k = 0; k < 8; k++)
                {
                    // visit position (x + row[k], y + col[k]) and find the
                    // maximum length from that path
                    int len = findMaxLength(mat, x + row[k], y + col[k], ch);

                    // update the length of longest path if required
                    max_length = max(max_length, 1 + len);
                }
            }
        }
    }

    return max_length;
}

int main()
{
    // input matrix
    char mat[][N] =
    {
        { 'D', 'E', 'H', 'X', 'B' },
        { 'A', 'O', 'G', 'P', 'E' },
        { 'D', 'D', 'C', 'F', 'D' },
        { 'E', 'B', 'E', 'A', 'S' },
        { 'C', 'D', 'Y', 'E', 'N' }
    };

    // starting character
    char ch = 'C';

    cout << "The length of longest path with consecutive characters\n"
         << "starting from character " << ch << " is "
         << findMaxLength(mat, ch) << endl;

    return 0;
}
