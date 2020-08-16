#include <iostream>
#include <algorithm>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k)
{
    int len = std::max(s.size(), t.size());
    string diffs = "";
    string difft = "";
    int p = 0;

    for(int i = 0; i<len; i++)
    {
        if(s[i] != t[i])
        {
            p = i;
            break;
        }
    }


    for(int i = p; i<s.size(); i++)
    {
        diffs += (s[i]);
    }

    for(int i = p; i<t.size(); i++)
    {
        difft += (t[i]);
    }


    if (difft == diffs)
        return "Yes";
    else if((difft.size() > diffs.size()) && k <= difft.size()*2 && difft.size() != 1)
        return "Yes";
    else if((difft.size() > diffs.size()) && k <= difft.size()*2 )
        return "No";
    else if ( diffs != "" && ((difft.size() + diffs.size()) <= k) )
        return "Yes";
    else
        return "No";
}


int main()
{

   //string result = appendAndDelete("y", "yu", 2);
    string result = appendAndDelete("zzzzz", "zzzzzzz", 4);
    // string result = appendAndDelete("peek", "seeker", 3);
    cout << result << endl;
    return 0;
}
