// CPP program to Remove spaces
// from a given string

#include <iostream>
#include <algorithm>
using namespace std;

// Function to remove all spaces from a given string
string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

// Driver program to test above function
int main()
{
    string str = "g  eeks   for ge  eeks   ";
    str = removeSpaces(str);
    cout << str;
    return 0;
}

// This code is contributed by Divyam Madaan
