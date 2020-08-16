#include <iostream>

using namespace std;

int anagram(string s)
{
    if (s.size() % 2 != 0)
        return -1;
    int n = s.size();
    int mid = n/2;
    string a = s.substr(0, mid);
    string b = s.substr(mid, mid - n);
    for(char &c: b)
    {
        auto f = a.find(c);
        if(f != std::string::npos)
            a.erase(f, 1);
    }

    return a.size();
}

int main()
{

    cout << anagram("abccde") << endl;
    cout << anagram("aaabbb") << endl;
    cout << anagram("ab") << endl;
    cout << anagram("abc") << endl;
    cout << anagram("mnop") << endl;
    cout << anagram("xyyx") << endl;
    cout << anagram("xaxbbbxx") << endl;
   cout << anagram("csgokgibmftzeozyadcofpouaerckbbpwhdg") << endl;

    return 0;
}
