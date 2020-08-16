#include <iostream>

using namespace std;

 string breakPalindrome(string str) {
        if(str.empty()||str.size()==1){
            return "IMPOSSIBLE";
        }
        for(int i = 0;i<str.size()/2;i++) {
            if(str[i] == 'a') {
                continue;
            }
            str[i] = 'a';
            return str;
        }
        str = "IMPOSSIBLE";
        return str;
    }

int main()
{
    cout << breakPalindrome("aaa") << endl;
    cout << breakPalindrome("aaaab") << endl;
    cout << breakPalindrome("aaabbaaa") << endl;
    return 0;
}
