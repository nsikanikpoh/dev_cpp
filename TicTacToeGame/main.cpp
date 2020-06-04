#include <cstdlib>// system definitions
#include <iostream>// I/O definitions
using namespace std; // make std:: accessible


const int X = 1, O = -1, EMPTY = 0;// possible marks
int board[3][3];// playing board
int currentPlayer; // current player (X or O)


void clearBoard()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = EMPTY;
    currentPlayer = X; // clear the board
}
void putMark(int i, int j)// mark row i column j
{
    board[i][j] = currentPlayer;// mark with current player
    currentPlayer = -currentPlayer;// switch players
}


// every cell is empty
// player X starts
bool isWin(int mark)
{
// is mark the winner?
    int win = 3*mark;
// +3 for X and -3 for O
    return ((board[0][0] + board[0][1] + board[0][2] == win)
// row 0
            || (board[1][0] + board[1][1] + board[1][2] == win)
// row 1
            || (board[2][0] + board[2][1] + board[2][2] == win)
// row 2
            || (board[0][0] + board[1][0] + board[2][0] == win)
// column 0
            || (board[0][1] + board[1][1] + board[2][1] == win)
// column 1
            || (board[0][2] + board[1][2] + board[2][2] == win)
// column 2
            || (board[0][0] + board[1][1] + board[2][2] == win)
// diagonal
            || (board[2][0] + board[1][1] + board[0][2] == win));
// diagonal
}


int getWinner()
{
    if (isWin(X))
        return X;
    else if (isWin(O))
        return O;
    else
        return EMPTY;
}
// who wins? (EMPTY means tie)
void printBoard2()
{
// print the board
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            switch (board[i][j])
            {
            if (j == 0)
                cout << "|";
            case X:
                cout << "X";
                break;
            case O:
                cout << "O";
                break;
            case EMPTY:
                cout << " ";
                break;
            }
            if (j < 2)
                cout << "|";
// column boundary
        }
            if (i < 2)
                cout << "\n-+-+-\n";
// row boundary
    }
}

void printBoard()
{

cout << "\n+-+-+-+\n";
// print the board
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
        if(j==0)
         cout << "|";
            switch (board[i][j])
            {
            if (j == 0)
                cout << "|";
            case X:
                cout << "X";
                break;
            case O:
                cout << "O";
                break;
            case EMPTY:
                cout << " ";
                break;
            }

                cout << "|";
// column boundary
        }

                cout << "\n+-+-+-+\n";
// row boundary
    }
}


int main()
{
    clearBoard();
    putMark(0,0);
    putMark(1,1);
    putMark(0,1);
    putMark(0,2);
    putMark(2,0);
    putMark(1,2);
    putMark(2,2);
    putMark(2,1);
    putMark(1,0);
    printBoard();
    int winner = getWinner();
    if (winner != EMPTY)
            cout << " " << (winner == X ? 'X' : 'O') << " wins"<< endl;
    else
        cout << " Tie" << endl;
return EXIT_SUCCESS;

}
