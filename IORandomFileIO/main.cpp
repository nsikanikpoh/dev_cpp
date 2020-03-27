#include <iostream>

using namespace std;

int main()
{


    inf.seekg(14, ios::cur); // move forward 14 bytes
    inf.seekg(-18, ios::cur); // move backwards 18 bytes
    inf.seekg(22, ios::beg); // move to 22nd byte in file
    inf.seekg(24); // move to 24th byte in file
    inf.seekg(-28, ios::end); // move to the 28th byte before end of the file
//Moving to the beginning or end of the file is easy:


    inf.seekg(0, ios::beg); // move to beginning of file
    inf.seekg(0, ios::end); // move to end of file
    return 0;
}
