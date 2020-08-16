#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

// Complete the makingAnagrams function below.
int makingAnagrams(string s1, string s2)
{
    string s = s1 + s2;
    cout << s << endl;
    set<char> lookup;
    int cmap{0};
    std::unordered_map<char, int> s1frequencyMap;

    for (char &x : s1)
    {
        auto search = s1frequencyMap.find(x);
        if(search != s1frequencyMap.end())
        {
            s1frequencyMap[x] = ++s1frequencyMap[x];
        }
        else
        {
            s1frequencyMap[x] = 1;
        }

    }

    std::unordered_map<char, int> s2frequencyMap;

    for (char &x : s2)
    {
        auto search = s2frequencyMap.find(x);
        if(search != s2frequencyMap.end())
        {
            s2frequencyMap[x] = ++s2frequencyMap[x];
        }
        else
        {
            s2frequencyMap[x] = 1;
        }

    }

    for(char &c: s)
    {
        auto search = lookup.find(c);
        if(search == lookup.end())
        {
            auto f1 = s1.find(c);
            auto f2 = s2.find(c);
            if(f1 != std::string::npos && f2 != std::string::npos)
            {
                if(s2frequencyMap[c] == s1frequencyMap[c])
                    cmap += s2frequencyMap[c] + s1frequencyMap[c];
                else
                    cmap += min(s2frequencyMap[c], s1frequencyMap[c]) * 2;
            }
            lookup.insert(c);
        }

    }
    return s.size() - cmap;
}

int main()
{
    cout << makingAnagrams("cde", "abcc") << endl;
    cout << makingAnagrams("abc","amnop") << endl;
    cout << makingAnagrams("absdjkvuahdakejfnfauhdsaavasdlkj","djfladfhiawasdkjvalskufhafablsdkashlahdfa") << endl;//19
    return 0;
}
