#include <iostream>
#include <string>

using namespace std;

// Complete the theLoveLetterMystery function below.
int theLoveLetterMystery(string s)
{
    int count = 0;
    string rev = string(s.rbegin(),s.rend());
    if(s == rev)
        return 0;
    int mid = s.length()/2;
    if(s.length() % 2 == 0)
    {
        string r = s.substr(0, mid);
        string rev = string(r.rbegin(),r.rend());
        string rv = s.substr(mid, mid);
        for(int i = 0; i<mid; i++)
         count += abs(rv[i] - rev[i]);
    }
    else
    {
        string r = s.substr(0, mid);
        string rev = string(r.rbegin(),r.rend());
        string rv = s.substr(mid + 1, mid);
        for(int i = 0; i<mid; i++)
            count += abs(rv[i] - rev[i]);

    }
    return count;
}

int main()
{
    cout << theLoveLetterMystery("abc") << endl;
    cout << theLoveLetterMystery("abcba") << endl;
    cout << theLoveLetterMystery("abcd") << endl;
    cout << theLoveLetterMystery("cba") << endl;
    return 0;
}
