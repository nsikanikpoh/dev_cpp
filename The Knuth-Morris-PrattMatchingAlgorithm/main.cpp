#include <iostream>
#include <vector>

using namespace std;

std::vector<int> computeFailFunction(const string& pattern)
{
    std::vector<int> fail(pattern.size());
    fail[0] = 0;
    int m = pattern.size();
    int j = 0;
    int i = 1;
    while (i < m)
    {
        if (pattern[j] == pattern[i])
        {// j + 1 characters match
            fail[i] = j + 1;
            i++;
            j++;
        }
        else if (j > 0)// j follows a matching prefix
            j = fail[j - 1];
        else
        {// no match
            fail[i] = 0;
            i++;
        }
    }
    return fail;
}

// KMP algorithm
int KMPmatch(const string& text, const string& pattern)
{
    int n = text.size();
    int m = pattern.size();
    std::vector<int> fail = computeFailFunction(pattern);
    int i = 0;// text index
    int j = 0;// pattern index
    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            if (j == m - 1)
                return i - m + 1;// found a match
            i++;
            j++;
        }
        else if (j > 0)
            j = fail[j - 1];
        else
            i++;
    }
    return -1;// no match
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
