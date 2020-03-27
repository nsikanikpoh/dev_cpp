#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    stringstream os;
    os << "12345 67.89"; // insert a string of numbers into the stream
    int nValue;
    double dValue;

    os >> nValue >> dValue;

    cout << nValue << " " << dValue << endl;

    cout << "adding: " << endl;
    cout << (nValue + dValue) << endl;
    return 0;
}
