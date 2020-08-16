#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

// Complete the weightedUniformStrings function below.
vector<string> weightedUniformStrings(string s, vector<int> queries)
{
    map<char, int> alpha = { {'a', 1}, {'b', 2}, {'c', 3}, {'d',4}, {'e',5}, {'f',6}, {'g',7}, {'h',8},
                            {'i',9}, {'j',10}, {'k',11}, {'l',12}, {'m',13}, {'n',14}, {'o',15}, {'p',16},
                            {'q',17}, {'r',18}, {'s',19}, {'t',20}, {'u',21}, {'v',22}, {'w',23}, {'x',24}, {'y',25}, {'z',26}
                           };
    set<int> scores;
    vector<string> result_arr;
    int ctr = 1;

    for(int i = 0; i< s.length(); i++)
    {
       int score = alpha[s[i]];
       scores.insert(score);
        if (i+1 != s.length() && s[i+1] == s[i])
                ctr += 1;
        else
                ctr = 1;
        scores.insert(score*ctr);

    }


    for(int &i: queries)
    {
        auto search = scores.find(i);
        if (search != scores.end())
        {
            result_arr.push_back("Yes");
        }
        else
        {
            result_arr.push_back("No");
        }
    }

    return result_arr;

}

int main()
{
    vector<int> queries {1,3,12,5,9,10};
    vector<string> results = weightedUniformStrings("abccddde", queries);
    for(string &str: results)
        cout << str << endl;
    return 0;
}
