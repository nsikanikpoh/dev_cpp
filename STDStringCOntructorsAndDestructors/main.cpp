#include <iostream>
#include <string>

using namespace std;

int main()
{
    //    string::string()
//This is the default constructor. It creates an empty string.

//string::string(const string& strString)
//This is the copy constructor. This constructor creates a new string as a copy of strString.

    string sSource("my string");
    string sOutput(sSource);
    cout << sOutput <<'\n';


    //  string::string(const string& strString, size_type unIndex)
//string::string(const string& strString, size_type unIndex, size_type unLength)


    string sOutput1(sSource, 3);
    cout << sOutput1<< endl;
    string sOutput2(sSource, 3, 4);
    cout << sOutput2 << endl;

    //string::string(const char *szCString)

    const char *szSource3("my string"); // c-style string
    string sOutput4(szSource3);
    cout << sOutput4 << endl;

   // string::string(const char *szCString, size_type unLength)
   string sOutput5(szSource3, 4);
   cout << sOutput5 << endl;


   //string::string(size_type nNum, char chChar)
   string sOutput6(4, 'Q');
   cout << sOutput6 << endl;

    return 0;
}
