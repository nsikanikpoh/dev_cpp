#include <algorithm>
#include <string>
#include <iostream>
#include <cctype>

using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    s.erase(std::remove(s.begin(), s.end(), ' '),
               s.end());
    transform(s.begin(), s.end(), s.begin(),
    [](unsigned char c){ return std::tolower(c); });
    sort(s.begin(), s.end());
    auto u_str = unique(s.begin(), s.end());
    string rs =  string(s.begin(), u_str);

   if(rs == alpha)
        return "pangram";
    else
       return "not pangram";
}

int main()
{
    string result = pangrams("We promptly judged antique ivory buckles for the prize");
    std::cout << "Result: " << result <<'\n';
    return 0;
}
