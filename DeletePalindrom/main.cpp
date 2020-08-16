#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Function to find out the minimum number of deletions required to
// convert a given string X[i..j] into a palindrome
int minDeletions(string X, int i, int j, auto &lookup)
{
    // base condition
    if (i >= j)
        return 0;

    // construct an unique map key from dynamic elements of the input
    string key = to_string(i) + "|" + to_string(j);

    // if sub-problem is seen for the first time, solve it and
    // store its result in a map
    if (lookup.find(key) == lookup.end())
    {
        // if last character of the string is same as the first character
        if (X[i] == X[j])
            lookup[key] = minDeletions(X, i + 1, j - 1, lookup);
        else
        // if last character of string is different to the first character

        // 1. Remove last character & recur for the remaining substring
        // 2. Remove first character & recur for the remaining substring

        // return 1 (for remove operation) + minimum of the two values

        lookup[key] = 1 + min (minDeletions(X, i, j - 1, lookup),
                        minDeletions(X, i + 1, j, lookup));
    }

    // return the subproblem solution from the map
    return lookup[key];
}

int main()
{
    string X = "ACBCDBAA";
    int n = X.length();

    // create a map to store solutions of subproblems
    unordered_map<string, int> lookup;

    cout << "The minimum number of deletions required are " <<
        minDeletions(X, 0, n - 1, lookup);

    return 0;
}
