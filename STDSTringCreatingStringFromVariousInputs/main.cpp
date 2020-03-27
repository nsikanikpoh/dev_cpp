#include <iostream>
#include <sstream>
#include <string>

template <typename T>
inline std::string ToString(T tX)
{
    std::ostringstream oStream;
    oStream << tX;
    return oStream.str();
}

using namespace std;

int main()
{
    string sFour(ToString(4));
    string sSixPointSeven(ToString(6.7));
    string sA(ToString('A'));
    cout << sFour << endl;
    cout << sSixPointSeven << endl;
    cout << sA << endl;
    return 0;
}
