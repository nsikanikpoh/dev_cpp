#include <iostream>

#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()


using namespace std;

int main()
{
    string sSource("012345678");
    cout << sSource.length() << endl;
    string sString1("Not Empty");
    cout << (sString1.empty() ? "true" : "false") << endl;
    string sString2; // empty
    cout << (sString2.empty() ? "true" : "false")  << endl;

//Returns the maximum number of characters that a string is allowed to have.
    string sString("MyString");
    cout << sString.max_size() << endl;
    //Returns the number of characters a string can hold without reallocation.
    cout << "Capacity: " << sString.capacity() << endl;




    string sString7("0123456789abcde");
    cout << "Length: " << sString7.length() << endl;
    cout << "Capacity: " << sString7.capacity() << endl;

// Now add a new character
    sString7 += "f";
    cout << "Length: " << sString7.length() << endl;
    cout << "Capacity: " << sString7.capacity() << endl;


    sString7.reserve(200);

    cout << "Length: " << sString7.length() << endl;
    cout << "Capacity: " << sString7.capacity() << endl;



    std::srand(std::time(nullptr)); // seed random number generator

    string sString8{}; // length 0
    sString8.reserve(64); // reserve 64 characters

    // Fill string up with random lower case characters
    for (int nCount{ 0 }; nCount < 64; ++nCount)
        sString8 += 'a' + std::rand() % 26;

    cout << sString8;

    return 0;
}
