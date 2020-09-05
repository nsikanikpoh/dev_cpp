#include <iostream>
#include <string>

using namespace std;

int beautifulBinaryString(string b)
{
    int count = 0;
    int i = 0;
    while(i < b.size())
    {
        if(b.substr(i, 3) == "010")
        {
            count++;
            i += 3;
        }
        else
            i+=1;

    }
    return count;
}

int main()
{
    cout << beautifulBinaryString("0100101010") << endl;
    cout << beautifulBinaryString("01100") << endl;
    cout << beautifulBinaryString("0101010") << endl;
    return 0;
}
