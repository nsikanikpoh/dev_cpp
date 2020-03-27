#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */


    if (s[8]=='A') {
        if (s[0] == '1' && s[1] == '2') {
            return "00"+s.substr(2,6);
        }
        return s.substr(0,8);
    } else {
        int clock = stoi(s.substr(0,2)) + 12;
        if (clock == 24) {
            return "12"+s.substr(2,6);
        }
        return to_string(clock) + s.substr(2,6);
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
