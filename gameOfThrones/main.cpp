#include <iostream>

using namespace std;
// Complete the gameOfThrones function below.
string gameOfThrones(string s)
{
    int flag = 0;
    uint64_t mask = 0x0;
    for (int i = 0; i < s.length(); i++)
        mask = mask ^ (1 << (s[i]-'a'));
    if ((!mask) || (((mask & (mask - 1)) == 0)))
        flag = 1;
    if(flag==0)
        return "NO";
    else
        return "YES";

}
int main()
{
    cout << gameOfThrones("aaabbbb") << endl;
    cout << gameOfThrones("cdefghmnopqrstuvw") << endl;
    cout << gameOfThrones("cdcdcdcdeeeef") << endl;
    return 0;
}
