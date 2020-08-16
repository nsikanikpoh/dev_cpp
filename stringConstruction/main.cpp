#include <iostream>
#include <set>
using namespace std;

int stringConstruction(string s)
{
    set<char> st;
    for(char &c: s)
        st.insert(c);
    return st.size();

}

int main()
{
    cout << stringConstruction("abcd") << endl;
    cout << stringConstruction("abab") << endl;
    return 0;
}
