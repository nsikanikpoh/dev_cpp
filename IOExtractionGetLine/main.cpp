#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
      char strBuf[120];
    // Read up to 10 characters
    cin.getline(strBuf, 11);
    cout << strBuf << endl;

    // Read up to 10 more characters

    cin.getline(strBuf, 100);
    cout << strBuf << endl;
    cout << cin.gcount() << " characters were read" << endl;

/*
ignore() discards the first character in the stream.
ignore(int nCount) discards the first nCount characters.
peek() allows you to read a character from the stream without removing it from the stream.
unget() returns the last character read back into the stream so it can be read again by the next call.
putback(char ch) allows you to put a character of your choice back into the stream to be read by the next call.

 */

    return 0;
}
