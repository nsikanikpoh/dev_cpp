#include <iostream>
#include <array>

using namespace std;


#include <cassert> // for assert()

int getArrayValue(const std::array<int, 10> &array, int index)
{
    // we're asserting that index is between 0 and 9
    assert(index >= 0 && index <= 9); // this is line 6 in Test.cpp

    return array[index];
}

int main()
{
std::array<int, 10> array;
getArrayValue(array, -3)
    cout << "Hello world!" << endl;
    return 0;
}
