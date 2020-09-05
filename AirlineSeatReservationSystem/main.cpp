#include "stdafx.h"
#include <iostream>
#include <utility>
using namespace std;

void FillSeatArray(pair<char, bool> arr[][4], int sizeDim1);
// Precondition: arr is a two dimensional array of type pair<char, bool>[4].
// sizeDim1 is the size of the first array dimesion.
// Postcondition: Each four element array of type pair<char, bool> is assigned values
// representing seats. The pair at index 0 is assigned 'A', 1 is assigned 'B',
// 2 is assigned 'C', and 3 is assigned 'D'. Each char value is paired with
// bool literal false to represent that the seat is empty.

void PrintSeats(pair<char, bool> arr[][4], int sizeDim1);
// Precondition: arr is a two dimensional array of type pair<char, bool>[4].
// sizeDim1 is the size of the first array dimesion.
// Postcondition: prints out a mapping of the current seats. A seat labeled
// with an X is unavailable.

pair<int, char> ChooseSeat(pair<char, bool> arr[][4], int sizeDim1);
// Precondition: arr is a two dimensional array of type pair<char, bool>[4].
// sizeDim1 is the size of the first array dimesion.
// Returns: a pair<int, char> object indicating a valid seat chosen by the user.

bool InvalidSeat(int rowChoice, char seatInRowChoice, pair<char, bool> arr[][4], int sizeDim1);
// Precondition: arr is a two dimensional array of type pair<char, bool>[4].
// sizeDim1 is the size of the first array dimesion. rowChoice is the desired row, seatInRowChoice
// is the desired seat choice.
// Returns: true if the values rowChoice and seatInRowChoice indicate a valid, unoccupied seating position.
// Valid seating positions are rowChoice 1-sizeDim1 and seatInRowChoice 'A'-'D'.

void ReserveSeat(pair<char, bool> arr[][4], pair<int, char> desiredSeat);
// Precondition: arr is a two dimensional array of type pair<char, bool>[4].
// desiredSeat is the row and seat of which to reserve.
// Poscondition: finds the representation of desiredSeat in arr and sets that value's
// bool value to true, indicating the seat is now reserved.

int SeatToIndex(char seatInRow);
// Precondition: seatInRow is a valid choice, 'A'-'D'.
// Returns: index 0-4 correspoding to each char 'A'-'D'.

int main()
{
	bool reservingASeat = true;
	const int ROWS = 7, SEATS_PER_ROW = 4;
	pair<char, bool> seats[ROWS][SEATS_PER_ROW];
	FillSeatArray(seats, ROWS);

	cout << "Welcome to the airline reservation system!\n\n";

	while (reservingASeat)
	{
		pair<int, char> desiredSeat = ChooseSeat(seats, ROWS);

		ReserveSeat(seats, desiredSeat);

		PrintSeats(seats, ROWS);

		char ans;
		do
		{
			cout << "Would you like to reserve another seat? (y/n): ";
			cin >> ans;
			cout << endl;
		} while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');

		if (ans == 'n' || ans == 'N')
			reservingASeat = false;
	}

    return 0;
}

void FillSeatArray(pair<char, bool> arr[][4], int sizeDim1)
{
	for (int i = 0; i < sizeDim1; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			switch (j)
			{
			case 0:
				arr[i][j] = make_pair('A', false);
				break;
			case 1:
				arr[i][j] = make_pair('B', false);
				break;
			case 2:
				arr[i][j] = make_pair('C', false);
				break;
			case 3:
				arr[i][j] = make_pair('D', false);
				break;
			}
		}
	}
}

void PrintSeats(pair<char, bool> arr[][4], int sizeDim1)
{
	for (int i = 0; i < sizeDim1; ++i)
	{
		cout << i + 1 << " ";
		for (int j = 0; j < 4; ++j)
		{
			cout << ((arr[i][j].second == false) ? arr[i][j].first : 'X');
		}
		cout << endl;
	}
	cout << endl;
}

pair<int, char> ChooseSeat(pair<char, bool> arr[][4], int sizeDim1)
{
	cout << "Current seating status:\n\n";
	PrintSeats(arr, sizeDim1);
	cout << endl;
	int row;
	char seatInRow;
	do
	{
		cout << "Choose a row (1-7): ";
		cin >> row;
		cout << "Choose a seat (A-D): ";

		cin >> seatInRow;
		cout << endl;

		seatInRow = ::toupper(seatInRow);
	} while (InvalidSeat(row, seatInRow, arr, sizeDim1));

	return make_pair(row, seatInRow);
}

bool InvalidSeat(int rowChoice, char seatInRowChoice, pair<char, bool> arr[][4], int sizeDim1)
{
	int row = rowChoice - 1;
	if (rowChoice <= 0 || rowChoice > sizeDim1)
	{
		cout << "Invalid row choice.\n\n";
		return true;
	}
	else if (seatInRowChoice < 'A' || seatInRowChoice > 'D')
	{
		cout << "Invalid seat choice.\n\n";
		return true;
	}
	else if (arr[row][SeatToIndex(seatInRowChoice)].second == true)
	{
		cout << "Seat " << rowChoice << seatInRowChoice << " is occupied.\n\n";
		return true;
	}

	return false;
}

void ReserveSeat(pair<char, bool> arr[][4], pair<int, char> desiredSeat)
{
	int row = desiredSeat.first - 1;
	int seatInRow = SeatToIndex(desiredSeat.second);

	arr[row][seatInRow].second = true;
	cout << "Seat " << desiredSeat.first << desiredSeat.second << " reserved.\n\n";
}

int SeatToIndex(char seatInRow)
{
	switch (seatInRow)
	{
	case 'A':
		return 0;
	case 'B':
		return 1;
	case 'C':
		return 2;
	case 'D':
		return 3;
	default:
		cerr << "Invalid value: desiredSeat.second, ReserveSeat\n\n";
		exit(1);
	}
}
