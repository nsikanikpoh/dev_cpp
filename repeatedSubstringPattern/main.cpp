#include <iostream>

using namespace std;

bool repeatedSubstringPattern(string s)
{
    string tmp = s+s;
        /* Remove first char to avoid to match with input string which is from 0 to s.length() */
        tmp = tmp.substr(1);
        /* Remove last char to avoid to match with input string which is appended after s.length() */
        tmp = tmp.substr(0, tmp.length()-1);
        /* if the input string present then then pattern is repeated*/
        return tmp.find(s) != string::npos ? true : false;

}

int main()
{
    /**
    Input: "abab"
    Output: True
    Explanation: It's the substring "ab" twice.
    Example 2:

    Input: "aba"
    Output: False
    Example 3:

    Input: "abcabcabcabc"
    **/
    string input1 = "abab";
    string input2 = "aba";
    string input3 = "abcabcabcabc";
    cout << repeatedSubstringPattern(input1) << endl;
    cout << repeatedSubstringPattern(input2) << endl;
    cout << repeatedSubstringPattern(input3) << endl;
    return 0;
}
