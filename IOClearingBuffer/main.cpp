#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    //Clearing a stringstream for reuse

//There are several ways to empty a stringstream’s buffer.

//1) Set it to the empty string using str() with a blank C-style string:


    stringstream os;
    os << "Hello ";

    os.str(""); // erase the buffer

    //clear() resets any error flags that may have been set and returns the stream back to the ok state.
    os.clear(); // reset error flags
    os << "World!";
    cout << os.str();
//2) Set it to the empty string using str() with a blank std::string object:



    stringstream os2;
    os2 << "Hello ";

    os2.str(std::string()); // erase the buffer

    os2 << "World!";
    cout << os2.str();
    return 0;
}
