#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char buf[10];
    cin >> setw(10) >> buf;


 //   char ch;
   // while (cin >> ch)
     //   cout << ch;



    //not discarding white space
     char ch1;
    while (cin.get(ch1))
        cout << ch1;
    return 0;



     // takes maximum numbers of characters to read

     char strBuf[11];
    cin.get(strBuf, 11);
    cout << strBuf << endl;
}
