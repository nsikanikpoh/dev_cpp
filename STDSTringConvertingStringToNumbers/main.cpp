#include <iostream>
#include <sstream>
#include <string>

template <typename T>
inline bool FromString(const std::string& sString, T &tX)
{
    std::istringstream iStream(sString);
    return (iStream >> tX) ? true : false; // extract value into tX, return success or not
}

using namespace std;

int main()
{
    double dX;
    if (FromString("3.4", dX))
        cout << dX << endl;
    if (FromString("ABC", dX))
        cout << dX << endl;
    return 0;
}


